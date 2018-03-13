#include <iostream>


template <class T>
T GetMax(T a, T b){
	return a>b?a:b;
}

int main(){
	int a=1, b=2;
	std::cout<< GetMax(a,b) <<std::endl;
	std::cout<< GetMax<int>(a,b) <<std::endl;
}
