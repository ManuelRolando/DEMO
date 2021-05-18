/*
 * show_options.cpp
 *
 *  Created on: Jul 4, 2020
 *      Author: solalu
 */


#include <string>
#include <iostream>

using namespace std;

int main()
{
	string name = "glozanoa";
	string show_menu="";

	show_menu	+= "Hello " + name \
				+ ", your options are:\n"\
				+ "1) Retreat Cards\n"	\
				+ "2) ";
	cout << show_menu;
}
