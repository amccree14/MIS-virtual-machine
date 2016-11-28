/******************
* FILE: Variable.cpp
* Author: Arthur Kung
* Date: Nov 8, 2016
*
* Details:
*	- Implements non-template functions for Variable class
******************/

#include "MIS_System.h"
#include "MIS_System_Data.h"
#include "OP_Param_Base.h"
#include "Variable.h"

	// this should retrieve the value from an 
	// 	indexed location ( pulled from the 
	//	variable map) in the variable data
	//	vector.
	// Basically a wrapper for V_Param
	//	class's getter.
void* Variable::getValue()
{
	return mdata->variables.at(value)->getValue();
}


	// this should store a value into an indexed 
	// 	location (pulled from the variable map)
	// 	in the variable data vector.
	// It's basically a wrapper for the
	//	V_Param class's setter.
void Variable::setValue(void* pt)
{
	mdata->variables.at(value)->setValue(pt);
	return;	
}


	// lock and unlock wrapper functions for V_Param
	//		NOTE: Recursive mutexes!
void Variable::lock(std::thread* id)
{
	mdata->variables.at(value)->lock(id);
}

void Variable::unlock(std::thread* id)
{
	mdata->variables.at(value)->unlock(id);
}
									



