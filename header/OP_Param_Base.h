#ifndef H_OP_PARAM_BASE
#define H_OP_PARAM_BASE


/******************
* FILE: OP_List.h
* Author: Arthur Kung
* Date: Nov 2, 2016
*
* Details:
*	- The methods declared in this header file are
*		implemented in OP_List.cpp.
*
*	- This file contains the declaration for the templated base class
*		for the Variable and Params classes. This is how values are
*		stored within our parameter vectors that are passed to each
*		function called while running through the command vector.
******************/


	// keep in mind here that this is a class template. While all these
	//	values will be stored correctly, it must be noted that the *parser*
	//	needs to check to make sure every given value falls within the
	//	limits given by the project guidelines.
	
	// To wit:
	//	NUMERIC - 8 bytes	- NOTE: __int8 and uint are for BITS not BYTES
	//	REAL 	- 8 bytes	- standard int/double is 8 bytes or MORE
	//	CHAR 	- 1 byte	- use 'long long' and 'double' for 8 bytes
	//	STRING 	- 1-256 bytes
template <class A>
class OP_Param_Base
{
	public:
		enum class OP_TYPE{NUMERIC, REAL, CHAR, STRING,
						   VAR_NUM, VAR_REA, VAR_CHA, VAR_STR};
		
			// store value in constructor
		OP_Param_Base(A x):value(x){};
		
			// get value from variable/parameter
		virtual A getValue();
			// set value for a variable, throw error for normal param
		virtual void setValue(A input);

		
		
	private:		
		A value;		// value stored within the param or variable
						//	- For param, it's an actual value
						//	- For variable, it's the variable index
						
		OP_TYPE type;	// the type of param or variable
		
};



#endif
