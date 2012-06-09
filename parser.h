//============================================================================
// Name        : parser.h
// Author      : Vishnu Suresh
// Version     :
// Copyright   : Your copyright notice
// Description : Token Parse header file
// Created on  : Mar 29, 2012
//============================================================================


#ifndef PARSER_H_
#define PARSER_H_

class token_unit;
//#include"universal.h"
class parser
{

public:

	/* Main functions for the parse operations  */

	void functiondeclaration();
	void functionheader();
	 void functionbody();
	 void functioncall();


	/* Get the next token */
	//token_unit token_scan();

	void read_token();

	/* Functions that match tokens */
	void matchtoken(int);
	void match_populate();


	void parsefile();

	/* Parse functions to parse each tokens */
	void parsetypemark();
	void parseparameter();
	void parsevariabledeclaration();
	void parseparameterlist();

	void parsedeclaration();
	void parsestatement();

	void parsedestination();


	/* Repeat functions  with minor changes */
	void functionheader2();
	void variabledeclaration2();

	void parseifstatement();
	void parseloopstatement();
	void parseassignstatement();

	void parseargumentlist();

	void parseexpression();
	void parsearithmetic();
	void parserelation();
	void parseterm();
	void parsefactor();

	void expression2();
	void arithmetic2();
	void relation2();
	void term2();

	void name2();

	void parsename();

	// General parser function related to the hashtable
	int hashfunction(token_unit);
	void print_variables();

	// General Parser functions for typechecking
	void typecheck();
	void update_datatype();


	~parser();


private:
	token_unit present_token,next_token,previous_token;
	enum TOKENNAMES { T_IDENTIFIER,T_INTEGER,T_FLOAT,T_SEMICOLON,T_MINUS,T_PLUS,T_COMMA,T_LPAREN,T_RPAREN,T_LBRAC,T_RBRAC,T_MULTIPLY,T_DIVIDE,T_COLON,

		T_AND = 15,T_OR = 16,
		T_LESS = 25,T_EQUAL,T_GREATER,T_NOT,
		T_LEQUAL = 30,T_EEQUAL,T_GEQUAL,T_NEQUAL,
		T_QUOTE = 49,T_STRING = 50,
		FUNCTION = 101, BEGIN = 105,END,GLOBAL = 110,
		INTEGER = 115,FLOAT,BOOLEAN,STRING,
		IF = 120,THEN,ELSE,
		FOR = 125,NOT = 130,
		TRUE = 135,FALSE = 136





	};

	/* structure to hold main data */
	token_unit main;
	int main_type;

	// Data type storage units
	int current_type;
	int function_type;
	int factor_type;
	bool argument_flag;

	bool global_flag;

	bool if_flag,for_flag;


};





#endif /* PARSER_H_ */
