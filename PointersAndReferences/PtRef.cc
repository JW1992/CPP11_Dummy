// Pointers and references
#include <iostream>     // std::cout

int main(){
	int a = 1, b = 2;
	std::cout << a << " " << b <<std::endl;
	int c = a, &d = b, *e = &d;
	std::cout << c << " " << d <<std::endl;
	d++;
	std::cout << b <<std::endl;
	*e++;
	std::cout << b <<std::endl;
	//I cannot directly initialize a double& to an int!
	double f = 3.0, &g = f;
	std::cout << f << " " << g <<std::endl;
	g = c;
	std::cout << f << " " << g <<std::endl;
	
	int x1, *x2, x3, *x4;
	x2 = &x1;
	x1 = 1; x3 = 3;
	x4 = &x3;
	std::cout << x1 << " " << *x2 << " " << x3 << " " << *x4 <<std::endl;
	
	//There can NOT be a pointer to a reference because a reference is NOT an object. There could only be a reference to a pointer!
	int *&x5 = x2;
	std::cout << *x5 <<std::endl;
	
	//Note null is an int instead of a literal. Hence pN cannot be initialized by 'null'.
	int null=0, *pN = 0;
	
	//Note the alias and the compound type yield surprising results. ps1 is a const pointer to char. However, ps2 is a pointer to const char.
	//The base type in declaration of p1 is pointer to char, NOT char itself.
	typedef char* pString;
	pString ps1 = 0;
	const char* ps2;
	
	return 0;
}
