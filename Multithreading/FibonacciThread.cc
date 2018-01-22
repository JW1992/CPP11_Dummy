#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
#include <vector>
#include <condition_variable>

class Fibonacci{
private:
	static const int MAX_INDEX = 100;

	std::vector<unsigned int> values;
	void PreCalc();
	bool optim;
	std::mutex mx_;
	std::condition_variable cond_;
	std::thread tCalc_;
public:
	Fibonacci(bool bOpt);
	~Fibonacci(){
		//tCalc_.interrupt();
    	tCalc_.join();
	};
	
	unsigned int Get(unsigned int index);
	unsigned int GetValue(unsigned int index);
};

Fibonacci::Fibonacci(bool bOpt){
	values.reserve(MAX_INDEX);
	optim = bOpt;
	tCalc_ = std::thread(&Fibonacci::PreCalc, this);
}

unsigned int Fibonacci::Get(unsigned int index)
{
    if(index < 0 || index > MAX_INDEX)
        return 0;


    std::lock_guard<std::mutex> lock(mx_);
    while(index >= values.size())
    {
        std::cout << "Please wait ..." << std::endl;
        cond_.wait(mx_);
    }
    return values.at(index);
    
    //return GetValue(index);
}

void Fibonacci::PreCalc(){
	for(int iteration = 0; iteration <= MAX_INDEX; ++iteration)
    {
        unsigned int value = GetValue(iteration);
        
        std::lock_guard<std::mutex> lock(mx_);
        values.push_back(value);
        cond_.notify_one();
        
    }
}

unsigned int Fibonacci::GetValue(unsigned int index)
{
    
    if(optim)
    {
        std::lock_guard<std::mutex> lock(mx_);
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
	
	
	Fibonacci fib = new Fibonacci(false);
	std::cout<<fib.GetValue(3)<<std::endl;
	
	return 0;
}
