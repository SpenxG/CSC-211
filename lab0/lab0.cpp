#include <iostream>
int main(int argc, char* argv[])
{
for (int i = 1; i < argc; i++) {
int j = 0;
while (argv[i][j] != '\0') {
std::cout << argv[i][j++];
}
std::cout << " ";
}
std::cout << std::endl;
return 0;
}
