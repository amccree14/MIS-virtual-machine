#ifndef H_MIS_SYSTEM_DATA
#define H_MIS_SYSTEM_DATA

/******************
* FILE: MIS_System_Data.h
* Author: Arthur Kung
* Date: Nov 2, 2016
*
* Details:
*	- This is a under-consideration base class that contains all the 
*		'global' variables needed throughout the system.
******************/


#include <string>		// strings
#include <fstream>		// file i/o
#include <memory>		// shared_ptr
#include <vector>		// std vectors
#include <map>			// std maps
#include <stack>		// std stacks
#include <stdexcept>	// out_of_range exception
#include <mutex>
#include <string>

#include "labelLink.h"
#include "Command.h"
#include "Variable.h"
#include "V_Param.h"
#include "Threads.h"
#include "Command_DLL_Struct.h"

	//	In the future, the varNames map will need to be individually
	//		lockable for multi-threading. So will PC.
	//		In the former case, that means that the Param class will
	//		need some way of being marked as 'locked'.
	//		In the latter case, PC will need to be marked as 'locked'
	//		somehow, as well, which can be done WITHIN THIS CLASS.



class MIS_System_Data
{
	unsigned long long PC = 0;					// 'program counter' (xf: LC-3)
	
	public:
		std::vector<std::shared_ptr<Command>> commands;	// command vector
	
		std::map<std::string,int> labels;		// map of label indices by name
	
			// varNames is only used during 'compile' time, since afterwards
			//		the variable parameters will be stored directly by index
		std::map<std::string, int> varNames;	// map of var indices by name
		std::vector<std::shared_ptr<OP_Param_Base>> variables;// var data vector
		
		
			// to store all the labels that haven't been linked yet
		std::stack<std::shared_ptr<labelLink>> labelLinkStack;
			// to signify whether we've parsed all labels already or not
		bool l_parse = false;
		
		
		std::ofstream o_out;
		std::ofstream o_err;
		
		
		
			// these functions MAY be needed for future locking capabilities
		unsigned long long getPC(){return PC;}	// get the current PC
		void setPC(long long val){PC = val;}	// set the current PC
		
		
		
		
		/**** extra variables for phase 2: threading and networking ****/
		
		std::thread* clean = 0;
		std::mutex m;	// for controlling incrementing/assigning thread IDs
		
			// info for total # of threads made/running and their unique IDs
		unsigned int unique_thread_id = 0;
		std::stack<unsigned int> thread_id_stack;
		
		long long lock_count = 0;
		long long unlock_count = 0;
		
		Thread_Cleaner t_clean;
		
		std::vector<std::string> warnings;
		
		
		/***************************************************************/
		
};


class Unique_PC
{
	unsigned long long PC = 0;
	std::thread* curr_thread = 0;
	
	public:
		Unique_PC(unsigned long long nPC, std::thread* stp):
							PC(nPC),curr_thread(stp){}
		unsigned long long getPC(){return PC;}			// get the current PC
		void setPC(long long val){PC = val;}	// set the current PC
		std::thread* get_thread(){return curr_thread;}
};


	// This was originally in MIS_System.h, and explains the thoughts behind
	//		the creation of this storage class.

	// I considered making these static and using nested classes,
	//	but the entire thing was more annoying than I would've liked.
	//	I would've made a larger base class "System" to contain all
	//	the nested classes, then had this MIS_System inherit from it
	//	in order to deal with the inability to forward declare
	//	nested classes within the enclosing class. :/
	
	// NOTE: all the private member variables/containers will need to be
	//			passed to the other classes. Consider making them
	//			friend classes and making the w/ a constructor that
	//			takes a reference or pointer to these private member.
	//			For that reason, it may be worthwhile to 1) make
	//			the private members into their own class, 2) make
	//			the private members all global instead, or 3) create
	//			a global pointer to a struct that contains all the
	//			private members, and have the MIS_System initialize
	//			that global pointer after it creates the struct/private
	//			members.
	
	//			Alternatively, if we make EVERYTHING inherit from MIS_System,
	//			we can set all the private members to static, which will
	//			make it so that only one version of them will be propogated
	//			throughout all the child classes. This is a very feasible
	//			approach, but it creates an odd amount of overhead on each
	//			class, since they don't have too much in common, and the
	//			static members become universal for all instances of the
	//			system.
	
	//			Once again alternatively, we may be able to create a base
	//			class with static members that propogate throughout the
	//			inherited classes, but this becomes static for ALL versions
	//			of the system, which is undesirable.


#endif

