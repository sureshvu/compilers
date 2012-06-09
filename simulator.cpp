//============================================================================
// Name        : simulator.h
// Author      : Vishnu Suresh
// Version     :
// Copyright   : Your copyright notice
// Description : Main file for scanner
// Created on  : Mar 17, 2012
//============================================================================



#include"universal.h"
#include<iostream>
using namespace std;
//#include"scanner.h"

//#include"tokenizer.h"

#include"parser.h"
int main()
{

	parser parsetree;

	//int i;



	parsetree.parsefile();

	cout << "Back to main() " << endl;

}

