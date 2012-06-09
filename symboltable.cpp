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
int hashentry::getmemory()
{
	return (memory_location);
}

/* ---------------------------------------------------------- */
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


/* ---------------------------------------------------------- */
void hashentry::setmemory(int memory)
{
	this -> memory_location = memory;
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

int hashmap::get_memory(int key)
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
			 return entry-> getmemory();
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


hashmap* hashmap::get_previous()
{
	return(this -> previous);
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
void hashmap::set_memory(int key,int memory)
{
	int hash = key % TABLESIZE;


	hashentry* entry;
	entry = table[hash];
	while((entry -> getkey() != key) )
	{
		entry = entry -> getnext();
	}

	if(entry -> getkey() == key)
	{
		entry -> setmemory(memory);
	}
	else
	{
cout << " The entry for data was not found :: No memory assigned" << endl;
	}
}

/* ---------------------------------------------------------- */

void hashmap::set_next(hashmap* next)
{

	this -> next = next;
}

void hashmap::set_previous(hashmap* previous)
{
	this -> previous = previous;
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

 int symboltable::get_location(int key)
 {
	 return(present_table -> get_memory(key));
 }
 /* ---------------------------------------------------------- */
 /* ---------------------------------------------------------- */

void symboltable::set_scope(int new_scope)
{

	present_table -> set_scope(new_scope);
}

/* ---------------------------------------------------------- */

void symboltable::set_location(int key, int location)
{

	present_table -> set_memory(key,location);
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

	if(present_table -> get_previous() == NULL)
	{
			hashmap* new_table;

			new_table = new hashmap;
			new_table -> set_next(present_table);
			new_table -> set_previous(NULL);

			present_table -> set_previous(new_table);

			new_table -> set_scope(stackpointer);

			present_table = new_table;


	cout<<"New # table inserted in stack with position  " << stackpointer << endl;

	}

	else
	{

		present_table= present_table->get_previous();

	}


}

/* ---------------------------------------------------------- */

void symboltable::pop_table()
{


	stackpointer--;

		present_scope = present_table->get_scope();
		present_scope--;

		if(present_scope == -1)
		{
			cout << "Stack is empty" << endl;
		}

		else
		{
			present_table = present_table -> get_next();

		}


	cout << "Top table is:  " << stackpointer << endl;



}

/* ---------------------------------------------------------- */
