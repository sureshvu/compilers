/*
 * memory.h
 *
 *  Created on: Jun 6, 2012
 *      Author: vishnusuresh
 */

#ifndef MEMORY_H_
#define MEMORY_H_

class memory
{
public:

	memory()
	{
		this -> current_location = 5001;
		this -> stack_pointer = 5001;
		this -> heap_pointer = 5000;
		this -> frame_pointer = 5001;
		this -> return_address = 5001;
	}

	void setcurrentlocation(int);
	void sethp(int);
	void setsp(int);
	void setfp(int);
	void setra(int);

	int getcurrentlocation();
	int getfp();
	int getsp();
	int gethp();
	int getra();



private:
	int current_location;
	int heap_pointer;
	int stack_pointer ;
	int frame_pointer;
	int return_address;


};


#endif /* MEMORY_H_ */
