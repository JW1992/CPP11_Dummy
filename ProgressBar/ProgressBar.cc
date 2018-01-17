#include <iostream>	// std::cout, std::endl
#include <chrono>
#include <thread>

int main(){
	float progress = 0.0;
	while (progress < 1.0) {
    	int barWidth = 70;
    	std::cout << "[";
    	int pos = barWidth * progress;
    	for (int i = 0; i < barWidth; ++i) {
        	if (i < pos) std::cout << "=";
        	else if (i == pos) std::cout << ">";
        	else std::cout << " ";
    	}
    	std::cout << "] " << int(progress * 100.0) << " %\r";
    	std::cout.flush();
    	progress += 0.05; // for demonstration only
    	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
	std::cout << std::endl;
}

