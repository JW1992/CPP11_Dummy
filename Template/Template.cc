#include <iostream>


template <class T>
T GetMax(T a, T b){
	return a>b?a:b;
}

template <class T>
struct MyPair{
	T p[2];
	MyPair(T a, T b){
		p[0]=a; p[1]=b;
	}
};

int main(){
	int a=1, b=2;
	std::cout<< GetMax(a,b) <<std::endl;
	std::cout<< GetMax<int>(a,b) <<std::endl;
	MyPair<double> foo(0.0, 0.1);
	std::cout << foo.p[0] << " " << foo.p[1] <<std::endl;
}
