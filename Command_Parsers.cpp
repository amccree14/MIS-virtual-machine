/******************
* FILE: Command_Parsers.cpp
* Author: Arthur Kung
* Date: Nov 7, 2016
*
* Details:
*	- implements the parse functions for every command class
******************/


#include <new>
#include <memory>	// shared_ptr
#include <string>
#include <sstream>

#include "MAXMIN_ENUM.h"
#include "OP_Param_Base.h"
#include "Params.h"
#include "Variable.h"
#include "V_Param.h"
#include "Command.h"
#include "Command_Param_Functions.h"
#include "MIS_Exception.h"




/*****************
*
* Function: C_ADD::parse()
*
*****************/
Command* C_ADD::parse(std:stringstream ss)
{
	Command* ret = new C_ADD(mdata);
	
	OP_Param_Base* op;
	
	if (!(op = makeParam(ss)))
		throw MIS_Exception("No parameters found. ADD.\n");
	
	PARAM_TYPE t = op->getType();
	
	if (t == PARAM_TYPE::VAR_REA ||
		t == PARAM_TYPE::VAR_NUM )
	{
		ret->addParam(op);	
	}
	else
		throw MIS_Exception("Invalid parameter. Parameter 1, ADD.\n");
		
	while (op = makeParam(ss) && ret->size() < 14)
	{
		t = op->getType();
		
		if (t == PARAM_TYPE::VAR_NUM ||
			t == PARAM_TYPE::VAR_REA ||
			t == PARAM_TYPE::NUMERIC ||
			t == PARAM_TYPE::REAL )
		{
			ret->addParam(op);
		}
		else
			throw MIS_Exception("Invalid parameter. ADD.\n");
	}
	
	std::string st;
	ss >> st;
	if (!st.empty())
	{
		throw MIS_Exception("Too many parameters. ADD.\n");
	}
	
	if (ret->size() < 3)
		throw MIS_Exception("Too few parameters. ADD.\n");
	
	return ret;
}

/*****************
*
* Function: C_SUB::parse()
*
*****************/
Command* C_SUB::parse(std:stringstream ss)
{
	Command* ret = new C_SUB(mdata);
	
	OP_Param_Base* op;
	
	if (!(op = makeParam(ss)))
		throw MIS_Exception("No parameters found. SUB.\n");
	
	PARAM_TYPE t = op->getType();
	
	if (t == PARAM_TYPE::VAR_REA ||
		t == PARAM_TYPE::VAR_NUM )
	{
		ret->addParam(op);	
	}
	else
		throw MIS_Exception("Invalid parameter. Parameter 1, SUB.\n");
		
	while (op = makeParam(ss) && ret->size() < 4)
	{
		t = op->getType();
		
		if (t == PARAM_TYPE::VAR_NUM ||
			t == PARAM_TYPE::VAR_REA ||
			t == PARAM_TYPE::NUMERIC ||
			t == PARAM_TYPE::REAL )
		{
			ret->addParam(op);
		}
		else
			throw MIS_Exception("Invalid parameter. SUB.\n");
	}
	
	std::string st;
	ss >> st;
	if (!st.empty())
	{
		throw MIS_Exception("Too many parameters. SUB.\n");
	}
	
	if (ret->size() < 3)
		throw MIS_Exception("Too few parameters. SUB.\n");
	
	return ret;
}

/*****************
*
* Function: C_MUL::parse()
*
*****************/
Command* C_MUL::parse(std:stringstream ss)
{
	Command* ret = new C_MUL(mdata);
	
	OP_Param_Base* op;
	
	if (!(op = makeParam(ss)))
		throw MIS_Exception("No parameters found. MUL.\n");
	
	PARAM_TYPE t = op->getType();
	
	if (t == PARAM_TYPE::VAR_REA ||
		t == PARAM_TYPE::VAR_NUM )
	{
		ret->addParam(op);	
	}
	else
		throw MIS_Exception("Invalid parameter. Parameter 1, MUL.\n");
		
	while (op = makeParam(ss) && ret->size() < 14)
	{
		t = op->getType();
		
		if (t == PARAM_TYPE::VAR_NUM ||
			t == PARAM_TYPE::VAR_REA ||
			t == PARAM_TYPE::NUMERIC ||
			t == PARAM_TYPE::REAL )
		{
			ret->addParam(op);
		}
		else
			throw MIS_Exception("Invalid parameter. MUL.\n");
	}
	
	std::string st;
	ss >> st;
	if (!st.empty())
	{
		throw MIS_Exception("Too many parameters. MUL.\n");
	}
	
	if (ret->size() < 3)
		throw MIS_Exception("Too few parameters. MUL.\n");
	
	return ret;
}

/*****************
*
* Function: C_DIV::parse()
*
*****************/
Command* C_DIV::parse(std:stringstream ss)
{
	Command* ret = new C_DIV(mdata);
	
	OP_Param_Base* op;
	
	if (!(op = makeParam(ss)))
		throw MIS_Exception("No parameters found. DIV.\n");
	
	PARAM_TYPE t = op->getType();
	
	if (t == PARAM_TYPE::VAR_REA ||
		t == PARAM_TYPE::VAR_NUM )
	{
		ret->addParam(op);	
	}
	else
		throw MIS_Exception("Invalid parameter. Parameter 1, DIV.\n");
		
	while (op = makeParam(ss) && ret->size() < 4)
	{
		t = op->getType();
		
		if (t == PARAM_TYPE::VAR_NUM ||
			t == PARAM_TYPE::VAR_REA ||
			t == PARAM_TYPE::NUMERIC ||
			t == PARAM_TYPE::REAL )
		{
			ret->addParam(op);
		}
		else
			throw MIS_Exception("Invalid parameter. DIV.\n");
	}
	
	std::string st;
	ss >> st;
	if (!st.empty())
	{
		throw MIS_Exception("Too many parameters. DIV.\n");
	}
	
	if (ret->size() < 3)
		throw MIS_Exception("Too few parameters. DIV.\n");
	
	return ret;
}

/*****************
*
* Function: C_ASSIGN::parse()
*
*****************/
Command* C_ASSIGN::parse(std:stringstream ss)
{
	Command* ret = new C_ASSIGN(mdata);
	
	OP_Param_Base* op;
	
	if (!(op = makeParam(ss)))
		throw MIS_Exception("No parameters found. ASSIGN.\n");
	
	PARAM_TYPE t = op->getType();
	
	if (t == PARAM_TYPE::VAR_REA ||
		t == PARAM_TYPE::VAR_NUM ||
		t == PARAM_TYPE::VAR_CHA ||
		t == PARAM_TYPE::VAR_STR )
	{
		ret->addParam(op);	
	}
	else
		throw MIS_Exception("Invalid parameter. Parameter 1, ASSIGN.\n");

	
	if (op = makeParam(ss))
	{
		switch(t)
		{
			case PARAM_TYPE::VAR_REA:
				t = op->getType();
				if (t == PARAM_TYPE::VAR_REA ||
					t == PARAM_TYPE::REAL )
				{
					ret->addParam(op);
				}
				else
					throw MIS_Exception("Invalid parameter. Assigned value has "
										"different type from storage.\n");
				break;
					
			case PARAM_TYPE::VAR_NUM:
				t = op->getType();
				if (t == PARAM_TYPE::VAR_NUM ||
					t == PARAM_TYPE::NUMERIC )
				{
					ret->addParam(op);
				}
				else
					throw MIS_Exception("Invalid parameter. Assigned value has "
										"different type from storage.\n");
				break;
					
			case PARAM_TYPE::VAR_CHA:
				t = op->getType();
				if (t == PARAM_TYPE::VAR_CHA ||
					t == PARAM_TYPE::CHAR )
				{
					ret->addParam(op);
				}
				else
					throw MIS_Exception("Invalid parameter. Assigned value has "
										"different type from storage.\n");
				break;
					
			case PARAM_TYPE::VAR_STR:
				t = op->getType();
				if (t == PARAM_TYPE::VAR_STR ||
					t == PARAM_TYPE::STRING )
				{
					ret->addParam(op);
				}
				else
					throw MIS_Exception("Invalid parameter. Assigned value has "
										"different type from storage.\n");
				break;
					
			default:
				throw MIS_Exception("Parameter parse failure. ASSIGN.\n");		
		}
	}
	else
		throw MIS_Exception("No assignment parameter found. ASSIGN.\n")
	
	std::string st;
	ss >> st;
	if (!st.empty())
	{
		throw MIS_Exception("Too many parameters. ASSIGN.\n");
	}
	
	if (ret->size() < 2)
		throw MIS_Exception("Too few parameters. ASSIGN.\n");
	
	return ret;
}

/*****************
*
* Function: C_OUT::parse()
*
*****************/
Command* C_OUT::parse(std:stringstream ss)
{
	Command* ret = new C_OUT(mdata);
	
	OP_Param_Base* op;
	
	if (!(op = makeParam(ss)))
		throw MIS_Exception("No parameters found. OUT.\n");
	
	PARAM_TYPE t = op->getType();
	
	ret->addParam(op);	

	while (op = makeParam(ss) && ret->size() < 14)
	{
		t = op->getType();

		ret->addParam(op);
	}
	
	std::string st;
	ss >> st;
	if (!st.empty())
	{
		throw MIS_Exception("Too many parameters. DIV.\n");
	}
	
	
	if (ret->size() < 1)
		throw MIS_Exception("Too few parameters. SUB.\n");
	
	return ret;
}

/*****************
*
* Function: C_SET_STR_CHAR::parse()
*
*****************/
Command* C_SET_STR_CHAR::parse(std:stringstream ss)
{
	Command* ret = new C_SET_STR_CHAR(mdata);
	
	OP_Param_Base* op;
	
	if (!(op = makeParam(ss)))
		throw MIS_Exception("No parameters found. SET_STR_CHAR.\n");
	
	PARAM_TYPE t = op->getType();
	
	
	
	if (t == PARAM_TYPE::VAR_STR )
	{
		ret->addParam(op);	
	}
	else
		throw MIS_Exception("Invalid parameter. Parameter 1, SET_STR_CHAR.\n");
		
	if (op = makeParam(ss))
		t = op->getType();
	else
		throw MIS_Exception("Parameter not found. Parameter 2,"
							" SET_STR_CHAR.\n");
	
	if (t == PARAM_TYPE::VAR_NUM ||
		t == PARAM_TYPE::NUMERIC )
	{
		ret->addParam(op);	
	}
	else
		throw MIS_Exception("Invalid parameter. Parameter 2, SET_STR_CHAR.\n");
		
		
	if (op = makeParam(ss))
		t = op->getType();
	else
		throw MIS_Exception("Parameter not found. Parameter 3,"
							" SET_STR_CHAR.\n");
	
	if (t == PARAM_TYPE::VAR_CHAR ||
		t == PARAM_TYPE::CHAR )
	{
		ret->addParam(op);	
	}
	else
		throw MIS_Exception("Invalid parameter. Parameter 3, SET_STR_CHAR.\n");
	
	std::string st;
	ss >> st;
	if (!st.empty())
	{
		throw MIS_Exception("Too many parameters. SET_STR_CHAR.\n");
	}
	
	if (ret->size() < 3)
		throw MIS_Exception("Too few parameters. SET_STR_CHAR.\n");
	
	return ret;
}

/*****************
*
* Function: C_GET_STR_CHAR::parse()
*
*****************/
Command* C_GET_STR_CHAR::parse(std:stringstream ss)
{
	Command* ret = new C_GET_STR_CHAR(mdata);
	
	OP_Param_Base* op;
	
	if (!(op = makeParam(ss)))
		throw MIS_Exception("No parameters found. GET_STR_CHAR.\n");
		
	PARAM_TYPE t = op->getType();

	
		
	if (t == PARAM_TYPE::VAR_STR )
	{
		ret->addParam(op);	
	}
	else
		throw MIS_Exception("Invalid parameter. Parameter 1, GET_STR_CHAR.\n");
		
	if (op = makeParam(ss))
		t = op->getType();
	else
		throw MIS_Exception("Parameter not found. Parameter 2,"
							" GET_STR_CHAR.\n");
	
	if (t == PARAM_TYPE::VAR_NUM ||
		t == PARAM_TYPE::NUMERIC )
	{
		ret->addParam(op);	
	}
	else
		throw MIS_Exception("Invalid parameter. Parameter 2, GET_STR_CHAR.\n");
		
		
	if (op = makeParam(ss))
		t = op->getType();
	else
		throw MIS_Exception("Parameter not found. Parameter 3,"
							" GET_STR_CHAR.\n");
	
	if (t == PARAM_TYPE::VAR_CHAR )
	{
		ret->addParam(op);	
	}
	else
		throw MIS_Exception("Invalid parameter. Parameter 3, GET_STR_CHAR.\n");
	
	std::string st;
	ss >> st;
	if (!st.empty())
	{
		throw MIS_Exception("Too many parameters. GET_STR_CHAR.\n");
	}
	
	if (ret->size() < 3)
		throw MIS_Exception("Too few parameters. GET_STR_CHAR.\n");
	
	return ret;
}

/*****************
*
* Function: C_SLEEP::parse()
*
*****************/
Command* C_SLEEP::parse(std:stringstream ss)
{
	Command* ret = new C_SLEEP(mdata);
	
	OP_Param_Base* op;
	
	if (!(op = makeParam(ss)))
		throw MIS_Exception("No parameters found. SLEEP.\n");
	
	PARAM_TYPE t = op->getType();
	
	if (t == PARAM_TYPE::VAR_NUM ||
		t == PARAM_TYPE::NUMERIC )
	{
		ret->addParam(op);	
	}
	else
		throw MIS_Exception("Invalid parameter. Parameter 1, SLEEP.\n");
		
	
	std::string st;
	ss >> st;
	if (!st.empty())
	{
		throw MIS_Exception("Too many parameters. SLEEP.\n");
	}
	
	if (ret->size() < 1)
		throw MIS_Exception("Too few parameters. SLEEP.\n");
	
	return ret;
}


/*********/


	// The problem with JMP is that the overall parser can find JMP
	//	and call it out of the object factory, but JMP(Z/NZ) and
	//	JMP(GT/LT/GTE/LTE) can NOT be so easily pulled from the factory.
	
	// Our solution is to declare every combination (JMPZ, JMPNZ, JMPGT, etc.)
	//	in the object factory map, but to make every pair of them create the
	//	same classes with different boolean markers. Notably, this works because
	//	> is the same as the opposite of <=, etc., and Z is the opposite of NZ.
	
/*****************
*
* Function: C_JMP::parse()
*
*****************/
Command* C_JMP::parse(std:stringstream ss)
{
	Command* ret = new C_JMP(mdata);
	
	OP_Param_Base* op;
	
	if (!(op = makeParam(ss)))
		throw MIS_Exception("No parameters found. JMP.\n");
	
	PARAM_TYPE t = op->getType();
	
	if (t == PARAM_TYPE::STRING )
	{
		ret->addParam(op);
	}
	else
		throw MIS_Exception("Invalid parameter. Parameter 1, JMP.\n");

	
	std::string st;
	ss >> st;
	if (!st.empty())
	{
		throw MIS_Exception("Too many parameters. JMP.\n");
	}
	
	if (ret->size() < 1)
		throw MIS_Exception("Too few parameters. JMP.\n");
	
	return ret;
}

/*****************
*
* Function: C_JMP_ZNZ::parse()
*
*****************/
Command* C_JMP_ZNZ::parse(std:stringstream ss)
{
	Command* ret = new C_JMP_ZNZ(mdata);
	
	OP_Param_Base* op;
	
	if (!(op = makeParam(ss)))
		throw MIS_Exception("No parameters found. JMP(Z/NZ).\n");
		
	
	PARAM_TYPE t = op->getType();
	
	if (t == PARAM_TYPE::STRING )
	{
		ret->addParam(op);
	}
	else
		throw MIS_Exception("Invalid parameter. Parameter 1, JMP(Z/NZ).\n");


	if (op = makeParam(ss))
		t = op->getType();
	else
		throw MIS_Exception("Parameter not found. Parameter 2,"
							" JMP(Z/NZ).\n");
	
	if (t == PARAM_TYPE::NUMERIC ||
		t == PARAM_TYPE::VAR_NUM )
	{
		ret->addParam(op);
	}
	else
		throw MIS_Exception("Invalid parameter. Parameter 2, JMP(Z/NZ).\n");
	
	std::string st;
	ss >> st;
	if (!st.empty())
	{
		throw MIS_Exception("Too many parameters. JMP(Z/NZ).\n");
	}
	
	if (ret->size() < 2)
		throw MIS_Exception("Too few parameters. JMP(Z/NZ).\n");
	
	return ret;
}

/*****************
*
* Function: C_JMP_GTLTE::parse()
*
*****************/
Command* C_JMP_GTLTE::parse(std:stringstream ss)
{
	Command* ret = new C_JMP_GTLTE(mdata);
	
	OP_Param_Base* op;
	
	if (!(op = makeParam(ss)))
		throw MIS_Exception("No parameters found. JMP(GT/LT).\n");
	
	PARAM_TYPE t = op->getType();
	
	if (t == PARAM_TYPE::STRING )
	{
		ret->addParam(op);
	}
	else
		throw MIS_Exception("Invalid parameter. Parameter 1, JMP(GT/LT).\n");


	if (op = makeParam(ss))
		t = op->getType();
	else
		throw MIS_Exception("Parameter not found. Parameter 2,"
							" JMP(GT/LT).\n");
	
	if (t == PARAM_TYPE::NUMERIC ||
		t == PARAM_TYPE::VAR_NUM )
	{
		ret->addParam(op);
	}
	else
		throw MIS_Exception("Invalid parameter. Parameter 2, JMP(GT/LT).\n");
		
		
	if (op = makeParam(ss))
		t = op->getType();
	else
		throw MIS_Exception("Parameter not found. Parameter 3,"
							" JMP(GT/LT).\n");
	
	if (t == PARAM_TYPE::NUMERIC ||
		t == PARAM_TYPE::VAR_NUM )
	{
		ret->addParam(op);
	}
	else
		throw MIS_Exception("Invalid parameter. Parameter 3, JMP(GT/LT).\n");
	
	
	std::string st;
	ss >> st;
	if (!st.empty())
	{
		throw MIS_Exception("Too many parameters. JMP(GT/LT).\n");
	}
	
	if (ret->size() < 3)
		throw MIS_Exception("Too few parameters. JMP(GT/LT).\n");
	
	return ret;
}

/*****************
*
* Function: C_JMP_GTELT::parse()
*
*****************/
Command* C_JMP_GTELT::parse(std:stringstream ss)
{
	Command* ret = new C_JMP_GTELT(mdata);
	
	OP_Param_Base* op;
	
	if (!(op = makeParam(ss)))
		throw MIS_Exception("No parameters found. JMP(GT/LT).\n");
	
	PARAM_TYPE t = op->getType();
	
	if (t == PARAM_TYPE::STRING )
	{
		ret->addParam(op);
	}
	else
		throw MIS_Exception("Invalid parameter. Parameter 1, JMP(GT/LT).\n");


	if (op = makeParam(ss))
		t = op->getType();
	else
		throw MIS_Exception("Parameter not found. Parameter 2,"
							" JMP(GT/LT).\n");
	
	if (t == PARAM_TYPE::NUMERIC ||
		t == PARAM_TYPE::VAR_NUM )
	{
		ret->addParam(op);
	}
	else
		throw MIS_Exception("Invalid parameter. Parameter 2, JMP(GT/LT).\n");
		
		
	if (op = makeParam(ss))
		t = op->getType();
	else
		throw MIS_Exception("Parameter not found. Parameter 3,"
							" JMP(GT/LT).\n");
	
	if (t == PARAM_TYPE::NUMERIC ||
		t == PARAM_TYPE::VAR_NUM )
	{
		ret->addParam(op);
	}
	else
		throw MIS_Exception("Invalid parameter. Parameter 3, JMP(GT/LT).\n");
	
	
	std::string st;
	ss >> st;
	if (!st.empty())
	{
		throw MIS_Exception("Too many parameters. JMP(GT/LT).\n");
	}
	
	if (ret->size() < 3)
		throw MIS_Exception("Too few parameters. JMP(GT/LT).\n");
	
	return ret;
}










/***********************/
/* the weird functions */
/***********************/

/*****************
*
* Function: C_LABEL::parse()
*
*****************/
Command* C_LABEL::parse(std:stringstream ss)
{
	Command* ret = 0;
	std::string st;
	st.clear();
	
		// clear front-side whitespace
	while (ss.peek() == ' ' || ss.peek() == '\t')
		ss.get();
		
	std::getline(ss, st, ',');
	
		// clear back-side whitespace
	for (int i = st.size() - 1; i > 0; --i)
	{
		if (st[i] == ' ' || st[i] == '\t')
			st.erase(i, 1);
		else
			break;
	}

		// check for non-alphanumeric characters		
	for (int i = 0; i < st.size(); ++i)
		if (!(isalnum(st[i])))
			throw MIS_Exception("Invalid label!\n");

	if (mdata->labels.find(st) != std::map::end)
		throw MIS_Exception("Label already exists!\n");
		
	if (st.empty())
		throw MIS_Exception("No label name was passed!\n");
	
	mdata->labels[st] = mdata->getPC();
	
	
	st.clear()
	ss >> st;
	if (!st.empty())
	{
		throw MIS_Exception("Too many parameters. LABEL.\n");
	}
	
	if (ret->size() < 1)
		throw MIS_Exception("Too few parameters. LABEL.\n");
	
	return ret;	
}

/*****************
*
* Function: C_VAR::parse()
*
*****************/
Command* C_VAR::parse(std:stringstream ss)
{
	Command* ret = 0;
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
		while (ss.peek() == ' ' || ss.peek() == '\t')
			ss.get();
		
		if (ss.peek() == '$')
		{
			ss.get();
			st.clear();
			std::getline(ss, st, ',');
			
				// remove trailing whitespace
			for (int i = st.size() - 1; i > 0; --i)
			{
				if (st[i] == ' ' || st[i] == '\t')
					st.erase(i, 1);
				else
					break;
			}
			
		// check for non-alphanumeric characters		
			for (int i = 0; i < st.size(); ++i)
				if (!(isalnum(st[i])))
					throw MIS_Exception("Invalid characters in variable "
										"name!\n");
			
				// CHECK IF VARIABLE EXISTS
			
			if (mdata->varNames.find(st) != std::map::end)
				throw MIS_Exception("Variable name is already in use!\n");
			
				// save variable name
			std::string varname = st;
			
			
		/////////////////////// parameter 2 ////////////////////////
			
				// clear front-side whitespace
			while (ss.peek() == ' ' || ss.peek() == '\t')
				ss.get();
				
			std::getline(ss, st, ',');
			
				// clear back-side whitespace
			for (int i = st.size() - 1; i > 0; --i)
			{
				if (st[i] == ' ' || st[i] == '\t')
					st.erase(i, 1);
				else
					break;
			}
		
				// check for non-alphanumeric characters		
			for (int i = 0; i < st.size(); ++i)
				if (!(isalnum(st[i])))
					throw MIS_Exception("Invalid variable type!\n");

			int index = mdata->variables.size();		// get index of new var
							
			
			
			
		/////////////////////// parameter 3 and 4 ////////////////////////
			
				// create the variable and v_param objects for the vectors
				//	and maps
			switch(st)
			{
				case "NUMERIC":
					std::shared_ptr<V_Param> vp(new V_Param<long long>(0,
												PARAM_TYPE::NUMERIC)
					std::shared_ptr<Variable> va(new Variable(index,
												PARAM_TYPE::VAR_NUM)
					mdata->variables.push_back(vp);		// store variable data
					mdata->varNames[varname] = index;	// store variable index
					
					
					
					
					
					OP_Param_Base* op1, op2;
					
					op1 = makeParam(ss);
					if (op2 = makeParam(ss))
					{
						throw MIS_Exception("Invalid (too many) parameters"
												" for VAR!\n");
					}
					else
					{
						if (op1->getType() != PARAM_TYPE::NUMERIC)
							throw MIS_Exception("Invalid parameter"
												" for VAR!\n");
						
						mdata->variables[index]->setValue(op1->getValue());					
					}
					
					
					
					break;
					
					
				case "REAL":
					std::shared_ptr<V_Param> vp(new V_Param<double>(0.0,
												PARAM_TYPE::REAL)
					std::shared_ptr<Variable> va(new Variable(index,
												PARAM_TYPE::VAR_REAL)
					mdata->variables.push_back(vp);		// store variable data
					mdata->varNames[varname] = index;	// store variable index
					
					
					
					OP_Param_Base* op1, op2;
					
					op1 = makeParam(ss);
					if (op2 = makeParam(ss))
					{
						throw MIS_Exception("Invalid (too many) parameters"
												" for VAR!\n");
					}
					else
					{
						if (op1->getType() != PARAM_TYPE::REAL)
							throw MIS_Exception("Invalid parameter"
												" for VAR!\n");
						
						mdata->variables[index]->setValue(op1->getValue());					
					}
					
					
					break;
					
					
				case "CHAR":
					std::shared_ptr<V_Param> vp(new V_Param<char>('',
												PARAM_TYPE::CHAR)
					std::shared_ptr<Variable> va(new Variable(index,
												PARAM_TYPE::VAR_CHA)
					mdata->variables.push_back(vp);		// store variable data
					mdata->varNames[varname] = index;	// store variable index		
					
					

					OP_Param_Base* op1, op2;
					
					op1 = makeParam(ss);
					if (op2 = makeParam(ss))
					{
						throw MIS_Exception("Invalid (too many) parameters"
												" for VAR!\n");
					}
					else
					{
						if (op1->getType() != PARAM_TYPE::CHAR)
							throw MIS_Exception("Invalid parameter"
												" for VAR!\n");
						
						mdata->variables[index]->setValue(op1->getValue());					
					}
								
					
					break;
					
					
				case "STRING":
					std::shared_ptr<V_Param> vp(new V_Param<std::string>("",
												PARAM_TYPE::STRING)
					std::shared_ptr<Variable> va(new Variable(index,
												PARAM_TYPE::VAR_STR)
					mdata->variables.push_back(vp);		// store variable data
					mdata->varNames[varname] = index;	// store variable index			

					
					
					OP_Param_Base* op1, op2;
					
					op1 = makeParam(ss);
					if (op2 = makeParam(ss))
					{
						if (makeParam(ss))
							throw MIS_Exception("Invalid (too many) parameters"
												" for VAR!\n");
						if (op1->getType() != PARAM_TYPE::NUMERIC ||
							op2->getType() !- PARAM_TYPE::STRING )
						{
							throw MIS_Exception("Invalid parameters"
												" for VAR!\n");
						}
						long long temp = *static_cast<long long*>
											(op1->getValue());
						std::string stemp = *static_cast<std::string*>
											(op2->getValue());
						
						if (stemp.size() > temp)
							throw MIS_Exception("Invalid parameters"
												" for VAR!\n");
							
						
						mdata->variables[index]->setSize(temp);
						mdata->variables[index]->setValue(static_cast<void*>
															(&stemp));
						
					}
					else
					{
						if (op1->getType() != PARAM_TYPE::STRING)
							throw MIS_Exception("Invalid parameter"
												" for VAR!\n");
						
						mdata->variables[index]->setValue(op1->getValue());					
					}
					
										
					break;
					
					
				default:
					throw MIS_Exception("Invalid variable type!\n");
			}			
			
		}
		else
			throw MIS_Exception("Invalid variable parameters!\n");
			
	}
	else
		throw MIS_Exception("Invalid variable parameters!\n");
		

	return ret;		
}


