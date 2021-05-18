/* 
*   blackjack game - Player class
*
*/

#ifndef INCLUDE_PLAYER_H_
#define INCLUDE_PLAYER_H_

#include<string>
#include<vector>

#ifndef INCLUDE_CARD_H_
#include "Card.h"
#endif  /*INCLUDE_CARD_H_*/

#ifndef INCLUDE_HAND_H_
#include "Hand.h"
#endif  /*INCLUDE_HAND_H_*/

#ifndef INCLUDE_DECK_H_
#include "Deck.h"
#endif /*INCLUDE_DECK_H_*/

using namespace std;


class Option
{
    protected:
        int index;
        string action;
    public:
        Option(){index=100; action="nothing";}
        Option(int index_option, string action_option):index{index_option}{action = action_option;}

        int getIndex(){return index;};
        string getAction(){return action;}

        //void setIndex(int index_option){index = index_option;}
        //void setAction(string action_option){action = action_option;}
        void reConstruct(int index_option, string action_option)
        {
            index = index_option;
            action = action_option;
        }
};

class Player
{
protected:
	// alive=true (your sum in lower than 21)
	// alive=false (your sum in greater than 21)
	bool alive;
    string name;
    double cash;    //dollar
    Hand cards;
    double initBet;
    
    double secureBet;   // if the delaer have a AS as first card
    //double resultBet;	// apuesta resultante (perdida o ganacia)

    //NOTA: para la primera accion la mayoria de acciones estan disponibles
    //      pero para las posteriores acciones algunas ya no.
    //bool firstActions;  // controlar acciones disponibles

    // variables for statistics
    int victories, losses, tie;
    double cash_winner, cash_losses, loan_cash;
    // alamcena "apuestas resultantes" de todos los juegos
    //vector<double> totalBets; 

public:
    Player(){}
    Player(string name_player);
    Player(string name_player, double cash_player);
    //~Player(){}

    void getStatistics();	//show statistics about winner and losses.
    string getAction(Player dealer); //show options for betting
    void showInfo();    // show the name and their cash

    /* Operation that the player can do*/
    Card getCard(Deck &deck);
    string getName(){return name;}
    int getTotal(){return cards.getTotal();}
    bool getAlive(){return alive;}
    double getBet(){return initBet;}
    double getSecureBet(){return secureBet;}
    int getNumCards(){return cards.getNumCards();}
    double getCash(){return cash;}
    int getVictories(){return victories;}
    double getEanedCash(){return cash_winner;}

    // separate game
    Card getFisrtCard(){return cards.getFirstCard();}
    Card getSecondCard(){return cards.getSecondCard();}
    //bool getFirstAction(){return firstActions;}

    void setSecureBet(double secure_bet){secureBet = secure_bet;}
    void setInitBet(double new_bet){initBet = new_bet;}
    void setAlive(bool alive_bool);
    void setTotal(int new_total){cards.setTotal(new_total);}
    void setCash(double new_cash){cash = new_cash;}
    //void setFirstAction(bool first_action_bool){firstActions=first_action_bool;}
    void showHand(string mode);


    void addCash(double eaned_cash){cash += eaned_cash;}
    void subsCash(double lost_cash){cash -= lost_cash;}

    void addCashWon(double eaned_cash){cash_winner += eaned_cash;}
    void addCashLost(double lost_cash){cash_losses += lost_cash;}

    void addLoanCash(double borrowed_cash){loan_cash += borrowed_cash;}
    //void addLoanCash(double borrowed_cash){loan_cash += borrowed_cash;}

    void addLosses(){losses+=1;};
    void addVictories(){victories+=1;};
    void addTie(){tie+=1;}

    void delHand();
    //void openCards();
    //void standCards();
    //void retreatCards();

    bool haveBlackjack(){return cards.isblackjack();}

    void reConstructor(string name_player, double cash_player);
    /* Bets that the player can do*/
	//void doubleBet();
    //void secureBet();

    // topPlayer order
    /*
    bool operator<(const Player player);
    bool operator>(const Player player);
    bool operator<=(const Player player);
    */
};



#endif /*INCLUDE_HAND_H_*/
