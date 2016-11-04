#ifndef H_VARIABLE
#define H_VARIABLE

/******************
* FILE: Variable.h
* Author: Arthur Kung
* Date: Nov 2, 2016
*
* Details:
*	- The methods declared in this header file are
*		implemented in Variable.cpp.
*
*	- This file contains the declaration for the Variable class template.
*		The only thing that is defined within this class is the setValue
*		function.
******************/

#include "OP_Param_Base.h"

	// note: non-virtual inheritance, because it's unnecessary
template <class A>
class Variable: public OP_Param_Base<A>
{
	A getValue();			// this should retrieve the value from an indexed
							// location in the variable map
	
	void setValue(A);		// this should store a value into an indexed 
							// location in the variable map
};



#endif
