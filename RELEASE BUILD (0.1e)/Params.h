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
*	- This file contains declaration & definition for the Params class template.
*		The only things that are defined within this class are the setValue
*		and getValue functions.
*
*	  NOTE: The setValue function could have been defined within this
*			header, since it literally does nothing but throw an
*			exception and has no real implementation, but I'm leaving it
*			as a normal declaration due to possible confusion when
*			debugging.
******************/

#include "MIS_Exception.h"		// for our exception
#include "OP_Param_Base.h"

	// note: non-virtual inheritance, because it's unnecessary
template <class A>
class Params: public OP_Param_Base
{
	private:
		A value;		// value stored within the param or variable
						//	- For param, it's an actual value
						//	- For variable, it's the variable index
	
	public:
		Params(A x, OP_TYPE t):OP_Param_Base(t),value(x){}
		
		void* getValue();			// return value
		void setValue(void*);		// this should always throw an exception
		
		void lock(std::thread* id);
		void unlock(std::thread* id);
};



template <class A>
void* Params<A>::getValue()			// return value
{
	return static_cast<void*>(&value);
}
		

template <class A>
void Params<A>::setValue(void* pt)	// this should always throw an exception
{
	throw MIS_Exception("Cannot assign value to right-hand value parameter.\n");
}

template <class A>
void Params<A>::lock(std::thread* id)	// this should always throw an exception
{
	throw MIS_Exception("Cannot lock a non-variable value.\n");
}


template <class A>
void Params<A>::unlock(std::thread* id)	// this should always throw an exception
{
	throw MIS_Exception("Cannot unlock a non-variable value.\n");
}




#endif
