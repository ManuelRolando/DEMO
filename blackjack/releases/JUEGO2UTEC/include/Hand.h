/* 
*   blackjack game - Hand class
*   This class give you functionalities for check
*   blackjack rules in an Hand of cards
*   Tested Class
*/

#ifndef INCLUDE_HAND_H_
#define INCLUDE_HAND_H_


#ifndef INCLUDE_CARD_H_
#include "Card.h"
#endif /*INCLUDE_CARD_H_*/

#ifndef INCLUDE_DECK_H_
#include "Deck.h"
#endif /*INCLUDE_DECK_H_*/

#include<vector>
#include<cstdlib>

typedef struct doubleHand
{
    std::vector<Card> firstHand;
    std::vector<Card> secondHand;
} doubleHand;

class Hand
{
private:
// alive=true (your sum in lower than 21)
// alive=false (your sum in greater than 21)
    bool alive;
    std::vector<Card> hand;
    // this variable is used for separate cards
    std::vector<doubleHand> separate_hand;   
    int total; //sum of card's values of your hand
public:
    Hand():total{0}, alive{true}{}
    //~Hand(){}
    Card getCard(Deck & deck);    // get card of the deck
    
    bool isblackjack();    // verify if your hand is blackjack
    bool isseparateCards();   // verify if i can separate my cards 

    //void separateCards();   // CORREGIR ERROR
    
    // REEMPLAZADOS POR Card::getBlackjackValue()
    // get the value of the card for playing blackjack
        // K, Q, J = 10 , A(As) = 1 or 11
    //friend int getvalueCard(Card player_card);
    //int getvalueCard(Card player_card); // NOTE: modified getValue in Card object
    int getTotal();
    void setTotal(int new_total){total = new_total;}
    std::vector<Card> getHand(){return hand;}
    bool getAlive(){return alive;}
    void setAlive(bool alive_bool){alive = alive_bool;}
    int getNumCards(){return hand.size();}
    // this is implement for betting secure against the dealer
    Card getFirstCard(){return hand[0];}
    Card getSecondCard(){return hand[1];}
    
    void delCards(); // del all the cards in Hand

};
#endif /*INCLUDE_HAND_H_*/
