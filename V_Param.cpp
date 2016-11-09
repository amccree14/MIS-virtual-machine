/******************
* FILE: V_Param.cpp
* Author: Arthur Kung
* Date: Nov 8, 2016
*
* Details:
*	- Implements getValue and setValue function templates for V_Param
******************/

#include "Params.h"
#include "MIS_Exception.h"

	// WARNING: because this returns a void*, OTHER FUNCTIONS CAN
	//			DEREFERENCE AND ASSIGN VALUES TO IT.
	//			Be very, very careful.
template <class A>
void* Params::getValue()			// return value
{
	return static_cast<void*>(&value);
}
		

template <class A>
void Params::setValue(void* pt);	// stores dereferenced value
{
	value = *static_cast<A*>(pt);
}


