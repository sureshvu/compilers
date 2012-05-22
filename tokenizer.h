//============================================================================
// Name        : tokenizer.h
// Author      : Vishnu Suresh
// Version     :
// Copyright   : Your copyright notice
// Description : Token generator header file
// Created on  : Mar 17, 2012
//============================================================================


#ifndef TOKENIZER_H_
#define TOKENIZER_H_

#include"universal.h"
//class token_unit;

class tokenizer
{


public:

	/* Constructor for the class */

	tokenizer();

	/* Destructor for class */

	~tokenizer();


	/* Functions for lexeme read  other operations */

	char get_lexeme();
	char get_lexeme_whitespace();
	void roll_back(int);

	int get_length();

	int get_lines();




	int get_token_id();

	/* Functions for tokenization operations  */

	token_unit single_token;

	token_unit s0();
	void s0repeat();
	void alpha();
	void number();

	void single_tokens();
	void double_quotes();
	void string();

	void relational();
	void new_line();

	void colon();

	void check_keyword();

	void write_string();






private:

	char *char_buffer;
	int length;
	int lines; // Number of lines in the file ;

	char pseudo_token[256];

	char lexeme,next_lexeme,temp_lexeme;

	int trace,count;
	int token_count;

	int i,j,k;

//	bool float_flag;

	bool string_entry ;
	bool string_exit ;
	bool keyword_flag;

};



#endif /* TOKENIZER_H_ */




