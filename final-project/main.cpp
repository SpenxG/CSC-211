/**
 * Started by Najib 3/21/18
 **/
#include <iterator>
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cctype>
#include <math.h>
#include "functions.h"
#include "bigint/bigint.h"


int main(int argc, char *argv[]) {
  if (argc == 1){
    std::cerr << "Program needs at least 2 arguments\n";
  }

  std::ifstream inFile;
  std::vector<double> cosine_similarity;
  inFile.open(argv[argc-1]);
  std::string unknown = language(inFile);
   for (int i = 1; i < (argc-1); i++) {
     std::ifstream training;
     training.open(argv[i]);
     std::string comp = language(training);

     bigint numerator, num, denom_a, denom_b, denominator;
     //Does the math for cosine similarity
     for(size_t count = 0; count <=17575; count++){
       num += (unknown[count]*comp[count]);
       denom_a += (unknown[count]*unknown[count]);
       denom_b += (comp[count]*comp[count]);
     }
     //converts from double to "bigint" form using scaled division
     numerator = std::stod(num.to_string());
     double Adouble = sqrt(std::stod(denom_a.to_string()));
     double Bdouble = sqrt(std::stod(denom_b.to_string()));
     denominator = Adouble*Bdouble;
     bigint similarity = (numerator*1000000)/denominator;
     double alt_sim = std::stod(similarity.to_string())/1000000;

     cosine_similarity.push_back(alt_sim);
   }
   inFile.close();

//Does final determination of which language is most similar
int maximum = 0;
for(double n = 0; n<cosine_similarity.size(); n++){
    if(cosine_similarity[maximum]<cosine_similarity[n]){
      maximum = n;
    }
}
std::cout << argv[maximum+1] << std::endl;

}
