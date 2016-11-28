/******************
* FILE: MIS.cpp
* Author: Arthur Kung
* Date: Nov 8, 2016
*
* Details:
*	- Client/Server interface for the MIS system,
*		calls parse() and run().
*
*	- Catches exceptions and outputs meaningful
*		user errors.
*
*	- Provides its interface as a dynamically-linked
*		library.
******************/

#include <iostream>
#include <fstream>
#include <string>
#include <dlfcn.h>		// dynamic shared library functions

#include "MIS_System.h"
#include "MIS_System_Data.h"
#include "MIS_Exception.h"
#include "Command_DLL_Struct.h"


// int main(int argc, char* argv[])
// {
// 	
// 	if (argc == 2)
// 	{
// 		
extern "C"
bool MIS(std::string s, bool run)
{
	bool linked = false;
	Command_DLL cmd;
		
	
		// RTLD_LAZY = bind functions on call, not on open
	void * dll=dlopen ("./command.so",RTLD_LAZY);
	
		// if the DLL opened successfully, then...
	if (dll)
	{
// 			std::cout << "- SUCCESS: 'command.so' "
// 						<< "dynamic library successfully loaded!\n\n"
// 						<< std::endl;
			//	load external functions and set them to pointers in the
			//	Command_DLL struct
			
			// this is a single, very long set of nested IF statements.
			//	It's done this way so I only have to check the a single
			//	boolean to see if everything loaded properly.	
		if (cmd.D_ADD = (CREATE_ADD*)dlsym(dll,"CREATE_C_ADD"))
		if (cmd.D_SUB = (CREATE_SUB*)dlsym(dll,"CREATE_C_SUB"))
		if (cmd.D_MUL = (CREATE_MUL*)dlsym(dll,"CREATE_C_MUL"))
		if (cmd.D_DIV = (CREATE_DIV*)dlsym(dll,"CREATE_C_DIV"))
		if (cmd.D_ASSIGN = (CREATE_ASSIGN*)dlsym(dll,"CREATE_C_ASSIGN"))
		if (cmd.D_OUT = (CREATE_OUT*)dlsym(dll,"CREATE_C_OUT"))
		if (cmd.D_SET_STR_CHAR = (CREATE_SET_STR_CHAR*)dlsym(dll,"CREATE_C_SET_STR_CHAR"))
		if (cmd.D_GET_STR_CHAR = (CREATE_GET_STR_CHAR*)dlsym(dll,"CREATE_C_GET_STR_CHAR"))
		if (cmd.D_LABEL = (CREATE_LABEL*)dlsym(dll,"CREATE_C_LABEL"))
		if (cmd.D_SLEEP = (CREATE_SLEEP*)dlsym(dll,"CREATE_C_SLEEP"))
		if (cmd.D_JMP = (CREATE_JMP*)dlsym(dll,"CREATE_C_JMP"))
		if (cmd.D_JMP_ZNZ = (CREATE_JMP_ZNZ*)dlsym(dll,"CREATE_C_JMP_ZNZ"))
		if (cmd.D_JMP_GTLTE = (CREATE_JMP_GTLTE*)dlsym(dll,"CREATE_C_JMP_GTLTE"))
		if (cmd.D_JMP_GTELT = (CREATE_JMP_GTELT*)dlsym(dll,"CREATE_C_JMP_GTELT"))
		if (cmd.D_VAR = (CREATE_VAR*)dlsym(dll,"CREATE_C_VAR"))
		if (cmd.D_THREAD_BEGIN = (CREATE_THREAD_BEGIN*)dlsym(dll,"CREATE_C_THREAD_BEGIN"))
		if (cmd.D_THREAD_END = (CREATE_THREAD_END*)dlsym(dll,"CREATE_C_THREAD_END"))
		if (cmd.D_LOCK = (CREATE_LOCK*)dlsym(dll,"CREATE_C_LOCK"))
		if (cmd.D_UNLOCK = (CREATE_UNLOCK*)dlsym(dll,"CREATE_C_UNLOCK"))
		if (cmd.D_BARRIER = (CREATE_BARRIER*)dlsym(dll,"CREATE_C_BARRIER"))
			linked = true;
		
		
			// if we failed to load the DLL somewhere, then output
			//	an error and stop
		if (!(linked))
		{
			std::cout << "\n\tCould not load external function: " 
						<< dlerror() << std::endl;
			return 0;
		}
	}
	else 
	{
		std::cout << "Failure to load dynamic library: "
					<< dlerror() << std::endl; 
		return 0;
	}
	
	
	
	//////////////////////////////////////////////
	//////////////////////////////////////////////
	
	
	MIS_System mis;
	
	mis.init(&cmd);	// initialize and allocate memory for the MIS System
	
	bool success = false;
	
		// run parse sequence
	try
	{	
		success = mis.parse((char*)s.c_str());
	}	// catch all our MIS_Exceptions
	catch (const MIS_Exception &ex)
	{
		std::cout << "\n\tMIS_EXCEPTION CAUGHT: " << ex.what() << std::endl;
		return false;
	}	// catch all other standard exceptions
	catch (const std::exception &ex)
	{
		std::cout << "\n\tEXCEPTION CAUGHT: " << ex.what() << std::endl;
		return false;
	}	// catch anything else that gets thrown
	catch (...)
	{
		std::cout << "\n\tUNKNOWN EXCEPTION CAUGHT!" << std::endl;
		return false;
	}
	
	//std::cout << "\t-Parsing Completed-" << std::endl;
	
		// run execution sequence
	if (success && run)
	{
		try
		{
			mis.run(0,0,0);
		}	// catch all our MIS_Exceptions
		catch (const MIS_Exception &ex)
		{
			std::cout << "\n\tMIS_EXCEPTION CAUGHT: " << ex.what() 
						<< std::endl;
			return false;
		}	// catch all other standard exceptions
		catch (const std::exception &ex)
		{
			std::cout << "\n\tEXCEPTION CAUGHT: " << ex.what() << std::endl;
			return false;
		}	// catch anything else that gets thrown
		catch (...)
		{
			std::cout << "\n\tUNKNOWN EXCEPTION CAUGHT!" << std::endl;
			return false;
		}
	}
	
	mis.quit();		// cleanup memory allocated for the MIS System
	dlclose(dll);	// close the dll


	return success;

}


