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

		this -> memory_location = 5001;
		this -> next = 0;

cout<< "hashentry::hashentry()  " << identifier.val_str << endl;
	}

	int getkey();
	token_unit getidentifier();
	int getdatatype();
	hashentry* getnext();
	int getmemory();

	void setkey(int);
	void setdatatype(int);
	void setidentifier(token_unit);
	void setnext(hashentry*);
	void setmemory(int);


private:

	int key,datatype;
	token_unit identifier;
	hashentry* next;

	int memory_location;

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
	hashmap* get_previous();
	int get_memory(int);

	void set_scope(int);
	void put_identifier(int,int,token_unit);
	void set_next(hashmap*);
	void set_previous(hashmap*);
	void set_memory(int,int);

private:
	hashentry** table;
	int scope;
	hashmap* next;
	hashmap* previous;
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
	int get_location(int);

	void set_scope(int);
	void populate_table(int,int,token_unit);
	void set_location(int,int);

	void push_table();
	void pop_table();





private:

	int stackpointer,present_scope;
	hashmap* present_table;

};

#endif /* HASHTABLE_H_ */
