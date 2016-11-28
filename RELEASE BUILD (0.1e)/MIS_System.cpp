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
#include "labelLink.h"
#include "helpers.h"
#include "Command_DLL_Struct.h"


#include "z_dbg.h"		// debug (for dbg::to_string emulation)



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
bool MIS_System::parse(char* filename)
{
	bool success = true;
	
	std::string fileN(filename);
	
	int filetype;
	if ((filetype = fileN.rfind(".mis")) != std::string::npos)
	{
		fileN.erase(filetype, 4);
	}
	else
		throw MIS_Exception("Invalid filetype, please use *.mis files.\n");
	
		
		
		
	
	mdata->thread_id_stack.push(0);
	mdata->lock_count = mdata->unlock_count = 0;
	mdata->unique_thread_id = 0;
	
	
	
	
	try
	{	
	/////////////////////// TRY ////////////////////////////////
	
	
	std::map<std::string, std::shared_ptr<Command>> objf;
	
			//////////////////////////////////////////////////
			//--CREATE OBJECT FACTORY FOR THIS MIS_SYSTEM:--//
			//////////////////////////////////////////////////
	
		// note: objf["__"] = std::shared_ptr<Command>(new C_XYZ()) works too.
	objf["ADD"].reset(cmd->D_ADD(mdata,0));
	objf["SUB"].reset(cmd->D_SUB(mdata,0));
	objf["MUL"].reset(cmd->D_MUL(mdata,0));
	objf["DIV"].reset(cmd->D_DIV(mdata,0));
	objf["ASSIGN"].reset(cmd->D_ASSIGN(mdata,0));
	objf["OUT"].reset(cmd->D_OUT(mdata,0));
	objf["SET_STR_CHAR"].reset(cmd->D_SET_STR_CHAR(mdata,0));
	objf["GET_STR_CHAR"].reset(cmd->D_GET_STR_CHAR(mdata,0));
	objf["LABEL"].reset(cmd->D_LABEL(mdata,0));
	objf["SLEEP"].reset(cmd->D_SLEEP(mdata,0));
	
	objf["JMP"].reset(cmd->D_JMP(mdata,0));
	
	objf["JMPZ"].reset(cmd->D_JMP_ZNZ(mdata,0, true));
	objf["JMPGT"].reset(cmd->D_JMP_GTLTE(mdata,0, true));
	objf["JMPGTE"].reset(cmd->D_JMP_GTELT(mdata,0, true));
	
	objf["JMPNZ"].reset(cmd->D_JMP_ZNZ(mdata,0, false));
	objf["JMPLTE"].reset(cmd->D_JMP_GTLTE(mdata,0, false));
	objf["JMPLT"].reset(cmd->D_JMP_GTELT(mdata,0, false));
	
	objf["VAR"].reset(cmd->D_VAR(mdata,0));
	
	objf["THREAD_BEGIN"].reset(cmd->D_THREAD_BEGIN(mdata,0, this, 0));
	objf["THREAD_END"].reset(cmd->D_THREAD_END(mdata,0));
	objf["LOCK"].reset(cmd->D_LOCK(mdata,0));
	objf["UNLOCK"].reset(cmd->D_UNLOCK(mdata,0));
	objf["BARRIER"].reset(cmd->D_BARRIER(mdata,0));
	
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
	ifs.open (fileN + ".mis", std::ifstream::in);
	
	if (ifs.fail())
		throw MIS_Exception("File could not be opened.\n");
		
	
		// if we opened the file, then create the .err and .out files	
	mdata->o_out.open(fileN+".out", std::ofstream::out);
	mdata->o_err.open(fileN+".err", std::ofstream::out);
	
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
		
		//std::cout << "LINE: " << linenumber << "\n";	//debug
	
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
				//std::cout << "\t\t -- not empty\n";
					// then search the map for the token
				if (objf.at(temp))
				{
					//std::cout << "\t\t -- very not empty\n";
						// if found, get the rest of the line after the token
					std::getline(ss, sbuf);
					
					ss.str("");
					ss.clear();	
					ss << sbuf;
						// call the parse function from the indexed
						//	command object, which will populate the
						//	command vector with push(). 
						// Certain command objects, like VAR and LABEL
						//	do not populate the command vector, but instead
						//	add values to their respective vectors or maps.
					try
					{
							// get Command* to store returned pointer from objf
						Command* cp;						
							// if the object was created and passed back
							//	a non-nullptr, then convert it to shared_ptr
							//	and push it onto the command vector.
							// otherwise it was a LABEL or VAR and should
							//	not be added to the command vector.
						if ((cp = objf.at(temp)->parse(ss)))
						{
							//std::cout << " NO ERROR HERE \n";
							std::shared_ptr<Command> scp(cp);
							mdata->commands.push_back(scp);
						}
					}
					catch (MIS_Exception ex)
					{
						std::cout 	<< "ERROR: " << dbg::to_string(ex.what())
									<< "\t\t - Line #" 
									<< dbg::to_string(linenumber) << ".\n";
						mdata->o_err << "ERROR: " << dbg::to_string(ex.what())
									<< "\t\t - Line #" 
									<< dbg::to_string(linenumber) << ".\n";
						success = false;
						//throw MIS_Exception("ERROR: "+ dbg::to_string(ex.what())
						//					+ "\t\t - Line #" 
						//					+ dbg::to_string(linenumber) 
						//					+ ".\n");
					}
					catch (std::out_of_range& ex)
					{
						std::cout 	<< "ERROR: Unable to match variable name"
									<< " to variable." << "\t\t - Line #" 
									<< dbg::to_string(linenumber) << ".\n";
						mdata->o_err << "ERROR: Unable to match variable name"
									<< " to variable." << "\t\t - Line #" 
									<< dbg::to_string(linenumber) << ".\n";
						success = false;
					}
				}
			}
		}	// if no token match was found in the map, then catch the exception
		catch(std::out_of_range& ex)
		{
				// and output an error with the line number
			std::cout 	<< "ERROR: '" << dbg::to_string(temp)
						<< "' unrecognized opcode at line "
						<< dbg::to_string(linenumber) << ".\n";
			mdata->o_err << "ERROR: '" << dbg::to_string(temp)
						<< "' unrecognized opcode at line "
						<< dbg::to_string(linenumber) << ".\n";
			success = false;
			//throw MIS_Exception("ERROR. '" + dbg::to_string(temp)
			//					+ "' unrecognized opcode at line " 
			//					+ dbg::to_string(linenumber) + ".\n");
			//std::cout << "\n\t --ERROR. '" << temp << "' unrecognized opcode"
			//			<< "at line " << linenumber << "." << std::endl;
		}
		
		
		if (sbuf.size() > 1024)
		{
			std::cout 	<< "ERROR: line #" << dbg::to_string(linenumber) 
						<< " is over 1024 characters long!\n";
			mdata->o_err << "ERROR: line #" << dbg::to_string(linenumber) 
						<< " is over 1024 characters long!\n";
			success = false;
			//throw MIS_Exception("ERROR, line #" + dbg::to_string(linenumber) 
			//					+ " is over 1024 characters long!\n");
			//return false;
		}
				
	}
	
		// close file
	ifs.close();
	
		// parsing is over, change label-parse flag to true
	mdata->l_parse = true;

	
		
		// some debug code
	//std::cout << "\n\tcommands: " << mdata->commands.size();
	//std::cout << "\n\tlabel stack: " << mdata->labelLinkStack.size() << "\n\n";

	
	
		// empty out our stack of unlinked label calls and attempt
		//	to link them.
	while (!(mdata->labelLinkStack.empty()))
	{
			// get the Command* to the object factory element
			//	responsible for creating the JMP command needed,
			//	then get the text to be parsed and an index into
			//	the command vector.
		Command* obj = mdata->labelLinkStack.top()->obj;
		std::string text = mdata->labelLinkStack.top()->text;
		long long index = mdata->labelLinkStack.top()->index;
		
			// temporarily add the relevant thread_id to the stack
		mdata->thread_id_stack.push(obj->thread_id);

		
			// convert the text into a stringstream, to match the
			//	required input parameters to the parsing functions
			//	of the object factory elements
		std::stringstream ss(text);
		
			// create the correct command
		try
		{
			mdata->commands[index].reset(obj->parse(ss));
		}
		catch (MIS_Exception &ex)
		{
			std::cout	<< "ERROR: " << dbg::to_string(ex.what());
			mdata->o_err << "ERROR: " << dbg::to_string(ex.what());
			success = false;
		}
		
			// remove the unlinked-label object from the stack
		mdata->labelLinkStack.pop();
			// remove the temporary thread_id from the stack
		mdata->thread_id_stack.pop();
	}
	
	
	if (mdata->thread_id_stack.size() > 1)
	{
		std::cout << "\n\tPARSER EXCEPTION: Hanging, open thread!" << std::endl;
		mdata->o_err << "\n\tPARSER EXCEPTION: Hanging, open thread!" << std::endl;
		return 0;
	}
	
	
	/////////////////////// CATCH ////////////////////////////////
	}
	catch (const MIS_Exception &ex)
	{
		std::cout << "\n\tPARSER EXCEPTION: " << ex.what() << std::endl;
		mdata->o_err << "\n\tPARSER EXCEPTION: " << ex.what() << std::endl;
		return 0;
	}	// catch all other standard exceptions
	catch (const std::exception &ex)
	{
		std::cout << "\n\tPARSER EXCEPTION: " << ex.what() << std::endl;
		mdata->o_err << "\n\tPARSER EXCEPTION: " << ex.what() << std::endl;
		return 0;
	}	// catch anything else that gets thrown
	catch (...)
	{
		std::cout << "\n\tUNKNOWN EXCEPTION CAUGHT!" << std::endl;
		mdata->o_err << "\n\tUNKNOWN EXCEPTION CAUGHT!" << std::endl;
		return 1;
	}
	
	
	
	
		// check for unbalanced number of locks to unlocks
	
	if (mdata->lock_count < mdata->unlock_count)
	{
		std::cout << "\n\tWARNING: More unlocks (" << mdata->unlock_count
					<< ") than locks (" << mdata->lock_count << ")!"
					<< std::endl;
		mdata->o_err << "\n\tWARNING: More unlocks (" << mdata->unlock_count
					<< ") than locks (" << mdata->lock_count << ")!"
					<< std::endl;
	}
	else if (mdata->lock_count > mdata->unlock_count)
	{
		std::cout << "\n\tWARNING: More locks (" << mdata->lock_count
					<< ") than unlocks (" << mdata->unlock_count << ")!"
					<< std::endl;
		mdata->o_err << "\n\tWARNING: More locks (" << mdata->lock_count
					<< ") than unlocks (" << mdata->unlock_count << ")!"
					<< std::endl;
	}
	

	if (mdata->warnings.size() > 0)
	{
		std::cout << "\n-----\n " << mdata->warnings.size()
					<< " warnings!\n" << std::endl;
		
			// print out each warning in the warning vector
		for (auto it:(mdata->warnings))
		{
			std::cout << "\t - " << it << std::endl;
		}
	}
	
	
	return success;
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

void MIS_System::run(unsigned int id, std::thread **cthread, 
						unsigned long long nPC)
{
	
	std::thread* cthreadpt;
	
		// if we have a real pointer to a thread pointer, then dereference it
		//	and store it in cthreadpt, otherwise set it to null
	if (cthread)
	{
		cthreadpt = *cthread;
	}
	else
		cthreadpt = 0;
		
	//std::cout << " \t\tTHREAD POINTER: " << cthreadpt << std::endl;
	
	try
	{
			// set PC to 0 in preparation for execution phase.
		Unique_PC pc(nPC, cthreadpt);
		
		if (!cthread)
		{
			//std::cout << "\t-Starting cleaner thread-" << std::endl;
			mdata->clean = new std::thread(&Thread_Cleaner::start, 
										&(mdata->t_clean));
		}
		
		//std::cout << "\t-Cleaner thread succesfully started-" << std::endl;
		//std::cout << "\n\t-# of Commands: " << mdata->commands.size() << "-" << std::endl;
			// loop through entire command vector using PC as index and
			//	call execute from each element
		for (; pc.getPC() < mdata->commands.size(); pc.setPC(pc.getPC()+1))
		{
			//std::cout << "\t  Considering Command Line: " << pc.getPC() << "\n";
			if (mdata->commands[pc.getPC()]->get_thread() == id)
			{
				//std::cout << "\t\t-Matching IDs: " << id << "-" << std::endl;
				//std::cout << "\t\tRunning Command Line: " << pc.getPC() << "\n";
				mdata->commands[pc.getPC()]->execute(cthreadpt, &pc);
			}
		}
		
		if (!cthread)
		{
// 			std::cout << "\n\t\tFINISHING EXECUTE - Terminate Cleaner" << std::endl;
			mdata->t_clean.finished();
			mdata->clean->join();
			delete mdata->clean;
		}
	}
	catch (const MIS_Exception &ex)
	{
		std::cout << "\n\tRUNTIME EXCEPTION: " << ex.what() << std::endl;
		mdata->o_err << "\n\tRUNTIME EXCEPTION: " << ex.what() << std::endl;
		if (!cthread)
		{
			mdata->t_clean.finished();
			mdata->clean->join();
			delete mdata->clean;
		}
		return;
	}	// catch all other standard exceptions
	catch (const std::exception &ex)
	{
		std::cout << "\n\tRUNTIME EXCEPTION: " << ex.what() << std::endl;
		mdata->o_err << "\n\tRUNTIME EXCEPTION: " << ex.what() << std::endl;
		if (!cthread)
		{
			mdata->t_clean.finished();
			mdata->clean->join();
			delete mdata->clean;
		}
		return;
	}	// catch anything else that gets thrown
	catch (...)
	{
		std::cout << "\n\tUNKNOWN EXCEPTION CAUGHT!" << std::endl;
		mdata->o_err << "\n\tUNKNOWN EXCEPTION CAUGHT!" << std::endl;
		if (!cthread)
		{
			mdata->t_clean.finished();
			mdata->clean->join();
			delete mdata->clean;
		}
		return;
	}
	
	
	if (cthread)
		delete cthread;	
		
	
}	



/***************************************/



void MIS_System::init(Command_DLL* _cmd)
{
	cmd = _cmd;
	mdata = new MIS_System_Data();
	
}

void MIS_System::quit()
{
	mdata->o_out.close();
	mdata->o_err.close();
	delete mdata;	
}








