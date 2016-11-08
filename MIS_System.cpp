/******************
* FILE: MIS_System.cpp
* Author: Arthur Kung
* Date: Nov 7, 2016
*
* Details:
*	- This contains the 'run' and 'parse' functions of the primary
*		MIS_System class. This relies on a number of other classes
*		in its implementation.
*
*	  The parsing is only partially completed here. All that the
*		parser included here does is find an opcode, then send
*		the parameter list to the found opcode's internal parser.
******************/


#include <memory>	// shared_ptr
#include <map>		// std maps
#include <string> 	// string
#include <iostream>		// input/output
#include <sstream>		// string stream
#include <fstream>		// file stream
#include <stdexcept>	// exceptions

#include "Command.h"
#include "MIS_System.h"
#include "MIS_Exception.h"



/***************************
* Function: MIS_System::run()
* 
* Input: N/A
* Output: N/A
*
* Details:
*	- This function iterates through the entire command vector and
*		executes every single command stored inside of it.
*
***************************/

	// this will throw an error on failure, either directly from here if
	//	OPCODE is unrecognized, or from the object-factory object interal
	//	parsers, if the parameters are malformed or otherwise unusable.
void MIS_System::parse(char* filename)
{
	std::map<string, std::shared_ptr<Command>> objf;
	
			//////////////////////////////////////////////////
			//--CREATE OBJECT FACTORY FOR THIS MIS_SYSTEM:--//
			//////////////////////////////////////////////////
	
		// note: objf["__"] = std::shared_ptr<Command>(new C_XYZ()) works too.	
	objf["ADD"].reset(new C_ADD(&mdata));
	objf["SUB"].reset(new C_SUB(&mdata));
	objf["MUL"].reset(new C_MUL(&mdata));
	objf["DIV"].reset(new C_DIV(&mdata));
	objf["ASSIGN"].reset(new C_ASSIGN(&mdata));
	objf["OUT"].reset(new C_OUT(&mdata));
	objf["SET_STR_CHAR"].reset(new C_SET_STR_CHAR(&mdata));
	objf["GET_STR_CHAR"].reset(new C_GET_STR_CHAR(&mdata));
	objf["LABEL"].reset(new C_LABEL(&mdata));
	objf["SLEEP"].reset(new C_SLEEP(&mdata));
	
	objf["JMP"].reset(new C_JMP(&mdata));
	
	objf["JMPZ"].reset(new C_JMP_Z(&mdata, true));
	objf["JMPGT"].reset(new C_JMP_GTLTE(&mdata, true));
	objf["JMPGTE"].reset(new C_JMP_GTELT(&mdata, true));
	
	objf["JMPNZ"].reset(new C_JMP_Z(&mdata, false));
	objf["JMPLTE"].reset(new C_JMP_GTLTE(&mdata, false));
	objf["JMPLT"].reset(new C_JMP_GTELT(&mdata, false));
	
	objf["VAR"].reset(new C_VAR(&mdata);
	
				////////////////////////////////////
				//--DONE CREATING OBJECT FACTORY--//
				////////////////////////////////////
			
			
			
	// start parsing file here
	
	// store the first token into a string, pass that string
	//	to the object factory and pass the rest of the line to the
	//	object factory element's parse() function.
	
	// store the result from parse() as a pointer in the command vector.
	
	
	
		// our counter for which line we're parsing (used for error reporting)
	unsigned long long linenumber = 0;	// goes up to 18 quintillion lines! lol

		// input file stream
	std::ifstream ifs;
		// string stream for parsing tokens from each line
	std::stringstream ss;
	
		// two strings for parsing tokens and comparing to the map
	std::string sbuf;
	std::string temp;

	

		// open file w/ c-style string filename
	ifs.open (filename, std::ifstream::in);
	
		// while file input stream is okay
	while (ifs.good())
	{
			// clear all our input token buffers
		ss.str("");
		ss.clear();
		sbuf.clear();
		temp.clear();
			
			// get next line and store in a string
		std::getline(ifs, sbuf);
			// store string into a stringstream, then use the
			//	stringstream's overloaded >> to store the first complete
			//	token (ignores whitespaces before first letter) into
			//	another string
		ss << sbuf;
		ss >> temp;
		
		
		++linenumber;				// increment line number
	
			/**************/		
			// debug stuff:
			/**************
					// output the current line being read
				std::cout << sbuf << std::endl;
					// output the current token that has been loaded
				std::cout << "\t -- (newline): " << temp << "\n";
			**************/
		
		
			// start trying to parse the token
		try
		{
				// if the token is not empty (ie: blank lines or all whitespace)
			if (!temp.empty())
			{
					// then search the map for the token
				if (objf.at(temp))
				{
						// if found, get the rest of the line after the token
					std::getline(ss, sbuf);
						// call the parse function from the indexed
						//	command object, which will populate the
						//	command vector with push(). 
						// Certain command objects, like VAR and LABEL
						//	do not populate the command vector, but instead
						//	add values to their respective vectors or maps.
					objf.at(temp)->parse(sbuf);
				}
			}
		}	// if no token match was found in the map, then catch the exception
		catch(std::out_of_range& ex)
		{
				// and output an error with the line number
			throw MIS_Exception("ERROR. '" + std::to_string(temp)
								+ "' unrecognized opcode at line " 
								+ std::to_string(linenumber) + ".\n");
			//std::cout << "\n\t --ERROR. '" << temp << "' unrecognized opcode"
			//			<< "at line " << linenumber << "." << std::endl;
		}
		
		
		if (ifs.fail() || sbuf.size() > 1024)
		{
			throw MIS_Exception("ERROR, line #" + std::to_string(linenumber) 
								+ "is over 1024 characters long!\n");
			return;
		}
				
	}
	
		// close file
	ifs.close();
	
	return;
}




/***************************
* Function: MIS_System::run()
* 
* Input: N/A
* Output: N/A
*
* Details:
*	- This function iterates through the entire command vector and
*		executes every single command stored inside of it.
*
***************************/

void MIS_System::run()
{
	for (int i = 0; i < mdata.commands.size(); ++i)
	{
		mdata.commands[i]->execute();
	}
}	



