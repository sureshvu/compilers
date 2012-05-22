//============================================================================
// Name        : filehandler.cpp
// Author      : Vishnu Suresh
// Version     :
// Copyright   : Your copyright notice
// Description : Filehandler for the scanner
// Created on  : Mar 17, 2012
//============================================================================


#include <iostream>
#include <fstream>
#include"filehandler.h"
using namespace std;

ifstream input;

/* ---------------------------------------------------------------------- */

void filehandler::open_file()
{
	cout << "Enter name of the input file: ";
	cin.get (file_name,256);

			input.open (file_name);
		 if (!input.good())
			{
				cout << "Wrong file name  " ;
				cout << endl;
				exit (0);
			}
			return;
}


/* ---------------------------------------------------------------------- */

/*Read File*/
void filehandler::read_file(char *buffer, int length)
{

	input.read(buffer,length);
	return;

}


/*File length */
int filehandler::file_length()
{

	  input.seekg (0, ios::end);
	  length = input.tellg();
	  input.seekg (0, ios::beg);


	return (length);
}



/* ---------------------------------------------------------------------- */


/*File closer*/
void filehandler::close_file()
{
     input.close();
     return;
}

