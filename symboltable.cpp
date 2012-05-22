//============================================================================
// Name        : symboltable.cpp
// Author      : Vishnu Suresh
// Version     :
// Copyright   : Your copyright notice
// Description : Hashtable implementation for symbol table
// Created on  : May 12, 2012
//============================================================================


#include<iostream>
using namespace std;

#include"symboltable.h"
#include"universal.h"


/* ---------------------------------------------------------- */
int hashentry::getkey()
{
	return(key);
}

/* ---------------------------------------------------------- */
int hashentry::getdatatype()
{
	return(datatype);
}

/* ---------------------------------------------------------- */
token_unit hashentry::getidentifier()
{


cout << "hashentry::getidentifier()   " << identifier.val_str << "	datatype:	" << datatype << endl;
	return(identifier);


}
/* ---------------------------------------------------------- */
hashentry* hashentry::getnext()
{
	return (next);
}

/* ---------------------------------------------------------- */
void hashentry::setkey(int key)
{

	this -> key = key;
}

/* ---------------------------------------------------------- */
void hashentry::setdatatype(int datatype)
{

	this -> datatype = datatype;
}

/* ---------------------------------------------------------- */
void hashentry::setidentifier(token_unit identifier)
{
	this -> identifier = identifier;

cout << "hashentry::setidentifier:		" << identifier.val_str << endl;

}

/* ---------------------------------------------------------- */
void hashentry::setnext(hashentry* next)
{
	this -> next = next;
}


//============================================================================
//============================================================================
//============================================================================
//============================================================================


int hashmap::get_scope()
{
	return (scope);

}

/* ---------------------------------------------------------- */

int hashmap::get_datatype(int key)
{
	int hash = key % TABLESIZE;
	 if(table[hash] ==  0)
	 {
		 return -1;
	 }

	 else
	 {
		 hashentry* entry = table[hash];
		 while((entry != 0) && (entry -> getkey() != key))
		 {
			 entry = entry-> getnext();
		 }
		 if(entry == 0)
		 {
			 return -1;
		 }

		 else
		 {
			 return entry-> getdatatype();
		 }

	 }

}

/* ---------------------------------------------------------- */

token_unit hashmap::get_identifier(int key)
{

	present_token.val_str[0] = '\0';
	int hash = key % TABLESIZE;

	 if(table[hash] ==  0)
	 {
		 return present_token;
	 }

	 else
	 {
		 hashentry* entry = table[hash];
		 while((entry != 0) && (entry -> getkey() != key))
		 {
			 entry = entry-> getnext();
		 }
		 if(entry == 0)
		 {
			 return present_token;
		 }

		 else
		 {
			 return entry-> getidentifier();
		 }

	 }

}

/* ---------------------------------------------------------- */

hashmap* hashmap::get_next()
{
	return(this -> next);
}

/* ---------------------------------------------------------- */
/* ---------------------------------------------------------- */

void hashmap::set_scope(int scope)
{

	this -> scope = scope;
}

/* ---------------------------------------------------------- */

void hashmap::put_identifier(int key,int datatype, token_unit identifier)
{
	int hash = key % TABLESIZE;

	if(table[hash] == 0 )
	{
		table[hash] =  new hashentry(key,datatype,identifier);
cout << "hashmap::put_identifier()   " << identifier.val_str << endl;

	}

	else
	{
		hashentry* entry = table[hash];

		while(entry -> getnext()!= 0)
		{
			entry = entry-> getnext();
		}
/*   //-- Test code without the get test
		if(entry -> getkey() == key)
		{
			entry -> setidentifier(identifier);
			entry -> setdatatype(datatype);
		}

		else

*/
		{
			entry -> setnext(new hashentry(key,datatype,identifier));
		}
	}

}

/* ---------------------------------------------------------- */

void hashmap::set_next(hashmap* next)
{

	this -> next = next;
}



//============================================================================
//============================================================================
//============================================================================
//============================================================================

symboltable::symboltable()
{

	stackpointer = 0;
	present_table = new hashmap ();

}

/* ---------------------------------------------------------- */

int symboltable::get_scope()
{
	return(present_table -> get_scope());
}

/* ---------------------------------------------------------- */
 token_unit symboltable::get_identifier(int key)
 {

	 return(present_table -> get_identifier(key));
 }

 /* ---------------------------------------------------------- */

 int symboltable::get_datatype(int key)
 {
	 return(present_table -> get_datatype(key));
 }

 /* ---------------------------------------------------------- */
 /* ---------------------------------------------------------- */

void symboltable::set_scope(int new_scope)
{

	present_table -> set_scope(new_scope);
}

/* ---------------------------------------------------------- */

void symboltable::populate_table(int key, int datatype, token_unit identifier)
{
	present_table -> put_identifier(key,datatype,identifier);
}

/* ---------------------------------------------------------- */

void symboltable::push_table()
{
	stackpointer++;

	hashmap* new_table;

	new_table = new hashmap;

	new_table -> set_next(present_table);
	new_table -> set_scope(stackpointer);

	present_table = new_table;


cout<<"New # table inserted in stack with position  " << stackpointer << endl;

}

/* ---------------------------------------------------------- */

void symboltable::pop_table()
{
	stackpointer--;
	hashmap* temp_table;

	if(stackpointer == -1)
	{
		cout << "Stack is empty" << endl;
	}

	else
	{
		temp_table = new hashmap;
		temp_table = present_table -> get_next();



		present_table = temp_table;
	}


cout << "Top table is:  " << stackpointer << endl;

}

/* ---------------------------------------------------------- */
