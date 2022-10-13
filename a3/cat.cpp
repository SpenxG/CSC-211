#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[]) {
	

	ifstream inFile;
	
	//for loop starts at one or it opens './cat'
	for (int i=1; i<argc; i++){
		inFile.open(argv[i]);

		std::string line;
		
		
		if (! inFile.fail()){
			while (getline(inFile,line)) {
			std::cout << line ;
			}
			
		}
		else if (inFile.fail()) {
			std::cerr << "cat: foo: no such file or directory";
		}
		else {
			return 0;
		}
		
		inFile.close();
	}
}