//============================================================================
// Name        : tokenizer.cpp
// Author      : Vishnu Suresh
// Version     :
// Copyright   : Your copyright notice
// Description : Token generator
// Created on  : Mar 17, 2012
//============================================================================

#include"tokenizer.h"
#include"filehandler.h"
#include"universal.h"
#include<iostream>

#include <iomanip>

#include<cmath>
using namespace std;



/* ------------------------------------------------------------------------ */

/* Function to initialize --  fill the char buffer */

tokenizer::tokenizer()
{
	filehandler file;

	file.open_file();

	length = file.file_length();
	char_buffer = new char[length + 1];

	cout << "The length of the file is: " << length + 1 << '\n'; // file.file_length()

	file.read_file(char_buffer,length+1);

	char_buffer[length] = '^';


	cout << "Buffer Filled " << endl;

	/* Buffer filled */
/*
	 Print buffer
	cout << "Begin Print Buffer" << endl;

		while (i <= length)
			{
			cout << "The data read is " << char_buffer[i++] << endl; // Can also be used as char_buffer[i++] or *char_buffer (NO it cant);

			}

		cout << "End Print Buffer " << endl;

		 Initialize variables
*/
		string_entry = 0;
		string_exit = 0;
		lines = 0;
		token_count = 1;

	file.close_file();



}
/* ------------------------------------------------------------------------ */

char tokenizer::get_lexeme()
{

	temp_lexeme = char_buffer[trace];
	trace++;

	/*
	while ((temp_lexeme == ' ')||(temp_lexeme == '\t'))
	{
		temp_lexeme = get_lexeme();
	}
	*/
	return (temp_lexeme);

}


/* ------------------------------------------------------------------------ */

char tokenizer::get_lexeme_whitespace()
{

	lexeme = char_buffer[trace];
	trace++;


	return (lexeme);

}

/* ------------------------------------------------------------------------ */

void tokenizer::roll_back(int steps)
{
	trace = trace  - 1; // trace - steps - 1

	return;
}


/* ------------------------------------------------------------------------ */
int tokenizer::get_lines()
{
	return(lines + 1);
}


/* ------------------------------------------------------------------------ */
int tokenizer::get_length()
{
	return(length);
}
/* ------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------ */

token_unit  tokenizer::s0()
{

/* Initializations */
single_token.illegal_char = 0;
i = 0;count = 0;
keyword_flag = 0;
//single_token.val_char = '/0';
//single_token.val_str[0] = '/0';
single_token.val_int = 0;
single_token.val_float = 0;




	if((string_entry == 1) && (string_exit == 0))
	{
		tokenizer::string();
		return(single_token);
	}

	lexeme = get_lexeme();

	while((lexeme == ' ')||(lexeme == '\t'))
	{
		lexeme = get_lexeme();
	}

cout <<  endl;


	if (((lexeme >=65) && (lexeme <= 90 ))||((lexeme >=97) && (lexeme <= 122 )) )
	{
		tokenizer::alpha();
	}
	else if((lexeme >=48) && (lexeme <= 57 ) )
	{
		tokenizer::number();
	}

	else if((lexeme == ';')||(lexeme == '-')||(lexeme == '+')||(lexeme == '(')||(lexeme == ')')||(lexeme == '[')||(lexeme == ']')||(lexeme == '*')||(lexeme == '/')||(lexeme == ',')||(lexeme == '&')||(lexeme == '|'))
		{
		tokenizer::single_tokens();
		}

	else if(lexeme == '"')
		{
		tokenizer::double_quotes();

		}
	else if(lexeme == ':')
			{
			tokenizer::single_tokens();

			}

	else if((lexeme == '>')||(lexeme == '<')||(lexeme == '=')||(lexeme == '!'))
		{
		tokenizer::relational();

		}
	else if(lexeme == '\n')
		{
		tokenizer::new_line();

		}

	else if(lexeme == '^')
	{
		single_token.id = -1;
		single_token.datatype = 1;
		single_token.val_char = lexeme;
cout << "EOF token: " << lexeme << endl;
	}
	else
	{
		single_token.id = 555;
		single_token.val_char = lexeme;
		single_token.datatype = 1;
		cout << "Other lexemes " << endl;
	}


	token_count ++;

/* Print the token */

if(single_token.datatype == 1 )
{
	cout << "Token # " << token_count << "token value char: " << single_token.val_char << endl;

}
else if (single_token.datatype == 2)
{
	cout << "Token # " << token_count << "token value string: " << single_token.val_str << endl;
}
else if (single_token.datatype == 3)
{
	cout << "Token # " << token_count<< "token value int: " << single_token.val_int << endl;
}
else
{
	cout << "Token # " << token_count << "token value float: " << single_token.val_float << endl;
}

	return(single_token);
}


/* ------------------------------------------------------------------------ */

void  tokenizer::s0repeat()
{


	lexeme = get_lexeme();

	while((lexeme == ' ')||(lexeme == '\t'))
		{
			lexeme = get_lexeme();
		}

	if (((lexeme >=65) && (lexeme <= 90 ))||((lexeme >=97) && (lexeme <= 122 )) )
	{
		tokenizer::alpha();
	}
	else if((lexeme >=48) && (lexeme <= 57 ) )
	{
		tokenizer::number();
	}

	else if((lexeme == ';')||(lexeme == '-')||(lexeme == '+')||(lexeme == '(')||(lexeme == ')')||(lexeme == '[')||(lexeme == ']')||(lexeme == '*')||(lexeme == '/')||(lexeme == ',')||(lexeme == '&')||(lexeme == '|'))
		{
			tokenizer::single_tokens();
		}


	else if(lexeme == '"')
		{
		tokenizer::double_quotes();

		}
	else if(lexeme == ':')
			{
			tokenizer::single_tokens();

			}
	else if((lexeme == '>')||(lexeme == '<')||(lexeme == '='))
		{
		tokenizer::relational();

		}

	else if(lexeme == '\n')
			{
			tokenizer::new_line();

			}
	else if(lexeme == '^')
	{
		single_token.id = -1;
		single_token.datatype = 1;
		single_token.val_char = lexeme;
cout << "EOF token: " << lexeme << endl;
	}
	else
	{
		cout << "In other tokens::  token is: " << lexeme << endl;
		single_token.id = 555;
		single_token.val_char = lexeme;
		single_token.datatype = 1;
		single_token.illegal_char = 1;
		cout << "Other lexemes " << endl;
	}


//cout << "Returning token from tokenizer::s0:	" << single_token.val_char << endl;

	return;
}


/* ------------------------------------------------------------------------ */

void tokenizer::alpha()
{


	while((((lexeme >=65) && (lexeme <= 90 ))||((lexeme >=97) && (lexeme <= 122 ))||(lexeme == '_')||((lexeme >=48) && (lexeme <= 57 ) )  ) )
	{

		pseudo_token[i++] = lexeme;
		lexeme = get_lexeme();
	}


	count = i;



	tokenizer::roll_back(1);

	tokenizer::check_keyword();

	/* Tokenize */

	if(keyword_flag == 0)
	{
		single_token.id = 0;
		single_token.datatype = 2;
		single_token.strcount = count;

		for(i = 0;i < count; i++)
		{
			single_token.val_str[i] = pseudo_token[i];
		}

		single_token.val_str[count] = '\0'; // end the string of characters
	}



	/* initialize all counts */
	i = 0;

//	cout << "In alpha() TOken size is: " << count << "And token is: " << single_token.val_str << endl;

}
/* ------------------------------------------------------------------------ */

void tokenizer::write_string()
{
	int i;
	for(i = 0;i < count; i++)
			{
				single_token.val_str[i] = pseudo_token[i];
			}

			single_token.val_str[count] = '\0';

}


/* ------------------------------------------------------------------------ */

void tokenizer::check_keyword()
{

	if(count == 2)
	{
		if((pseudo_token[0] == 'i')&&(pseudo_token[1] == 'f'))
				{
					single_token.id = 120;
					single_token.datatype = 2;
					single_token.strcount = 2;
					tokenizer::write_string();
					keyword_flag = 1;

				}


	}

	else if (count == 3)
	{
		if((pseudo_token[0] == 'f')&&(pseudo_token[1] == 'o')&&(pseudo_token[2] == 'r'))
		{
			single_token.id = 125;
			single_token.datatype = 2;
			single_token.strcount = 2;
			tokenizer::write_string();
			keyword_flag = 1;

		}
		else if((pseudo_token[0] == 'n')&&(pseudo_token[1] == 'o')&&(pseudo_token[2] == 't'))
		{
			single_token.id = 130;
			single_token.datatype = 2;
			single_token.strcount = 2;
			tokenizer::write_string();
			keyword_flag = 1;
		}
		else if((pseudo_token[0] == 'e')&&(pseudo_token[1] == 'n')&&(pseudo_token[2] == 'd'))
		{
			single_token.id = 106;
			single_token.datatype = 2;
			single_token.strcount = 2;
			tokenizer::write_string();
			keyword_flag = 1;
		}


	}


	else if(count == 4)
	{

		if((pseudo_token[0] == 't')&&(pseudo_token[1] == 'h')&&(pseudo_token[2] == 'e')&&(pseudo_token[3] == 'n'))
		{
			single_token.id = 121;
			single_token.datatype = 2;
			single_token.strcount = 2;
			tokenizer::write_string();
			keyword_flag = 1;

		}
		else if((pseudo_token[0] == 'e')&&(pseudo_token[1] == 'l')&&(pseudo_token[2] == 's')&&(pseudo_token[3] == 'e'))
		{

			single_token.id = 122;
			single_token.datatype = 2;
			single_token.strcount = 2;
			tokenizer::write_string();
			keyword_flag = 1;
		}
		else if((pseudo_token[0] == 't')&&(pseudo_token[1] == 'r')&&(pseudo_token[2] == 'u')&&(pseudo_token[3] == 'e'))
			{

				single_token.id = 135;
				single_token.datatype = 2;
				single_token.strcount = 2;
				tokenizer::write_string();
				keyword_flag = 1;
			}

	}

	else if(count == 5)
	{
		if ((pseudo_token[0] == 'b')&&(pseudo_token[1] == 'e')&&(pseudo_token[2] == 'g')&&(pseudo_token[3] == 'i')&&(pseudo_token[4] == 'n'))
		{
			single_token.id = 105;
						single_token.datatype = 2;
						single_token.strcount = 2;
						tokenizer::write_string();
						keyword_flag = 1;

		}
		else if ((pseudo_token[0] == 'f')&&(pseudo_token[1] == 'l')&&(pseudo_token[2] == 'o')&&(pseudo_token[3] == 'a')&&(pseudo_token[4] == 't'))
		{

			single_token.id = 116;
						single_token.datatype = 2;
						single_token.strcount = 2;
						tokenizer::write_string();
						keyword_flag = 1;
		}
		else if ((pseudo_token[0] == 'f')&&(pseudo_token[1] == 'a')&&(pseudo_token[2] == 'l')&&(pseudo_token[3] == 's')&&(pseudo_token[4] == 'e'))
				{

					single_token.id = 136;
								single_token.datatype = 2;
								single_token.strcount = 2;
								tokenizer::write_string();
								keyword_flag = 1;
				}


	}

	else if(count == 6)
		{
			if ((pseudo_token[0] == 'g')&&(pseudo_token[1] == 'l')&&(pseudo_token[2] == 'o')&&(pseudo_token[3] == 'b')&&(pseudo_token[4] == 'a')&&(pseudo_token[5] == 'l'))
			{
				single_token.id = 110;
							single_token.datatype = 2;
							single_token.strcount = 2;
							tokenizer::write_string();
							keyword_flag = 1;

			}
			else if ((pseudo_token[0] == 's')&&(pseudo_token[1] == 't')&&(pseudo_token[2] == 'r')&&(pseudo_token[3] == 'i')&&(pseudo_token[4] == 'n')&&(pseudo_token[5] == 'g'))
			{

				single_token.id = 118;
							single_token.datatype = 2;
							single_token.strcount = 2;
							tokenizer::write_string();
							keyword_flag = 1;
			}


		}

	else if(count == 7)
			{
				if ((pseudo_token[0] == 'i')&&(pseudo_token[1] == 'n')&&(pseudo_token[2] == 't')&&(pseudo_token[3] == 'e')&&(pseudo_token[4] == 'g')&&(pseudo_token[5] == 'e')&&(pseudo_token[6] == 'r'))
				{
					single_token.id = 115;
								single_token.datatype = 2;
								single_token.strcount = 2;
								tokenizer::write_string();
								keyword_flag = 1;

				}
				else if ((pseudo_token[0] == 'b')&&(pseudo_token[1] == 'o')&&(pseudo_token[2] == 'o')&&(pseudo_token[3] == 'l')&&(pseudo_token[4] == 'e')&&(pseudo_token[5] == 'a')&&(pseudo_token[6] == 'n'))
				{

					single_token.id = 117;
								single_token.datatype = 2;
								single_token.strcount = 2;
								tokenizer::write_string();
								keyword_flag = 1;
				}


			}

	else if(count == 8)
				{
					if ((pseudo_token[0] == 'f')&&(pseudo_token[1] == 'u')&&(pseudo_token[2] == 'n')&&(pseudo_token[3] == 'c')&&(pseudo_token[4] == 't')&&(pseudo_token[5] == 'i')&&(pseudo_token[6] == 'o')&&(pseudo_token[7] == 'n'))
					{
						single_token.id = 101;
									single_token.datatype = 2;
									single_token.strcount = 2;
									tokenizer::write_string();
									keyword_flag = 1;

					}
				}




}


/* ------------------------------------------------------------------------ */


void tokenizer::single_tokens()
{


	if (lexeme == ';')
	{
		single_token.id = 3;
				single_token.datatype = 1;
				single_token.val_char = lexeme;

	}
	else if(lexeme == '-')
	{
		single_token.id = 4;
				single_token.datatype = 1;
				single_token.val_char = lexeme;

	}
	else if(lexeme == '+')
	{
		single_token.id = 5;
				single_token.datatype = 1;
				single_token.val_char = lexeme;
	}
	else if(lexeme == ',')
	{
		single_token.id = 6;
				single_token.datatype = 1;
				single_token.val_char = lexeme;
	}
	else if(lexeme == '(')
	{
		single_token.id = 7;
				single_token.datatype = 1;
				single_token.val_char = lexeme;
	}
	else if(lexeme == ')')
	{
		single_token.id = 8;
				single_token.datatype = 1;
				single_token.val_char = lexeme;
	}
	else if(lexeme == '[')
	{
		single_token.id = 9;
				single_token.datatype = 1;
				single_token.val_char = lexeme;
	}
	else if(lexeme == ']')
	{
		single_token.id = 10;
				single_token.datatype = 1;
				single_token.val_char = lexeme;
	}
	else if(lexeme == ':')
	{
		single_token.id = 13;
				single_token.datatype = 1;
				single_token.val_char = lexeme;
	}
	else if(lexeme == '*')
	{
		single_token.id = 11;
				single_token.datatype = 1;
				single_token.val_char = lexeme;
	}
	else if(lexeme == '&')
		{
			single_token.id = 15;
					single_token.datatype = 1;
					single_token.val_char = lexeme;
		}
	else if(lexeme == '|')
		{
			single_token.id = 16;
					single_token.datatype = 1;
					single_token.val_char = lexeme;
		}
	else
	{
		lexeme = get_lexeme();


		if(lexeme != '/')

		{


tokenizer::roll_back(1);

		single_token.id = 12;
		single_token.datatype = 1;
		single_token.val_char = lexeme;

		}
		else
		{
			while(lexeme != '\n')
				{
					 lexeme = get_lexeme_whitespace();

				}
			lines++;
			tokenizer::s0repeat();
		}


	}






}

/* ------------------------------------------------------------------------ */

void tokenizer::double_quotes()
{
/* Tokenize */
	single_token.id = 49;
	single_token.datatype = 1;
	single_token.val_char = lexeme;


	if(string_entry)
	{
		string_exit = 0;
	}

	string_entry = !(string_entry);


}

/* ------------------------------------------------------------------------ */
void tokenizer::string()
{


	lexeme = get_lexeme_whitespace();
	while(lexeme != '"')
	{

		if (((lexeme >=65) && (lexeme <= 90 ))||((lexeme >=97) && (lexeme <= 122 ))||(lexeme == '_')||((lexeme >=48) && (lexeme <= 57 ) ) || (lexeme == ' ') || (lexeme == '.') ||(lexeme == ';') || (lexeme == ':') ||(lexeme == '?') || (lexeme == '!') )
		{
			single_token.val_str[i++] = lexeme;
			lexeme = get_lexeme_whitespace();

		}
		else
		{
			single_token.val_str[i++] = lexeme;
			lexeme = get_lexeme_whitespace();
			single_token.illegal_char = 1;
		}


	}

	tokenizer::roll_back(1);

	single_token.val_str[i] = '\0';
	single_token.strcount  = i + 1;
	single_token.datatype = 2;
	single_token.id = 50;

cout << "String is:  " << single_token.val_str << endl ;

	string_exit = 1;

}

/* ------------------------------------------------------------------------ */

void tokenizer::new_line()
{
/* No Tokenization */

	lines++;


tokenizer::s0repeat();



}



/* ------------------------------------------------------------------------ */
void tokenizer::number()
{

	int i,j;
	bool float_flag = 0;
	float incount = 0,flcount = 0;


while((lexeme >=48) && (lexeme <= 57 ) )
{
	pseudo_token[i++] = lexeme;
	lexeme =  get_lexeme();

	incount++;
}
	incount --;
if(lexeme == '.')
{
//	pseudo_token[i++] = lexeme;
	lexeme =  get_lexeme();
	float_flag = 1;
}


while((lexeme >=48) && (lexeme <= 57 ) )
{
	pseudo_token[i++] = lexeme;
	lexeme =  get_lexeme();
	flcount++;
}
	flcount--;
count = i;

/* Tokenize */

tokenizer::roll_back(1);

/* Tokenize */


	if(float_flag == 1)
	{
		single_token.id = 2;
		single_token.datatype = 4;
		for(j=0;j<=incount;j++)
			{
			single_token.val_float +=  ((pseudo_token[j] - 48) * (pow(10 , incount - j)));
			}

cout << "Float calcuation" << incount << "  float count " << flcount << endl;
		for(j=incount + 1;j<=incount + 1 + flcount;j++)
			{
			single_token.val_float +=  ((pseudo_token[j] - 48) * (pow(10 , -(j - incount))));
			}


	}
	else
	{
		single_token.id = 1;
		single_token.datatype = 3;
		for(j=0;j<=incount;j++)
		{
			single_token.val_int +=  ((pseudo_token[j] - 48) * (pow(10 , incount - j)));
		}
		//single_token.val_int = pseudo_token[count - 1]* ;


	}
	single_token.strcount = incount + flcount + 1;


/* initialize all counts */




}

/* ------------------------------------------------------------------------ */

void tokenizer::relational()
{
	next_lexeme = get_lexeme();


	if(next_lexeme == '=')
	{
		if(lexeme == '>')
		{
			single_token.id = 32;
			single_token.val_str[0] = lexeme;
			single_token.val_str[1] = next_lexeme;
			single_token.val_str[2] = '\0';

			single_token.datatype = 2;
			single_token.strcount = 2;

		}
		else if(lexeme == '=')
		{
			single_token.id = 31;
			single_token.val_str[0] = lexeme;
			single_token.val_str[1] = next_lexeme;
			single_token.val_str[2] = '\0';

			single_token.datatype = 2;
			single_token.strcount = 2;

		}

		else if (lexeme == '<')
		{
			single_token.id = 30;
			single_token.val_str[0] = lexeme;
			single_token.val_str[1] = next_lexeme;
			single_token.val_str[2] = '\0';

			single_token.datatype = 2;
			single_token.strcount = 2;

		}

		else
				{
					single_token.id = 33;
					single_token.val_str[0] = lexeme;
					single_token.val_str[1] = next_lexeme;
					single_token.val_str[2] = '\0';

					single_token.datatype = 2;
					single_token.strcount = 2;

				}



	}

	else
	{
		tokenizer::roll_back(1);

		if(lexeme == '>')
				{
					single_token.id = 27;
					single_token.val_char = lexeme;

					single_token.datatype = 1;

				}
				else if(lexeme == '=')
				{
					single_token.id = 26;
					single_token.val_char = lexeme;

					single_token.datatype = 1;

				}

				else if (lexeme == '<')
				{
					single_token.id = 25;
					single_token.val_char = lexeme;

					single_token.datatype = 1;

				}

				else
				{
					single_token.id = 28;
						single_token.val_char = lexeme;

						single_token.datatype = 1;

				}

	}


}





/* ------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------ */
/* Destructor */

tokenizer::~tokenizer()
{

	/* Delete once done */




cout << "Destructor for tokenizer <<" << endl;


	delete[] char_buffer;


}







