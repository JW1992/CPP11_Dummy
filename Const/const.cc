// Pointers and references
#include <iostream>     // std::cout

//A const MUST be initialized, because the a const variable cannot be reassigned later.

int main(){
	int i = 0;
	const int ci = 1;
	//Note: A reference to const COULD be initialized to a plain variable of the same base type.
	//However, a reference to a plain variable MUST NOT be initialized to a const variable of the same base type, as this potentially allows changing the value of a const variable.
	const int &ri = ci;
	//A reference to const can be initialized from an expression, a literal, or a non-const variable of the same base type.
	const int &ci2 = ci*2;
	//A reference to const can also be initialized from a numerical value.
	const int &ci3 = 3;
	std::cout << i << " " << ci << " " << ri << " " << ci2 << " " << ci3 << " " << std::endl;
	
	//Note cp must be a pointer to a const double, instead of a pointer to a plain double.
	const double cf = 42;
	const double *cp = &cf;
	//Note the difference between a pointer to const, and a const pointer.
	int const *cpi = &i;
	std::cout << cf << " " << *cp << " " << *cpi << std::endl;
	
	//A const reference could be initialized from a literal, unlike plain ref.
	const double& foo = 1.0;
	std::cout << foo << std::endl;
	
	return 0;
}
