#ifndef H_THREAD_CLEAN
#define H_THREAD_CLEAN


#include <mutex>
#include <thread>
#include <queue>
#include <condition_variable>

#define THREAD_MAXIMUM 4294967294
#define THREAD_TERMINATE 4294967295


	// our class wrapper for new threads
class ThreadID
{
	public:
		unsigned int i;
		std::thread* t;
		
		ThreadID(int _i, std::thread* _t):i(_i), t(_t){}
};

	// our object for collecting and cleaning up completed threads
class Thread_Cleaner
{
	private:
		std::mutex wait;
		std::mutex wait_barrier;
		std::queue<ThreadID> threads;
		std::condition_variable cv;
		std::condition_variable cv_barrier;
		
	public:
		bool mainDone = false;
		unsigned int tcount = 0;
	
		Thread_Cleaner() = default;
		
			// function for starting the cleaner thread
		void start();
		
			// function for incrementing the total thread count
		void addThread();
		
			// function for threads to use to signal that they are
			//	finished and ready to be cleaned up
		void markDone(std::thread* t, unsigned int i);
		
			// function for requesting this thread cleanup object
			//	to terminate itself once its queue is empty
		void finished();
		
			// function to barrier with
		void barrier();
			
};





#endif


