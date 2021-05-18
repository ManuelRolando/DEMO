/* 
*   blackjack game - Definicion of Card class and SuitCard struct 
*   NOTE: Source code is in src
* 	OBS:
* 		class definition and SRC code tested
*       Tested file: test/testCard.cpp
*/


#ifndef INCLUDE_CARD_H_
#define INCLUDE_CARD_H_

#include<string>
using namespace std;


class SuitCard{
protected:
	string suit_card;
	string symbol_card;

public:
    // NOTE: NO INICIALIZAR LAS VARIALBE CON PUNTEROS 
    // NULOS(Segmentation fault ERROR).
	SuitCard(){}
	SuitCard(string suit, string symbol);

	string getSuit();
	string getSymbol();

};

// Common card
class Card
{
protected:
    int value;
    //bool hide; // 1 =true (hide card), 0=false (unhide card)
    SuitCard suit;
public:
    Card():value{0}{}
    Card(int value_card, SuitCard suit_card);
    //~Card(){delete[] suit;};
    string getSuit();
    string getValue();
    int getBlackjackValue();
    string getSymbol();

    //void setSuit();
    //bool operator==(Card & other_card);
    void graphicPrint();
    void simplePrint();

    void reConstructor(int new_value_card,SuitCard new_suit_card);
    //friend ostream& operator<<(ostream &output, const Card  card);
};


#endif /* INCLUDE_CARD_H_ */
