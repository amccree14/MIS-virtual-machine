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

#include "MIS_System.h"
#include "MIS_System_Data.h"
#include "MAXMIN_ENUM.h"		// NEED TO IMPLEMENT THESE
#include "OP_Param_Base.h"
#include "Params.h"
#include "Variable.h"
#include "V_Param.h"
#include "Command.h"
#include "MIS_Exception.h"
#include "helpers.h"
#include "Threads.h"


#include <iostream>	// for debugging
#include "z_dbg.h"	// for debugging


/*****************
*
* Function: C_ADD::parse()
*
*****************/
Command* C_ADD::parse(std::stringstream& ss)
{
	Command* ret = new C_ADD(mdata, mdata->thread_id_stack.top());
	
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
		
	while ((op = makeParam(ss)) && ret->size() <= MAXPARAM::ADD)
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
	
	if (ret->size() < MINPARAM::ADD)
		throw MIS_Exception("Too few parameters. ADD.\n");
	
	return ret;
}

/*****************
*
* Function: C_SUB::parse()
*
*****************/
Command* C_SUB::parse(std::stringstream& ss)
{
	Command* ret = new C_SUB(mdata, mdata->thread_id_stack.top());
	
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
		
	while ((op = makeParam(ss)) && ret->size() <= MAXPARAM::SUB)
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
	
	if (ret->size() < MINPARAM::SUB)
		throw MIS_Exception("Too few parameters. SUB.\n");
	
	return ret;
}

/*****************
*
* Function: C_MUL::parse()
*
*****************/
Command* C_MUL::parse(std::stringstream& ss)
{
	Command* ret = new C_MUL(mdata, mdata->thread_id_stack.top());
	
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
		
	while ((op = makeParam(ss)) && ret->size() <= MAXPARAM::MUL)
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
	
	if (ret->size() < MINPARAM::MUL)
		throw MIS_Exception("Too few parameters. MUL.\n");
	
	return ret;
}

/*****************
*
* Function: C_DIV::parse()
*
*****************/
Command* C_DIV::parse(std::stringstream& ss)
{
	Command* ret = new C_DIV(mdata, mdata->thread_id_stack.top());
	
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
		
	while ((op = makeParam(ss)) && ret->size() <= MAXPARAM::DIV)
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
	
	if (ret->size() < MINPARAM::DIV)
		throw MIS_Exception("Too few parameters. DIV.\n");
	
	return ret;
}

/*****************
*
* Function: C_ASSIGN::parse()
*
*****************/
Command* C_ASSIGN::parse(std::stringstream& ss)
{
	Command* ret = new C_ASSIGN(mdata, mdata->thread_id_stack.top());
	
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
		throw MIS_Exception("No assignment parameter found. ASSIGN.\n");
	
	std::string st;
	ss >> st;
	if (!st.empty())
	{
		throw MIS_Exception("Too many parameters. ASSIGN.\n");
	}
	
	if (ret->size() < MINPARAM::ASSIGN)
		throw MIS_Exception("Too few parameters. ASSIGN.\n");
	
	return ret;
}

/*****************
*
* Function: C_OUT::parse()
*
*****************/
Command* C_OUT::parse(std::stringstream& ss)
{
	//std::cout << "\n\t\t-new OUT- " << mdata->thread_id_stack.top() << "\n";
	Command* ret = new C_OUT(mdata, mdata->thread_id_stack.top());
	
	OP_Param_Base* op;
	
	if (!(op = makeParam(ss)))
		throw MIS_Exception("No parameters found. OUT.\n");
	
	PARAM_TYPE t = op->getType();
	
	ret->addParam(op);	

	while ((op = makeParam(ss)) && ret->size() <= MAXPARAM::OUT)
	{
		//std::cout << "loop | ";
		t = op->getType();

		ret->addParam(op);
	}
	
	std::string st;
	ss >> st;
	if (!st.empty())
	{
		throw MIS_Exception("Too many parameters. OUT.\n");
	}
	
	
	if (ret->size() < MINPARAM::OUT)
		throw MIS_Exception("Too few parameters. OUT.\n");
	
	return ret;
}

/*****************
*
* Function: C_SET_STR_CHAR::parse()
*
*****************/
Command* C_SET_STR_CHAR::parse(std::stringstream& ss)
{
	Command* ret = new C_SET_STR_CHAR(mdata, mdata->thread_id_stack.top());
	
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
	
	if (t == PARAM_TYPE::VAR_CHA ||
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
	
	if (ret->size() < MINPARAM::SET_STR_CHAR)
		throw MIS_Exception("Too few parameters. SET_STR_CHAR.\n");
	
	return ret;
}

/*****************
*
* Function: C_GET_STR_CHAR::parse()
*
*****************/
Command* C_GET_STR_CHAR::parse(std::stringstream& ss)
{
	Command* ret = new C_GET_STR_CHAR(mdata, mdata->thread_id_stack.top());
	
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
	
	if (t == PARAM_TYPE::VAR_CHA )
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
	
	if (ret->size() < MINPARAM::GET_STR_CHAR)
		throw MIS_Exception("Too few parameters. GET_STR_CHAR.\n");
	
	return ret;
}

/*****************
*
* Function: C_SLEEP::parse()
*
*****************/
Command* C_SLEEP::parse(std::stringstream& ss)
{
	Command* ret = new C_SLEEP(mdata, mdata->thread_id_stack.top());
	
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
	
	if (ret->size() < MINPARAM::SLEEP)
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
Command* C_JMP::parse(std::stringstream& ss)
{
	Command* ret = new C_JMP(mdata, mdata->thread_id_stack.top());
	
	OP_Param_Base* op;
	std::string label;
	long long index;
	
	fixSS(ss);
	std::string backup = ss.str();
	
		// try to get the first token from the stringstream
	try
	{
		label = getFirstToken(ss);
	}
	catch(MIS_Exception ex)
	{
		throw MIS_Exception("No label was specified for JMP!\n");
	}
	
		// if the acquired token has non-alphanumeric characters, then
		//	it can't be a label name
	if (!gapless(label))
		throw MIS_Exception("Invalid label name for JMP!\n");
	
	try
	{
		index = mdata->labels.at(label);
	}
	catch(std::out_of_range ex)
	{
			// if we've already generated every label, then....
		if (mdata->l_parse)
			throw MIS_Exception("Unable to find label \'"+ dbg::to_string(label)
								+ "\' to JMP to!\n");
			
			// othwersie, store a pointer to this JMP factor, the string to be
			//	parsed, and an index into the command vector for later linking	
		std::shared_ptr<labelLink> ll(new labelLink(static_cast<Command*>(this),
										backup, mdata->commands.size()));
		
		mdata->labelLinkStack.push(ll);
		return ret;
	}
	
	op = new Params<long long>(index, PARAM_TYPE::NUMERIC);
	ret->addParam(op);
	
	
		// check for potential infinite loops
	long long current;
	bool infloop = false;
	if (!(mdata->l_parse))
		current = mdata->commands.size();
	else
		current = mdata->labelLinkStack.top()->index;

	if (current > (index + 1))
		infloop = true;
				
	for (long long indcur = (index + 1); indcur < current; ++indcur)
	{
		if (dynamic_cast<C_JMP*>(mdata->commands[indcur].get()))
			infloop = false;
		else if (dynamic_cast<C_JMP_ZNZ*>(mdata->commands[indcur].get()))
			infloop = false;
		else if (dynamic_cast<C_JMP_GTLTE*>(mdata->commands[indcur].get()))
			infloop = false;
		else if (dynamic_cast<C_JMP_GTELT*>(mdata->commands[indcur].get()))
			infloop = false;
	}
	
	if (infloop == true)
	{
		std::string s("Potential infinite loop detected!\n");
		mdata->warnings.push_back(s);
	}
		
		
	
		// check if JMP is pointing to a valid thread index
		//	NOTE: remember that the label index value is always pointing
		//			to the line BEFORE the command it will execute, because
		//			the run loop always increments the PC immediately
		//			after the JMP sets it to a label. Therefore, we need
		//			to check index+1, not index (which can be -1 if the
		//			label is on the first line).
	if (mdata->commands[index + 1]->get_thread() != ret->get_thread())
	{
// 		std::cout << "Index: " << index << " | ids: "
// 					<< mdata->commands[index]->get_thread() << ", "
// 					<< ret->get_thread() << std::endl;
		throw MIS_Exception("Attempting to JMP out of thread's scope!\n");
	}
		
		
	std::string st;
	ss >> st;
	if (!st.empty())
	{
		throw MIS_Exception("Too many parameters. JMP.\n");
	}
	
	if (ret->size() < MINPARAM::JMP)
		throw MIS_Exception("Too few parameters. JMP.\n");
	
	return ret;
}

/*****************
*
* Function: C_JMP_ZNZ::parse()
*
*****************/
Command* C_JMP_ZNZ::parse(std::stringstream& ss)
{
	Command* ret = new C_JMP_ZNZ(mdata, mdata->thread_id_stack.top(), side);
	
	PARAM_TYPE t;
	OP_Param_Base* op;
	std::string label;
	long long index;
	
	fixSS(ss);
	std::string backup = ss.str();
	
		// try to get the first token from the stringstream
	try
	{
		label = getFirstToken(ss);
	}
	catch(MIS_Exception ex)
	{
		throw MIS_Exception("No label was specified for JMP(Z/NZ)!\n");
	}
	
		// if the acquired token has non-alphanumeric characters, then
		//	it can't be a label name
	if (!gapless(label))
		throw MIS_Exception("Invalid label name for JMP(Z/NZ)!\n");
	
	try
	{
		index = mdata->labels.at(label);
	}
	catch(std::out_of_range ex)
	{
			// if we've already generated every label, then....
		if (mdata->l_parse)
			throw MIS_Exception("Unable to find label \'"+ dbg::to_string(label)
								+ "\' to JMP(Z/NZ) to!\n");
			
			// othwersie, store a pointer to this JMP factor, the string to be
			//	parsed, and an index into the command vector for later linking	
		std::shared_ptr<labelLink> ll(new labelLink(static_cast<Command*>(this),
										backup, mdata->commands.size() - 1));
		
		mdata->labelLinkStack.push(ll);
		return ret;
	}
	
	op = new Params<long long>(index, PARAM_TYPE::NUMERIC);
	ret->addParam(op);

		// check if JMP is pointing to a valid thread index
	if (mdata->commands[index+1]->get_thread() != ret->get_thread())
	{
		throw MIS_Exception("Attempting to JMP out of thread's scope!\n");
	}
	

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
	
	if (ret->size() < MINPARAM::JMP_ZNZ)
		throw MIS_Exception("Too few parameters. JMP(Z/NZ).\n");
	
	return ret;
}

/*****************
*
* Function: C_JMP_GTLTE::parse()
*
*****************/
Command* C_JMP_GTLTE::parse(std::stringstream& ss)
{
	Command* ret = new C_JMP_GTLTE(mdata, mdata->thread_id_stack.top(), side);
	
	PARAM_TYPE t;
	OP_Param_Base* op;
	std::string label;
	long long index;
	
	fixSS(ss);
	std::string backup = ss.str();
	
		// try to get the first token from the stringstream
	try
	{
		label = getFirstToken(ss);
	}
	catch(MIS_Exception ex)
	{
		throw MIS_Exception("No label was specified for JMP(GT/LTE)!\n");
	}
	
		// if the acquired token has non-alphanumeric characters, then
		//	it can't be a label name
	if (!gapless(label))
		throw MIS_Exception("Invalid label name for JMP(GT/LTE)!\n");
	
	try
	{
		index = mdata->labels.at(label);
	}
	catch(std::out_of_range ex)
	{
			// if we've already generated every label, then....
		if (mdata->l_parse)
			throw MIS_Exception("Unable to find label \'"+ dbg::to_string(label)
								+ "\' to JMP(GT/LTE) to!\n");
			
			// othwersie, store a pointer to this JMP factor, the string to be
			//	parsed, and an index into the command vector for later linking	
		std::shared_ptr<labelLink> ll(new labelLink(static_cast<Command*>(this),
										backup, mdata->commands.size() - 1));
		
		mdata->labelLinkStack.push(ll);
		return ret;
	}
	
	op = new Params<long long>(index, PARAM_TYPE::NUMERIC);
	ret->addParam(op);
	
		// check if JMP is pointing to a valid thread index
	if (mdata->commands[index+1]->get_thread() != ret->get_thread())
	{
		throw MIS_Exception("Attempting to JMP out of thread's scope!\n");
	}

	
	if (op = makeParam(ss))
		t = op->getType();
	else
		throw MIS_Exception("Parameter not found. Parameter 2,"
							" JMP(GT/LTE).\n");
	
	if (t == PARAM_TYPE::NUMERIC ||
		t == PARAM_TYPE::VAR_NUM )
	{
		ret->addParam(op);
	}
	else
		throw MIS_Exception("Invalid parameter. Parameter 2, JMP(GT/LTE).\n");
		
		
	if (op = makeParam(ss))
		t = op->getType();
	else
		throw MIS_Exception("Parameter not found. Parameter 3,"
							" JMP(GT/LTE).\n");
	
	if (t == PARAM_TYPE::NUMERIC ||
		t == PARAM_TYPE::VAR_NUM )
	{
		ret->addParam(op);
	}
	else
		throw MIS_Exception("Invalid parameter. Parameter 3, JMP(GT/LTE).\n");
	
	
	std::string st;
	ss >> st;
	if (!st.empty())
	{
		throw MIS_Exception("Too many parameters. JMP(GT/LTE).\n");
	}
	
	if (ret->size() < MINPARAM::JMP_GTLT)
		throw MIS_Exception("Too few parameters. JMP(GT/LTE).\n");
	
	return ret;
}

/*****************
*
* Function: C_JMP_GTELT::parse()
*
*****************/
Command* C_JMP_GTELT::parse(std::stringstream& ss)
{
	Command* ret = new C_JMP_GTELT(mdata, mdata->thread_id_stack.top(), side);
	
	PARAM_TYPE t;
	OP_Param_Base* op;
	std::string label;
	long long index;
	
	fixSS(ss);
	std::string backup = ss.str();
	
		// try to get the first token from the stringstream
	try
	{
		label = getFirstToken(ss);
	}
	catch(MIS_Exception ex)
	{
		throw MIS_Exception("No label was specified for JMP(GTE/LT)!\n");
	}
	
		// if the acquired token has non-alphanumeric characters, then
		//	it can't be a label name
	if (!gapless(label))
		throw MIS_Exception("Invalid label name for JMP(GTE/LT)!\n");
	
	try
	{
		index = mdata->labels.at(label);
	}
	catch(std::out_of_range ex)
	{
			// if we've already generated every label, then....
		if (mdata->l_parse)
			throw MIS_Exception("Unable to find label \'"+ dbg::to_string(label)
								+ "\' to JMP(GTE/LT) to!\n");
			
			// othwersie, store a pointer to this JMP factor, the string to be
			//	parsed, and an index into the command vector for later linking	
		std::shared_ptr<labelLink> ll(new labelLink(static_cast<Command*>(this),
										backup, mdata->commands.size() - 1));
		
		mdata->labelLinkStack.push(ll);
		return ret;
	}
	
	op = new Params<long long>(index, PARAM_TYPE::NUMERIC);
	ret->addParam(op);

		// check if JMP is pointing to a valid thread index
	if (mdata->commands[index+1]->get_thread() != ret->get_thread())
	{
		throw MIS_Exception("Attempting to JMP out of thread's scope!\n");
	}

	
	if (op = makeParam(ss))
		t = op->getType();
	else
		throw MIS_Exception("Parameter not found. Parameter 2,"
							" JMP(GTE/LT).\n");
	
	if (t == PARAM_TYPE::NUMERIC ||
		t == PARAM_TYPE::VAR_NUM )
	{
		ret->addParam(op);
	}
	else
		throw MIS_Exception("Invalid parameter. Parameter 2, JMP(GTE/LT).\n");
		
		
	if (op = makeParam(ss))
		t = op->getType();
	else
		throw MIS_Exception("Parameter not found. Parameter 3,"
							" JMP(GTE/LT).\n");
	
	if (t == PARAM_TYPE::NUMERIC ||
		t == PARAM_TYPE::VAR_NUM )
	{
		ret->addParam(op);
	}
	else
		throw MIS_Exception("Invalid parameter. Parameter 3, JMP(GTE/LT).\n");
	
	
	std::string st;
	ss >> st;
	if (!st.empty())
	{
		throw MIS_Exception("Too many parameters. JMP(GTE/LT).\n");
	}
	
	if (ret->size() < MINPARAM::JMP_GTLT)
		throw MIS_Exception("Too few parameters. JMP(GTE/LT).\n");
	
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
Command* C_LABEL::parse(std::stringstream& ss)
{
	Command* ret = nullptr;
	std::string st;
	st.clear();
	
		// get first full token (no whitespace)		
	try
	{
		st = getFirstToken(ss);
	}
	catch(MIS_Exception ex)
	{
		throw MIS_Exception("No name was passed for the LABEL!\n");
	}

		// check for non-alphanumeric characters in label name
	if (!gapless(st))
		throw MIS_Exception("Invalid label!\n");

		// if label exists
	if (mdata->labels.find(st) != mdata->labels.end())
	{
			// if label has an index into the command vector...
		if (mdata->labels[st] >= 0)
			throw MIS_Exception("Label already exists!\n");
	}
	
		// otherwise, if the label doesn't exist or has not
		//	been initialized to a value (this happens when
		//	JMP has requested a label but the label is declared
		//	later in the code), initialize the label and store the
		//	index of the next command in it.
	mdata->labels[st] = mdata->commands.size() - 1;
	
	
	st.clear();
	ss >> st;
	if (!st.empty())
	{
		throw MIS_Exception("Invalid syntax/parameters. LABEL.\n");
	}
	
	return ret;	
}

/*****************
*
* Function: C_VAR::parse()
*
*****************/
Command* C_VAR::parse(std::stringstream& ss)
{
	//std::cout << "\n\tENTERING C_VAR::parse()\n\n";
	
	Command* ret = nullptr;
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
		
		if (ss.peek() == '$')
		{
			ss.get();
			st.clear();
			std::getline(ss, st, ',');
			
				// remove trailing whitespace
			noWhiteEndString(st);
			
				// check for non-alphanumeric characters		
			if (!(gapless(st)))
				throw MIS_Exception("Invalid characters in variable "
										"name!\n");
			
				// CHECK IF VARIABLE EXISTS
			if (st.empty())
				throw MIS_Exception("No variable name was passed!\n");
			
			if (mdata->varNames.find(st) != mdata->varNames.end())
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
			if (st == "NUMERIC")
			{
					std::shared_ptr<OP_Param_Base> vp(new V_Param<long long>(0,
												PARAM_TYPE::NUMERIC));
					std::shared_ptr<Variable> va(new Variable(index,
												PARAM_TYPE::VAR_NUM, mdata));
					mdata->variables.push_back(vp);		// store variable data
					mdata->varNames[varname] = index;	// store variable index
					
					
					
					
					
					OP_Param_Base* op1, * op2;
					
					op1 = makeParam(ss);
						//showType(op1);
					if (op2 = makeParam(ss))
					{
							//showType(op2);
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
					
					
			}
			else if (st == "REAL")
			{
					std::shared_ptr<OP_Param_Base> vp(new V_Param<double>(0.0,
												PARAM_TYPE::REAL));
					std::shared_ptr<Variable> va(new Variable(index,
												PARAM_TYPE::VAR_REA, mdata));
					mdata->variables.push_back(vp);		// store variable data
					mdata->varNames[varname] = index;	// store variable index
					
					
					
					OP_Param_Base* op1, * op2;
					
					op1 = makeParam(ss);
						//showType(op1);
					if (op2 = makeParam(ss))
					{
							//showType(op2);
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
					
					
			}
			else if (st == "CHAR")
			{
					std::shared_ptr<OP_Param_Base> vp(new V_Param<char>('\0',
												PARAM_TYPE::CHAR));
					std::shared_ptr<Variable> va(new Variable(index,
												PARAM_TYPE::VAR_CHA, mdata));
					mdata->variables.push_back(vp);		// store variable data
					mdata->varNames[varname] = index;	// store variable index		
					
					

					OP_Param_Base* op1, * op2;
					
					op1 = makeParam(ss);
						//showType(op1);
					if (op2 = makeParam(ss))
					{
							//showType(op2);
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
								
					
			}
			else if (st == "STRING")
			{
				//std::cout << "\n\tENTERED STRING\n\n";
					std::shared_ptr<OP_Param_Base> vp(new V_Param<std::string>
												("", PARAM_TYPE::STRING));
					std::shared_ptr<Variable> va(new Variable(index,
												PARAM_TYPE::VAR_STR, mdata));
					mdata->variables.push_back(vp);		// store variable data
					mdata->varNames[varname] = index;	// store variable index			

					
					
					OP_Param_Base* op1, * op2;
					
					op1 = makeParam(ss);
						//showType(op1);
					if (op2 = makeParam(ss))
					{
							//showType(op2);
						if (makeParam(ss))
							throw MIS_Exception("Invalid (too many) parameters"
												" for VAR!\n");
						if (op1->getType() != PARAM_TYPE::NUMERIC ||
							op2->getType() != PARAM_TYPE::STRING )
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
					
										
			}
			else
				throw MIS_Exception("Invalid variable type!\n");
					
			
		}
		else
			throw MIS_Exception("Variable name must be prefixed with $!\n");
			
	}
	else
		throw MIS_Exception("Invalid variable parameters!\n");
		

	return ret;		
}




/*************************************/
/*
/*
/* NEW METHODS FOR PHASE TWO
/*
/*
/*************************************/


Command* C_THREAD_BEGIN::parse(std::stringstream& ss)
{
	unsigned int temp = mdata->thread_id_stack.top();
	++(mdata->unique_thread_id);
	
	//std::cout << "\t-PARSING THREAD START- " << temp << ", "
	//			<< mdata->unique_thread_id << "| pre-stack: "
	//			<< mdata->thread_id_stack.size() << std::endl;
	Command* ret = new C_THREAD_BEGIN(mdata, temp, ms, (mdata->unique_thread_id));
	
	if (mdata->unique_thread_id == THREAD_MAXIMUM)
		throw MIS_Exception("Attempting to create too many unique threads.\n");
	
	mdata->thread_id_stack.push((mdata->unique_thread_id));
	
	return ret;
}

Command* C_THREAD_END::parse(std::stringstream& ss)
{
	if (mdata->thread_id_stack.size() <= 0)
		throw MIS_Exception("Attempting to kill thread that wasn't created.\n");
		
	Command* ret = new C_THREAD_END(mdata, mdata->thread_id_stack.top());
	
	mdata->thread_id_stack.pop();
		
	return ret;
}

Command* C_LOCK::parse(std::stringstream& ss)
{
	Command* ret = new C_LOCK(mdata, (mdata->thread_id_stack.top()));
	
	OP_Param_Base* op;
	
	if (!(op = makeParam(ss)))
		throw MIS_Exception("No parameters found. LOCK.\n");
	
	PARAM_TYPE t = op->getType();
	
	if (t == PARAM_TYPE::VAR_REA ||
		t == PARAM_TYPE::VAR_NUM ||
		t == PARAM_TYPE::VAR_CHA ||
		t == PARAM_TYPE::VAR_STR)
	{
		ret->addParam(op);	
	}
	else
		throw MIS_Exception("Invalid parameter. Parameter 1, LOCK.\n");
		
	std::string st;
	ss >> st;
	if (!st.empty())
	{
		throw MIS_Exception("Too many parameters. LOCK.\n");
	}
	
		
	++(mdata->lock_count);	// increment overall lock counter	
		
		
	return ret;	
	
}

Command* C_UNLOCK::parse(std::stringstream& ss)
{
	Command* ret = new C_UNLOCK(mdata, mdata->thread_id_stack.top());
	
	OP_Param_Base* op;
	
	if (!(op = makeParam(ss)))
		throw MIS_Exception("No parameters found. UNLOCK.\n");
	
	PARAM_TYPE t = op->getType();
	
	if (t == PARAM_TYPE::VAR_REA ||
		t == PARAM_TYPE::VAR_NUM ||
		t == PARAM_TYPE::VAR_CHA ||
		t == PARAM_TYPE::VAR_STR)
	{
		ret->addParam(op);	
	}
	else
		throw MIS_Exception("Invalid parameter. Parameter 1, UNLOCK.\n");
		
	std::string st;
	ss >> st;
	if (!st.empty())
	{
		throw MIS_Exception("Too many parameters. UNLOCK.\n");
	}
	
		
	++(mdata->unlock_count);	// decrement overall lock counter	
		
		
	return ret;	
}



Command* C_BARRIER::parse(std::stringstream& ss)
{	
	if (mdata->thread_id_stack.top() != 0)
		throw MIS_Exception("BARRIER can only be invoked from main thread.\n");

	Command* ret = new C_BARRIER(mdata, mdata->thread_id_stack.top());
				
	return ret;
}



