#include <iostream>
#include <random>
#include <vector>
#include <chrono>

double approximatePi(const int numSamples)
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(0.0, 1.0);
    int counter = 0;
    for (int s = 0; s != numSamples; s++)
    {
        auto x = dis(gen);
        auto y = dis(gen);
        
        if (x * x + y * y < 1)
        {
            counter++;
        }
    }

    return 4.0 * counter / numSamples;
}


int samplesInsideCircle(const int numSamples)
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(0.0, 1.0);
    
    int counter = 0;
    for (int s = 0; s != numSamples; s++)
    {
       	auto x = dis(gen);
        auto y = dis(gen);
        
        if (x * x + y * y < 1)
        {
            counter++;
        }
    }
    
    return counter;
}

double approximatePi_Parallel(const int numTotalSamples)
{
    int numChunks = 8;
    int chunk = numTotalSamples / numChunks;
    
    int counter = 0;
    
    #pragma omp parallel for shared(numChunks, chunk) reduction(+:counter)
    for (int i = 0; i < numChunks; i++)
    {
        counter += samplesInsideCircle(chunk);
    }

    return 4.0 * counter / numTotalSamples;
}

int main(){
	auto start = std::chrono::steady_clock::now();
	std::cout << approximatePi(1E7) << std::endl;
	//std::cout << approximatePi_Parallel(1E7) << std::endl;
	auto end = std::chrono::steady_clock::now();
	
	std::cout << "Elapsed time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count() << " ms" <<std::endl;
}
