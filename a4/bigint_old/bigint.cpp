#include "bigint.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <stdint.h>
#include <algorithm>
#include <cstdlib>
#include <fstream>

//Remove any excess zeros from the number vector
void bigint::strip_zeros() {
  while(number.back() == 0){
    if (number.size() == 1){
      break;
    }
    number.pop_back();

  }
  if (number.empty())
    number.push_back(0);
}

/* Constructors
 *
 * */

/*Default contructor*/
//Assign a new Bigint variable with no arguments a 0
bigint::bigint() {
  number.clear();
  number.push_back(0);
}

/*Vector Constructor*/
//Loop through the input vector and push it into number
bigint::bigint(const std::vector<vec_bin> &that) {
  number.clear();
  for (int i = that.size()-1; i >= 0; i--){
    number.push_back(that[i]);
  }
  strip_zeros();
}

/*Integer Constructor*/
//use a modulus to represent powers and positions in number
bigint::bigint(unsigned long long i) {
  number.clear();
  //in the event the number is a 0
  if (i == 0){
    number.push_back(0);
  } else {
    while (i != 0){
      int num = i % 10;
      number.push_back(num);
      i /= 10;
    }
    strip_zeros();

  }
}
/*String Constructor*/
//Loop through the string from the end to the front and push the converted values to number
bigint::bigint(std::string str) {
  number.clear();
  for (int i = str.length() - 1; i >= 0; i--){
    char temp = str[i];
    vec_bin temp2 = (vec_bin)(temp - '0');
    number.push_back(temp2);
  }
  strip_zeros();
}

/*File Constructor*/
//Read the input from the file and push each character that isnt \n to number
bigint::bigint(std::ifstream &infile) {
  number.clear();
  char ch;
  while (infile.get(ch)){
    if (ch != '\n'){
      int temp = (int)(ch - '0');
      number.push_back(temp);
    }
  }
  std::reverse(number.begin(), number.end());
  strip_zeros();
}

/*Bigint Constructor*/
//Create a bigint from a bigint by looping through the input bigint
bigint::bigint(const bigint &that) {
  number.clear();
  for(int i : that.getNumber()){
    number.push_back(i);
  }
}


/* Number Access
 *
 * */
const std::vector<vec_bin> &bigint::getNumber() const {
  return number;
}

vec_bin bigint::operator[](size_t index) const {
  return number[index];
}


/** Comparators
 *
 * */
 //Use the predefined == operator for vectors to compare this and that's number
bool bigint::operator==(const bigint &that) const {
  return this->getNumber() == that.getNumber();
}

bool bigint::operator!=(const bigint &that) const {
  return this->getNumber() != that.getNumber();
}

bool bigint::operator<(const bigint &that) const {
  if (this->number.size() == that.number.size()){
    for(int i = this->number.size()-1; i >= 0; i--){
      if (this->number[i] < that.number[i]){
        return true;
      } else if (that.number[i] < this->number[i]) {
        return false;
      }
    }

  } else if(this->number.size() < that.number.size()) {
    return true;

  } else {
    return false;
  }
}

bool bigint::operator<=(const bigint &that) const {
  if (this->number == that.number){
    return true;
  }
  if (this->number.size() == that.number.size()){
    for(int i = this->number.size(); i >= 0; i--){
      if (this->number[i] < that.number[i]){
        return true;
      } else if (that.number[i] < this->number[i]) {
        return false;
      }
    }

  } else if(this->number.size() < that.number.size()) {
    return true;

  } else {
    return false;
  }
}

bool bigint::operator>(const bigint &that) const {
  if (this->number.size() == that.number.size()){
    for(int i = this->number.size() - 1; i >= 0; i--){
      if (this->number[i] > that.number[i]){
        return true;
      } else if (that.number[i] > this->number[i]) {
        return false;
      }
    }

  } else if(this->number.size() > that.number.size()) {
    return true;

  } else {
    return false;
  }
}

bool bigint::operator>=(const bigint &that) const {
  if(this->number == that.number){
    return true;
  }
  if (this->number.size() == that.number.size()){
    for(int i = this->number.size() - 1; i >= 0; i--){
      if (this->number[i] > that.number[i]){
        return true;
      } else if (that.number[i] > this->number[i]) {
        return false;
      }
    }

  } else if(this->number.size() > that.number.size()) {
    return true;

  } else {
    return false;
  }
}


/** Addition
 *
 * */

bigint bigint::add(const bigint &that) const {
  int carry = 0;
  int len;
  std::vector <vec_bin> thatCopy = that.number;
  std::vector <vec_bin> thisCopy = this->number;
  std::vector <vec_bin> returnVec;

  //find the bigint with more entries to use it to loop and make sure the vectors are the same size
  if(*this > that){
    len = this->number.size();
    while (thatCopy.size() <= this->number.size()){
      thatCopy.push_back(0);
    }
    //give each vector a bucket to account for overflow
    thisCopy.push_back(0);
    thatCopy.push_back(0);
  } else {
    len = that.number.size();
    while (thisCopy.size() <= that.number.size()){
      thisCopy.push_back(0);
    }
    thisCopy.push_back(0);
    thatCopy.push_back(0);
  }

  for (int i = 0; i <= len; i++){

    int temp = thisCopy[i] + thatCopy[i] + carry;
    carry = 0;
    if (temp >= 10){
      returnVec.push_back(temp % 10);
      carry = 1;
    } else {
      returnVec.push_back(temp);
    }
  }

  //bigint returnBigint = returnVec;
  std::reverse(returnVec.begin(), returnVec.end());
  bigint returnBigint = returnVec;
  return returnBigint;
}

bigint bigint::operator+(const bigint &that) const {
  return (this->add(that));
}

bigint &bigint::operator+=(const bigint &that) {
  *this = *this + that;
}

bigint &bigint::operator++() {
  bigint z = 1;
  *this = *this + z;
}
//broken
bigint bigint::operator++(int) {
  bigint z = 1;
  *this = *this + z;
}


/** Subtraction
 *
 * */

bigint bigint::subtract(const bigint &that) const {
  int carry = 0;
  int len;
  std::vector <vec_bin> thatCopy = that.number;
  std::vector <vec_bin> returnVec;

  //error handling
  if(that > *this){
    std::cerr << "Bigints cannot be negative" << std::endl;
  } else {

    len = this->number.size();
    while (thatCopy.size() <= this->number.size()){
      thatCopy.push_back(0);
    }

    for (int i = 0; i < len; i++){
      if ((thatCopy[i] + carry) > this->number[i]) {
        int temp = 10 - ((thatCopy[i] + carry) - this->number[i]);
        carry = 1;
        returnVec.push_back(temp);
      } else {
        returnVec.push_back(this->number[i] - (thatCopy[i] + carry));
        carry = 0;
      }
    }
  }
  std::reverse(returnVec.begin(), returnVec.end());
  bigint returnBigint = returnVec;
  return returnVec;
}

bigint bigint::operator-(const bigint &that) const {
  return (this->subtract(that));
}

bigint &bigint::operator-=(const bigint &that) {
  *this = *this - that;
}

bigint &bigint::operator--() {
  bigint z = 1;
  *this -= z;
}
//broken
bigint bigint::operator--(int) {
  bigint z = 1;
  *this -= z;
}


/** Multiplication
 *
 * */

bigint bigint::multiply(const bigint &that) const {
  bigint thatCopy = that;
  bigint returnBigint = bigint();
  bigint done = bigint();
  while (thatCopy != done){
      returnBigint = returnBigint + *this;
      thatCopy--;
  }
  return returnBigint;
}

bigint bigint::operator*(const bigint &that) const {
  bigint ret = this->multiply(that);
  return ret;
}

bigint &bigint::operator*=(const bigint &that) {
  *this = this->multiply(that);
  return *this;
}


/** Division
 *
 * */

bigint bigint::divide(const bigint &that) const {
  bigint thisCopy = *this;
  bigint returnBigint;

  if(that <= 0){
    std::cerr << "Cannot divide by 0" << std::endl;
  } else {

    while (thisCopy >= that){
      thisCopy -= that;
      returnBigint++;
    }
    return returnBigint;
  }
}
bigint bigint::operator/(const bigint &that) const {
  return (this->divide(that));
}

bigint &bigint::operator/=(const bigint &that) {
  *this = this->divide(that);
  return *this;
}


/** Modulo
 *
 * */

bigint bigint::mod(const bigint &that) const {
  bigint thisCopy = *this;

  while (thisCopy > that){
    thisCopy -= that;
  }
  return thisCopy;
}


bigint bigint::operator%(const bigint &that) const {
  return (this->mod(that));
}

bigint &bigint::operator%=(const bigint &that) {
  *this = this->mod(that);
}


/** Power
 *
 * */

bigint bigint::pow(unsigned long long n) {
  bigint returnBigint = 1;

  for(int counter = 0; counter < n; counter++){
    returnBigint = returnBigint.multiply(*this);
  }
  return returnBigint;
}


/** Display methods
 *
 * */

std::ostream &operator<<(std::ostream &os, const bigint &bigint1) {
  os << bigint1.to_string(true);
}

//Send the internal bigint number to a human readable string form
std::string bigint::to_string(bool commas) const {
  std::string str;
  std::vector<vec_bin> strnum;
  for(int i : number){
    strnum.push_back(i);
  }
  std::reverse(strnum.begin(), strnum.end());
  for (int j : strnum){
    str = str + std::to_string(j);
}
  if(commas!= true){
    return str;
  } else {

    /*Insert commas every three numbers if commas is true*/
    int comcount = 0;
    for(int j = str.length(); j > 0; j--){
      comcount += 1;
      if (comcount == 4){
        comcount = 1;
        str.insert(j, ",");
      }
    }
    return str;
  }
}

//Represent the internal bigint number in scientific notation in a string
std::string bigint::scientific(unsigned int decimal_points) const {
  std::string tempstr = this->to_string();
  tempstr.insert(1, ".");
  tempstr = tempstr.substr(0,decimal_points+2);
  tempstr += "E";
  tempstr += std::to_string(number.size()-1);
  return tempstr;
}

//Write the internal representation of the number in a human readable form to outfile
void bigint::to_file(std::ofstream &outfile, unsigned int wrap) {
  int count = 0;
  if (!outfile.fail()){
    for (int i = this->number.size()-1; i >= 0; i--){
        count++;
        if (count == wrap+1){
          outfile << '\n';
        } else {
          outfile << std::to_string(this->number[i]);
        }
    }
	} else {
    std::cerr << "Could not open file " << std::endl;
		}
}
