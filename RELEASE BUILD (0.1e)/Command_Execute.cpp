/**********************************
*
* Author(s): Arthur (ADD, Threading/Locking), Andrew (Everything else)
*
**********************************/


#include <vector>
#include <string>
#include <sstream>
#include <memory>
#include <iostream>
#include <stdio.h>
#include <chrono>
#include <thread>


#include "Command.h"
#include "MIS_System_Data.h"
#include "OP_Param_Base.h"
#include "MIS_Exception.h"
#include "z_dbg.h"
#include "MIS_System.h"	// for C_THREAD_BEGIN, should be included from Command.h
#include "Threads.h"


	// add takes 3-13 parameters, with the first parameter being a variable
	//		and the remaining parameters being either variables or
	//		immediate values. We don't care WHAT those values are.


void C_ADD::execute(std::thread *ct, Unique_PC* pc)
{
		// check storage variable getType(). If it's a NUMERIC type....
	if (oplist[0]->getType() == PARAM_TYPE::VAR_NUM)
	{
			// create temporary variable for storage
		long long temp = 0;
			// loop through every parameter and add them based on
			//	their declared getType()s (casting their returned void*
			//	to their respective getType()s)
		for (int i = 1; i < oplist.size(); ++i)
		{
			switch(oplist[i]->getType())
			{
				case PARAM_TYPE::NUMERIC:
				case PARAM_TYPE::VAR_NUM:
					temp += *static_cast<long long*>(oplist[i]->getValue());
					break;

				case PARAM_TYPE::REAL:
				case PARAM_TYPE::VAR_REA:
					temp += *static_cast<double*>(oplist[i]->getValue());
					break;				
				
				
					// if there are no matches, throw an exception
				default: throw MIS_Exception("ERROR: Invalid parameter getType()!"
										" (ADD parameter" 
										+ dbg::to_string(i+1) + ")\n");
			}
		}
			// store the final value into the given variable
		oplist[0]->setValue(static_cast<void*>(&temp));		
	}
		// otherwise, if it's a REAL getType()... (see above for comments)
	else if (oplist[0]->getType() == PARAM_TYPE::VAR_REA)
	{
		double temp = 0;
		for (int i = 1; i < oplist.size(); ++i) {
			switch(oplist[i]->getType())
			{
				case PARAM_TYPE::NUMERIC:
				case PARAM_TYPE::VAR_NUM:
					temp += *static_cast<long long*>(oplist[i]->getValue());
					break;

				case PARAM_TYPE::REAL:
				case PARAM_TYPE::VAR_REA:
					temp += *static_cast<double*>(oplist[i]->getValue());
					break;				
				
				//case PARAM_TYPE::CHAR:
				//case PARAM_TYPE::VAR_CHA:
				//	temp += *static_cast<char*>(oplist[i]->getValue());
				//	break;
				
				//case PARAM_TYPE::STRING:
				//case PARAM_TYPE::VAR_STR:
				//	temp += *static_cast<string*>(oplist[i]->getValue());
				//	break;
				
				default: throw MIS_Exception("ERROR: Invalid parameter getType()!"
										" (ADD parameter" 
										+ dbg::to_string(1) + ")\n");
			}
		oplist[0]->setValue(static_cast<void*>(&temp)); }
			
	}
		// otherwise, if it's neither a REAL or NUMERIC variable, it's an error

	else
		throw MIS_Exception("ERROR: Invalid storage getType()! (ADD)\n");
		
	
	return;	
}









////////////// I think separating every command class into its own

	////////////// cpp file may be useful here. It's debatable, since it will////////////// also make finding all the relevant command classes to adjust
////////////// code more irritating.




void C_SUB::execute(std::thread *ct, Unique_PC* pc)
{
	
 	long long temp;
	double tempd;
	long long var1;
	double var1d;
		// check storage variable getType(). If it's a NUMERIC type....
	if (oplist[0]->getType() == PARAM_TYPE::VAR_NUM) {
		
			switch(oplist[1]->getType())
			{
				case PARAM_TYPE::NUMERIC:
				case PARAM_TYPE::VAR_NUM:
					var1 = *static_cast<long long*>(oplist[1]->getValue());
					
									
					switch(oplist[2]->getType())
					{
						case PARAM_TYPE::NUMERIC:
						case PARAM_TYPE::VAR_NUM:
						{
							long long var2 = *static_cast<long long*>(oplist[2]->getValue());
							temp = var1 - var2;
							break;
						}

						case PARAM_TYPE::REAL:
						case PARAM_TYPE::VAR_REA:
						{
							double var2 = *static_cast<double*>(oplist[2]->getValue());
							temp = var1 - var2;
							break;
						}

						default: throw MIS_Exception("ERROR: Invalid parameter getType()!"
												" (SUB parameter" 
												+ dbg::to_string(2) + ")\n");
					}
					break;
					     

				case PARAM_TYPE::REAL:
				case PARAM_TYPE::VAR_REA:
					{var1d = *static_cast<double*>(oplist[1]->getValue());
					
									
					switch(oplist[2]->getType()){
						case PARAM_TYPE::NUMERIC:
						case PARAM_TYPE::VAR_NUM:
							{long long var2 = *static_cast<long long*>(oplist[2]->getValue());
							temp = var1d - var2;
							break;}

						case PARAM_TYPE::REAL:
						case PARAM_TYPE::VAR_REA:
							{double var2 = *static_cast<double*>(oplist[2]->getValue());
							temp = var1d - var2;
							break;}

						default: {throw MIS_Exception("ERROR: Invalid parameter getType()!"
												" (SUB parameter" 
												+ dbg::to_string(2) + ")\n");}}
					break;}
								
				default: {throw MIS_Exception("ERROR: Invalid parameter getType()!"
										" (SUB parameter" 
										+ dbg::to_string(1) + ")\n");}
			
				
		}
			// store the final value into the given variable
		oplist[0]->setValue(static_cast<void*>(&temp));		
	}
		// otherwise, if it's a REAL getType()... (see above for comments)
	else if (oplist[0]->getType() == PARAM_TYPE::VAR_REA)
	{
		
			switch(oplist[1]->getType())
			{
				case PARAM_TYPE::NUMERIC:
				case PARAM_TYPE::VAR_NUM:
					{ var1 = *static_cast<long long*>(oplist[1]->getValue());
					
									
					switch(oplist[2]->getType())
					{
						case PARAM_TYPE::NUMERIC:
						case PARAM_TYPE::VAR_NUM:
							{long long var2 = *static_cast<long long*>(oplist[2]->getValue());
							tempd = var1 - var2;
							break;}

						case PARAM_TYPE::REAL:
						case PARAM_TYPE::VAR_REA:
							{double var2 = *static_cast<double*>(oplist[2]->getValue());
							tempd = var1 - var2;
							break;}

						default: {throw MIS_Exception("ERROR: Invalid parameter getType()!"
												" (SUB parameter" 
												+ dbg::to_string(2) + ")\n");}}
					break;
				}
					
					     
				case PARAM_TYPE::REAL:
				case PARAM_TYPE::VAR_REA:
					{ var1d = *static_cast<double*>(oplist[1]->getValue());
					
									
					switch(oplist[2]->getType()){
						case PARAM_TYPE::NUMERIC:
						case PARAM_TYPE::VAR_NUM:
							{long long var2 = *static_cast<long long*>(oplist[2]->getValue());
							tempd = var1d - var2;
							break;}

						case PARAM_TYPE::REAL:
						case PARAM_TYPE::VAR_REA:
							{double var2 = *static_cast<double*>(oplist[2]->getValue());
							tempd = var1d - var2;
							break;}

						default: {throw MIS_Exception("ERROR: Invalid parameter getType()!"
												" (SUB parameter" 
												+ dbg::to_string(2) + ")\n");}}
					break;
								
				default: throw MIS_Exception("ERROR: Invalid parameter getType()!"
										" (SUB parameter" 
										+ dbg::to_string(1) + ")\n");}		
		}
		
			// store the final value into the given variable
		oplist[0]->setValue(static_cast<void*>(&tempd));		
			// otherwise, if it's neither a REAL or NUMERIC variable, it's an error

	} else { throw MIS_Exception("ERROR: Invalid storage getType()! (ADD)\n"); }
		
	
	
	//}	
	return;
}

void C_DIV::execute(std::thread *ct, Unique_PC* pc)
{
 	long long temp;
	double tempd;
	long long var1;
	double var1d;
	
	if (oplist[0]->getType() == PARAM_TYPE::VAR_NUM) {
		
		
			switch(oplist[1]->getType())
			{
				case PARAM_TYPE::NUMERIC:
				case PARAM_TYPE::VAR_NUM:
					{var1 = *static_cast<long long*>(oplist[1]->getValue());
					
									
					switch(oplist[2]->getType())
					{
						case PARAM_TYPE::NUMERIC:
						case PARAM_TYPE::VAR_NUM:
							{long long var2 = *static_cast<long long*>(oplist[2]->getValue());
							 if(var2 == 0) { throw MIS_Exception("ERROR: divide by zero! (DIV)\n"); }
							 else {temp = var1 / var2;}
							break;}

						case PARAM_TYPE::REAL:
						case PARAM_TYPE::VAR_REA:
					 		{double var2 = *static_cast<double*>(oplist[2]->getValue());
							 if(var2 == 0) { throw MIS_Exception("ERROR: divide by zero! (DIV)\n"); }
							 else {temp = var1 / var2;}
							break;}


						default: {throw MIS_Exception("ERROR: Invalid parameter getType()!"
												" (SUB parameter" 
												+ dbg::to_string(2) + ")\n");}} 
					
					break;							
					}

				case PARAM_TYPE::REAL:
				case PARAM_TYPE::VAR_REA:
					{var1d = *static_cast<double*>(oplist[1]->getValue());
					
									
					switch(oplist[2]->getType()){
						case PARAM_TYPE::NUMERIC:
						case PARAM_TYPE::VAR_NUM:
							{long long var2 = *static_cast<long long*>(oplist[2]->getValue());
							 if(var2 == 0) { throw MIS_Exception("ERROR: divide by zero! (DIV)\n"); }
							 else {temp = var1d / var2;}
							break;}

						case PARAM_TYPE::REAL:
						case PARAM_TYPE::VAR_REA:
					 		{double var2 = *static_cast<double*>(oplist[2]->getValue());
							 if(var2 == 0) { throw MIS_Exception("ERROR: divide by zero! (DIV)\n"); }
							 else {temp = var1d / var2;
							 }
							break;}

						default: {throw MIS_Exception("ERROR: Invalid parameter getType()!"
												" (DIV parameter" 
												+ dbg::to_string(2) + ")\n");}}
					break;}
								
				default: throw MIS_Exception("ERROR: Invalid parameter getType()!"
										" (DIV parameter" 
										+ dbg::to_string(1) + ")\n");
					}
			// store the final value into the given variable
		oplist[0]->setValue(static_cast<void*>(&temp));		
	}
		// otherwise, if it's a REAL getType()... (see above for comments)
	else if (oplist[0]->getType() == PARAM_TYPE::VAR_REA)
	{
		
		
			switch(oplist[1]->getType())
			{
				case PARAM_TYPE::NUMERIC:
				case PARAM_TYPE::VAR_NUM:
					{var1 = *static_cast<long long*>(oplist[1]->getValue());
					
									
					switch(oplist[2]->getType())
					{
						case PARAM_TYPE::NUMERIC:
						case PARAM_TYPE::VAR_NUM:
							{long long var2 = *static_cast<long long*>(oplist[2]->getValue());
							 if(var2 == 0) { throw MIS_Exception("ERROR: divide by zero! (DIV)\n"); }
							 else {tempd = var1; tempd = tempd / var2;}
							break;}

						case PARAM_TYPE::REAL:
						case PARAM_TYPE::VAR_REA:
					 		{double var2 = *static_cast<double*>(oplist[2]->getValue());
							 if(var2 == 0) { throw MIS_Exception("ERROR: divide by zero! (DIV)\n"); }
							 else { tempd = var1; tempd = tempd / var2; }
							break;}

						default: {throw MIS_Exception("ERROR: Invalid parameter getType()!"
												" (SUB parameter" 
												+ dbg::to_string(2) + ")\n");}}
												
				break;								
				}
				case PARAM_TYPE::REAL:
				case PARAM_TYPE::VAR_REA:
					{var1d = *static_cast<double*>(oplist[1]->getValue());
					
									
					switch(oplist[2]->getType()){
						case PARAM_TYPE::NUMERIC:
						case PARAM_TYPE::VAR_NUM:
							{long long var2 = *static_cast<long long*>(oplist[2]->getValue());
							 if(var2 == 0) { throw MIS_Exception("ERROR: divide by zero! (DIV)\n"); }
							 else {tempd = var1d / var2;}
							break;}
						case PARAM_TYPE::REAL:
						case PARAM_TYPE::VAR_REA:
					 		{double var2 = *static_cast<double*>(oplist[2]->getValue());
							 if(var2 == 0) { throw MIS_Exception("ERROR: divide by zero! (DIV)\n"); }
							 else {tempd = var1d / var2;}
							break;}

						default: {throw MIS_Exception("ERROR: Invalid parameter getType()!"
												" (SUB parameter" 
												+ dbg::to_string(2) + ")\n");}}
					break;}
								
				default: throw MIS_Exception("ERROR: Invalid parameter getType()!"
										" (SUB parameter" 
										+ dbg::to_string(1) + ")\n");
		
		}
		
			// store the final value into the given variable
		oplist[0]->setValue(static_cast<void*>(&tempd));		
		
	} 	else { throw MIS_Exception("ERROR: Invalid storage getType()! (ADD)\n"); }
		
	
	//}	
	return;
}

void C_MUL::execute(std::thread *ct, Unique_PC* pc) {
	
	if (oplist[0]->getType() == PARAM_TYPE::VAR_NUM)
	{
			// create temporary variable for storage
		long long temp = 1;
			// loop through every parameter and add them based on
			//	their declared getType()s (casting their returned void*
			//	to their respective getType()s)
		for (int i = 1; i < oplist.size(); ++i)
		{
			switch(oplist[i]->getType())
			{
				case PARAM_TYPE::NUMERIC:
				case PARAM_TYPE::VAR_NUM:
					temp *= *static_cast<long long*>(oplist[i]->getValue());
					break;

				case PARAM_TYPE::REAL:
				case PARAM_TYPE::VAR_REA:
					temp *= *static_cast<double*>(oplist[i]->getValue());
					break;				
				
					// the below 4 cases are ignored because they are invalid
					//	parameter getType()s for ADD. += doesn't make sense
					//	for character at all, and is not implemented for
					//	strings in our virtual machine.
					
				//case PARAM_TYPE::CHAR:
				//case PARAM_TYPE::VAR_CHA:
				//	temp += *static_cast<char*>(oplist[i]->getValue());
				//	break;
				
				//case PARAM_TYPE::STRING:
				//case PARAM_TYPE::VAR_STR:
				//	temp += *static_cast<string*>(oplist[i]->getValue());
				//	break;
				
					// if there are no matches, throw an exception
				default: throw MIS_Exception("ERROR: Invalid parameter getType()!"
										" (ADD parameter" 
										+ dbg::to_string(i+1) + ")\n");
			}
		}
			// store the final value into the given variable
		oplist[0]->setValue(static_cast<void*>(&temp));		
	}
		// otherwise, if it's a REAL getType()... (see above for comments)
	else if (oplist[0]->getType() == PARAM_TYPE::VAR_REA)
	{
		double temp = 1;
			for (int i = 1; i < oplist.size(); ++i){
			switch(oplist[i]->getType())
			{
				case PARAM_TYPE::NUMERIC:
				case PARAM_TYPE::VAR_NUM:
					temp *= *static_cast<long long*>(oplist[i]->getValue());
					break;

				case PARAM_TYPE::REAL:
				case PARAM_TYPE::VAR_REA:
					temp *= *static_cast<double*>(oplist[i]->getValue());
					break;				
				
				//case PARAM_TYPE::CHAR:
				//case PARAM_TYPE::VAR_CHA:
				//	temp += *static_cast<char*>(oplist[i]->getValue());
				//	break;
				
				//case PARAM_TYPE::STRING:
				//case PARAM_TYPE::VAR_STR:
				//	temp += *static_cast<string*>(oplist[i]->getValue());
				//	break;
				
				default: throw MIS_Exception("ERROR: Invalid parameter getType()!"
										" (ADD parameter" 
										+ dbg::to_string(i+1) + ")\n");
			}
		}
		oplist[0]->setValue(static_cast<void*>(&temp));
	}
		// otherwise, if it's neither a REAL or NUMERIC variable, it's an error

	else
		throw MIS_Exception("ERROR: Invalid storage getType()! (ADD)\n");
		
	
	return;	
}


void C_ASSIGN::execute(std::thread *ct, Unique_PC* pc)
{
	
	if((oplist[0]->getType() == PARAM_TYPE::VAR_NUM) && ((oplist[1]->getType() == PARAM_TYPE::VAR_NUM) || (oplist[1]->getType()== PARAM_TYPE::NUMERIC))) {
		long long var = *static_cast<long long*>(oplist[1]->getValue());
		oplist[0]->setValue(static_cast<void*>(&var)); }
				   
	else if((oplist[0]->getType() == PARAM_TYPE::VAR_REA) && ((oplist[1]->getType() == PARAM_TYPE::VAR_REA) || (oplist[1]->getType() == PARAM_TYPE::REAL))) {
		double var = *static_cast<double*>(oplist[1]->getValue());
		oplist[0]->setValue(static_cast<void*>(&var)); }
				   
	else if((oplist[0]->getType() == PARAM_TYPE::VAR_CHA) && ((oplist[1]->getType() == PARAM_TYPE::VAR_CHA) || (oplist[1]->getType() == PARAM_TYPE::CHAR))) {
		char var = *static_cast<char*>(oplist[1]->getValue());
		oplist[0]->setValue(static_cast<void*>(&var)); }	
				   
	else if((oplist[0]->getType() == PARAM_TYPE::VAR_STR) && ((oplist[1]->getType() == PARAM_TYPE::VAR_STR) || (oplist[1]->getType() == PARAM_TYPE::STRING))) {
		//string var = *static_cast<string*>(oplist[0]->getValue());
		std::string constant = *static_cast<std::string*>(oplist[1]->getValue());
		long long size = oplist[0]->getSize();
		
		if( constant.size() > size ) {
			throw MIS_Exception("ERROR: Invalid size! (ASSIGN)\n");	}
		
		oplist[0]->setValue(static_cast<void*>(&constant)); }
					
	else { throw MIS_Exception("ERROR: Invalid storage getType()! (ASSIGN)\n"); }
				   
	return;			   
				   
				   
}

void C_OUT::execute(std::thread *ct, Unique_PC* pc) {
		// start at begininng of oplist to print out every value 
		for (int i = 0; i < oplist.size(); ++i)
	{
		switch(oplist[i]->getType())
			{
				case PARAM_TYPE::NUMERIC:
				case PARAM_TYPE::VAR_NUM:
				{long long val = *static_cast<long long*>(oplist[i]->getValue());
					std::cout << val;
				 	mdata->o_out << val;
					break;}

				case PARAM_TYPE::REAL:
				case PARAM_TYPE::VAR_REA:
				{double val = *static_cast<double*>(oplist[i]->getValue());
					std::cout << val;
				 	mdata->o_out << val;
					break;}	
				
				case PARAM_TYPE::CHAR:
				case PARAM_TYPE::VAR_CHA:
				{char val = *static_cast<char*>(oplist[i]->getValue());
					std::cout << val;
				 	mdata->o_out << val;
					break;}
				
				case PARAM_TYPE::STRING:
				case PARAM_TYPE::VAR_STR:
				{std::string val = *static_cast<std::string*>(oplist[i]->getValue());
					std::cout << val;
				 	mdata->o_out << val;
					break;}
		}
	}
	return;
}

void C_SET_STR_CHAR::execute(std::thread *ct, Unique_PC* pc) {
	
	long long index = *static_cast<long long*>(oplist[1]->getValue());
	std::string* s = static_cast<std::string*>(oplist[0]->getValue());
	char c = *static_cast<char*>(oplist[2]->getValue());
	
	s->at(index) = c;
	
	return;
}

void C_GET_STR_CHAR::execute(std::thread *ct, Unique_PC* pc) {
	
	long long index = *static_cast<long long*>(oplist[1]->getValue());
	std::string s = *static_cast<std::string*>(oplist[0]->getValue());
	//char *c = static_cast<char*>(oplist[2]->getValue());
	
	char c = s.at(index);
	oplist[2]->setValue(static_cast<void*>(&c));
	
	return;	
}
				   
void C_JMP::execute(std::thread *ct, Unique_PC* pc) {
	
	long long label = *static_cast<long long*>(oplist[0]->getValue());
	pc->setPC(label);
	return;
	
}
				   
void C_JMP_ZNZ::execute(std::thread *ct, Unique_PC* pc) {
	
	long long label = *static_cast<long long*>(oplist[0]->getValue());
	long long var = *static_cast<long long*>(oplist[1]->getValue());
	bool zero;
	
	if( var == 0 ) {
		zero = true; }
	else zero = false;
	
	
	if ((side) && (zero)) {
		pc->setPC(label); }
	
	else if (!(side) && !(zero)) {
		pc->setPC(label); }
	return;
	
	
}
				   
void C_JMP_GTLTE::execute(std::thread *ct, Unique_PC* pc) {
	
	long long label = *static_cast<long long*>(oplist[0]->getValue());
	long long var1 = *static_cast<long long*>(oplist[1]->getValue());
	long long var2 = *static_cast<long long*>(oplist[2]->getValue());
	
	if( (var1 > var2) && (side) ) {
		pc->setPC(label); }
	
	else if( !(var1 > var2) && !(side) ) {
		pc->setPC(label); }
	return;
	
}
				   
				   
void C_JMP_GTELT::execute(std::thread *ct, Unique_PC* pc) {
	
	long long label = *static_cast<long long*>(oplist[0]->getValue());
	long long var1 = *static_cast<long long*>(oplist[1]->getValue());
	long long var2 = *static_cast<long long*>(oplist[2]->getValue());
	
	if( (var1 >= var2) && (side) ) {
		pc->setPC(label); }
	
	else if( !(var1 >= var2) && !(side) ) {
		pc->setPC(label); }	
	return;
	
	
}	
				   
void C_SLEEP::execute(std::thread *ct, Unique_PC* pc) {
	
	long long var = *static_cast<long long*>(oplist[0]->getValue());
    	std::this_thread::sleep_for(std::chrono::seconds(var));
	return;
	 
}

void C_LABEL::execute(std::thread *ct, Unique_PC* pc) {
	
	throw MIS_Exception("ERROR: Attempting to execute label (non- executable)! (LABEL)\n");
	
}
				   
				   
void C_VAR::execute(std::thread *ct, Unique_PC* pc) {
	
	throw MIS_Exception("ERROR: Attempting to execute VAR (non-executable)! (VAR)\n");				   
	
}





/*****************************************/
/*
/*
/*	PHASE TWO COMMANDS (Arthur Kung)
/*
/*
/*****************************************/


/***************************
* Function: C_THREAD_BEGIN::execute()
* 
* Input: std::thread*, Unique_PC*
* Output: N/A
*
* Details:
*	- creates a new thread and passes it a pointer to itself. Also
*		increments the cleaner thread's counter of currently running
*		threads.
*
***************************/
void C_THREAD_BEGIN::execute(std::thread *ct, Unique_PC* pc) 
{
	//std::cout << "\n\t\tnew thread, id: " << thread_exec << "\n";
	
	mdata->t_clean.addThread();
	if (thread_id == THREAD_MAXIMUM)
		throw MIS_Exception("ERROR: Too many unique threads!\n");
	
	unsigned long long nPC = pc->getPC() + 1;
	
		// NOTE: to facilitate providing the new thread with a pointer
		//			to itself, we create a thread pointer-pointer, which
		//			points to a dynamically allocated pointer to a thread.
		//			We then create the thread under that new dynamically
		//			allocated pointer and pass the pointer-to-the-dynamically-
		//			allocated-pointer to the new thread by value.
		//		 This allows us to let the pointer-pointer die by going
		//			out of scope, while keeping the actual thread pointer
		//			available for the new thread to reference. The new thread
		//			is therefore in charge of figuring out if the pointer
		//			is or is not valid and if it needs to be deleted (and if
		//			so, actually deleting it).
		//		 Without this, we'd either need to do some finicky shared_ptr
		//			approach or rework the way the system is created entirely,
		//			because otherwise the pointer would go out of scope too
		//			quickly and cause a segfault when the new thread tried
		//			to access it.
	std::thread** ntpt = new (std::thread*);
	*ntpt = new std::thread(&MIS_System::run, ms, thread_exec, ntpt, nPC);
	
	//std::cout << "\t-RUNNING THREAD_BEGIN | " << nt << std::endl;
}


/***************************
* Function: C_THREAD_END::execute()
* 
* Input: std::thread*, Unique_PC*
* Output: N/A
*
* Details:
*	- adds the calling thread to the cleaner's queue of threads to
*		destroy.
*
***************************/
void C_THREAD_END::execute(std::thread *ct, Unique_PC* pc) 
{
	// call reaper on thread
	mdata->t_clean.markDone(pc->get_thread(), thread_id);
}


/***************************
* Function: C_LOCK::execute()
* 
* Input: std::thread*, Unique_PC*
* Output: N/A
*
* Details:
*	- calls a Variable's lock() method, which in turn calls a
*		V_Param's lock().
*
***************************/
void C_LOCK::execute(std::thread *ct, Unique_PC* pc) 
{				   
	oplist[0]->lock(pc->get_thread());
	return;
}


/***************************
* Function: C_UNLOCK::execute()
* 
* Input: std::thread*, Unique_PC*
* Output: N/A
*
* Details:
*	- calls a Variable's unlock() method, which in turn calls a
*		V_Param's unlock().
*
***************************/
void C_UNLOCK::execute(std::thread *ct, Unique_PC* pc) 
{				   
	oplist[0]->unlock(pc->get_thread());
	return;
}


/***************************
* Function: C_BARRIER::execute()
* 
* Input: std::thread*, Unique_PC*
* Output: N/A
*
* Details:
*	- waits until all currently running threads are finished, and
*		then returns. This is achieved by telling the cleaner thread
*		to self-destruct, and then calling join() on the cleaner thread.
*
*		Since join() will only occur when the thread has ended, this
*		function will naturally wait until the cleaner thread has
*		destroyed all other running threads.
*
*		This function then deletes the completed cleaner thread and 
*		starts a new one before returning.
*
*		This function can ONLY be called from the MAIN THREAD.
*
***************************/
void C_BARRIER::execute(std::thread *ct, Unique_PC* pc) 
{		
	//std::cout << "\n\t\t\entering barrier\n";		   
	
	if (thread_id == 0)
	{
		//mdata->t_clean.barrier();
		
		mdata->t_clean.finished();
		mdata->clean->join();
		delete mdata->clean;
		
		mdata->clean = new std::thread(&Thread_Cleaner::start, &(mdata->t_clean));
	}
	//std::cout << "\n\t\t\exiting barrier\n";
}

