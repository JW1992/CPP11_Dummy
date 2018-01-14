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
	
    std::regex rComment ("^#");
    std::regex rBlank ("^\s*$");
    std::regex rTime ("^SIM_TIME");
    std::regex rPointSouce ("^SOURCE_POINT");
    std::regex rCuboidObject ("^OBJ_CUBOID");
    std::smatch m;
    std::string strKeyWord;
    
    bool bIfInputValid = true;
	
	while (std::getline(infile, line))
	{
    	if(std::regex_search (line,m,rComment)) continue;
    	if(std::regex_search (line,m,rBlank)) continue;
    	//Input time length
    	if(std::regex_search (line,m,rTime)){
    		std::istringstream iss(line);
    		if(!(iss >> strKeyWord)) bIfInputValid = false;
    		double fTime = 0.0;
    		if(!(iss >> fTime)) bIfInputValid = false;
    		std::cout<<"Simulation time length: "<<fTime<<" seconds"<<std::endl;
    	}
    	//Input source type
    	if(std::regex_search (line,m,rPointSouce)){
    		std::istringstream iss(line);
    		if(!(iss >> strKeyWord)) bIfInputValid = false;
    		double x,y,z,fA;
    		if(!(iss >> x >> y >> z >>fA)) bIfInputValid = false;
    		std::cout<<"Add point source, x="<<x<<", y="<<y<<", z="<<z;
    		std::cout<<", Activity: "<<fA<<" uCi."<<std::endl;
    	}
    	//Input object type
    	if(std::regex_search (line,m,rCuboidObject)){
    		std::istringstream iss(line);
    		if(!(iss >> strKeyWord)) bIfInputValid = false;
    		double x1,y1,z1,x2,y2,z2;
    		std::string strMaterialName;
    		int nIsDetector;
    		if(!(iss >> x1 >> y1 >> z1 >> x2 >> y2 >> z2)) bIfInputValid = false;
    		if(!(iss >> strMaterialName)) bIfInputValid = false;
    		if(!(iss >> nIsDetector)) bIfInputValid = false;
    		std::cout<<"Add new object: cuboid of "<<strMaterialName;
    		if(nIsDetector>0) std::cout<<" as active detctor volume.";
    		std::cout<<std::endl;
    		std::cout<<"Position: "<<x1<<" "<<y1<<" "<<z1<<" "<<x2<<" "<<y2<<" "<<z2<<" "<<std::endl;
    	}
    	if(!bIfInputValid){
    		std::cout<<"Input file exception"<<std::endl;
    		return 0;
    	}
	}
	return 0;
}
