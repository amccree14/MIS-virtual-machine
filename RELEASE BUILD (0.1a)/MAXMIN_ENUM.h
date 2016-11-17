#ifndef H_MAXMIN_ENUM
#define H_MAXMIN_ENUM

/******************
* FILE: MAXMIN_ENUM.h
* Author: Arthur Kung
* Date: Nov 2, 2016
*
* Details:
*	- This file provides MAX and MIN values for the number of parameters
*		each command operation can accept in the form of two enumerated lists
*		encapsulated within two structs. These are basically just constants.
*
*	- Not all of these values are actually used, but they're here for
*		reference.
******************/


// NOTE: changing this to struct + c-style enum for scoping and ease-of-use.
//			Access as follows: MAXPARAM::ADD, MINPARAM::ADD and so-on.

struct MAXPARAM
{
	enum
	{
		ADD = 13,
		SUB = 3,
		MUL = 13,
		DIV = 3,
		ASSIGN = 2,
		OUT = 12,
		SET_STR_CHAR = 3,
		GET_STR_CHAR = 3,
		JMP = 1,
		JMP_ZNZ = 2,
		JMP_GTLT = 3,
		SLEEP = 1,
		LABEL = 1,
		VAR = 4
	};
};

struct MINPARAM
{	
	enum
	{
		ADD = 3,
		SUB = 3,
		MUL = 3,
		DIV = 3,
		ASSIGN = 2,
		OUT = 1,
		SET_STR_CHAR = 3,
		GET_STR_CHAR = 3,
		JMP = 1,
		JMP_ZNZ = 2,
		JMP_GTLT = 3,
		SLEEP = 1,
		LABEL = 1,
		VAR = 3
	};
};


#endif

