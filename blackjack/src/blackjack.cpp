/* 
*   blackjack game - main
*
*/
#ifndef INCLUDE_BLACKJACK_H_
#include "../include/Blackjack.h"
#endif /* INCLUDE_BLACKJACK_H_*/

#include <string>
#include <random>
#include <iostream>
#include <unistd.h>

using namespace std;


/* Global Variables */
int num_decks = 1;
double init_cash = 1000;


void menu_blackjack(Group *groupPlayers);
void continuePlaying(string game_mode , Group *groupPlayers, Player *Dealer, int ndeck);
void payBets(vector<Player>* pPlayers, Player *Dealer);
void playBlackjack(Group *groupPlayers, Player *Dealer, int ndecks,  string modeGame);
void playDealer(Player *Dealer, Deck &deck);
void playPlayers(Group *groupPlayers, Player *Dealer, Deck &deck);
void registerPlayers(Group *groupPlayers);
void settings_game(Group *groupPlayers);
void showCardsPlayers(Group *groupPlayers);
void playSingleBlackjack(Group* groupPlayers, Player *Dealer, int ndecks);




void showCardsPlayers(Group *groupPlayers)
{
	for(Player bjPlayer :groupPlayers->getPlayers())
	{
		if(bjPlayer.getAlive())
		{
			string player_cards = " " + bjPlayer.getName() + " Cards\n";
			/*LINUX
			cout 	<< 	"═════════════════════════════\n"
					<<	player_cards
					<<	"═════════════════════════════\n";
			*/
		cout 		<< 	"===================================\n"
					<<	player_cards
					<<	"===================================\n";
			//bjPlayer.showHand("graphic"); // graphic or simple
			bjPlayer.showHand("simple");
			cout << "Total: " << bjPlayer.getTotal() << endl;
		}
	}
} 

void payBets(vector<Player>* pPlayers, Player *Dealer)
{
	/*LINUX
	cout 	<< "\n═══════════════════\n"
			<< "	BETS\n"
			<< "═══════════════════\n";
	*/
	cout 	<< "\n=====================\n"
			<< "	BETS\n"
			<< "=====================\n";

	vector<Player>::iterator bjPlayer;
	for(bjPlayer=pPlayers->begin(); bjPlayer!=pPlayers->end(); bjPlayer++)
	{
		cout 	<< "Bets " << bjPlayer->getName()
				<<  "(Puntuation: " << bjPlayer->getTotal()
				<< ")" <<  endl;
		double totalBet;
		if(bjPlayer->getAlive() &&  Dealer->getAlive())
		{
			// Secure bet
			if(bjPlayer->getSecureBet() > 0)
			{
				if(Dealer->haveBlackjack())
				{
					totalBet = bjPlayer->getSecureBet();
					bjPlayer->addCash(totalBet);
					bjPlayer->addCashWon(totalBet);
					cout 	<< "[+]Won Secure Bet : "
							<< totalBet << endl;  
				}

				else
				{
					totalBet = bjPlayer->getSecureBet();
					bjPlayer->subsCash(totalBet);
					bjPlayer->addCashLost(totalBet);
					cout << "[-]Lost Secure Bet: " << totalBet << endl;
				}
			}

			
			// Normal bet
			if(bjPlayer->getTotal() > Dealer->getTotal())
			{
				bjPlayer->addVictories();
				if(bjPlayer->haveBlackjack())
					{
						totalBet = 1.5*bjPlayer->getBet();
						bjPlayer->addCash(totalBet);
						bjPlayer->addCashWon(totalBet);
						cout 	<< "[+]Won Bet(blackjack): "
								<< totalBet << endl;
					}
				else
					{
						totalBet = bjPlayer->getBet();
						bjPlayer->addCash(totalBet);
						bjPlayer->addCashWon(totalBet);
						cout 	<< "[+]Won Bet: "
								<< totalBet << endl;
					}
			}
			else if(bjPlayer->getTotal() == Dealer->getTotal()) // empate
			{
				if (bjPlayer->haveBlackjack() || Dealer->haveBlackjack())
				{
					if(bjPlayer->haveBlackjack() && !(Dealer->haveBlackjack()))
					{
						bjPlayer->addVictories();
						totalBet = + 1.5*bjPlayer->getBet();
						bjPlayer->addCash(totalBet);
						bjPlayer->addCashWon(totalBet);
						cout 	<< "[+]Won Bet(blackjack): "
								<< totalBet << endl;
					} 
					else if(bjPlayer->haveBlackjack() && Dealer->haveBlackjack())
					{
						bjPlayer->addTie();
						totalBet = bjPlayer->getBet();
						bjPlayer->addCash(totalBet);
						cout << "[*]Recuperate Bet: " << totalBet << endl;
					}
					else{
						bjPlayer->addLosses();
						totalBet = bjPlayer->getBet();
						bjPlayer->subsCash(totalBet);
						bjPlayer->addCashLost(totalBet);
						cout 	<< "[-]Lost Bet: "
								<< totalBet << endl;
					}
				}
				else
				{
					bjPlayer->addTie();
					totalBet = bjPlayer->getBet();
					cout << "[*]Recuperate Bet: " << totalBet << endl;
				}
				
			}
			else
			{
				bjPlayer->addLosses();
				totalBet = bjPlayer->getBet();
				bjPlayer->subsCash(totalBet);
				bjPlayer->addCashLost(totalBet);
				cout 	<< "[-]Lost Bet: "
								<< totalBet << endl;
			}
		}
		else if (bjPlayer->getAlive() &&  !(Dealer->getAlive()))
		{	
			bjPlayer->addVictories();
			if(bjPlayer->haveBlackjack())
				{
					totalBet = 1.5*bjPlayer->getBet();
					bjPlayer->addCash(totalBet);
					bjPlayer->addCashWon(totalBet);
					cout 	<< "[+]Won Bet(blackjack): "
								<< totalBet << endl;
				}
			else
				{
					totalBet = bjPlayer->getBet();
					bjPlayer->addCash(totalBet);
					cout 	<< "[+]Won Bet: "
								<< totalBet << endl;
				}
		}
		else
		{
			bjPlayer->addLosses();
			totalBet = bjPlayer->getBet();
			bjPlayer->subsCash(totalBet);
			bjPlayer->addCashLost(totalBet);
			cout 	<< "[-]Lost Bet: "
								<< totalBet << endl;
		}
	}
}


void registerPlayers(Group *groupPlayers)
{
	string name_player;
	Player new_player;
	
	int num_newPlayers;
	cout << "How many players do you want to add? ";
	cin >> num_newPlayers;

	cout << "REGISTRATION" << endl;
	
	int num_existPlayers = groupPlayers->getSize();
	for(int i=1; i<=num_newPlayers; i++)
	{
		cout << "(Player " << i + num_existPlayers << ")Enter name: ";
		cin >> name_player;
		new_player.reConstructor(name_player, init_cash);
		if(groupPlayers->isInGroup(new_player))
		{
			cout 	<< new_player.getName() 
					<< " Player already exist." << endl;
			new_player.showInfo();	//show short info
		}
		else
		{
			groupPlayers->addPlayer(new_player);
		}
	}
}
/*
void playSingleBlackjack(Group* groupPlayers, Player *Dealer, int ndecks)
{
	cout << "Select a player:" << endl;
	groupPlayers->listPlayers();

	string singlePlayerName;
	cin >> singlePlayerName;

	Group singleGroup;
	Player* singlePlayer;
	singlePlayer = groupPlayers->getPPlayerByName(singlePlayerName);
	if(singlePlayer == nullptr)
	{
		cout << "No player was selected!" << endl;
		menu_blackjack(groupPlayers);
	}
	singleGroup.addPlayer(*singlePlayer);
	playBlackjack(&singleGroup, Dealer, num_decks, "Single");
}
*/
void playBlackjack(Group* groupPlayers, Player *Dealer, int ndecks, string modeGame)
{
	if(groupPlayers->getSize() >= 1)
	{
		if(modeGame == "Single")
		{
			cout << "Select a player:" << endl;
			groupPlayers->listPlayers();

			string singlePlayerName;
			cin >> singlePlayerName;

			Group singleGroup;
			Player* singlePlayer;
			singlePlayer = groupPlayers->getPPlayerByName(singlePlayerName);
			if(singlePlayer == nullptr)
			{
				cout << "No player was selected!" << endl;
				menu_blackjack(groupPlayers);
			}
			singleGroup.addPlayer(*singlePlayer);
			playBlackjack(&singleGroup, Dealer, num_decks, "Single");
		}
		else
		{
			cout 	<< "############################\n"
					<< "List of players in this game\n"
					<< "############################\n";
			groupPlayers->listPlayers();

			Deck deck(ndecks);
			deck.shuffle();
			
			// Init Bet
			vector<Player>* pPlayers = groupPlayers->getPointerPlayers();
			vector<Player>::iterator bjPlayer;
			for(bjPlayer=pPlayers->begin(); bjPlayer!=pPlayers->end(); bjPlayer++)
			{
				double bet_player;
				bool not_enoughCash = true;
				while(not_enoughCash)
				{
					cout << "(" << bjPlayer->getName() << ") How much do you want to bet? ";
					cin >> bet_player;

					double totalCash = bjPlayer->getCash();
					if(bet_player > totalCash)
					{
						cout 	<< "(" << bjPlayer->getName() << ")"
								<< " You don't have enough cash!\n"
								<< "Total Cash: " << totalCash << endl;  
					}
					else{
						not_enoughCash = false;
						bjPlayer->setInitBet(bet_player);
					}
				}
			}

			//repartir dos cartas iniciales
			for(int ncard=1; ncard<=2; ncard++)
			{
				vector<Player>::iterator bjPlayer;
				for(bjPlayer=pPlayers->begin(); bjPlayer!=pPlayers->end(); bjPlayer++)	//bjPlayer = blackjack player
				{
					bjPlayer->getCard(deck);
				}
				if(ncard == 1)
					Dealer->getCard(deck);
			}
			

			// showing players cards
			/* LINUX
			cout 	<< 	"╔═════════════════════════════╗\n"
					<<	"	Dealer Cards\n"
					<<	"╚═════════════════════════════╝\n";
			*/
			cout 	<< 	"====================================\n"
					<<	"	Dealer Cards\n"
					<<	"====================================\n";
			Dealer->showHand("simple");
			showCardsPlayers(groupPlayers);

			playPlayers(groupPlayers, Dealer, deck);
			
			// if all dead, Dealer don't play a win all the bets.

			if(groupPlayers->allDead())
			{
				payBets(pPlayers, Dealer);
				continuePlaying(modeGame, groupPlayers, Dealer, ndecks);
			}
			else
			{
				playDealer(Dealer, deck);
				payBets(pPlayers, Dealer);

				continuePlaying(modeGame, groupPlayers, Dealer, ndecks);	
			}
		}
		
	}
	else
	{
		cout 	<< "NO PLAYERS REGISTERED!\n"
				<< "Register your players and then play.\n";
		registerPlayers(groupPlayers);
		playBlackjack(groupPlayers, Dealer,ndecks,modeGame);
	}
}

// the dealer play if total is lower than 16 and it stand with greater than 17
void playDealer(Player *Dealer, Deck &deck)
{
	cout 	<<	"==================\n" 
			<<	"Dealer Game:\n"
			<<	"==================\n";
	Dealer->showHand("simple");
	while(Dealer->getTotal() <= 16 && Dealer->getAlive())
	{
		Card dealer_card = Dealer->getCard(deck);
		dealer_card.simplePrint();
		//std::this_thread::sleep_for (std::chrono::seconds(1));
		sleep(1);
	}
	cout << "(Dealer) Total: " << Dealer->getTotal() << endl;

}

/*
bool playerGetCard(vector<Player>::iterator &bjPlayer, Deck &deck)
{
	Card new_card = bjPlayer->getCard(deck);	
	new_card.simplePrint();
	if(!bjPlayer->getAlive())
	{
		cout 	<< "You sum your sum exceds 21\n"
				<< "(" << bjPlayer->getName() << ")"
				<< "Total: " 
				<< bjPlayer->getTotal() << endl;
		return false;
	}
	cout 	<< "(" << bjPlayer->getName()
			<< ")Total: " << bjPlayer->getTotal() << endl;
	return true;
}
*/
void playSepareteCards(vector<Player>::iterator &bjPlayer, Deck &deck)
{
	Card firstCard = bjPlayer->getFisrtCard();
	Card secondCard = bjPlayer->getSecondCard();

	cout << "First Hand" << endl;
	//bjPlayer
}

//return the amount of laon cash 
double loanCash(vector<Player>::iterator &bjPlayer, Group* groupPlayers)
{
	cout << "Select a player to lend money:\n";
	
	double transferedCash = 0.0;
	string lenderName;
	string beggarPlayerName = bjPlayer->getName();
	// List all the players in the gruop exect the beggar player
	groupPlayers->listLenderPlayers(beggarPlayerName);
	cout << "blakjack> ";
	cin >> lenderName;
	Player *plenderPlayer = groupPlayers->getPPlayerByName(lenderName);
	if(plenderPlayer == nullptr)
	{
		cout << "(Lender Player) " << lenderName << "Doesn't exist!" << endl;
		return 0;
	}
	else{
		cout 	<< "How many cash do you want to lend(MAX "
				<< plenderPlayer->getCash() << ")? ";
		cin >> transferedCash;
		bjPlayer->addCash(transferedCash);
		plenderPlayer->subsCash(transferedCash);
		return transferedCash;
	}
}	

void playPlayers(Group *groupPlayers, Player *Dealer, Deck &deck)
{
	vector<Player>::iterator bjPlayer;
	vector<Player> *pPlayers = groupPlayers->getPointerPlayers();
	for(bjPlayer=pPlayers->begin(); bjPlayer!=pPlayers->end(); bjPlayer++)
	{
		cout 	<< "##########################################\n"
				<< bjPlayer->getName() + " Game"
				<< "\t(Init Cash: " << bjPlayer->getCash() << ")\n"
				<< "Total:\t" << bjPlayer->getTotal() << "\n"
				<< "##########################################\n";
		string bj_option = "";
		while(bj_option != "nothing" && bjPlayer->getAlive())
		{
			
			cout << endl;
			bj_option = bjPlayer->getAction(*Dealer);
			
			if(bj_option == "Retreat")
			{
				bjPlayer->addLosses();
				bjPlayer->addCash(bjPlayer->getBet()/2);
				bjPlayer->setAlive(false);
			}
			else if(bj_option == "Secure")
			{
				double secure_bet;
				cout 	<< "How much do you want to bet for secure(< "
						<< bjPlayer->getBet() << ")? ";
				cin >> secure_bet;
				bjPlayer->setSecureBet(secure_bet);
			}
			else if(bj_option == "Double") // only give 1 card
			{
				double double_initBet = 2*bjPlayer->getBet();
				if(double_initBet > bjPlayer->getCash())
				{
					cout << "You don't have enough money for double your bet!\n";
					double loan_cash = loanCash(bjPlayer, groupPlayers);
					if( loan_cash > 0 && double_initBet < bjPlayer->getCash()+0.5)
					{
						bjPlayer->addLoanCash(loan_cash);
						bjPlayer->addCash(loan_cash);
					}
					else
					{
						cout << "Not enough cash for double bet!\n";
						continue;
					}
						
				}
				
				bjPlayer->setInitBet(double_initBet);
				Card finalCard = bjPlayer->getCard(deck);
				finalCard.simplePrint();
				if(!bjPlayer->getAlive())
				{
					cout 	<< "You sum your sum exceds 21\n"
							<< "(" << bjPlayer->getName() << ")"
							<< "Total: " 
							<< bjPlayer->getTotal() << endl;
				}
				else
					cout 	<< "(" << bjPlayer->getName()
							<< ")Total: " << bjPlayer->getTotal() << endl;
				
				break;
			}
			else if(bj_option == "GetCard")
			{
				// NOTE: encapsular en funcion playerGetCard
				Card new_card = bjPlayer->getCard(deck);	
				new_card.simplePrint();
				if(!bjPlayer->getAlive())
				{
					cout 	<< "You sum your sum exceds 21\n"
							<< "(" << bjPlayer->getName() << ")"
							<< "Total: " 
							<< bjPlayer->getTotal() << endl;
					break;
				}
				cout 	<< "(" << bjPlayer->getName()
						<< ")Total: " << bjPlayer->getTotal() << endl;
			}
			else if (bj_option == "Separate")
			{
				/*
				if(bjPlayer->getCash() >= 2*bjPlayer->getBet())
				{
					playSepareteCards(bjPlayer, deck);
					break;
				}
				else
				{
					cout << "You don't have enough money for separate game!\n";
					loanCash(bjPlayer, groupPlayers);
				}
				*/
				cout << "FINISH IMPLEMENTING" << endl;
			}
			else if(bj_option == "nothing" || bj_option == "Stand")
			{
				if(bj_option == "Stand")
					bj_option = "nothing";
				else
					cout << "INVALID OPTION (Stand default action)." << endl;
			}
		}
		
	}
}


void deleteCards(Group * groupPlayers, Player* Dealer)
{
	// Deleting old cards
	vector<Player>::iterator bjPlayer;
	vector<Player>* pPlayers = groupPlayers->getPointerPlayers();
	for(bjPlayer=pPlayers->begin(); bjPlayer!=pPlayers->end(); bjPlayer++)
	{
		bjPlayer->delHand();// elimina las cartas que tiene
		bjPlayer->setAlive(true);
		bjPlayer->setInitBet(0);
		bjPlayer->setSecureBet(0);
		bjPlayer->setTotal(0);
	}
	Dealer->delHand();
	Dealer->setAlive(true);
	Dealer->setTotal(0);
}

void addCashPlayer(Group *groupPlayers)
{
	cout 	<< "====================================\n"
			<< "Players\n"
			<< "====================================\n";
	groupPlayers->listPlayers();
	
	string nameQueryPlayer;
	cout << "Select the player: ";
	cin >> nameQueryPlayer;
	double cashQueryPlayer = 0.0;
	Player queryPlayer(nameQueryPlayer, cashQueryPlayer);
	
	Player* pQueryPlayer = groupPlayers->getPointerPlayer(queryPlayer);
	if(pQueryPlayer == nullptr)
	{
		cout 	<< "The Player (" << nameQueryPlayer 
				<< ") doesn't exist!" << endl;
	}
	else
	{
		cout 	<< "How many cash do you want to add to " 
				<< nameQueryPlayer << "? ";
		cin >> cashQueryPlayer;
		pQueryPlayer->addCash(cashQueryPlayer);
	}
		
}

void continuePlaying(string modeGame , Group *groupPlayers, Player *Dealer, int ndeck)
{
	string question = "Do you want to continue " + modeGame + "player game?[Y/N]";
	Answer answer(question);
	answer.askQuestion();
	int reply = answer.getState();
	if(reply == 1)
	{
		//system("clear");
		cout << "PLAYING" << modeGame << "MODE" << endl;
		deleteCards(groupPlayers, Dealer);
		playBlackjack(groupPlayers, Dealer ,ndeck, modeGame);
	}
	else if(reply == 0)
	{
		deleteCards(groupPlayers, Dealer);
		cout 	<< "\t1) Show player statistics\n"
				<< "\t2) Go back to main menu\n"
				<< "\t3) Go to setting game\n"
				<< "\t4) Quit Game\n"
				<< "blackjack> ";
		cin >> reply;
		switch (reply)
		{
			case 1:
				groupPlayers->showStatistics();
			case 2:
				//system("clear");
				menu_blackjack(groupPlayers);
				break;
			
			case 3:
				settings_game(groupPlayers);
				
			case 4:
				system("exit");
				break;

			default:
				cout << "[-]INVALID OPTION\n";
				system("exit");
		}
	}
	else
	{
		cout << "[-] INVALID OPTION\n"
			<< "[-] Come back soon!\n";
		system("exit");
	}
}

void delPlayer(Group* groupPlayers)
{
	
	cout << "Select a player to delete it.\n";
	groupPlayers->listPlayers();

	string delPlayerName;
	cout << "blackjack> ";
	cin >> delPlayerName;
	Player delPlayer(delPlayerName);
	groupPlayers->delPlayer(delPlayer);

}

void settings_game(Group *groupPlayers)
{
	int reply;
	cout << "Settings:\n"
				"\t1) Init Number of Decks\n"
				"\t2) Init Player Cash\n"
				"\t3) Add Player\n"
				"\t4) Del Player\n"
				"\t5) Add Cash\n"
				"\t6) Show Options\n"
				"\t7) show Statistics\n"
				"\t8) Play now\n"
				"blackjack> ";
	cin >> reply;

	switch(reply)
	{
	case 1:
		cout << "How many decks do you like to play? ";
		cin >> num_decks;
		settings_game(groupPlayers);	
		break;
	
	case 2:
		cout << "How much cash do you want to start? ";
		cin >> init_cash;
		settings_game(groupPlayers);
		break;
	case 3:	//Add Player
		registerPlayers(groupPlayers);
		settings_game(groupPlayers);
		break;
	case 4: //del player
		delPlayer(groupPlayers);
		settings_game(groupPlayers);
		break;
	case 5:	//Add Cash
		//cout << "CODE NOT DEBUGED" << endl;
		addCashPlayer(groupPlayers);
		settings_game(groupPlayers);

		break;

	case 6:
		cout 	<< "\tNumber of decks	: " << num_decks
				<< "\n\tInit Cash	: "	<< init_cash
				<< "\n\tRegisted Players:" << endl;
		for(Player bjPlayer : groupPlayers->getPlayers())
		{
			string name_player = bjPlayer.getName();
			double cash_player = bjPlayer.getCash();
			string cash_player_str = to_string(cash_player);

			cout 	<< "\t\t" + name_player
					<< "\t" +  cash_player_str << endl;

		} 

		settings_game(groupPlayers);
		break;

	case 7:
		groupPlayers->showStatistics();
		settings_game(groupPlayers);
		break;

	case 8:
		cout << "[+] CHANGES SAVED\n";	
		menu_blackjack(groupPlayers);
		//system("clear");
		
		break;

	default:
		cout << "[-] INCORRECT OPTION. NO CHAGES SAVED!" << endl;
		system("exit");
		break;
	}
}
/*
void topPlayers(Group groupPlayers, int nPLayers)
{
	Group topPlayers;
	vector<Player> players = groupPlayers.getPlayers();
	sort(players.begin(), players.end());
	vector<Player>::iterator iterPlayer;
	for(iterPlayer=players.begin(),iterPlayer!=players.begin()+nPLayers; iterPlayer++)
	{
		cout 	<< "(" << iterPlayer->getName() << ")"
				<< "Victories: " << iterPlayer->getVictories()
				<< "\tEarned money: " << iterPlayer->getEanedCash() << endl;
	}
}
*/

void menu_blackjack(Group *groupPlayers)
{
	Logo blackjack_logo;
	

	double cash_dealer = 10000;
	Player Dealer("Dealer", cash_dealer);	// Dealer player


	string logo_init = blackjack_logo.getRandomLogo();

	int reply;
	cout << logo_init << "\n"
			"1) Singleplayer\n"
			"2) Multiplayer\n"
			"3) Personalize your game\n"
			"4) Top Players\n"
			"99) Quit game\n"
			"blackjack> ";

	cin >> reply;
		
	switch(reply)
	{
	case 1:
		cout << "SINGLE PLAYER GAME\n";
		//playBlackjack(groupPlayers, &Dealer, num_decks, "Single");
		cout << "FINISH IMPLEMENTATION" << endl;
		menu_blackjack(groupPlayers);
		break;

	case 2:
		//system("clear");
		cout << "MULTIPLAYER GAME" << endl;
		playBlackjack(groupPlayers, &Dealer, num_decks, "Multi");
		break;

	case 3:
		settings_game(groupPlayers);
		break;
			
	case 4:
		//topPlayers(*groupPlayers, 5);
		cout << "NOT IMPLEMENTE YET!" << endl;
		menu_blackjack(groupPlayers);
		break;
	case 99:
		cout << "[-] Come back soon!\n";
		system("exit");
		break;
	default:
		cout << "[-] INVALID OPTION\n";
		system("exit");
	}
}



int main()
{
	Group groupPlayers; // allocate all the player in the game
	menu_blackjack(&groupPlayers);

	return 0;
}