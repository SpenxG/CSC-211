
/** This is where to do your work.
 * 
 */

#include <iostream>
#include "recursion.h"

bool is_palindrome(const char *string, int left, int right) {
	if ( left >= right){return true;}
	if(string[left] != string[right]){return false;}
	return is_palindrome(string, ++left, --right);
}

int arr_sum(int *arr, int n) {
	if (n <= 0){
		return 0;
	}
	return (arr_sum(arr, n - 1) + arr[n-1]);
}

int min(int a, int b) {
	if (a<b) {
		return a;
	}
	else{
		return b;
	}
}

int arr_min(int *arr, int n) {
	if (n == 1) {
		return arr[0];
	}
	return min(arr[n-1], arr_min(arr, n-1));
}

int max(int a, int b) {
	if (a>b){
		return a;
	}
	else {
		return b;
	}
}

int arr_max(int *arr, int n) {
	if (n == 1) {
		return arr[0];
	}
	return max(arr[n-1], arr_max(arr, n-1));
}

void draw_triangle(int a, int b, int c, std::ostream &os) {
	for (int i=a; i<b; i++) {
		os << "+";
	}
	os << std::endl;
	
	//print a # times 


	if (a < b) {
		draw_triangle(a+c, b, c, os);
	}
	
	//print a # 
	
	os << std::endl;

}	

int multiply(int a, int b) {
	if(b > 1){
		return(a + (multiply(a, b - 1)));
	}
	else if ((a == 0) || (b == 0)) {
		return 0;
	}
	else if (b == 1){
		return a;
	}
	return 0;
}
