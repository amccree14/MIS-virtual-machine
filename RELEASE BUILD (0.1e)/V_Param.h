#ifndef H_V_PARAM
#define H_V_PARAM

/******************
* FILE: V_Params.h
* Author: Arthur Kung
* Date: Nov 2, 2016
*
* Details:
*	- The methods declared in this header file are
*		implemented in V_Param.cpp.
*
*	- This file contains the declaration and implementation
*		for the V_Param class template.
*
*	- This class is ONLY used to store the data elements of variables
*		in a vector to be accessed by the Variable class's getValue and
*		setValue functions.
******************/

#include <thread>
#include <mutex>
#include <iostream>
#include <condition_variable>

#include "OP_Param_Base.h"

	// note: non-virtual inheritance, because it's unnecessary
template <class A>
class V_Param: public OP_Param_Base
{
	private:
		A value;		// value stored within the param or variable
						//	- For param, it's an actual value
						//	- For variable, it's the variable index
		std::recursive_mutex m;
		std::mutex mlock;
		std::condition_variable_any cv;
		
	
	public:
		V_Param(A x, OP_TYPE t):OP_Param_Base(t),value(x){}
		
		void* getValue();			// return value
		void setValue(void*);		// this will set a value
		
			// mutex functions
		void lock(std::thread* id);
		void unlock(std::thread* id);
		
			// lock call counter, used during parse and during execute time
				//	parse - checks if there are extra locks/unlocks called
				//	execute - tracks recursive locking
		int lock_count = 0;
			// value for which thread currently has owns the mutex
		std::thread *lock_id = 0;
			// boolean for whether the mutex is locked or not
		bool is_locked = false;
};



template <class A>
void* V_Param<A>::getValue()			// return value
{
	return static_cast<void*>(&value);
}
		

template <class A>
void V_Param<A>::setValue(void* pt)		// stores dereferenced value
{
	value = *static_cast<A*>(pt);
}

template <class A>
void V_Param<A>::lock(std::thread* id)
{
	mlock.lock();
	//std::cout << "\t-lock stat: locked:" << is_locked << ", lock_id: "
	//			<< lock_id << ", given_id: " << id << std::endl;
	
	do
	{
		cv.wait(mlock, [&]{return !(is_locked && lock_id != id);});
	}while ((is_locked && lock_id != id));
	
	//std::cout << "\t-locked for locking" << std::endl;
		// if it's locked by this thread already, then lock it again
		//	and increment the total lock count
	if (is_locked && lock_id == id)
	{
		m.lock();
		++lock_count;
	}
		// otherwise, if it's not locked or isn't locked by this thread,
		//	simply call lock and increment the lock count. NOTE: this will
		//	only ever occur at lock_count == 0, because for it to be
		//	fully unlocked, lock_count MUST be equal to 0.
	else
	{
			// note: will block if called by thread that doesn't own the mutex
		m.lock();
		lock_id = id;
		++lock_count;
		is_locked = true;
	}
	
	//std::cout << "\t-unlocking for locking..." << std::endl;
	
	mlock.unlock();
}

template <class A>
void V_Param<A>::unlock(std::thread* id)
{
	std::lock_guard<std::mutex> lk(mlock);
		// if it's locked by this thread, decrement lock count (must be
		//	done prior to unlocking for consistency and guaranteeing that
		//	the decrement occurs in the critical section) and then unlock
	if (is_locked && lock_id == id)
	{
		//std::cout << "\t-unlocking variable-" << std::endl;
		--lock_count;
		
			// if we reach 0 lock counts, then mark the recursive mutex
			//	as fully unlocked
		if (lock_count == 0)
			is_locked = false;
		
		m.unlock();
	}
	
	cv.notify_all();
	//std::cout << "\t-notified of unlock" << std::endl;
	
		// otherwise, if the mutex is already unlocked or is not owned
		//	by the calling thread, ignore the unlock request.
}


#endif
