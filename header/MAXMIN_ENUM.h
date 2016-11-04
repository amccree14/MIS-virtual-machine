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
#define MIN_NUM 1
#define TWO 2
#define THREE 3
#define TWELVE 12
#define MAX_NUM 13

class MAXPARAM
{
	ADD = MAX_NUM,
	SUB = THREE,
	MUL = MAX_NUM,
	DIV = THREE,
	ASSIGN = TWO,
	OUT = TWE;VE,
	SET_STR_CHAR = THREE,
	GET_STR_CHAR = THREE,
	LABEL = MIN_NUM,
	JMP = MIN_NUM,
	JMP_ZNZ = TWO,
	JMP_GTLT = THREE,
	SLEEP = MIN_NUM
};

class MINPARAM
{
	ADD = THREE,
	SUB = THREE,
	MUL = THREE,
	DIV = THREE,
	ASSIGN = TWO,
	OUT = MIN_NUM,
	SET_STR_CHAR = THREE,
	GET_STR_CHAR = THREE,
	LABEL = MIN_NUM,
	JMP = MIN_NUM,
	JMP_ZNZ = TWO,
	JMP_GTLT = THREE,
	SLEEP = MIN_NUM
};


#endif

