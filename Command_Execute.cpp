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


	// add takes 3-13 parameters, with the first parameter being a variable
	//		and the remaining parameters being either variables or
	//		immediate values. We don't care WHAT those values are.


void C_ADD::execute()
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
										+ std::to_string(i+1) + ")\n");
			}
		}
			// store the final value into the given variable
		oplist[0]->setValue(static_cast<void*>(&temp));		
	}
		// otherwise, if it's a REAL getType()... (see above for comments)
	else if (oplist[0]->getType() == PARAM_TYPE::VAR_REA)
	{
		double temp = 0;
			switch(oplist[0]->getType())
			{
				case PARAM_TYPE::NUMERIC:
				case PARAM_TYPE::VAR_NUM:
					temp += *static_cast<long long*>(oplist[0]->getValue());
					break;

				case PARAM_TYPE::REAL:
				case PARAM_TYPE::VAR_REA:
					temp += *static_cast<double*>(oplist[0]->getValue());
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
										+ std::to_string(1) + ")\n");
			}
		oplist[0]->setValue(static_cast<void*>(&temp));
			
	}
		// otherwise, if it's neither a REAL or NUMERIC variable, it's an error

	else
		throw MIS_Exception("ERROR: Invalid storage getType()! (ADD)\n");
		
	
	return;	
}









////////////// I think separating every command class into its own

	////////////// cpp file may be useful here. It's debatable, since it will////////////// also make finding all the relevant command classes to adjust
////////////// code more irritating.




void C_SUB::execute()
{
		// check storage variable getType(). If it's a NUMERIC type....
	if (oplist[0]->getType() == PARAM_TYPE::VAR_NUM) {
		
	 	long long temp;
		long long var1;
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
												+ std::to_string(2) + ")\n");
					}
					break;
					     

				case PARAM_TYPE::REAL:
				case PARAM_TYPE::VAR_REA:
					{double var1 = *static_cast<double*>(oplist[1]->getValue());
					
									
					switch(oplist[2]->getType()){
						case PARAM_TYPE::NUMERIC:
						case PARAM_TYPE::VAR_NUM:
							{long long var2 = *static_cast<long long*>(oplist[2]->getValue());
							temp = var1 - var2;
							break;}

						case PARAM_TYPE::REAL:
						case PARAM_TYPE::VAR_REA:
							{double var2 = *static_cast<double*>(oplist[2]->getValue());
							temp = var1 - var2;
							break;}

						default: {throw MIS_Exception("ERROR: Invalid parameter getType()!"
												" (SUB parameter" 
												+ std::to_string(2) + ")\n");}}
					break;}
								
				default: {throw MIS_Exception("ERROR: Invalid parameter getType()!"
										" (SUB parameter" 
										+ std::to_string(1) + ")\n");}
			
			/*switch(oplist[2]->getType())
			{
				case PARAM_TYPE::NUMERIC:
				case PARAM_TYPE::VAR_NUM:
					var2 = *static_cast<long long*>(oplist[2]->getValue());
					break;

				case PARAM_TYPE::REAL:
				case PARAM_TYPE::VAR_REA:
					var2 = *static_cast<double*>(oplist[2]->getValue());
					break;
								
				default
					throw MIS_Exception("ERROR: Invalid parameter getType()!"
										" (SUB parameter" 
										+ std::to_string(2) + ")\n");} }*/
				
		}
			// store the final value into the given variable
		oplist[0]->setValue(static_cast<void*>(&temp));		
	}
		// otherwise, if it's a REAL getType()... (see above for comments)
	else if (oplist[0]->getType() == PARAM_TYPE::VAR_REA)
	{
		double temp;
		
			switch(oplist[1]->getType())
			{
				case PARAM_TYPE::NUMERIC:
				case PARAM_TYPE::VAR_NUM:
					{long long var1 = *static_cast<long long*>(oplist[1]->getValue());
					
									
					switch(oplist[2]->getType())
					{
						case PARAM_TYPE::NUMERIC:
						case PARAM_TYPE::VAR_NUM:
							{long long var2 = *static_cast<long long*>(oplist[2]->getValue());
							temp = var1 - var2;
							break;}

						case PARAM_TYPE::REAL:
						case PARAM_TYPE::VAR_REA:
							{double var2 = *static_cast<double*>(oplist[2]->getValue());
							temp = var1 - var2;
							break;}

						default: {throw MIS_Exception("ERROR: Invalid parameter getType()!"
												" (SUB parameter" 
												+ std::to_string(2) + ")\n");}}}
					
					     
				case PARAM_TYPE::REAL:
				case PARAM_TYPE::VAR_REA:
					{double var1 = *static_cast<double*>(oplist[1]->getValue());
					
									
					switch(oplist[2]->getType()){
						case PARAM_TYPE::NUMERIC:
						case PARAM_TYPE::VAR_NUM:
							{long long var2 = *static_cast<long long*>(oplist[2]->getValue());
							temp = var1 - var2;
							break;}

						case PARAM_TYPE::REAL:
						case PARAM_TYPE::VAR_REA:
							{double var2 = *static_cast<double*>(oplist[2]->getValue());
							temp = var1 - var2;
							break;}

						default: {throw MIS_Exception("ERROR: Invalid parameter getType()!"
												" (SUB parameter" 
												+ std::to_string(2) + ")\n");}}
					break;}
								
				default: throw MIS_Exception("ERROR: Invalid parameter getType()!"
										" (SUB parameter" 
										+ std::to_string(1) + ")\n");
		
	}
		// otherwise, if it's neither a REAL or NUMERIC variable, it's an error

	} else { throw MIS_Exception("ERROR: Invalid storage getType()! (ADD)\n"); }
		
	
	
	//}	
	return;
}

void C_DIV::execute()
{
	if (oplist[0]->getType() == PARAM_TYPE::VAR_NUM) {
		
	 	long long temp;
		
			switch(oplist[1]->getType())
			{
				case PARAM_TYPE::NUMERIC:
				case PARAM_TYPE::VAR_NUM:
					{long long var1 = *static_cast<long long*>(oplist[1]->getValue());
					
									
					switch(oplist[2]->getType())
					{
						case PARAM_TYPE::NUMERIC:
						case PARAM_TYPE::VAR_NUM:
							{long long var2 = *static_cast<long long*>(oplist[2]->getValue());
							temp = var1 / var2;
							break;}

						case PARAM_TYPE::REAL:
						case PARAM_TYPE::VAR_REA:
							{double var2 = *static_cast<double*>(oplist[2]->getValue());
							temp = var1 / var2;
							break;}

						default: {throw MIS_Exception("ERROR: Invalid parameter getType()!"
												" (SUB parameter" 
												+ std::to_string(2) + ")\n");}} }

				case PARAM_TYPE::REAL:
				case PARAM_TYPE::VAR_REA:
					{double var1 = *static_cast<double*>(oplist[1]->getValue());
					
									
					switch(oplist[2]->getType()){
						case PARAM_TYPE::NUMERIC:
						case PARAM_TYPE::VAR_NUM:
							{long long var2 = *static_cast<long long*>(oplist[2]->getValue());
							temp = var1 / var2;
							break;}

						case PARAM_TYPE::REAL:
						case PARAM_TYPE::VAR_REA:
							{double var2 = *static_cast<double*>(oplist[2]->getValue());
							temp = var1 / var2;
							break;}

						default: {throw MIS_Exception("ERROR: Invalid parameter getType()!"
												" (DIV parameter" 
												+ std::to_string(2) + ")\n");}}
					break;}
								
				default: throw MIS_Exception("ERROR: Invalid parameter getType()!"
										" (DIV parameter" 
										+ std::to_string(1) + ")\n");
					}
			// store the final value into the given variable
		oplist[0]->setValue(static_cast<void*>(&temp));		
	}
		// otherwise, if it's a REAL getType()... (see above for comments)
	else if (oplist[0]->getType() == PARAM_TYPE::VAR_REA)
	{
		double temp;
		
			switch(oplist[1]->getType())
			{
				case PARAM_TYPE::NUMERIC:
				case PARAM_TYPE::VAR_NUM:
					{long long var1 = *static_cast<long long*>(oplist[1]->getValue());
					
									
					switch(oplist[2]->getType())
					{
						case PARAM_TYPE::NUMERIC:
						case PARAM_TYPE::VAR_NUM:
							{long long var2 = *static_cast<long long*>(oplist[2]->getValue());
							temp = var1 / var2;
							break;}

						case PARAM_TYPE::REAL:
						case PARAM_TYPE::VAR_REA:
							{double var2 = *static_cast<double*>(oplist[2]->getValue());
							temp = var1 / var2;
							break;}

						default: {throw MIS_Exception("ERROR: Invalid parameter getType()!"
												" (SUB parameter" 
												+ std::to_string(2) + ")\n");}}}
				case PARAM_TYPE::REAL:
				case PARAM_TYPE::VAR_REA:
					{double var1 = *static_cast<double*>(oplist[1]->getValue());
					
									
					switch(oplist[2]->getType()){
						case PARAM_TYPE::NUMERIC:
						case PARAM_TYPE::VAR_NUM:
							{long long var2 = *static_cast<long long*>(oplist[2]->getValue());
							temp = var1 / var2;
							break;}

						case PARAM_TYPE::REAL:
						case PARAM_TYPE::VAR_REA:
							{double var2 = *static_cast<double*>(oplist[2]->getValue());
							temp = var1 / var2;
							break;}

						default: {throw MIS_Exception("ERROR: Invalid parameter getType()!"
												" (SUB parameter" 
												+ std::to_string(2) + ")\n");}}
					break;}
								
				default: throw MIS_Exception("ERROR: Invalid parameter getType()!"
										" (SUB parameter" 
										+ std::to_string(1) + ")\n");
		
	}
		
	} 	else { throw MIS_Exception("ERROR: Invalid storage getType()! (ADD)\n"); }
		
	
	//}	
	return;
}

void C_MUL::execute() {
	
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
										+ std::to_string(i+1) + ")\n");
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
										+ std::to_string(i+1) + ")\n");
			}
		}
		oplist[0]->setValue(static_cast<void*>(&temp));
	}
		// otherwise, if it's neither a REAL or NUMERIC variable, it's an error

	else
		throw MIS_Exception("ERROR: Invalid storage getType()! (ADD)\n");
		
	
	return;	
}


void C_ASSIGN::execute()
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

void C_OUT::execute() {
		// start at begininng of oplist to print out every value 
		for (int i = 0; i < oplist.size() - 1; ++i)
	{
		std::cout << oplist[i]->getValue() << std::endl;
	}
	
	return;
}

void C_SET_STR_CHAR::execute() {
	
	long long index = *static_cast<long long*>(oplist[1]->getValue());
	std::string* s = static_cast<std::string*>(oplist[0]->getValue());
	char c = *static_cast<char*>(oplist[2]->getValue());
	
	s->at(index) = c;
	
	return;
}

void C_GET_STR_CHAR::execute() {
	
	long long index = *static_cast<long long*>(oplist[1]->getValue());
	std::string s = *static_cast<std::string*>(oplist[0]->getValue());
	//char *c = static_cast<char*>(oplist[2]->getValue());
	
	char c = s.at(index);
	oplist[2]->setValue(static_cast<void*>(&c));
	
	return;	
}
				   
void C_JMP::execute() {
	
	long long label = *static_cast<long long*>(oplist[0]->getValue());
	mdata->setPC(label);
	return;
	
}
				   
void C_JMP_ZNZ::execute() {
	
	long long label = *static_cast<long long*>(oplist[0]->getValue());
	long long var = *static_cast<long long*>(oplist[1]->getValue());
	bool zero;
	
	if( var == 0 ) {
		zero = true; }
	else zero = false;
	
	
	if ((side) && (zero)) {
		mdata->setPC(label); }
	
	else if (!(side) && !(zero)) {
		mdata->setPC(label); }
	return;
	
	
}
				   
void C_JMP_GTLTE::execute() {
	
	long long label = *static_cast<long long*>(oplist[0]->getValue());
	long long var1 = *static_cast<long long*>(oplist[1]->getValue());
	long long var2 = *static_cast<long long*>(oplist[2]->getValue());
	
	if( (var1 > var2) && (side) ) {
		mdata->setPC(label); }
	
	else if( !(var1 > var2) && !(side) ) {
		mdata->setPC(label); }
	return;
	
}
				   
				   
void C_JMP_GTELT::execute() {
	
	long long label = *static_cast<long long*>(oplist[0]->getValue());
	long long var1 = *static_cast<long long*>(oplist[1]->getValue());
	long long var2 = *static_cast<long long*>(oplist[2]->getValue());
	
	if( (var1 < var2) && (side) ) {
		mdata->setPC(label); }
	
	else if( !(var1 < var2) && !(side) ) {
		mdata->setPC(label); }	
	return;
	
	
}	
				   
void C_SLEEP::execute() {
	
	long long var = *static_cast<long long*>(oplist[0]->getValue());
    std::this_thread::sleep_for(std::chrono::seconds(var));
	return;
	 
}

void C_LABEL::execute() {
	
	throw MIS_Exception("ERROR: Attempting to execute label (non- executable)! (LABEL)\n");
	
}
				   
				   
void C_VAR::execute() {
	
	throw MIS_Exception("ERROR: Attempting to execute VAR (non-executable)! (VAR)\n");				   
	
}
