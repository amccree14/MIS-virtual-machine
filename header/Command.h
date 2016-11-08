#ifndef H_COMMAND
#define H_COMMAND

/******************
* FILE: Command.h
* Author: Arthur Kung
* Date: Nov 2, 2016
*
* Details:
*	- The methods declared in this header file are
*		implemented in Command.cpp and Command_addParam.cpp.
*
*	- This file contains the declaration for the Command class, as well
*		as includes the header for all of the functions to be executed within
*		the command class.
*
*		The Command class contains a function pointer that points to
*		whichever function it is supposed to execute, as well as a vector
*		of whatever operands it is supposed to process.
*
*		The vector and function pointer are initialized during the parsing
*		phase of the MIS_System.
******************/

#include <vector>
#include <string>
#include <sstream>
#include <memory>	// shared_ptr

#include "MIS_System_Data.h"	// all the necessary data members
#include "OP_System_Data.h"
#include "MAXMIN_ENUM.h"		// enum lists for the parameter adding


class Command
{
		// protected member variables for inheritance to derived classes
	protected:
											// vector of operands for function
		std::vector<std::shared_ptr<OP_Param_Base>> oplist;
		
		OP_System_Data* mdata;
		
		int max_size = 0;
											
	
	
	public:
		Command(OP_System_Data* data):mdata(data){}		// basic constructor
														// sets mdata pointer
		
			// !! - These functions all throw exceptions if failures occur,
			//		so please use try-catch blocks around them
			
			// addParam will return PERROR values to denote whether
			//	we have enough parameters, too few, or too many.
			
			// addParam() is non-virtual, because it will work the same way
			//		no matter what. Consider making it static (check
			//		how that interacts with multiple objects).
			
		void addParam(OP_Param_Base*);		// add another param to the oplist.
											//  Takes a pointer and converts it
											//	to a shared_ptr to be placed
											//	in the oplist vector.
		static OP_Param_Base* makeParam(std::stringstream);
											// static function in the class
											//	that parses a string and
											//	creates a parameter from it
		
		
		virtual void execute();			// calls op and passes it parameters
		
		virtual Command* parse(std::stringstream);
		
		
		// ~Command destructor will only be needed if vectors do not clean
		//		themselves up when they exit scope. If they do NOT, then all we
		//		need to do is 'while(oplist.pop())', and it will clean it up.
		//	Since we're using shared pointers in the vector, and vectors
		//		call the destructors of all their elements when they exit
		//		scope, we should be fine with the default destructor.
		
		

};





	// All the child classes, one for each opcode. They each have their
	//	own specialized execution call and their own specialized parameter
	//	parser.
	
	// Most of these classes have a basic constructor that mirrors the
	//	base-class constructor and just passes the parameters through to it.
	//	The JMP classes are a special case, because they also require a bool
	//	value.
	
	// These need to be put into a std::map.


class C_ADD: public Command
{
	public:
		C_ADD(OP_System_Data* data):Command(data){}
		execute();
		Command* parse(std:stringstream ss);	
};
class C_SUB: public Command
{
	public:
		C_SUB(OP_System_Data* data):Command(data){}
		execute();
		Command* parse(std:stringstream ss);	
};
class C_MUL: public Command
{
	public:
		C_MUL(OP_System_Data* data):Command(data){}
		execute();
		Command* parse(std:stringstream ss);	
};
class C_DIV: public Command
{
	public:
		C_DIV(OP_System_Data* data):Command(data){}
		execute();
		Command* parse(std:stringstream ss);	
};
class C_ASSIGN: public Command
{
	public:
		C_ASSIGN(OP_System_Data* data):Command(data){}
		execute();
		Command* parse(std:stringstream ss);	
};
class C_OUT: public Command
{
	public:
		C_OUT(OP_System_Data* data):Command(data){}
		execute();
		Command* parse(std:stringstream ss);	
};
class C_SET_STR_CHAR: public Command
{
	public:
		C_SET_STR_CHAR(OP_System_Data* data):Command(data){}
		execute();
		Command* parse(std:stringstream ss);	
};
class C_GET_STR_CHAR: public Command
{
	public:
		C_GET_STR_CHAR(OP_System_Data* data):Command(data){}
		execute();
		Command* parse(std:stringstream ss);	
};
class C_LABEL: public Command
{
	public:
		C_LABEL(OP_System_Data* data):Command(data){}
		execute();
		Command* parse(std:stringstream ss);	
};
class C_SLEEP: public Command{
	public:
		C_SLEEP(OP_System_Data* data):Command(data){}
		execute();
		Command* parse(std:stringstream ss);	
};


/*********/


	// The problem with JMP is that the overall parser can find JMP
	//	and call it out of the object factory, but JMP(Z/NZ) and
	//	JMP(GT/LT/GTE/LTE) can NOT be so easily pulled from the factory.
	
	// Our solution is to declare every combination (JMPZ, JMPNZ, JMPGT, etc.)
	//	in the object factory map, but to make every pair of them create the
	//	same classes with different boolean markers. Notably, this works because
	//	> is the same as the opposite of <=, etc., and Z is the opposite of NZ.
class C_JMP: public Command
{
	private:
		bool side;		// used for zero/non-zero or gt/lt or gte/lte
	public:
		C_JMP(OP_System_Data* data):Command(data){}
		execute();
		Command* parse(std:stringstream ss);	
};
class C_JMP_ZNZ: public C_JMP
{
	public:
			// basic constructor to set the boolean
		C_JMP_ZNZ(OP_System_Data* data, bool b):C_JMP(data), side(b){}
		execute();
		Command* parse(std:stringstream ss);	
};
class C_JMP_GTLTE: public C_JMP
{
	public:
			// basic constructor to set the boolean
		C_JMP_GTLTE(OP_System_Data* data, bool b):C_JMP(data), side(b){}
		execute();
		Command* parse(std:stringstream ss);	
};
class C_JMP_GTELT: public C_JMP
{
	public:
			// basic constructor to set the boolean
		C_JMP_GTELT(OP_System_Data* data, bool b):C_JMP(data), side(b){}
		execute();
		Command* parse(std:stringstream ss);	
};


/*********/


class C_VAR: public Command
{
	public:
		C_VAR(OP_System_Data* data):Command(data){}
		execute();
		Command* parse(std:stringstream ss);	
};
































#endif

