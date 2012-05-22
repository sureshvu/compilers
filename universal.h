/*
 * universal.h
 *
 *  Created on: Mar 17, 2012
 *      Author: Vishnu
 */

#ifndef UNIVERSAL_H_
#define UNIVERSAL_H_


/* --------------------------------------------------------------------------*/

class token_unit
{
public:
	int id;
	int datatype; 				// 1= char, 2- string , 3-int, 4- float
	int strcount;

	char val_char;
	char val_str[2048];
	int  val_int;
	float val_float;

	bool illegal_char;

/* Copy Constructor */
	token_unit& operator= (const token_unit& cSource)
	{

		 // check for self-assignment by comparing the address of the
		    // implicit object and the parameter
		    if (this == &cSource)
		        return *this;

	    // do the copy
	    id = cSource.id;
	    datatype = cSource.datatype;
	    strcount = cSource.strcount;
	    val_char = cSource.val_char;
	    for(int i =0; i < 2048 ; i ++)
	   	   {
	   	    val_str[i] = cSource.val_str[i];
	   	   }
	    val_int = cSource.val_int;
	    val_float = cSource.val_float;
	    illegal_char = cSource.illegal_char;


	    // return the existing object
	    return *this;
	}


};

/* --------------------------------------------------------------------------*/




#endif /* UNIVERSAL_H_ */
