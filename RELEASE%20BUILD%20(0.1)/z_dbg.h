#ifndef H_Z_DBG
#define H_Z_DBG

#include <string>
#include <sstream>
#include <iostream>
#include "OP_Param_Base.h"

	// fake std::to_string function because cygwin and other windows
	//	gcc builds do NOT support it.
namespace dbg
{
	template <typename A>
	string to_string(A x)
	{
		stringstream temp;
		temp << x;
		return temp.str();
	}
}

void showType(OP_Param_Base* op);


#endif

