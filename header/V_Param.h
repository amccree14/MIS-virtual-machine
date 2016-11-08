#ifndef H_V_PARAM
#define H_V_PARAM

/******************
* FILE: V_Params.h
* Author: Arthur Kung
* Date: Nov 2, 2016
*
* Details:
*	- The methods declared in this header file are
*		implemented in Params.cpp.
*
*	- This file contains the declaration for the V_Param class template.
*
*	- This class is ONLY used to store the data elements of variables
*		in a vector to be accessed by the Variable class's getValue and
*		setValue functions.
******************/

#include "OP_Param_Base.h"

	// note: non-virtual inheritance, because it's unnecessary
template <class A>
class V_Param: public OP_Param_Base
{
	private:
		A value;		// value stored within the param or variable
						//	- For param, it's an actual value
						//	- For variable, it's the variable index
	
	public:
		Params(A x):value(x){};
		
		void* getValue();			// return value
		void setValue(void*);		// this will set a value
};



#endif
