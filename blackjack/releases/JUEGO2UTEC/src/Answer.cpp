/*
 * Answer.cpp
 *
 *  Created on: Jul 3, 2020
 *      Author: solalu
 */

#include "../include/Answer.h"

#include <string>
//#include <boost/algorithm/string.hpp>
#include <iostream>

using namespace std;


int Answer::getState()
{
	if(accept)
		return 1;
	else if (negate)
		return 0;
	else
		return -1;
}

void Answer::setAccept()
{
	accept = true;
	negate = false;
	ambiguous = false;
}

void Answer::setNegate()
{
	accept = false;
	negate = true;
	ambiguous = false;
}

void Answer::setAmbiguo()
{
	accept = false;
	negate = false;
	ambiguous = true;
}

void Answer::setState()
{
	//boost::algorithm::to_lower(answer_question);
	if(answer_question == "yes" || answer_question == "y")
		this->setAccept();
	else if (answer_question == "no" || answer_question == "n")
		this->setNegate();
	else
		this->setAmbiguo();
}

void Answer::askQuestion()
{
	if(question == "")
	{
		string new_question="";
		cout << "Set question: ";
		
		// ERROR: this not read the 	complete question 
		cin >> new_question;	
		 
		question = new_question;
		this->askQuestion();
	}
	else
	{
		cout << question << " ";
		cin >> answer_question;
		this->setState();
	}
	
}

void Answer::changeQuestion(string newQuestion)
{
	question = newQuestion;
	this->askQuestion();
}




