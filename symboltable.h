//============================================================================
// Name        : hashtable.h
// Author      : Vishnu Suresh
// Version     :
// Copyright   : Your copyright notice
// Description : Hashtable implementation for symbol table
// Created on  : May 12, 2012
//============================================================================

#ifndef HASHTABLE_H_
#define HASHTABLE_H_



#include"universal.h"
#include<iostream>
using namespace std;

class hashentry
{
	public:

	/* Copy constructor for the class */
	hashentry(int key,int datatype, token_unit identifier )
	{
		this->key = key;

		this->datatype = datatype;
		this->identifier = identifier;
		this -> next = 0;

cout<< "hashentry::hashentry()  " << identifier.val_str << endl;
	}

	int getkey();
	token_unit getidentifier();
	int getdatatype();
	hashentry* getnext();

	void setkey(int);
	void setdatatype(int);
	void setidentifier(token_unit);
	void setnext(hashentry*);


private:

	int key,datatype;
	token_unit identifier;
	hashentry* next;

};


//============================================================================
//============================================================================

const int TABLESIZE = 100;

//============================================================================
//============================================================================

class hashmap
{

public:

	hashmap()
	{
		table = new hashentry* [TABLESIZE];

		for(int i=0; i<TABLESIZE;i++)
		{
		table[i] = 0;

		}


	}



	int get_scope();
	token_unit get_identifier(int);
	int get_datatype(int);
	hashmap* get_next();

	void set_scope(int);
	void put_identifier(int,int,token_unit);
	void set_next(hashmap*);

private:
	hashentry** table;
	int scope;
	hashmap* next;
	token_unit present_token;

};

//============================================================================
//============================================================================
//============================================================================
//============================================================================

class symboltable
{

public:

	symboltable();


	int get_scope();
	token_unit get_identifier(int);
	int get_datatype(int);

	void set_scope(int);
	void populate_table(int,int,token_unit);

	void push_table();
	void pop_table();





private:

	int stackpointer;
	hashmap* present_table;

};

#endif /* HASHTABLE_H_ */
