#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <chrono>

std::mutex mu;

void shared_cout(std::string msg, int id)
{
	{
		//Using lock_guard automatically unlocks the mutex again when it goes out of scope. That makes it impossible to forget to unlock it
		std::lock_guard<std::mutex> lock(mu);
		//mu.lock();
		std::cout << msg << ":" << id << std::endl;
		//mu.unlock();
	}
	
	//Sleeping allows the other thread to wait on mutex. However it DOES NOT ensure the other thread will always come first.
	//It is said mutex does NOT ensure fairness.
	////////////////////////
	//From Stackoverflow: Because your first thread locks mutex, sleeps, unlocks mutex and then tries to lock mutex again.
	//Now thread 1 and thread 2 are both trying to acquire mutex, but thread 1 is in running state, while thread 2 is sleeping,
	//so it is much more likely that thread 1 will acquire mutex first.
	////////////////////////////////////////
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
}
void thread_function()
{
	for (int i = -10; i < 0; i++)
		shared_cout("thread function", i);
}

int main()
{
	std::thread t(&thread_function);
	for (int i = 10; i > 0; i--)
	    shared_cout("main thread", i);
	t.join();
	return 0;
}
