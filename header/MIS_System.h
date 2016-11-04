#ifndef H_MIS_SYSTEM
#define H_MIS_SYSTEM

/******************
* FILE: MIS_System.h
* Author: Arthur Kung
* Date: Nov 2, 2016
*
* Details:
*	- The methods declared in this header file are implemented in 
		MIS_System.cpp.
*
*	- This file contains the declaration of the MIS_System management class.
*		This class oversees the entire MIS system. It contains the command
*		vector, the parser that reads the input file into the command vector,
*		and the labels and variable vectors. Everything that must be done
*		in order to run the input file's code will be executed from within
*		this class.
*
*		External code should NOT be able to directly manipulate any of the
*		parsed code, variables, or labels.
******************/


#include <string>		// strings
#include <fstream>		// file i/o
#include <vector>		// std vectors

#include "Command.h"
#include "Label.h"
#include "Variable.h"
#include "MIS_System_Data.h"


class MIS_System
{

	MIS_System_Data mdata;	
	
	public:
	
			// these should throw exceptions for errors			
			
			
			// NOTE: parser should use a map of command names (strings) and
			//			function pointers, to directly compare the parsed
			//			command and get its matching function pointer.
			
			// NOTE 2: if ANY vector or map fails to expand/add items,
			//			we MUST catch the exception and exit elegantly.
			//			The STD containers WILL throw std::bad_alloc exceptions
			//			if there is not enough memory to expand or create items!
		void parse(string filename);	// parse file into vectors
		void run();						// execute through the command vector
			
	
};







#endif


