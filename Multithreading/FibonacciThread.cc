#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

class Fibonacci{
private:
	static const int MAX_INDEX = 100;

	std::vector<unsigned int> values;
	void PreCalc();
	bool optim;
public:
	Fibonacci(bool bOpt);
	~Fibonacci(){};
	
	unsigned int Get(unsigned int index);
	unsigned int GetValue(unsigned int index);
};

Fibonacci::Fibonacci(bool bOpt){
	values.reserve(MAX_INDEX);
	optim = bOpt;
}

unsigned int Fibonacci::Get(unsigned int index)
{
    if(index < 0 || index > MAX_INDEX)
        return 0;

/*
    boost::lock_guard<boost::mutex> lock(mx_);
    while(index >= values_.size())
    {
        std::cout << "Please wait ..." << std::endl;
        cond_.wait(mx_);
    }
    return values_.at(index);
    */
    return GetValue(index);
}

void Fibonacci::PreCalc(){
	for(int iteration = 0; iteration <= MAX_INDEX; ++iteration)
    {
        unsigned int value = GetValue(iteration);
        /*
        boost::lock_guard<boost::mutex> lock(mx_);
        values_.push_back(value);
        cond_.notify_one();
        */
    }
}

unsigned int Fibonacci::GetValue(unsigned int index)
{
    /*
    if(optim)
    {
        boost::lock_guard<boost::mutex> lock(mx_);
        if(index < values_.size())
            return values_.at(index);
    }
    */
    
    switch(index)
    {
    case 0:
        return 0;
    case 1:
        return 1;
    default:
        //boost::this_thread::interruption_point();
        return GetValue(index - 2) + GetValue(index - 1);
    }
}

int main(){
	
	
	Fibonacci fib = new Fibonacci(false);
	std::cout<<fib.GetValue(3)<<std::endl;
	
	return 0;
}
