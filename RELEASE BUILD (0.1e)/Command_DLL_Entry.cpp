/******************
* FILE: Command_DLL_Entry.cpp
* Author: Arthur Kung
* Date: Nov 27, 2016
*
* Details:
*	- This file contains all the entry-point functions for the dynamic
*		library. It has one entry function for every single one of
*		the various commands.
*
*	- NOTE: this can be achieved by making separate libraries for every
*		command and dynamically loading each one separately, but for the
*		sake of compactness and time, I've done it this way. This does
*		unfortunately mean that the MIS_System is not particularly
*		extendable via additional libraries (plugins, etc.), but does mean
*		that users can, if they so wish, create their entirely own set of
*		functions for each existing command class (following the provided
*		header file declarations), compile them into command.so, and load them
*		for execution within the system if they so wish.
*
*
*	- NOTE 2: due to the way the system was constructed, both the DLL and
*		the rest of the program rely on some of the same code, and so both
*		have it included in their compiles. This could (and perhaps should?)
*		have been resolved as a separately linked library, but... well,
*		time is at a premium here.
******************/


#include "Command.h"
#include "MIS_System_Data.h"

	// extern "C" for every function in this file
	//	- since all functions here are entry-points, they need to have
	//		(or at least benefit from having) unmangled names for linkage.
extern "C"
{
Command* CREATE_C_ADD(MIS_System_Data* data, unsigned int thread)
{
	return new C_ADD(data, thread);
}

Command* CREATE_C_SUB(MIS_System_Data* data, unsigned int thread)
{
	return new C_SUB(data, thread);
}

Command* CREATE_C_MUL(MIS_System_Data* data, unsigned int thread)
{
	return new C_MUL(data, thread);
}

Command* CREATE_C_DIV(MIS_System_Data* data, unsigned int thread)
{
	return new C_DIV(data, thread);
}

Command* CREATE_C_ASSIGN(MIS_System_Data* data, unsigned int thread)
{
	return new C_ASSIGN(data, thread);
}

Command* CREATE_C_OUT(MIS_System_Data* data, unsigned int thread)
{
	return new C_OUT(data, thread);
}

Command* CREATE_C_SET_STR_CHAR(MIS_System_Data* data, unsigned int thread)
{
	return new C_SET_STR_CHAR(data, thread);
}

Command* CREATE_C_GET_STR_CHAR(MIS_System_Data* data, unsigned int thread)
{
	return new C_GET_STR_CHAR(data, thread);
}

Command* CREATE_C_LABEL(MIS_System_Data* data, unsigned int thread)
{
	return new C_LABEL(data, thread);
}

Command* CREATE_C_SLEEP(MIS_System_Data* data, unsigned int thread)
{
	return new C_SLEEP(data, thread);
}

Command* CREATE_C_JMP(MIS_System_Data* data, unsigned int thread)
{
	return new C_JMP(data, thread);
}

Command* CREATE_C_JMP_ZNZ(MIS_System_Data* data, unsigned int thread, bool b)
{
	return new C_JMP_ZNZ(data, thread, b);
}

Command* CREATE_C_JMP_GTLTE(MIS_System_Data* data, unsigned int thread, bool b)
{
	return new C_JMP_GTLTE(data, thread, b);
}

Command* CREATE_C_JMP_GTELT(MIS_System_Data* data, unsigned int thread, bool b)
{
	return new C_JMP_GTELT(data, thread, b);
}

Command* CREATE_C_VAR(MIS_System_Data* data, unsigned int thread)
{
	return new C_VAR(data, thread);
}

Command* CREATE_C_THREAD_BEGIN(MIS_System_Data* data, unsigned int thread, 
							MIS_System *_ms, unsigned int exec)
{
	return new C_THREAD_BEGIN(data, thread, _ms, exec);
}

Command* CREATE_C_THREAD_END(MIS_System_Data* data, unsigned int thread)
{
	return new C_THREAD_END(data, thread);
}

Command* CREATE_C_LOCK(MIS_System_Data* data, unsigned int thread)
{
	return new C_LOCK(data, thread);
}

Command* CREATE_C_UNLOCK(MIS_System_Data* data, unsigned int thread)
{
	return new C_UNLOCK(data, thread);
}

Command* CREATE_C_BARRIER(MIS_System_Data* data, unsigned int thread)
{
	return new C_BARRIER(data, thread);
}

}



