#ifndef H_V_PARAM
#define H_V_PARAM

/******************
* FILE: V_Params.h
* Author: Arthur Kung
* Date: Nov 2, 2016
*
* Details:
*	- The methods declared in this header file are
*		implemented in V_Param.cpp.
*
*	- This file contains the declaration and implementation
*		for the V_Param class template.
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
		V_Param(A x, OP_TYPE t):OP_Param_Base(t),value(x){}
		
		void* getValue();			// return value
		void setValue(void*);		// this will set a value
};



template <class A>
void* V_Param<A>::getValue()			// return value
{
	return static_cast<void*>(&value);
}
		

template <class A>
void V_Param<A>::setValue(void* pt)		// stores dereferenced value
{
	value = *static_cast<A*>(pt);
}


#endif
