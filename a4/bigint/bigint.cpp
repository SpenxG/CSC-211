#include "bigint.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <stdint.h>
#include <algorithm>
#include <cstdlib>
#include <fstream>
// strip zeros essentially eliminates the extra zeros from right to left until it's a non zero
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
// default constructor
bigint::bigint() {
  number.clear();
 number.push_back(0);
}

bigint::bigint(const std::vector<vec_bin> &that) {
  number.clear();
  for (int i = that.size()-1; i >= 0; i--){
    number.push_back(that[i]);
  }
  strip_zeros();
}

// unsigned means it can only be positive
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

//string constructor, yields a bigInt equal to the integer value of the string
bigint::bigint(std::string str) {
  number.clear();
  for (int i = str.length() - 1; i >= 0; i--){
    char temp = str[i];
    vec_bin temp2 = (vec_bin)(temp - '0');
    number.push_back(temp2);
  }
  strip_zeros();
}

// file constructor
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

// Bigint constructor, it creates 2 equal bigInts
bigint::bigint(const bigint &that) {
  number.clear();
  number=that.number;
  strip_zeros();
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
bool bigint::operator==(const bigint &that) const {

  for (int i = 0; i < number.size(); i++) {
  if (number[i] != that.number[i]) {
  return false;
}
  return true;
}
}

bool bigint::operator!=(const bigint &that) const {

  for (int i = 0; i < number.size(); i++) {
   if (number[i] != that.number[i]) {
   return true;
  }
   return false;
  }
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
  std::vector <vec_bin> that_c = that.number;
  std::vector <vec_bin> this_c = this->number;
  std::vector <vec_bin> returnVector;

  if(*this > that){
    len = this->number.size();
    while (that_c.size() <= this->number.size()){
      that_c.push_back(0);
    }
    this_c.push_back(0);
    that_c.push_back(0);
  } else {
    len = that.number.size();
    while (this_c.size() <= that.number.size()){
      this_c.push_back(0);
    }
    this_c.push_back(0);
    that_c.push_back(0);
  }

  for (int i = 0; i <= len; i++){

    int temp = this_c[i] + that_c[i] + carry;
    carry = 0;
    if (temp >= 10){
      returnVector.push_back(temp % 10);
      carry = 1;
    } else {
      returnVector.push_back(temp);
    }
  }

  std::reverse(returnVector.begin(), returnVector.end());
  bigint returnBigint = returnVector;
  return returnBigint;
}

bigint bigint::operator+(const bigint &that) const {
	return this->add(that);
}

bigint &bigint::operator+=(const bigint &that) {
	(*this) = (*this) + that;
	return (*this);
}

bigint &bigint::operator++() {
	(*this) = (*this) + 1;
	return (*this);
}

bigint bigint::operator++(int) {
	bigint before = (*this);

	(*this) = (*this) + 1;

	return before;
}


/** Subtraction
 *
 * */


bigint bigint::subtract(const bigint &that) const {
 int carry = 0;
  int len;
  std::vector <vec_bin> that_c = that.number;
  std::vector <vec_bin> returnVector;

  if(that > *this){
    std::cerr << "Bigints cannot be negative" << std::endl;
  } else {

    len = this->number.size();
    while (that_c.size() <= this->number.size()){
      that_c.push_back(0);
    }

    for (int i = 0; i < len; i++){
      if ((that_c[i] + carry) > this->number[i]) {
        int temp = 10 - ((that_c[i] + carry) - this->number[i]);
        carry = 1;
        returnVector.push_back(temp);
      } else {
        returnVector.push_back(this->number[i] - (that_c[i] + carry));
        carry = 0;
      }
    }
  }
  std::reverse(returnVector.begin(), returnVector.end());
  bigint returnBigint = returnVector;
  return returnVector;
}

bigint bigint::operator-(const bigint &that) const {
	return this->subtract(that);
}

bigint &bigint::operator-=(const bigint &that) {
	(*this) = (*this) - that;
	return (*this);
}

bigint &bigint::operator--() {
	(*this) = (*this) - 1;
	return (*this);
}

bigint bigint::operator--(int) {
	bigint before = (*this);

	(*this) = (*this) - 1;

	return before;
}


/** Multiplication
 *
 * */

bigint bigint::multiply(const bigint &that) const {
  bigint that_c = that;
  bigint returnBigint = bigint();
  bigint done = bigint();
  while (that_c != done){
      returnBigint = returnBigint + *this;
      that_c--;
  }
  return returnBigint;
}

bigint bigint::operator*(const bigint &that) const {
  bigint ret = this->multiply(that);
  return ret;
}

bigint &bigint::operator*=(const bigint &that) {
  *this = this->multiply(that);
}


/** Division
 *
 * */
//
bigint bigint::divide(const bigint &that) const {
  bigint this_c = *this;
  bigint returnBigint;

  if(that <= 0){
    std::cerr << "Cannot divide by 0" << std::endl;
  } else {

    while (this_c >= that){
      this_c -= that;
      returnBigint++;
    }
    return returnBigint;
  }
}

bigint bigint::operator/(const bigint &that) const {
	return this->divide(that);
}

bigint &bigint::operator/=(const bigint &that) {
	(*this) = (*this) / that;
	return (*this);
}


/** Modulo
 *
 * */

bigint bigint::mod(const bigint &that) const {
  bigint this_c = *this;

  while (this_c > that){
    this_c -= that;
  }
  return this_c;
}

bigint bigint::operator%(const bigint &that) const {
	return this->mod(that);
}

bigint &bigint::operator%=(const bigint &that) {
	(*this) = (*this) % that;
	return (*this);
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

std::string bigint::to_string(bool commas) const {
  std::string str;
  std::vector<vec_bin> string_number;
  for(int i : number){
    string_number.push_back(i);
  }
  std::reverse(string_number.begin(), string_number.end());
  for (int j : string_number){
    str = str + std::to_string(j);
}
  if(commas!= true){
    return str;
  } else {

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

std::string bigint::scientific(unsigned int decimal_points) const {
  std::string science;  // science as in scientific notation
  int sci_count = (number.size()-1);
  science += char('0'+number[sci_count]);
  science += '.';
  for (int i = 0; i < (decimal_points); i++){
    if(sci_count - i - 1 < 0){
      science += '0';
    }
    else{ 
      science += char('0'+number[sci_count-i-1]);
    }
  }
  science += 'E';
  std::string strip = std::to_string(sci_count);
  science += strip;
  return science;
}
void bigint::to_file(std::ofstream &outfile, unsigned int wrap) {
  std::string file = this -> to_string();
  for(int i = file.length()-1; i >= 0; i--){
    outfile << (char)(number[i]+48);
    if (i % wrap ==0){
      outfile << std::endl;
    }

  }

}