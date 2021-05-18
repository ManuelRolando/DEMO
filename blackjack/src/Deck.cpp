// Deck.h - implementation of method

// get random card
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<random>
#include<vector>
#include<iostream>

#include "../include/Deck.h"
#include "../include/Card.h"

using namespace std;


/* Implementation of DeckSuitCard Class */

DeckSuitCard::DeckSuitCard()
{
SuitCard Spades("Spades", "♠");
SuitCard Diamonds("Diamonds", "♦");
SuitCard Hearts("Hearts", "♥");
SuitCard Clubs("Clubs", "♣");

DeckSuit.push_back(Spades);
DeckSuit.push_back(Diamonds);
DeckSuit.push_back(Hearts);
DeckSuit.push_back(Clubs);
}

vector<SuitCard> DeckSuitCard::getDeckSuit()
{
    return DeckSuit;
}


/* Implementation of Deck Class */

Deck::Deck(int ndecks)
: num_decks{ndecks}
{
    int num_cards = NCARDS*num_decks;


    // Setting values for cards
    DeckSuitCard DECK_SUIT_CARD;    // standar deck
    vector<SuitCard> DECK_SUIT = DECK_SUIT_CARD.getDeckSuit();    
    
    Card new_card;
    
    for(int i=0; i<num_decks; i++)
    {
        for(SuitCard suit : DECK_SUIT)
        {
        	for(int value=1; value <= 13; value++)
        	{
        		new_card.reConstructor(value, suit);
        		cards.push_back(new_card);
        	}
        }
    }
    //debug
    //cout << "(debug)FINISH DECK CONSTRUCTOR" << endl;
}

// get a card of the deck and delete it
Card Deck::getCard()
{
    if (cards.size() > 0)
    {
        Card card = cards[0];
        cards.erase(cards.begin());
        return card;
    }
    Card empty; // empty if there is not cards
    return empty;
}

void Deck::shuffle()
{  
    // important for generation of diferent deck shuffled
    srand(unsigned(std::time(0))); 
    random_shuffle(cards.begin(), cards.end());
}

void Deck::simplePrint()
{
    for(Card card : cards)    
        card.simplePrint(); 

}