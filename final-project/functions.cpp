/**
 * Started by Najib 3/21/18
 **/


#include <iterator>
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cctype>

#include "functions.h"
#include "bigint/bigint.h"


///////////////////////////////////////////////////////////////////
// FUNCTION DEFINITIONS GO HERE
///////////////////////////////////////////////////////////////////

std::string frequencies(std::istream &input){
  char x;
  std::string answer="";
  x=input.get();
  while(!std::isalpha(x) && !input.eof()){
    x=input.get();
  }
  while(std::isalpha(x)){
    answer.push_back(std::tolower(x));
    x=input.get();
  }
  return answer;
}

std::string trigram(std::ifstream &filename){
    std::map<std::string,int> words;
    std::string str;
    std::string empty="";
    while((str==frequencies(filename)) && str!=empty){
      ++words[str];
    }
    for(std::map<std::string,int>::iterator it = words.begin(); it!= words.end(); ++it){
      std::cout<<it->first<<' '<<it->second<<std::endl;
    }
    return 0;
}

std::string language(std::ifstream &in){
  std::string text;
  std::getline(in,text);
  in.close();
  return text;
}
