/******************
* FILE: Variable.cpp
* Author: Arthur Kung
* Date: Nov 8, 2016
*
* Details:
*	- Implements non-template functions for Variable class
******************/

#include "OP_Param_Base.h"

	// this should retrieve the value from an 
	// 	indexed location ( pulled from the 
	//	variable map) in the variable data
	//	vector.
	// Basically a wrapper for V_Param
	//	class's getter.
void* getValue()
{
	return mdata->variables.at(value)->getValue();
}


	// this should store a value into an indexed 
	// 	location (pulled from the variable map)
	// 	in the variable data vector.
	// It's basically a wrapper for the
	//	V_Param class's setter.
void setValue(void* pt)
{
	mdata->variables.at(value)->setValue(pt);
	return;	
}
									



