//============================================================================
// Name        : registers.h
// Author      : Vishnu Suresh
// Version     :
// Copyright   : Your copyright notice
// Description : Registers header file
// Created on  : Mar 29, 2012
//============================================================================

#ifndef REGISTERS_H_
#define REGISTERS_H_


class registers
{
public:

	void free_register();
	void use_register();



private:
	float reg;
	float SP,FP,GP,RA;
	int top_register;


};

#endif /* REGISTERS_H_ */
