#ifndef H_PARAMS
#define H_PARAMS

/******************
* FILE: Params.h
* Author: Arthur Kung
* Date: Nov 2, 2016
*
* Details:
*	- The methods declared in this header file are
*		implemented in Params.cpp.
*
*	- This file contains the declaration for the Params class template.
*		The only thing that is defined within this class is the setValue
*		function.
*
*	  NOTE: The setValue function could have been defined within this
*			header, since it literally does nothing but throw an
*			exception and has no real implementation, but I'm leaving it
*			as a normal declaration due to possible confusion when
*			debugging.
******************/

#include "OP_Param_Base.h"

	// note: non-virtual inheritance, because it's unnecessary
template <class A>
class Params: public OP_Param_Base<A>
{
	Params(A x):OP_Param_Base(x){};
	
	A getValue();			// return value
	void setValue(A);		// this should just throw an exception
};



#endif
