#ifndef H_HELPERS
#define H_HELPERS


/******************
* FILE: helpers.h
* Author: Arthur Kung
* Date: Nov 8, 2016
*
* Details:
*	- declares 5 helper functions for string/sstream manipulation/parsing
******************/

#include <sstream>
#include <string>


	// remove all leading whitespace from a stringstream reference
void noWhite(std::stringstream& ss);

	// remove trailing whitespace from a string reference
void noWhiteEndString(std::string& st);

	// check if a string has any non-alphanumeric characters in it prior
	//	to the end of the string
bool gapless(std::string st);

	// deletes anything in the stringstream prior to its
	//	current index
void fixSS(std::stringstream& ss);

	// pulls first token from a passed stringstream and returns it
	//	as a std::string
std::string getFirstToken(std::stringstream& ss);


#endif

