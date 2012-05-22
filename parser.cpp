//============================================================================
// Name        : parser.cpp
// Author      : Vishnu Suresh
// Version     :
// Copyright   : Your copyright notice
// Description : Token Parse functions defined in file
// Created on  : Mar 29, 2012
//============================================================================

#include"universal.h"
#include"parser.h"
#include"tokenizer.h"
#include"symboltable.h"
#include<iostream>
using namespace std;

//scanner token_generator;
tokenizer generate_token;
//token_unit present_token,next_token;

symboltable table;
int scope;


/* ------------------------------------------------------------------------ */

void parser::parsefile()
{
	//	Read the first token into the parser
	present_token = generate_token.s0();

	parser::functiondeclaration();
}

/* ------------------------------------------------------------------------ */

void parser::functiondeclaration()
{
	parser::functionheader();
	parser::functionbody();
}
/* ------------------------------------------------------------------------ */


void parser::functionheader()
{
cout << "Welcome to function header " << endl;

	if(present_token.id == GLOBAL)
	{
		// accept the keyword and move on

		//Read next token
			previous_token = present_token;
			present_token = generate_token.s0();

	}

		parser::parsetypemark();

		main_type = previous_token.id;  	// Get the return type of main.

		parser::matchtoken(FUNCTION);

		parser::matchtoken(T_IDENTIFIER);
		main = previous_token;				// NAME OF THE MAIN PROGRAM.



		parser::matchtoken(T_LPAREN);

		if(present_token.id != T_RPAREN)
		{
		parser::parseparameterlist();
		}

		parser::matchtoken(T_RPAREN);


}
/* ------------------------------------------------------------------------ */
void parser::functionheader2()
{
cout << " Function declaration 2 gateway " << endl;


/* PupulTE The symbol table and push the contents into the stack */
//		parser::matchtoken(T_IDENTIFIER);
		parser::match_populate();
		table.push_table();
		scope++;
cout << "Pushing table " << scope << endl ;

// Continue parsing operation
		parser::matchtoken(T_LPAREN);

		if(present_token.id != T_RPAREN)
		{
		parser::parseparameterlist();
		}

		parser::matchtoken(T_RPAREN);


}

/* ------------------------------------------------------------------------ */
// Underway :):):):):):):):):):):):):):):):)

void parser::functionbody()
{

cout<<"Welcome to function body " << endl;

	while (present_token.id != BEGIN)
	{
cout << "Declaration phase :)" << endl;
		parser::parsedeclaration();
		matchtoken(T_SEMICOLON);
	}

	/* Accept the BEGIN token and move on -- start the parsing of function statements */

	//Read next token
	previous_token = present_token;
	present_token = generate_token.s0();

	while (present_token.id != END)
	{
		parser::parsestatement();
		matchtoken(T_SEMICOLON);
	}

	/* Accept the END token and move on */




	//Read next token
	previous_token = present_token;
	present_token = generate_token.s0();

	parser::matchtoken(FUNCTION);



	/* Check the following code */
	if(present_token.id == -1 )
	{
		/* Consume token and end the parsing */
		cout << "END OF FILE :) " << endl;
	}


}

/* ------------------------------------------------------------------------ */

void parser::parsetypemark()
{


	if((present_token.id == INTEGER )||(present_token.id == FLOAT )||(present_token.id == BOOLEAN )||(present_token.id == STRING ) )
		{
			// Functions to accept token and move on

		}
	else
		{
			cout << "Parser error in line :  " << generate_token.get_lines()  << " :with token " << present_token.id <<  endl;
			exit(0);
		}
	//Read next token
	previous_token = present_token;
	present_token = generate_token.s0();



}

/* ------------------------------------------------------------------------ */

void parser::parseparameterlist()
{

cout << "Welcome to parameterlist" << endl;

	parser::parseparameter();


	if(present_token.id == T_COMMA)
	{
		// Functions to accept token and move on

		//Read next token
		previous_token = present_token;
		present_token = generate_token.s0();

		parser::parseparameterlist();
	}

cout << "Leaving  parameterlist" << endl;

}
/* ------------------------------------------------------------------------ */
void parser::parseparameter()
{
	parser::parsevariabledeclaration();
}

/* ------------------------------------------------------------------------ */
void parser::parsevariabledeclaration()
{

cout << "Welcome to variable declaration" << endl;
	if((present_token.id == GLOBAL ))
		{

			// Function to accept/consume token and move on
			// Read next token
				previous_token = present_token;
				present_token = generate_token.s0();

				parser::parsetypemark();

		}

	else
		{
			parser::parsetypemark();
		}

	// Populate the symbol table
//		parser::matchtoken(T_IDENTIFIER);
		parser::match_populate();


		if(present_token.id == T_LBRAC)
		{
			//Read next token
			previous_token = present_token;
			present_token = generate_token.s0();
			parser::matchtoken(T_INTEGER);

			parser::matchtoken(T_RBRAC);

		}

cout << "Leaving variable declaration" << endl;

}

/* ------------------------------------------------------------------------ */
void parser::variabledeclaration2()
{

	// Populate symbol table
//			parser::matchtoken(T_IDENTIFIER);
			parser::match_populate();


			if(present_token.id == T_LBRAC)
			{
				//Read next token
				present_token = generate_token.s0();
				parser::matchtoken(T_INTEGER);

				parser::matchtoken(T_RBRAC);

			}


}
/* ------------------------------------------------------------------------ */

void parser::match_populate()
{
cout << "Welcome to match populate" << endl;

	if(present_token.id == T_IDENTIFIER)
	{
cout << "Calculate key for " << present_token.id << endl;
		int key = parser::hashfunction(present_token);
cout << "Key " << key << endl;

// Function to accept token and move on
		table.populate_table(key,previous_token.id,present_token);
cout << "Populating table" << endl;
	}
	else
	{
		cout << "Parser error in line: " << generate_token.get_lines() <<  " Expected token: IDENTIFIER"  << endl;
		exit (0);
	}

	//Read next token
	previous_token = present_token;
	present_token = generate_token.s0();
cout << "Leaving match populate" << endl;

}



/* ------------------------------------------------------------------------ */

void parser::matchtoken(int token)
{
	if(present_token.id == token)
	{
		// Function to accept token and move on
			if(token == T_IDENTIFIER)
			{
//				table.populate_table(parser::hashfunction(present_token),previous_token.id,present_token);

			}
	}
	else
	{
		cout << "Parser error in line: " << generate_token.get_lines() <<  " Expected token: " <<  token << endl;
		exit (0);
	}

	//Read next token
	previous_token = present_token;
	present_token = generate_token.s0();

}
/* ------------------------------------------------------------------------ */

void parser::parsedeclaration()
{
cout << "Welcome to parse declaration" << endl;


	 if(present_token.id == GLOBAL)
	 	{
	 		// Function to accept/consume token and move on
	 		//Read next token
		 previous_token = present_token;
		 present_token = generate_token.s0();

	 		parser::parsetypemark();
	 	}

	 	else
	 	{
	 		parser::parsetypemark();
	 	}

	 if(present_token.id == FUNCTION)
	 {
		 // Function to accept/consume token and move on
		//Read next token
		present_token = generate_token.s0();

		parser::functionheader2();
		parser::functionbody();
	 }
	 else
	 {
		 parser::variabledeclaration2();

	 }


}
/* ------------------------------------------------------------------------ */
void parser::parsestatement()
{

	if(present_token.id == IF)
	{
		/* Accept the if and read the next token */

		present_token = generate_token.s0();
		parser::parseifstatement();
	}

	else if(present_token.id == FOR)
	{
		/* Accept the if and read the next token */

			present_token = generate_token.s0();
			parser::parseloopstatement();

	}

	else
	{
		parser::parseassignstatement();
	}

}

/* ------------------------------------------------------------------------ */

void parser::parseifstatement()
{
	parser::parseexpression();

	matchtoken(THEN);

	while (present_token.id != END)
	{
cout << "Processing THEN statements" << endl;
		parser::parsestatement();

		matchtoken(T_SEMICOLON);

		if(present_token.id == ELSE)
		{
			/* Accept the ELSE and read the next token */
			cout << "Accepting else" << endl;

			present_token = generate_token.s0();


					while (present_token.id != END )
					{
cout<< "Processing ELSe statements" << endl;
						parser::parsestatement();

						matchtoken(T_SEMICOLON);

					}

		}

	}



	if(present_token.id == END)
	{
		/* Accept the END and read the next token */

			present_token = generate_token.s0();

			parser::matchtoken(IF);

	}



}

/* ------------------------------------------------------------------------ */

/* ------------------------------------------------------------------------ */
void parser::parseloopstatement()
{

	parser::parseassignstatement();

	parser::parseexpression();

	while (present_token.id != END )
		{
			parser::parsestatement();

			matchtoken(T_SEMICOLON);

		}


	if(present_token.id == END)
	{

		/* Accept the if and read the next token */

		present_token = generate_token.s0();

		parser::matchtoken(FOR);

	}

}


/* ------------------------------------------------------------------------ */

void parser::functioncall()
{
	parser::matchtoken(T_IDENTIFIER);

	parser::matchtoken(T_LPAREN);

	parser::parseargumentlist();

	parser::matchtoken(T_RPAREN);

}


/* ------------------------------------------------------------------------ */

void parser::parseargumentlist()
{
cout << "Welcome to argument list" << endl;
/* Have to decide where exactly the parseexpression goes at the top of the if or below the  if */


	parser::parseexpression();

	if(present_token.id == T_COMMA)
	{
		/* Accept the COMMA and read the next token */

		present_token = generate_token.s0();

		parser::parseargumentlist();
	}



}


/* ------------------------------------------------------------------------ */
void parser::parseassignstatement()
{
cout << "Welcome to parse assign " << endl;
	parser::parsedestination();

	parser::matchtoken(T_COLON);
	parser::matchtoken(T_EQUAL);

	parser::parseexpression();



}
/* ------------------------------------------------------------------------ */
void parser::parsedestination()
{

	parser::matchtoken(T_IDENTIFIER);

	if(present_token.id == T_LBRAC)
	{

		/* Accept the token and read the next token */

			present_token = generate_token.s0();
			parser::parseexpression();

			parser::matchtoken(T_RBRAC);


	}


}
/* ------------------------------------------------------------------------ */

void parser::parseexpression()
{
	if(present_token.id == NOT)
	{
		/* Accept the token NOT and read the next token */

		present_token = generate_token.s0();


	}

	parser::parsearithmetic();

	parser::expression2();


}

/* ------------------------------------------------------------------------ */

void parser::expression2()
{
	if(present_token.id == T_AND)
	{
		/* Accept the token AND and read the next token */

		present_token = generate_token.s0();

		parser::parsearithmetic();

		parser::expression2();
	}

	else if(present_token.id == T_OR)
	{
		/* Accept the token OR and read the next token */

		present_token = generate_token.s0();

		parser::parsearithmetic();

		parser::expression2();

	}

}

/* ------------------------------------------------------------------------ */

void parser::parsearithmetic()
{
	parser::parserelation();

	parser::arithmetic2();


}

/* ------------------------------------------------------------------------ */

void parser::arithmetic2()
{
	if(present_token.id == T_PLUS)
	{
		/* Accept the token PLUS and read the next token */

		present_token = generate_token.s0();

		parser::parserelation();

		parser::arithmetic2();

	}

	else if(present_token.id == T_MINUS)
		{
		/* Accept the token MINUS and read the next token */

		present_token = generate_token.s0();

		parser::parserelation();

		parser::arithmetic2();

		}

}

/* ------------------------------------------------------------------------ */

void parser::parserelation()
{
	parser::parseterm();

	parser::relation2();


}

/* ------------------------------------------------------------------------ */
void parser::relation2()
{
	if(present_token.id == T_LESS)
	{
		/* Accept the token LESS and read the next token */

		present_token = generate_token.s0();

		parser::parseterm();

		parser::relation2();

	}

	else if(present_token.id == T_GREATER)
	{
		/* Accept the token LESS and read the next token */

		present_token = generate_token.s0();

		parser::parseterm();

		parser::relation2();

	}

	else if(present_token.id == T_NEQUAL)
		{
			/* Accept the token LESS and read the next token */

			present_token = generate_token.s0();

			parser::parseterm();

			parser::relation2();

		}

	else if(present_token.id == T_LEQUAL)
		{
			/* Accept the token LESS and read the next token */

			present_token = generate_token.s0();

			parser::parseterm();

			parser::relation2();

		}

	else if(present_token.id == T_EEQUAL)
		{
			/* Accept the token LESS and read the next token */

			present_token = generate_token.s0();

			parser::parseterm();

			parser::relation2();

		}

	else if(present_token.id == T_GEQUAL)
		{
			/* Accept the token LESS and read the next token */

			present_token = generate_token.s0();

			parser::parseterm();

			parser::relation2();

		}

}


/* ------------------------------------------------------------------------ */

void parser::parseterm()
{
		parser::parsefactor();

		parser::term2();

}

/* ------------------------------------------------------------------------ */

void parser::term2()
{
cout << "Welcome to term 2 " << endl;

	if(present_token.id == T_MULTIPLY)
	{
		/* Accept the token STAR and read the next token */

		present_token = generate_token.s0();

		parser::parsefactor();

		parser::term2();

	}

	else if(present_token.id == T_DIVIDE)
	{
		/* Accept the token DIVIDE and read the next token */

		present_token = generate_token.s0();

		parser::parsefactor();

		parser::term2();

	}

}

/* ------------------------------------------------------------------------ */

void parser::parsefactor()
{

cout << "Welcome to parsefactor" << endl;

	if(present_token.id == T_LPAREN)
	{
		/* Accept the token LPAREN and read the next token */

		present_token = generate_token.s0();

		if(present_token.id != T_RPAREN)
		{
		parser::parseexpression();
		}

		parser::matchtoken(T_RPAREN);
	}

	else if(present_token.id == T_QUOTE)
	{
		/* Accept the token QUOTE and read the next token */

		present_token = generate_token.s0();

		parser::matchtoken(T_STRING);

		parser::matchtoken(T_QUOTE);

	}

	else if ((present_token.id == TRUE) || (present_token.id == FALSE))
	{
		/* Accept the token TRUE/FALSE and read the next token */

		present_token = generate_token.s0();

	}

	else if ((present_token.id == T_MINUS) )
	{
		/* Accept the token MINUS and read the next token */

		present_token = generate_token.s0();

		if((present_token.id == T_INTEGER)|| (present_token.id == T_FLOAT))
		{
			/* Accept the token NUMBER and read the next token */

			present_token = generate_token.s0();

		}

		else
		{
			parser::parsename();
		}

	}


	else if ((present_token.id == T_INTEGER)|| (present_token.id == T_FLOAT))
	{
		/* Accept the token NUMBER and read the next token */

		present_token = generate_token.s0();
	}

/* have to take care of  name and functioncall */

	else if ( present_token.id == T_IDENTIFIER)
	{

		/* Accept the token IDENTIFIER and read the next token */

		present_token = generate_token.s0();

		if(present_token.id == T_LBRAC)
		{
			/* Accept the token LBRAC and read the next token */

			present_token = generate_token.s0();

			parser::name2();
		}


		else if (present_token.id == T_LPAREN)
		{
cout << "Welcom to funciton call in factor " << endl;
			/* Accept the token LPAREN and read the next token */

			present_token = generate_token.s0();

			if(present_token.id != T_RPAREN)
			{
			parser::parseargumentlist();
			}

			parser::matchtoken(T_RPAREN);

		}


	}
	else
	{
cout << "Parser error in factor line " << generate_token.get_lines() << endl;
exit (0);

	}

}

/* ------------------------------------------------------------------------ */

void parser::parsename()
{

cout << "Welcome to parsename" << endl;

	parser::matchtoken(T_IDENTIFIER);

	if(present_token.id == T_LBRAC)
	{
		/* Accept the token LBRAC and read the next token */

		present_token = generate_token.s0();

		parser::parseexpression();

		parser::matchtoken(T_RBRAC);
	}

}


/* ------------------------------------------------------------------------ */

void parser::name2()
{

		parser::parseexpression();

		parser::matchtoken(T_RBRAC);

}


//============================================================================
//============================================================================
//============================================================================
//============================================================================

int parser::hashfunction(token_unit identifier)
{
	int key,i;

	while(identifier.val_str[i] != '\0')
	{

		key = key + identifier.val_str[i];
	i++;
	}
	return(key);
}
/* ------------------------------------------------------------------------ */
void parser::print_variables()
{

cout << table.get_identifier(658).id << " data  " << table.get_identifier(658).val_str << "For scope " << table.get_scope() << "With datatype " << table.get_datatype(658) << endl;


}

//============================================================================
//============================================================================
//============================================================================
//============================================================================


/* ------------------------------------------------------------------------ */

parser::~parser()
{
	cout << " End of parse operations for main function " << main.val_str << "   With return type:	" << main_type<< endl;

}

/* ------------------------------------------------------------------------ */
