#include <iostream>
#include <unordered_map>
#include "bigint/bigint.h"
#include "fib.h"
using namespace std;


bigint r_fib(int n, std::unordered_map<int, bigint>& memo) {
	if (n <= 1){
		return n;
	}
	
	if (memo.find(n) == memo.end()){
		memo[n] = r_fib(n-1, memo) + r_fib(n-2, memo);
	}
	return memo[n];
}

bigint fib(int n) {
	std::unordered_map<int, bigint> memo;
	return r_fib(n, memo);
}

