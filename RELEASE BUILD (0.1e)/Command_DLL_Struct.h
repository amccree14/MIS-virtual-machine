#ifndef H_COMMAND_DLL_STRUCT
#define H_COMMAND_DLL_STRUCT

/******************
* FILE: Command_DLL_Struct.h
* Author: Arthur Kung
* Date: Nov 27, 2016
*
* Details:
*	- this file contains all the typedefs for the functions that can be
*		linked from the dynamic library.
*	- also defines the struct that is used to store all the loaded
*		function pointers.
******************/




#include "Command.h"

class MIS_System_Data;
class MIS_System;

// THESE ARE THE DLL ENTRY POINTS



typedef Command* (CREATE_ADD) (MIS_System_Data* data, unsigned int thread);
typedef Command* (CREATE_SUB) (MIS_System_Data* data, unsigned int thread);
typedef Command* (CREATE_MUL) (MIS_System_Data* data, unsigned int thread);
typedef Command* (CREATE_DIV) (MIS_System_Data* data, unsigned int thread);
typedef Command* (CREATE_ASSIGN) (MIS_System_Data* data, unsigned int thread);
typedef Command* (CREATE_OUT) (MIS_System_Data* data, unsigned int thread);
typedef Command* (CREATE_SET_STR_CHAR) (MIS_System_Data* data, unsigned int thread);
typedef Command* (CREATE_GET_STR_CHAR) (MIS_System_Data* data, unsigned int thread);
typedef Command* (CREATE_LABEL) (MIS_System_Data* data, unsigned int thread);
typedef Command* (CREATE_SLEEP) (MIS_System_Data* data, unsigned int thread);
typedef Command* (CREATE_JMP) (MIS_System_Data* data, unsigned int thread);
typedef Command* (CREATE_JMP_ZNZ) (MIS_System_Data* data, unsigned int thread, bool b);
typedef Command* (CREATE_JMP_GTLTE) (MIS_System_Data* data, unsigned int thread, bool b);
typedef Command* (CREATE_JMP_GTELT) (MIS_System_Data* data, unsigned int thread, bool b);
typedef Command* (CREATE_VAR) (MIS_System_Data* data, unsigned int thread);
typedef Command* (CREATE_THREAD_BEGIN) (MIS_System_Data* data, unsigned int thread, 
							MIS_System *_ms, unsigned int exec);
typedef Command* (CREATE_THREAD_END) (MIS_System_Data* data, unsigned int thread);
typedef Command* (CREATE_LOCK) (MIS_System_Data* data, unsigned int thread);
typedef Command* (CREATE_UNLOCK) (MIS_System_Data* data, unsigned int thread);
typedef Command* (CREATE_BARRIER) (MIS_System_Data* data, unsigned int thread);


struct Command_DLL
{
	CREATE_ADD *D_ADD;
	CREATE_SUB *D_SUB;
	CREATE_MUL *D_MUL;
	CREATE_DIV *D_DIV;
	CREATE_ASSIGN *D_ASSIGN;
	CREATE_OUT *D_OUT;
	CREATE_SET_STR_CHAR *D_SET_STR_CHAR;
	CREATE_GET_STR_CHAR *D_GET_STR_CHAR;
	CREATE_LABEL *D_LABEL;
	CREATE_SLEEP *D_SLEEP;
	CREATE_JMP *D_JMP;
	CREATE_JMP_ZNZ *D_JMP_ZNZ;
	CREATE_JMP_GTLTE *D_JMP_GTLTE;
	CREATE_JMP_GTELT *D_JMP_GTELT;
	CREATE_VAR *D_VAR;
	CREATE_THREAD_BEGIN *D_THREAD_BEGIN;
	CREATE_THREAD_END *D_THREAD_END;
	CREATE_LOCK *D_LOCK;
	CREATE_UNLOCK *D_UNLOCK;
	CREATE_BARRIER *D_BARRIER;
};


#endif

