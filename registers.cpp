//============================================================================
// Name        : registers.cpp
// Author      : Vishnu Suresh
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Register operations functions defined here
// Created on  : Mar 29, 2012
//============================================================================


#include"registers.h"
#include"iostream"
using namespace std;

void registers::free_register()
{
	top_register--;

}

// =================================================================================

void registers::use_register()
{
	top_register ++;
}
// =================================================================================


// =================================================================================


