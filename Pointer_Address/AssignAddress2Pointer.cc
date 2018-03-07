#include <iostream>

struct Node{
	int val;
	Node *next;
	Node(int n): val(n), next(nullptr) {}
};

int main(){
	Node *p1 = new Node(1);
	if(true){
		Node p2(2);
		p1->next = &p2;
	}
	std::cout<<p1->next->val<<std::endl;
	std::cout<<"foo"<<std::endl;
}
