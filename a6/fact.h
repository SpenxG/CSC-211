#ifndef _fact_h
#define _fact_h

#include "bigint/bigint.h"
template <typename T> T factorial(T n){
	if (n > 1) {
		return n*factorial(n-1);
	}
	else {
		return 1;
	}
}

#endif