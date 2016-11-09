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
*	- This file contains the declaration for the Variable class (non-template).
*		The only thing that is defined within this class is the setValue
*		function.
******************/

#include "OP_Param_Base.h"
#include "MIS_System_Data.h"

	// note: non-virtual inheritance, because it's unnecessary
class Variable: public OP_Param_Base
{
	private:
		int value;		// value stored within the param or variable
						//	- For param, it's an actual value
						//	- For variable, it's the variable index
		MIS_System_Data* mdata;
	
	public:
		Variable(int x, OP_TYPE t, MIS_System_Data* data)
						:OP_Param_Base(t),value(x), mdata(data){}
	
		void* getValue();			// this should retrieve the value from an 
									// 	indexed location ( pulled from the 
									//	variable map) in the variable data
									//	vector.
									// Basically a wrapper for V_Param
									//	class's getter.
	
		void setValue(void*);		// this should store a value into an indexed 
									// 	location (pulled from the variable map)
									// 	in the variable data vector.
									// It's basically a wrapper for the
									//	V_Param class's setter.
};



#endif
