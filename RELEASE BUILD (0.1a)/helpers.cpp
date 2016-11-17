/******************
* FILE: helpers.cpp
* Author: Arthur Kung
* Date: Nov 8, 2016
*
* Details:
*	- includes 3 helper functions at the top of the file in the form of
*		noWhite(), noWhiteEndString(), and gapless().
******************/


#include "helpers.h"
#include "MIS_Exception.h"
#include <iostream>
#include <cctype>

	// remove all leading whitespace from a stringstream reference
void noWhite(std::stringstream& ss)
{
	while (ss.peek() == ' ' || ss.peek() == '\t')
		ss.get();
}

	// remove trailing whitespace from a string reference
void noWhiteEndString(std::string& st)
{
	for (int i = st.length() - 1; i >= 0; --i)
	{
		if (st[i] == ' ' || st[i] == '\t' || st[i] == '\n' || st[i] == '\r')
		{
			st.erase(i, 1);
		}
		else
			return;
	}
}

	// check if a string has any non-alphanumeric characters in it prior
	//	to the end of the string
bool gapless(std::string st)
{
	for (int i = 0; i < st.size(); ++i)
		if (!(isalnum(st[i])))
			return false;
			
	return true;
}


	// deletes anything in the stringstream prior to its
	//	current index
void fixSS(std::stringstream& ss)
{
	std::string temp;
	int i = ss.tellg();
	
	temp = ss.str();
	temp.erase(0,i);
	ss.str("");
	ss.clear();
	ss << temp;
	return;	
}

	// pulls first token from a passed stringstream and returns it
	//	as a std::string
std::string getFirstToken(std::stringstream& ss)
{	
	std::string st;	
	st.clear();
	
	if(ss.good())
	{
			// remove leading whitespace
		noWhite(ss);
		
		std::getline(ss, st, ',');
			
		noWhiteEndString(st);
			
				// CHECK IF VARIABLE EXISTS
		if (st.empty())
			throw MIS_Exception("No tokens were passed!\n");
			
		return st;
	}
}





