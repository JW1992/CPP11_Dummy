// regex_search example
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>

int main ()
{
  	/*
  	std::string s ("this subject has a submarine as a subsequence");
  	std::smatch m;
  	std::regex e ("\\b(sub)([^ ]*)");   // matches words beginning by "sub"

	std::cout << "Target sequence: " << s << std::endl;
  	std::cout << "Regular expression: /\\b(sub)([^ ]*)/" << std::endl;
  	std::cout << "The following matches and submatches were found:" << std::endl;

  	while (std::regex_search (s,m,e)) {
    	for (auto x:m) std::cout << x << " ";
    	std::cout << std::endl;
    	s = m.suffix().str();
  	}
  	*/
  	
	std::ifstream infile("Settings.ini");//No need to release the memory manually this way
	std::string line;
	int nTemp1 = 0;
	int nTemp2 = 0;
	while (std::getline(infile, line))
	{
		/*
    	std::istringstream iss(line);
    	int a, b;
    	if (!(iss >> a >> b)) { break; } // error
    	*/
		//std::cout<<line<<std::endl;
    	std::regex rComment ("^#");
    	std::regex rBlank ("^\s*$");
    	std::smatch m;
    	if(std::regex_search (line,m,rComment)) nTemp1++;
    	if(std::regex_search (line,m,rBlank)) nTemp2++;
	}
	std::cout<<nTemp1<<std::endl;
	std::cout<<nTemp2<<std::endl;
	return 0;
}
