// sort algorithm example
#include <iostream>     // std::cout
#include <set>       // std::vector

int main(){
	std::multiset<int> set;
	for(int i=0; i<5; i++) set.insert(i);
	//Iterator initialize by auto
	auto it = set.begin();
	
	for(auto t= set.begin(); t!=set.end(); t++) std::cout<<*t<<std::endl;
	
	it = next(set.begin(), 2);
	std::cout<< *it <<std::endl;
	
	//Note I cannot simply delete the iterator it without incrementing/decrementing. Otherwise the iterator becomes undefined.
	set.erase(it++);
	for(auto t= set.begin(); t!=set.end(); t++) std::cout<<*t<<std::endl;
	//Note it is BAD practice if I do not increment/decrement within the bracket.
	std::cout<< *std::prev(it,1) << " " << *it << " " << *std::next(it,1) <<std::endl;
	
	//After the insertion the iterator still points to the same value as before!
	set.insert(2);
	for(auto t= set.begin(); t!=set.end(); t++) std::cout<<*t<<std::endl;	
	std::cout<< *std::prev(it,1) << " " << *it << " " << *std::next(it,1) <<std::endl;
	//By default, inserted duplicate number is placed before other duplicates.
	set.insert(2);	
	for(auto t= set.begin(); t!=set.end(); t++) std::cout<<*t<<std::endl;
	std::cout<< *std::prev(it,1) << " " << *it << " " << *std::next(it,1) <<std::endl;
	//By default, all the values (2) are deleted.
	set.erase(2);	
	for(auto t= set.begin(); t!=set.end(); t++) std::cout<<*t<<std::endl;
	set.insert(2);
	set.insert(2);
	for(auto t= set.begin(); t!=set.end(); t++) std::cout<<*t<<std::endl;
	//By default find() finds the FIRST value among duplicates.
	it = set.find(2);
	std::cout<< *std::prev(it,1) << " " << *it << " " << *std::next(it,1) <<std::endl;
	
	return 0;
}
