/* 
*   blackjack game - Deck class
*
*/

#include<vector>

#ifndef INCLUDE_DECK_H_
#define INCLUDE_DECK_H_

#ifndef INCLUDE_CARD_H_
#include "Card.h"
#endif  /*INCLUDE_CARD_H_*/

#define NCARDS 52 //number of cards in a deck

using namespace std;

// tipo de cartas en una baraja (corazones, trebol,espadas, cocos)
class DeckSuitCard
{
private:
    vector<SuitCard> DeckSuit;
public:
    DeckSuitCard();
    //~DeckSuitCard();
    std::vector<SuitCard> getDeckSuit();
};





class Deck
{
protected:
    int num_decks = 1;
    vector<Card> cards;
public:
    Deck(int ndecks);
    //~Deck(){delete[] cards;};
    Card getCard(); // get the first card of the Deck
    void shuffle(); // shuffle the Deck

    vector<Card> getDeck(){return cards;}

    void simplePrint();	//print all the cards in the Deck
};


#endif /*INCLUDE_DECK_H_*/
