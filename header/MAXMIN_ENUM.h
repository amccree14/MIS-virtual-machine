#ifndef H_MAXMIN_ENUM
#define H_MAXMIN_ENUM

/******************
* FILE: MAXMIN_ENUM.h
* Author: Arthur Kung
* Date: Nov 2, 2016
*
* Details:
*	- This file provides MAX and MIN values for the number of parameters
*		each command operation can accept in the form of two enumerated lists.
******************/


// NOTE: this file should be replaced with a list of macro definitions

enum class MAXPARAM
{
	ADD = 13,
	SUB = 3,
	MUL = 13,
	DIV = 3,
	ASSIGN = 2,
	OUT = 12,
	SET_STR_CHAR = 3,
	GET_STR_CHAR = 3,
	LABEL = 1,
	JMP = 1,
	JMP_ZNZ = 2,
	JMP_GTLT = 3,
	SLEEP = 1
};

enum class MINPARAM
{
	ADD = 3,
	SUB = 3,
	MUL = 3,
	DIV = 3,
	ASSIGN = 2,
	OUT = 1,
	SET_STR_CHAR = 3,
	GET_STR_CHAR = 3,
	LABEL = 1,
	JMP = 1,
	JMP_ZNZ = 2,
	JMP_GTLT = 3,
	SLEEP = 1
};


#endif

