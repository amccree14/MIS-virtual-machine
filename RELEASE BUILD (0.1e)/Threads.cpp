/******************
* FILE: Threads.cpp
* Author: Arthur Kung
* Date: Nov 24, 2016
*
* Details:
*	- defines all the Thread_Cleaner class methods.
*
*	- NOTE: as with a couple of the other newer files, almost everything
*			commented with slashes (//) set against the far left of the
*			page is debugging code that I don't wish to delete.
******************/



#include <mutex>
#include <thread>
#include <queue>
#include <condition_variable>
#include <sstream>
#include <iostream>

#include "Threads.h"


/***************************
* Function: Thread_Cleaner::start()
* 
* Input: N/A
* Output: N/A
*
* Details:
*	- starts a thread cleaner. This MUST be started as a NEW THREAD
*		before any other threads are sent to it to be cleaned.
*
***************************/
void Thread_Cleaner::start()
{
	tcount = 0;
	while(true)
	{
		std::unique_lock<std::mutex> lk(wait);
		do
		{
			cv.wait(lk, [&]{return !threads.empty();});
		}while (threads.empty());
		
		do
		{
			ThreadID t = threads.front();
			
			
				// check for end of program when no threads are running
			if (tcount == 0 && mainDone)
			{
				//std::cout << "\tterminating cleanup thread" << std::endl;
				cv_barrier.notify_all();
				return;
			}
			
			
			if (t.t)
			{
// 				std::cout << "\treaping a thread, total: " << tcount << std::endl;
				std::lock_guard<std::mutex> lkb(wait_barrier);
// 	 			std::stringstream ss;
// 	 	
// 	 			ss << "\n\t\tdeleting thread #" << (threads.front()).i;
// 	 	
// 	 			std::string s = ss.str();
// 	 			
// 	 			std::cout << s << std::endl;
// 				std::cout << "\t\njoining... " << t.t << "\n";
				t.t->join();
// 				std::cout << "\t\njoined\n";
				threads.pop();
				--tcount;
				delete t.t;
				
				if (tcount == 0)
					cv_barrier.notify_all();
			}
			else
				threads.pop();
				
// 			std::cout << "\tthread stack: " << threads.size()
// 					<< " | tcount: " << tcount
// 					<< " | isDone: " << mainDone << std::endl;
					
			
				// check for end of program when threads are running
				//	and are actively being deleted
			if (tcount == 0 && mainDone)
			{
				//std::cout << "\tterminating cleanup thread" << std::endl;
				cv_barrier.notify_all();
				return;
			}
// 	 		if (!threads.empty())
// 	 		{
// 	 			t = threads.front();
// 	 			std::cout << "\tnext thread: " << t.t << " | " << t.i << std::endl;
// 	 		}
		}while (threads.size());
	}
}


/***************************
* Function: Thread_Cleaner:addThread
* 
* Input: N/A
* Output: N/A
*
* Details:
*	- increments a counter that tracks how many real threads
*		have been created and have not yet been destroyed.
*		Note that this is different from the number of threads in
*		queue to be destroyed, because the queue only holds threads
*		that have finished already, not threads that are still
*		running.
*
***************************/

void Thread_Cleaner::addThread()
{
	std::lock_guard<std::mutex> lk(wait);
	++tcount;
// 	std::cout << "\n\t\tTCOUNTADD: " << tcount << std::endl;
}


/***************************
* Function: Thread_Cleaner:markDone
* 
* Input: std::thread*, unsigned int
* Output: N/A
*
* Details:
*	- pushes a completed thread onto the cleanup stack and notifies
*		the cleaner thread that there's something to clean. The
*		unsigned int is basically only used for debugging purposes,
*		but it keeps track of which unique thread block in the written code
*		(not runtime) the dying thread was executing.
*
***************************/
void Thread_Cleaner::markDone(std::thread* t, unsigned int i)
{
	std::lock_guard<std::mutex> lk(wait);
	
	//std::cout << "\tthread done: " << t << " | " << i << std::endl;
	
	ThreadID tid(i,t);
	threads.push(tid);
	
	
	std::stringstream ss;
	
// 	ss << "\tadding thread ";
// 	if (i != THREAD_TERMINATE)
// 		ss << i << " to cleanup queue in position " << threads.size();
// 	else
// 		ss << "TERMINATION_FLAG " << i << " to cleanup queue.";
// 	
// 	std::string s = ss.str();
// 	std::cout << s << std::endl;
	
	
	cv.notify_all();
}


/***************************
* Function: Thread_Cleaner:finished
* 
* Input: N/A
* Output: N/A
*
* Details:
*	- signifies to the cleaner thread that it should finish up and then
*		return from its function. Basically causes the cleaner thread to
*		self-destruct and become ready for a join() call after it deletes
*		all other running threads. As long as a thread is still running,
*		it will still be added to the queue and destroyed before the
*		cleaner thread finishes.
*
***************************/
void Thread_Cleaner::finished()
{
    mainDone = true;
    markDone(0, THREAD_TERMINATE);	
}





/*****************************************
*
* DEPRECATED:
*
* Alternative approach to Barrier. Works to some degree,
*	but the final approach implemented in C_Barrier::execute()
*	is simpler and more reliable. Left here for posterity.
*
*
*****************************************/

void Thread_Cleaner::barrier()
{
// 	std::cout << "\n\t\tentering barrier" << tcount << "\n";
	std::unique_lock<std::mutex> lkb(wait_barrier);
	while (tcount != 0)
	{
		cv_barrier.wait(lkb, [&]{return (tcount==0);});
	}
		
// 	std::cout << "\n\t\t exiting barrier, tcount: " << tcount << std::endl;
}



