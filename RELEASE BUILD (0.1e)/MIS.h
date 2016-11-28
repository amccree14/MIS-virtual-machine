#ifndef H_MIS
#define H_MIS

/******************
* FILE: MIS.h
* Author: Arthur Kung
* Date: Nov 27, 2016
*
* Details:
*	- provides information for loading the dynamically-linked library.
******************/


#include <string>

bool MIS(std::string s, bool run);


typedef bool (MIS_F) (std::string, bool);


#endif

