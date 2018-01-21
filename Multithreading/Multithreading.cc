#include <iostream>
#include <thread>
#include <chrono>

void call_from_thread(){
	while(1){
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		std::cout << "foo" << std::endl;
	}
	//std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	//std::cout << "foo" << std::endl;
}

int main(){
	//Launch a thread
	std::thread tl(call_from_thread);
	
	//Detach the thread from the main thread
	tl.detach();
	
	char c;
	while(1){
		std::cin>>c;
		std::cout<<"bar"<<std::endl;
	}
	return 0;
}
