//============================================================================
// Name        : filehandler.h
// Author      : Vishnu Suresh
// Version     :
// Copyright   : Your copyright notice
// Description : Filehandler for the scanner
// Created on  : Mar 17, 2012
//============================================================================



#ifndef FILEHANDLER_H_
#define FILEHANDLER_H_

class filehandler
{


public:
	/*File opener */
	void open_file();

	/*File closer*/
	void close_file();

	/*Read file*/
	void read_file(char *,int );

	/* Get file length*/
	int file_length();

private:

	char file_name[256];    // File name with a max of 256 characters
	int length;



};



#endif /* FILEHANDLER_H_ */




