#include "../include/Hand.h"
#include "../include/Card.h"
#include "../include/Deck.h"
#include<vector>

#include<iostream> // debug

Card Hand::getCard(Deck & deck)
{
    Card new_card = deck.getCard();
    int optimal_value = new_card.getBlackjackValue();
    string str_optimal_value = new_card.getValue();
    
    if(str_optimal_value == "AS")
    {
        int puntuation;
        puntuation = total + 11;
        if(puntuation <= 21 && puntuation > (total+1))
            optimal_value = 11;
        else
            optimal_value = 1;

    }

    if(total + optimal_value > 21)
        alive = false;   
    else
        hand.push_back(new_card);
    
    total += optimal_value;
    
    return new_card;
}


bool Hand::isblackjack()
{
    if(hand.size() == 2 && total == 21)
        return true;
    return false;
}

bool Hand::isseparateCards()
{
    if(hand.size() == 2)
    {
        string value_first, value_second;
        
        value_first = hand[0].getBlackjackValue();
        value_second = hand[1].getBlackjackValue();
        if(value_first == value_second)
            return true;
    }
    return false;
}

// EROOR with allocation
/*
void Hand::separateCards()
{
    Card first, second;
    first = hand->at(0);
    second = hand->at(2);

    separate_hand = new twoHands;
    //separate_hand->first_hand = new vector<Card>;

    separate_hand->first_hand.push_back(first);
    //separate_hand->second_hand.push_back(second);
}
*/

// NOTE: Total esta actualizado (cada vez que agrega una carta)
int Hand::getTotal()
{
    return total;
}

void Hand::delCards()
{
    hand.erase(hand.begin(), hand.end());
}