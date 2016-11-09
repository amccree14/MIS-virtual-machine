/******************
* FILE: Command_Param_Functions.cpp
* Author: Arthur Kung
* Date: Nov 7, 2016
*
* Details:
*	- implements the two main functions from the Command class necessary
*		for parsing parameters and adding them to the parameter vectors.
*
*	- also includes 3 helper functions at the top of the file in the form of
*		noWhite(), noWhiteEndString(), and gapless().
******************/


#include <new>
#include <memory>	// shared_ptr
#include <string>
#include <sstream>
#include <cctype>		// isdigit, isalpha, isalnum

#include "OP_Param_Base.h"
#include "Params.h"
#include "Variable.h"
#include "V_Param.h"
#include "Command.h"
#include "MIS_Exception.h"



	// remove all leading whitespace from a stringstream reference
void noWhite(std::stringstream& ss)
{
	while (ss.peek() == ' ' || ss.peek() == '\t')
		ss.get();
}

	// remove trailing whitespace from a string reference
void noWhiteEndString(std::string& st)
{
	for (int i = st.size() - 1; i > 0; --i)
	{
		if (st[i] == ' ' || st[i] == '\t')
			st.erase(i, 1);
		else
			break;
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


/****************************
*
* Function: Command::makeParam()
* Input: std::stringstream& ss
* Output: OP_Param_Base*
*
* Details:
*	- handles creation of all parameters with the exception of
*		the VAR and LABEL opcodes, which handle parsing a bit
*		differently, so that they can add to the needed map/vectors.
*
****************************/

static OP_Param_Base* Command::makeParam(std::stringstream& ss)
{
		// create a storage string and empty it
	std::string st;	
	st.clear();
	
	OP_Param_Base* opbp = nullptr;
	
		// if the stringstream isn't empty (this would be a
		//	while loop if it weren't a subroutine that was
		//	only called once per parameter)
	if(ss.good())
	{
			// remove leading whitespace
		noWhite(ss);
		
			/************************
			* Check for STRING
			************************/
		if (ss.peek() == '\"')
		{
				// create temp string
			std::string temp;
				// remove leading character that we checked for
			ss.get();
			
				// pull characters until we hit the closing quote
			std::getline(ss, temp, '\"');
			
				// clear our string buffer, load it until our first comma
				//	after the closing quote
			st.clear();
			std::getline(ss, st, ',');
			
				// concatenate the two strings
			st = temp + st;
			
			
				// STRING-specific sequences, replace escape codes
				//	with their equivalents.
			temp = "\\n";
			int i = st.find(temp);
			while (i != std::string::npos)
				st.replace(i, 2, "\n");
				
			temp = "\\r";
			int i = st.find(temp);
			while (i != std::string::npos)
				st.replace(i, 2, "\r");
				
			temp = "\\t";
			int i = st.find(temp);
			while (i != std::string::npos)
				st.replace(i, 2, "\t");
			
			
				// CREATE STRING PARAM (use st)
				
			opbp = new Params<std::string>(st, PARAM_TYPE::STRING);	
			return opbp;
				
		}
			/************************
			* Check for CHAR
			************************/
		else if (ss.peek() == '\'')
		{
			char c;
			std::string temp;
			ss.get();
			
			std::getline(ss, temp, '\'');
			
			st.clear();
			std::getline(ss, st, ',');
			st = temp + st;
			
			
			noWhiteEndString(st);
			
			if(!(gapless(st)))
				throw MIS_Exception("Error during parse of character!\n");
				
			if(st.size() > 1 && st[0] == '\\')
			{
				if (st.size[1] == 'n')
					c = '\n';
				else if (st.size[1] == 'r')
					c = '\r';
				else if (st.size[1] == 't')
					c = '\t';
				else
					throw MIS_Exception("Error during parse of character!"
										"Unrecognized escape code.\n");
			}
			else if(st.size() == 1)
			{
				c = st[0];
			}
			else
				throw MIS_Exception("Error during parse: unrecognized "
									"character!\n");
				// CREATE CHAR PARAM (use c)
				
			opbp = new Params<char>(c, PARAM_TYPE::CHAR);
			return opbp;
				
		}
			/************************
			* Check for VARIABLE
			************************/
		else if (ss.peek() == '$')
		{
			ss.get();
			st.clear();
			std::getline(ss, st, ',');
			
			noWhiteEndString(st);
			
			if(!(gapless(st)))
				throw MIS_Exception("Error during parse of variable name!\n");
			
				// CREATE VARIABLE
			
			int index = mdata->varNames.at(st);
			
			PARAM_TYPE t = mdata->variables.at(index)->getType();
			
			switch(t)
			{
				case PARAM_TYPE::STRING
					t = PARAM_TYPE::VAR_STR;
					break;
				case PARAM_TYPE::NUMERIC
					t = PARAM_TYPE::VAR_NUM;
					break;
				case PARAM_TYPE::CHAR
					t = PARAM_TYPE::VAR_CHA;
					break;
				case PARAM_TYPE::REAL
					t = PARAM_TYPE::VAR_REA;
					break;
				default
					throw MIS_Exception("Error getting variable type-info!\n");
			}
			
			opbp = new Variable(index, t);
			return opbp;
			
		}
			/************************
			* Check for LABEL
			************************/
		else if (isalpha(ss.peek()))
		{
			st.clear();
			std::getline(ss, st, ',');
			
			noWhiteEndString(st);
			
			if(!(gapless(st)))
				throw MIS_Exception("Error during parse of label name!\n");
			
				// CREATE LABEL
			
			int index = mdata->labels.at(st);
			
			opbp = new Params<int>(index, PARAM_TYPE::NUMERIC);
			return opbp;
			
		}
			/************************
			* Check for NUMERIC or REAL
			************************/
		else if (isdigit(ss.peek()))
		{
			st.clear();
			std::getline(ss, st, ',');
			
			noWhiteEndString(st);
			
			for (int i = 0; i < st.size(); ++i)
			{
				if (!(isdigit(st[i])))
					throw MIS_Exception("Error during parse of a number! "
										"Non-digit detected!\n");
			}
			
			
			if(!(gapless(st)))
			{
				int flag = 0;
				for (int i = 0; i < st.size(); ++i)
				{
					if (st[i] == '.')
						++flag;
				}
				
				if (flag == 1)
				{
						// CREATE IMMEDIATE REAL PARAM
					std::stringstream sstemp(st);
					double val;
					sstemp >> val;
					opbp = new Params<double>(val, PARAM_TYPE::REAL);
					return opbp;
				}
				else
					throw MIS_Exception("Error during parse of REAL!\n");
			}
			else
			{
						// CREATE IMMEDIATE NUMERIC PARAM
				long long val;
				ss.str("");
				ss << st;
				ss >> val;
				opbp = new Params<long long>(val, PARAM_TYPE::NUMERIC);
				return opbp;
			}
			
			throw MIS_Exception("Error during parse of NUMERIC/REAL!\n");

		}
			/************************
			* If everything fails...
			************************/
		else
		{
			throw MIS_Exception("Error parsing parameters, unparsable.\n");
		}
			
	}
	
		// return nullptr if the parameter text is empty
	return opbp;
}



/****************************
*
* Function: Command::addParam()
* Input: OP_Param_Base* op
* Output: N/A
*
* Details:
*	- takes an OP_Param_Base* and converts
*		it to a shared_ptr and pushes it onto the
*		vector of parameters.
*
****************************/

void Command::addParam(OP_Param_Base* op)
{
		// create a shared_ptr and load it with the OP_Param_Base pointer
	std::shared_ptr<OP_Param_Base>> sp;
	sp.reset(op);
	
		// try to push the shared_ptr onto the back of the vector,
		//	and catch any failed allocations by the vector
	try
	{
		oplist.push_back(sp);
	}
	catch (std::bad_alloc ex)
	{
		throw MIS_Exception("Unable to add parameters to list, "
							" unable to allocate more memory.\n");
	}	
}


