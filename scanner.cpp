//============================================================================
// Name        : scanner.h
// Author      : Vishnu Suresh
// Version     :
// Copyright   : Your copyright notice
// Description : Scanner encapsulation with the token buffer that holds the created token stream
// Created on  : Mar 17, 2012
//============================================================================


#include"universal.h"
#include"tokenizer.h"
#include"scanner.h"
#include<iostream>
using namespace std;



void scanner::scan()
{

	int i,j;
	tokenizer state;
	length = state.get_length();
	cout << "Length is: " << length << endl;
	token_buffer = new token_unit[length];

	token_unit temp_token;

	cout <<"Creating local token" <<endl;

	while(temp_token.id != -1)
	{
//		cout << "While check " << j++ << endl;
		temp_token = state.s0();
	cout << "temp token #" << j++ << "  is: " << temp_token.id << "   " << temp_token.datatype << endl;

		token_buffer[i++] = temp_token;

//		cout << "Spewing tokens" << endl;



	}

	cout << "End of scan "<< "TOken count: " <<  i <<  endl;
	cout << "Number of lines in program: " << state.get_lines() << endl;




}



