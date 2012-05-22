//============================================================================
// Name        : scanner.h
// Author      : Vishnu Suresh
// Version     :
// Copyright   : Your copyright notice
// Description : Scanner encapsulation header file
// Created on  : Mar 17, 2012
//============================================================================


#ifndef SCANNER_H_
#define SCANNER_H_


//class token_unit;

#include"universal.h"
class scanner
{

public:
	token_unit *token_buffer;
	void scan();


	token_unit single_token;






private:





	int length;

};




#endif /* SCANNER_H_ */
