/* 
*   blackjack game - Player class implementation
*
*/
#include "../include/Player.h"
#include "../include/Deck.h"

#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

Player::Player(string name_player)
{
	name = name_player;
	//cash = cash_player;
	alive = true;
	initBet = 0;
	secureBet = 0.0;
	cash = 0;
	victories = 0;
	tie = 0;
	losses = 0;
	cash_losses = 0;
	cash_winner = 0;
	loan_cash=0;
}

Player::Player(string name_player, double cash_player)
{
	name = name_player;
	cash = cash_player;
	alive = true;
	initBet = 0;
	secureBet = 0.0;
	//resultBet = 0;
	victories = 0;
	tie = 0;
	losses = 0;
	cash_losses = 0;
	cash_winner = 0;
	loan_cash=0;
}

void Player::reConstructor(string name_player, double cash_player)
{
	name = name_player;
	cash = cash_player;
	alive = true;
	initBet = 0;
	secureBet = 0.0;
	//resultBet = 0;
	victories = 0;
	losses = 0;
	tie = 0;
	cash_losses = 0;
	cash_winner = 0;
	loan_cash=0;
}
/* LINUX
#include <thread>
#include <chrono>
*/
void Player::showHand(string mode)
{
	if(mode == "simple")
	{
		for(Card playerCard: cards.getHand())
		{	
			sleep(1);
			//std::this_thread::sleep_for (std::chrono::seconds(1));
			playerCard.simplePrint();
		}
	}
	else if(mode == "graphic")
	{
		for(Card playerCard: cards.getHand())
		{	
			sleep(1);
			//std::this_thread::sleep_for (std::chrono::seconds(1));
			playerCard.graphicPrint();
		}
	}
	else{
		cout 	<< "INCORECT MODE!"
				<< "Avariable modes: (simple/graphic)" << endl;
	}
}
void Player::getStatistics()
{

	string player_statistcs = "\n     " + name + " statistics";
	cout 	<< "\n========================================"
			<< player_statistcs
			<< "\n========================================"
			<< "\n[+] Number of Games	\t: " << victories + losses + tie
			<< "\n[+] Winner Games		: " << victories
			<< "\n[+] Losses Games		: " << losses
			<< "\n[+] Tie Games			: " << tie
			<< "\n[+] Winner Cash		\t: " << cash_winner
			<< "\n[-] Losses Cash		\t: " << cash_losses << endl;
			//<< "\n[+]========================================\n";
	//make a graphic of winner and losses with totalbets vector
}

// return the acction to do
string Player::getAction(Player dealer)
{
	vector<Option> valid_options;
	
	Option option(1, "GetCard");
	valid_options.push_back(option);

	/*
	option.reConstruct(2, "Retreat");
	valid_options.push_back(option);
	*/

	option.reConstruct(2, "Stand");
	valid_options.push_back(option);

	string menu="";
	menu	+= "Hello " + name 				\
				+ ", your options are:\n"	\
				+ "1) Get Card\n"			\
				+ "2) Stand Cards\n";

	int num_options = 2;

	if(this->getNumCards() == 2)
	{
		num_options++;
		option.reConstruct(num_options, "Retreat");
		valid_options.push_back(option);
		menu += to_string(num_options) + ") Retreat cards\n";
	}

	if (dealer.cards.getNumCards() == 1)
	{
		Card firstCardDealer = dealer.cards.getFirstCard();
		bool secureBetCero = (secureBet < 0.9)? true:false;
		if(firstCardDealer.getValue() == "AS" && secureBetCero)
		{
			num_options++;
			option.reConstruct(num_options, "Secure");
			valid_options.push_back(option);
			menu += to_string(num_options) + ") Secure\n";	
		}
	}
	
	
	if(cards.isseparateCards())
	{
		num_options++;
		option.reConstruct(num_options, "Separate");
		valid_options.push_back(option);
		menu += to_string(num_options) +  ") Separate Cards\n";
	}	

	if(cards.getNumCards() == 2 && (cards.getTotal()>=9 && cards.getTotal()<=11))
	{
		num_options++;
		option.reConstruct(num_options, "Double");
		valid_options.push_back(option);
		menu += to_string(num_options) \
			  + ") Doublate Bet (Init Bet: " \
			  + to_string(initBet) + ")\n";
	}

	cout << menu << "\nblackjack> ";
	
	int option_selected;
	cin >> option_selected;

	// Search action for this option selected
	for(Option option: valid_options)
	{
		if(option.getIndex() == option_selected)
		{
			string action_player =  option.getAction();
			//if(action_player == "")
			return action_player;
		}	
	}
	return "nothing";
}

Card Player::getCard(Deck &deck)
{
	Card new_card = cards.getCard(deck);
	alive = cards.getAlive();
	return new_card;
}

void Player::showInfo()
{
	cout << name << "\t" << cash << endl;
}

void Player::delHand()
{
	this->cards.delCards();	
}

void Player::setAlive(bool alive_bool)
{
	alive = alive_bool;
	cards.setAlive(alive_bool);
}

// top Player order
/*
bool Player::operator<(const Player player)
{
	if(victories > player.victories)
		return false;
	return true;
}

bool Player::operator<(const Player player)
{
	return !(*this<player);
}

bool Player::operator<=(const Player player)
{
	if(victories > player.victories || victories == player.victories)
		return false;
	return true;
}
*/