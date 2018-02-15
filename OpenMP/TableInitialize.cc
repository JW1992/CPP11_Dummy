#include <cmath>
#include <omp.h>
#include <iostream>
#include <stdio.h>
#include <chrono>

int main()
{
    const int size = 1E6;
    double sinTable[size];
    
  	auto start = std::chrono::high_resolution_clock::now();
  	
  	//Without parallelism the execution time is ~0.099 S. With parallelism the time becomes 0.02 S.
  	//Howevr for smaller arrays the difference is negligible.
    #pragma omp parallel for
    for(int n=0; n<size; ++n)
	    sinTable[n] = std::sin(2 * M_PI * n / size);
	    
  	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	std::cout<<"Elapsed time "<< elapsed.count() << "S" <<std::endl;

	#pragma omp parallel for
	for(int n=0; n<10; ++n)
	{
		printf(" %d", n);
	}
	printf(".\n");
	
	int omp_get_thread_num();
	# pragma omp parallel
	{
		printf("Thread rank: %d\n", omp_get_thread_num());
	}
}

