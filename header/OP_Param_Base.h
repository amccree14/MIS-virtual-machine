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
class OP_Param_Base
{
	public:
		enum class OP_TYPE{NUMERIC, REAL, CHAR, STRING,
						   VAR_NUM, VAR_REA, VAR_CHA, VAR_STR};
		
			// store value in constructor
		OP_Param_Base(OP_TYPE t):type(t){}	// empty constructor
		
		
			// get value from variable/parameter
		virtual void* getValue()=0;
			// set value for a variable, throw error for normal param
		virtual void setValue(void*)=0;
	
			// these size functions are for the STRING variables
		void setSize(long long val){max_size = val;}
		long long getSize(){return max_size;}
		
			// return type of this parameter
		OP_TYPE getType(){return type;}

		//~OP_Param_Base(){}
		
		
	protected:	
		long long max_size = 0;
		OP_TYPE type;	// the type of param or variable
		
};


typedef OP_Param_Base::OP_TYPE PARAM_TYPE;	// typedef for easier enum access



#endif
