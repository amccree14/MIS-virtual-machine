/******************
* FILE: Command_Parsers.cpp
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

#include "MAXMIN_ENUM.h"
#include "OP_Param_Base.h"
#include "Params.h"
#include "Variable.h"
#include "V_Param.h"
#include "Command.h"
#include "MIS_Exception.h"




/*****************
*
* Function: C_ADD::parse()
*
*****************/
Command* C_ADD::parse(std:stringstream ss)
{
	Command* ret = new C_ADD(mdata);
	
	OP_Param_Base* op = makeParam(ss);
	
	PARAM_TYPE t = op->getType();
	
	if (t == PARAM_TYPE::VAR_REA ||
		t == PARAM_TYPE::VAR_NUM )
	{
		ret->addParam(op);	
	}
	else
		throw MIS_Exception("Invalid parameter. Parameter 1, ADD.\n");
		
	while (ss.good() && ret->oplist.size() < 14)
	{
		op = makeParam(ss);
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
	
	OP_Param_Base* op = makeParam(ss);
	
	PARAM_TYPE t = op->getType();
	
	if (t == PARAM_TYPE::VAR_REA ||
		t == PARAM_TYPE::VAR_NUM )
	{
		ret->addParam(op);	
	}
	else
		throw MIS_Exception("Invalid parameter. Parameter 1, SUB.\n");
		
	while (ss.good() && ret->oplist.size() < 4)
	{
		op = makeParam(ss);
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
	
	OP_Param_Base* op = makeParam(ss);
	
	PARAM_TYPE t = op->getType();
	
	if (t == PARAM_TYPE::VAR_REA ||
		t == PARAM_TYPE::VAR_NUM )
	{
		ret->addParam(op);	
	}
	else
		throw MIS_Exception("Invalid parameter. Parameter 1, MUL.\n");
		
	while (ss.good() && ret->oplist.size() < 14)
	{
		op = makeParam(ss);
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
	
	OP_Param_Base* op = makeParam(ss);
	
	PARAM_TYPE t = op->getType();
	
	if (t == PARAM_TYPE::VAR_REA ||
		t == PARAM_TYPE::VAR_NUM )
	{
		ret->addParam(op);	
	}
	else
		throw MIS_Exception("Invalid parameter. Parameter 1, DIV.\n");
		
	while (ss.good() && ret->oplist.size() < 4)
	{
		op = makeParam(ss);
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
	
	OP_Param_Base* op = makeParam(ss);
	
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

	
	if (ss.good())
		op = makeParam(ss);
		
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
	
	std::string st;
	ss >> st;
	if (!st.empty())
	{
		throw MIS_Exception("Too many parameters. SUB.\n");
	}
	
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
	
	OP_Param_Base* op = makeParam(ss);
	
	PARAM_TYPE t = op->getType();
	
	ret->addParam(op);	

	while (ss.good() && ret->oplist.size() < 14)
	{
		op = makeParam(ss);
		t = op->getType();

		ret->addParam(op);
	}
	
	std::string st;
	ss >> st;
	if (!st.empty())
	{
		throw MIS_Exception("Too many parameters. DIV.\n");
	}
	
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
	
	OP_Param_Base* op = makeParam(ss);
	
	PARAM_TYPE t = op->getType();
	
	if (t == PARAM_TYPE::VAR_STR )
	{
		ret->addParam(op);	
	}
	else
		throw MIS_Exception("Invalid parameter. Parameter 1, SET_STR_CHAR.\n");
		
	op = makeParam(ss);
	t = op->getType();
	
	if (t == PARAM_TYPE::VAR_NUM ||
		t == PARAM_TYPE::NUMERIC )
	{
		ret->addParam(op);	
	}
	else
		throw MIS_Exception("Invalid parameter. Parameter 2, SET_STR_CHAR.\n");
		
		
	op = makeParam(ss);
	t = op->getType();
	
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
	
	OP_Param_Base* op = makeParam(ss);
	
	PARAM_TYPE t = op->getType();
	
	if (t == PARAM_TYPE::VAR_STR )
	{
		ret->addParam(op);	
	}
	else
		throw MIS_Exception("Invalid parameter. Parameter 1, SET_STR_CHAR.\n");
		
	op = makeParam(ss);
	t = op->getType();
	
	if (t == PARAM_TYPE::VAR_NUM ||
		t == PARAM_TYPE::NUMERIC )
	{
		ret->addParam(op);	
	}
	else
		throw MIS_Exception("Invalid parameter. Parameter 2, SET_STR_CHAR.\n");
		
		
	op = makeParam(ss);
	t = op->getType();
	
	if (t == PARAM_TYPE::VAR_CHAR )
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
	
	OP_Param_Base* op = makeParam(ss);
	
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
	
	OP_Param_Base* op = makeParam(ss);
	
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
	
	OP_Param_Base* op = makeParam(ss);
	
	PARAM_TYPE t = op->getType();
	
	if (t == PARAM_TYPE::STRING )
	{
		ret->addParam(op);
	}
	else
		throw MIS_Exception("Invalid parameter. Parameter 1, JMP(Z/NZ).\n");


	op = makeParam(ss);
	t = op->getType();
	
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
	
	OP_Param_Base* op = makeParam(ss);
	
	PARAM_TYPE t = op->getType();
	
	if (t == PARAM_TYPE::STRING )
	{
		ret->addParam(op);
	}
	else
		throw MIS_Exception("Invalid parameter. Parameter 1, JMP(GT/LT).\n");


	op = makeParam(ss);
	t = op->getType();
	
	if (t == PARAM_TYPE::NUMERIC ||
		t == PARAM_TYPE::VAR_NUM )
	{
		ret->addParam(op);
	}
	else
		throw MIS_Exception("Invalid parameter. Parameter 2, JMP(GT/LT).\n");
		
		
	op = makeParam(ss);
	t = op->getType();
	
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
	
	OP_Param_Base* op = makeParam(ss);
	
	PARAM_TYPE t = op->getType();
	
	if (t == PARAM_TYPE::STRING )
	{
		ret->addParam(op);
	}
	else
		throw MIS_Exception("Invalid parameter. Parameter 1, JMP(GT/LT).\n");


	op = makeParam(ss);
	t = op->getType();
	
	if (t == PARAM_TYPE::NUMERIC ||
		t == PARAM_TYPE::VAR_NUM )
	{
		ret->addParam(op);
	}
	else
		throw MIS_Exception("Invalid parameter. Parameter 2, JMP(GT/LT).\n");
		
		
	op = makeParam(ss);
	t = op->getType();
	
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
	
	mdata->labels[st] = mdata->PC;
	
	
	st.clear()
	ss >> st;
	if (!st.empty())
	{
		throw MIS_Exception("Too many parameters. LABEL.\n");
	}
	
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
					throw MIS_Exception("Invalid characters in variable name!\n");
			
				// CHECK IF VARIABLE EXISTS
			
			if (mdata->varNames.find(st) != std::map::end)
				throw MIS_Exception("Variable name is already in use!\n");
			
				// save variable name
			std::string varname = st;
			
			
	/////////////////////////////// parameter 2 ////////////
			
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
							
				// create the variable and v_param objects for the vectors
				//	and maps
			switch(st)
			{
				case "NUMERIC":
					std::shared_ptr<V_Param> vp(new V_Param<long long>(0,
												PARAM_TYPE::NUMERIC)
					std::shared_ptr<Variable> va(new Variable(index,
												PARAM_TYPE::VAR_NUM)
					mdata->variables.push_back(vp);
					
					
					
					
					
					
					break;
					
					
				case "REAL":
					std::shared_ptr<V_Param> vp(new V_Param(0.0,
												PARAM_TYPE::REAL)
					std::shared_ptr<Variable> va(new Variable(index,
												PARAM_TYPE::VAR_REAL)
					mdata->variables.push_back(vp);
					
					
					
					
					break;
					
					
				case "CHAR":
					std::shared_ptr<V_Param> vp(new V_Param('',
												PARAM_TYPE::CHAR)
					std::shared_ptr<Variable> va(new Variable(index,
												PARAM_TYPE::VAR_CHA)
					mdata->variables.push_back(vp);
					
					
					
					
					
					break;
					
					
				case "STRING":
					std::shared_ptr<V_Param> vp(new V_Param("",
												PARAM_TYPE::STRING)
					std::shared_ptr<Variable> va(new Variable(index,
												PARAM_TYPE::VAR_STR)
					mdata->variables.push_back(vp);
					
					
					
					
					
					
					break;
					
					
				default:
					throw MIS_Exception("Invalid variable type!\n");
			}
					
			
			
			
			
			
			
			
			
			mdata->labels[st] = mdata->PC;
			
			
			st.clear()
			ss >> st;
			if (!st.empty())
			{
				throw MIS_Exception("Too many parameters. LABEL.\n");
			}	
			
			
			
			
			
			
			
			
			
			
			
				
			
			opbp = new Variable<int>(index, t);
			return opbp;
		
		
}





int index = mdata->varNames.at(st);



