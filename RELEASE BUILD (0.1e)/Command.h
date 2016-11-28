#ifndef H_COMMAND
#define H_COMMAND

/******************
* FILE: Command.h
* Author: Arthur Kung
* Date: Nov 2, 2016
*
* Details:
*	- The methods declared in this header file are
*		implemented in Command_Param_Functions.cpp, Command_Parsers.cpp,
*		Command_Execute.cpp
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
#include <thread>

#include "MAXMIN_ENUM.h"		// enum lists for the parameter adding
#include "OP_Param_Base.h"

#include "MIS_System.h"	// for C_THREAD_BEGIN class
#include "MIS_System_Data.h"


class MIS_System_Data;
class Unique_PC;
class MIS_System;

class Command
{
		// protected member variables for inheritance to derived classes
	protected:
											// vector of operands for function
		std::vector<std::shared_ptr<OP_Param_Base>> oplist;
		
		MIS_System_Data* mdata;
											
	
	
	public:

		const unsigned int thread_id;	

		Command(MIS_System_Data* data, unsigned int thread):
						mdata(data), thread_id(thread) {} // basic constructor
													// sets mdata + thread_id
		
			// !! - These functions all throw exceptions if failures occur,
			//		so please use try-catch blocks around them
			
			// addParam will return PERROR values to denote whether
			//	we have enough parameters, too few, or too many.
			
			// addParam() is non-virtual, because it will work the same way
			//		no matter what. Consider making it static (check
			//		how that interacts with multiple objects).
			
		virtual void addParam(OP_Param_Base*);		// add another param to the oplist.
											//  Takes a pointer and converts it
											//	to a shared_ptr to be placed
											//	in the oplist vector.
		virtual OP_Param_Base* makeParam(std::stringstream&);
											// function in the class
											//	that parses a string and
											//	creates a parameter from it
	
		virtual int size(){return oplist.size();}		// function for # of parameters
		virtual unsigned int get_thread(){return thread_id;}	// get thread_id
		
		
			// calls op and passes it parameters
		virtual void execute(std::thread *ct, Unique_PC* pc)=0;
		
		virtual Command* parse(std::stringstream&)=0;
		
		
		
		virtual ~Command(){}
		
		
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
		C_ADD(MIS_System_Data* data, unsigned int thread):
											Command(data, thread){}
		virtual void execute(std::thread *ct, Unique_PC* pc);
		virtual Command* parse(std::stringstream& ss);
};
class C_SUB: public Command
{
	public:
		C_SUB(MIS_System_Data* data, unsigned int thread):
											Command(data, thread){}
		virtual void execute(std::thread *ct, Unique_PC* pc);
		virtual Command* parse(std::stringstream& ss);	
};
class C_MUL: public Command
{
	public:
		C_MUL(MIS_System_Data* data, unsigned int thread):
											Command(data, thread){}
		virtual void execute(std::thread *ct, Unique_PC* pc);
		virtual Command* parse(std::stringstream& ss);	
};
class C_DIV: public Command
{
	public:
		C_DIV(MIS_System_Data* data, unsigned int thread):
											Command(data, thread){}
		virtual void execute(std::thread *ct, Unique_PC* pc);
		virtual Command* parse(std::stringstream& ss);	
};
class C_ASSIGN: public Command
{
	public:
		C_ASSIGN(MIS_System_Data* data, unsigned int thread):
											Command(data, thread){}
		virtual void execute(std::thread *ct, Unique_PC* pc);
		virtual Command* parse(std::stringstream& ss);	
};
class C_OUT: public Command
{
	public:
		C_OUT(MIS_System_Data* data, unsigned int thread):
											Command(data, thread){}
		virtual void execute(std::thread *ct, Unique_PC* pc);
		virtual Command* parse(std::stringstream& ss);	
};
class C_SET_STR_CHAR: public Command
{
	public:
		C_SET_STR_CHAR(MIS_System_Data* data, unsigned int thread):
											Command(data, thread){}
		virtual void execute(std::thread *ct, Unique_PC* pc);
		virtual Command* parse(std::stringstream& ss);	
};
class C_GET_STR_CHAR: public Command
{
	public:
		C_GET_STR_CHAR(MIS_System_Data* data, unsigned int thread):
											Command(data, thread){}
		virtual void execute(std::thread *ct, Unique_PC* pc);
		virtual Command* parse(std::stringstream& ss);	
};
class C_LABEL: public Command
{
	public:
		C_LABEL(MIS_System_Data* data, unsigned int thread):
											Command(data, thread){}
		virtual void execute(std::thread *ct, Unique_PC* pc);
		virtual Command* parse(std::stringstream& ss);	
};
class C_SLEEP: public Command{
	public:
		C_SLEEP(MIS_System_Data* data, unsigned int thread):
											Command(data, thread){}
		virtual void execute(std::thread *ct, Unique_PC* pc);
		virtual Command* parse(std::stringstream& ss);	
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
	protected:
		bool side;		// used for zero/non-zero or gt/lt or gte/lte
	public:
		C_JMP(MIS_System_Data* data, unsigned int thread):
											Command(data, thread){}
		virtual void execute(std::thread *ct, Unique_PC* pc);
		virtual Command* parse(std::stringstream& ss);	
};
class C_JMP_ZNZ: public C_JMP
{
	public:
			// basic constructor to set the boolean
		C_JMP_ZNZ(MIS_System_Data* data, unsigned int thread, bool b):
											C_JMP(data, thread){side=b;}
		virtual void execute(std::thread *ct, Unique_PC* pc);
		virtual Command* parse(std::stringstream& ss);	
};
class C_JMP_GTLTE: public C_JMP
{
	public:
			// basic constructor to set the boolean
		C_JMP_GTLTE(MIS_System_Data* data, unsigned int thread, bool b):
											C_JMP(data, thread){side=b;}
		virtual void execute(std::thread *ct, Unique_PC* pc);
		virtual Command* parse(std::stringstream& ss);	
};
class C_JMP_GTELT: public C_JMP
{
	public:
			// basic constructor to set the boolean
		C_JMP_GTELT(MIS_System_Data* data, unsigned int thread, bool b):
											C_JMP(data, thread){side=b;}
		virtual void execute(std::thread *ct, Unique_PC* pc);
		virtual Command* parse(std::stringstream& ss);	
};


/*********/


	// VAR and LABEL are special in the sense that they do not
	//	actually require the thread_id information, nor do they persist
	//	after they finish running their parse commands. They have no real
	//	'execute' methods, and will indeed throw exceptions if their
	//	'execute' methods somehow get called.
	
class C_VAR: public Command
{
	public:
		C_VAR(MIS_System_Data* data, unsigned int thread):
											Command(data, thread){}
		virtual void execute(std::thread *ct, Unique_PC* pc);
		virtual Command* parse(std::stringstream& ss);	
};




/***************************/
/* New Section for Phase 2 */
/***************************/


class C_THREAD_BEGIN: public Command
{
	private:
		MIS_System *ms;
		unsigned int thread_exec;
	public:
		C_THREAD_BEGIN(MIS_System_Data* data, unsigned int thread, 
							MIS_System *_ms, unsigned int exec):
							Command(data, thread), ms(_ms),
							thread_exec(exec){}
		virtual void execute(std::thread *ct, Unique_PC* pc);
		virtual Command* parse(std::stringstream& ss);	
};

class C_THREAD_END: public Command
{
	public:
		C_THREAD_END(MIS_System_Data* data, unsigned int thread):
											Command(data, thread){}
		virtual void execute(std::thread *ct, Unique_PC* pc);
		virtual Command* parse(std::stringstream& ss);	
};

class C_LOCK: public Command
{
	public:
		C_LOCK(MIS_System_Data* data, unsigned int thread):
											Command(data, thread){}
		virtual void execute(std::thread *ct, Unique_PC* pc);
		virtual Command* parse(std::stringstream& ss);	
};

class C_UNLOCK: public Command
{
	public:
		C_UNLOCK(MIS_System_Data* data, unsigned int thread):
											Command(data, thread){}
		virtual void execute(std::thread *ct, Unique_PC* pc);
		virtual Command* parse(std::stringstream& ss);	
};

class C_BARRIER: public Command
{
	public:
		C_BARRIER(MIS_System_Data* data, unsigned int thread):
											Command(data, thread){}
		virtual void execute(std::thread *ct, Unique_PC* pc);
		virtual Command* parse(std::stringstream& ss);	
};






#endif



