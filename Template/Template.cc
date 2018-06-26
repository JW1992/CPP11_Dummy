#include <iostream>


template <typename T>
T GetMax(T a, T b){
	return a>b?a:b;
}

template<class T, class U>
class DoubleTempParClass{
private:
	T t;
	U u;
public:
	DoubleTempParClass(T inT, U inU):t(inT),u(inU){}
	T getT(){return t;}
	T getU(){return u;}
};

template <typename T>
class MyPair{
public:
	T p[2];
	MyPair(T a, T b){
		p[0]=a; p[1]=b;
	}
	static const double Pi(){
		return 3.14;
	}
};

int main(){
	int a=1, b=2;
	std::cout<< GetMax(a,b) <<std::endl;
	std::cout<< GetMax<int>(a,b) <<std::endl;
	MyPair<double> foo(0.0, 0.1);
	std::cout << foo.p[0] << " " << foo.p[1] <<std::endl;
	std::cout << MyPair<int>::Pi() <<std::endl;
	DoubleTempParClass<int, double> DTPC{1, 2.0};
	std::cout << DTPC.getT() <<std::endl;
	std::cout << DTPC.getU() <<std::endl;
}
