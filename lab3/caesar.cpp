#include <iostream>
#include <fstream>
#include <ostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

char encrypt(char *c, char *k, int key);
char decrypt(char *c, char *k, int key);

int main(int argc, char *argv[]) {

	int key;
	key = atoi(argv[2]);
	char *inp;
	inp = argv[3];
	char *out;
	out = argv[4];
	for (int i = 1; i <argc; i++) {
		if (i + 1 !=argc) {
			if (strncmp(argv[i],"-d",2) == 0) {
				decrypt(inp,out,key);
			}
			else if (strncmp(argv[i],"-e",2) == 0){
				encrypt(inp,out,key);
			}
			else{
				return 0;
			}
		}
	}
	
}

char encrypt(char *c, char *k, int key) {
	
	ofstream ofile;
	ifstream ifile;
	ifile.open(c);
	ofile.open(k);
	char buffer;
	buffer=ifile.get();
	while(!ifile.eof()) {
		if(buffer>='a' && buffer<='z') {
			buffer-= 'a';
			buffer+= key;
			buffer%= 26;
			buffer+= 'A';
		}
		ofile.put(buffer);
		buffer=ifile.get();
	}
	ifile.close();
	ofile.close();
	
	
	return 0;
}

char decrypt(char *c, char *k, int key) {
	
	ofstream ofile;
	ifstream ifile;
	ifile.open(c);
	ofile.open(k);
	char buffer;
	buffer=ifile.get();
	while(!ifile.eof()) {
		if(buffer>='A' && buffer<='Z') {
			buffer-= 'A';
			buffer+= 26-key;
			buffer%= 26;
			buffer+= 'a';
		}
		ofile.put(buffer);
		buffer=ifile.get();
	}
	ifile.close();
	ofile.close();
	
	return 0;
}
