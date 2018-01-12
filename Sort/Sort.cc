// sort algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector

void PrintVector(std::vector<int> nVec){
	//Print vector
	for(std::vector<int>::iterator it=nVec.begin(); it!=nVec.end(); it++){
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

//Note: here the operator overloading results the object DescStrct to become a functionObject type, allowing it to be used by Sort().
struct SortDesc{
	bool operator() (const int i, const int j){
		return i>j;
	}
} DescStrct;

bool IsSmaller(const int i, const int j){
	return i<j;
}

int main(){
	std::vector<int> nVector;
	for(int i=0; i<10; i++){
		nVector.insert(nVector.begin(), i);
	}
	PrintVector(nVector);
	//Defalt sort
	std::sort(nVector.begin(), nVector.end());
	PrintVector(nVector);
	//Sort by custom descending order object
	std::sort(nVector.begin(), nVector.end(), DescStrct);
	PrintVector(nVector);
	//Sort by custom ascending order object
	std::sort(nVector.begin(), nVector.end(), IsSmaller);
	PrintVector(nVector);
	return 0;
}
