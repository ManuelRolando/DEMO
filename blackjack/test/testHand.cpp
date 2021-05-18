#include "../include/Hand.h"
#include "../include/Deck.h"
#include <vector>
#include <iostream>

int main()
{
    Deck deck(1);
    Hand hand;

    deck.shuffle(); // varajear cartas
    hand.getCard(deck); // first card
    hand.getCard(deck); //second card

    // verify if is a blackjack
    cout << "[+] blackjack: " << hand.isblackjack() << endl;

    // verify if you can separate
    cout << "[+] separate: " << hand.isseparateCards() << endl;

    Card first = hand.getFisrtcard();
    cout << "First Card\n";
    cout << "Value: "<< first.getValue();
}