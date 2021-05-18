/*
 * testDeck.cpp
 *
 *  Created on: Jul 7, 2020
 *      Author: solalu
 */

#include "../include/Deck.h"
#include "../include/Card.h"
#include<iostream>

using namespace std;

int main()
{
    Deck deck(1);   //ok
    Card deck_card = deck.getCard();

    cout << "Card of deck: \n";
    
    //deck_card.simplePrint();

    cout << "shuffle Deck: \n";
    deck.shuffle();
    
    cout << "Deck shuffled\n";
    //deck.simplePrint();
}