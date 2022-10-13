#include <iterator>
#include <iostream>

int main (int argc, char *argv[]) {
	
	std::copy(argv+1, argv+argc-1, std::ostream_iterator<char *>(std::cout, " "));
	if (argc == 1) std::cout << " ";
	if (argc >1) std::cout << argv[argc-1] << std::endl;

}