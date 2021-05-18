/*
 * TestCard.cpp
 *
 *  Created on: Jul 6, 2020
 *      Author: glozanoa
 *
 *      Testing Card Class
 */


#include "../include/Card.h"

#include <iostream>
using namespace std;

int main()
{
	//cout << "Into MAIN" << endl;


	string suit= "Headers";
	string symbol = "♥";
	SuitCard suit_card(suit, symbol);

	//cout << "FINISH WITH EX struct\n";
 	Card card(1, suit_card);
	/*
	cout 	<< "suit_card STRUCT:\n"
			<< "suit_card.suit: " << suit_card.getSuit()
			<< "\nsuit_card.symbol: "<< suit_card.getSymbol()<< endl;
	*/

	cout << "SUIT CLASS\n";
	cout 	<< "\nSuit: " << card.getSuit()
			<< "\nsymbol: " << card.getSymbol()
			<< "\nvalue: " << card.getValue() << endl;
			//<< "CARD:\n" << card.printCard() << endl;

	//card.printCard();
	//card.simplePrint();
	/*
	cout << "Suit: " << card.getSuit()
		 << "\nValue: " << card.getValue()
		 << "\nSymbol: " << card.getSymbol() << endl;
	*/
}
