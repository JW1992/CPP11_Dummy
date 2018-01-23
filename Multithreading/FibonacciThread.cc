#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
#include <vector>
#include <condition_variable>

class Fibonacci{
private:

	std::vector<unsigned int> values;
	void PreCalc();
	bool optim;
	std::mutex mx_;
	std::condition_variable cond_;
	std::thread tCalc_;
public:
	static const int MAX_INDEX = 40;
	Fibonacci(bool bOpt);
	~Fibonacci(){
    	tCalc_.join();
	};
	
	unsigned int Get(unsigned int index);
	unsigned int GetValue(unsigned int index);
};

Fibonacci::Fibonacci(bool bOpt){
	values.reserve(MAX_INDEX);
	optim = bOpt;
	//Starting a MEMBER function in another thread
	//Note: the called thread starts running here. join() is only telling the main function to wait for the thread to finish!
	tCalc_ = std::thread(&Fibonacci::PreCalc, this);
}

unsigned int Fibonacci::Get(unsigned int index)
{
    if(index < 0 || index > MAX_INDEX)
        return 0;

	//Declare a unique_lock object and lock the mutex object.
	//Block the thread if the lock is owned by other threads.
    std::unique_lock<std::mutex> lock(mx_);
    while(index >= values.size())
    {
        std::cout << "Please wait ..." << std::endl;
        cond_.wait(lock);
    }
    return values.at(index);
}

void Fibonacci::PreCalc(){
	for(int iteration = 0; iteration <= MAX_INDEX; ++iteration)
    {
        unsigned int value = GetValue(iteration);
        
        //Declare a unique_lock object and lock the mutex object.
		//Block the thread if the lock is owned by other threads.
        std::unique_lock<std::mutex> lock(mx_);
        values.push_back(value);
        cond_.notify_one();
    }
}

unsigned int Fibonacci::GetValue(unsigned int index)
{
    
    if(optim)
    {
        std::unique_lock<std::mutex> lock(mx_);
        if(index < values.size())
            return values.at(index);
    }
    
    
    switch(index)
    {
    case 0:
        return 0;
    case 1:
        return 1;
    default:
        //std::this_thread.interruption_point();
        return GetValue(index - 2) + GetValue(index - 1);
    }
}

int main(){
	
	auto start = std::chrono::high_resolution_clock::now();

	Fibonacci* fib = new Fibonacci(true);
//	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "Fibonacci of " << 40 << " is "
            << fib->Get(40) << std::endl;
	
	auto finish = std::chrono::high_resolution_clock::now();
	
	std::chrono::duration<double> elapsed = finish - start;
	std::cout<<"Elapsed time "<< elapsed.count() << "S" <<std::endl;
	
	int input;
    while(true)
    {
        std::cout << "Your input [0 .. "
            << Fibonacci::MAX_INDEX << "]: ";
        std::cin >> input;
        if(input < 0 || input > Fibonacci::MAX_INDEX)
            break;
        std::cout << "Fibonacci of " << input << " is "
            << fib->Get(input) << std::endl;
    }
    std::cout << "Bye" << std::endl;
	
	delete fib;
	
	return 0;
}
