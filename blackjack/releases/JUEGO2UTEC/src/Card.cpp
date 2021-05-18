#include "../include/Card.h"
#include<iostream>
#include <string>

using namespace std;


/* SuitCard Class implementation */
SuitCard::SuitCard(string suit, string symbol)
{
	suit_card = suit;
	symbol_card = symbol;
}


string SuitCard::getSuit()
{
    return this->suit_card;
}

string SuitCard::getSymbol()
{
    return this->symbol_card;
}

/* Card Class implementation */

Card::Card(int value_card,SuitCard suit_card)
:value{value_card}
{
	suit = suit_card;
}

void Card::reConstructor(int new_value_card,SuitCard new_suit_card)
{
	suit = new_suit_card;
    value = new_value_card;
}

string Card::getSuit()
{
	return suit.getSuit();
}

string Card::getSymbol()
{
	return suit.getSymbol();
}

string Card::getValue()
{
    switch(value)
    {
    case 11:
    	return "J";

    case 12:
    	return "Q";

    case 13:
    	return "K";

    case 1: // AS
    	return "AS";
    default:
    	return to_string(value);
    }

}

//tested
int Card::getBlackjackValue()
{
    string value_card = this->getValue();
   
   if(value_card == "J" || value_card == "Q" || value_card == "K")
        return 10;
    else if (value_card == "AS")
        return 1;
    else
        return atoi(value_card.c_str());
}


/*
bool Card::operator==(Card & other_card)
{
    if(value == other_card.value && suit->suit == other_card.suit->suit)
    {
        return true;
    }
    return false;
}
*/


void Card::graphicPrint()
{
    string card_value;
    if (this->getValue() == "AS" || this->getValue() == "10")
    {
        /* LINUX
        card_value = 
            "║     " + this->getValue() +"     ║\n";
        */
       card_value = 
            "|     " + this->getValue() +"     |\n";
    }
    else
    {
        /* LINUX
        card_value = 
            "║      " + this->getValue() +"     ║\n";
        */
       card_value = 
            "|      " + this->getValue() +"     |\n";
    }
    /* LINUX
    string card_symbol = "║      " + suit.getSymbol() + "     ║\n";

	cout    << "╔════════════╗\n"
			<<  card_value
		    <<	"║            ║\n"
            <<	card_symbol
            <<	"║            ║\n"
		    <<	"║            ║\n"
		    <<	"╚════════════╝" << endl;
    */
   // WINWDOWS
   //string card_symbol = "|      " + suit.getSymbol() + "     |\n";

	cout    << "|=============|\n"
			<<  card_value
		    <<	"|            |\n"
            //<<	card_symbol
            <<	"|            |\n"
		    <<	"|            |\n"
		    <<	"|============|" << endl;
}

void Card::simplePrint()
{
	cout 	<<"[+] " <<  this->getValue() 
            << " of " << suit.getSuit()<< endl; 
        //    << "(" << suit.getSymbol() << ")" << endl;
}