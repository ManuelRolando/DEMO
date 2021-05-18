/* 
*   blackjack game - main
*
*/

//#include "../include/__init__.h"
#include "../include/Logos.h"
#include <string>
#include <random>
#include <iostream>

using namespace std;

int main()
{
	Logo blackjack_logos;

	char *menu;
	string logo_init = blackjack_logos.getRandomLogo();
	sprintf(menu,
			"%s\n"
			"1) Play blackjack\n"
			"2) Buy more chips\n"
			"3) View your advance\n"
			"99) Quit game\n"
			"blackjack> ", logo_init);

	cout << menu << endl;

}
