/*
 * memory.cpp
 *
 *  Created on: Jun 6, 2012
 *      Author: vishnusuresh
 */

#include"memory.h"


// ===========================================================

void memory::setcurrentlocation(int current)
{
	current_location = current;
}

// ===========================================================
void memory::setsp(int sp)
{
	stack_pointer = sp;
}


// ===========================================================

void memory::sethp(int hp)
{
	heap_pointer = hp;
}



// ===========================================================

void memory::setfp(int fp)
{
	frame_pointer = fp;
}


// ===========================================================

void memory::setra(int ra)
{

	return_address = ra;
}

// ===========================================================
// ===========================================================
// ===========================================================
// ===========================================================

int memory::getcurrentlocation()
{
	return(current_location);
}

// ===========================================================

int memory::getsp()
{
	return(stack_pointer);
}

// ===========================================================

int memory::getfp()
{
	return(frame_pointer);
}

// ===========================================================

int memory::gethp()
{
	return(heap_pointer);
}

// ===========================================================

int memory::getra()
{
	return(return_address);
}

// ===========================================================

