/*
 * stringToInt.cpp
 *
 *  Created on: Jul 4, 2020
 *      Author: solalu
 */



#include <string>
#include <iostream>

using namespace std;

int main()
{
	/*
	string number = "121";
	int int_num = atoi(number.c_str())+100;

	cout << "number(str) " << number
			<< "\nnumber(int) " << int_num << endl;
*/
	int num = 10;
	string str_num = to_string(num);

	cout << "str_num = " << str_num
		 <<	"\n str_num + HELLO = " << str_num + "HELLO" << endl;
}
