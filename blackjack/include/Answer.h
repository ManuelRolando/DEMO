/*
 * Answer.h
 *
 *  Created on: Jul 3, 2020
 *      Author: solalu
 * 	Tested Answer class 
 * 	ERROR: Siempre inicializar el contructor
 * 			NO LEE PREGUNTAS COMPLETAS.  
 */

#ifndef INCLUDE_ANSWER_H_
#define INCLUDE_ANSWER_H_

#include <string>
#include <iostream>

class Answer {
private:
	bool accept;
	bool negate;
	bool ambiguous;
	std::string question;
	std::string answer_question;
public:
	Answer():accept{false}, negate{false}, ambiguous{true}{question="";}
	Answer(std::string shortQuestion):accept{false}, negate{false}, ambiguous{true}{question = shortQuestion;}
	//~Answer();

	void askQuestion();
	void changeQuestion(std::string newQuestion);
	// (accept)return 1(true), (negate)return 0(false), (ambiguos) return -1
	void setState();
	int getState();
	void setAccept();
	void setNegate();
	void setAmbiguo();

};

#endif /* INCLUDE_ANSWER_H_ */
