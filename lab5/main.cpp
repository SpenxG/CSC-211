#include <iostream>
#include <cassert>
#include <cstring>
#include <sstream>

#include "recursion.h"

/** This main uses asserts instead of Catch++.
 * 
 * The advantage to this is speed, you'll notice faster compile times.
 * The downfall is that asserts are much less robust, and they are turned off when
 * compiling for production. It is wise to only use asserts when debugging, 
 * and particularly, only when you're testing that your code is right.
 * NEVER test input constraints with assert. Again, all assert statements
 * are disabled when compiling for production.
 * 
 */

int main() {
    std::cout << "Level 0: List summation\t\t\t";
    int arr1[] = {1, 2, 3, 4, 5};
    assert(arr_sum(arr1, 5) == 15);
    arr1[4] = 0;
    assert(arr_sum(arr1, 5) == 10);
    std::cout << "Passed, great start!" << std::endl;

    std::cout << "Level 1: Palindrome Testing\t\t";
    const char* s1 = "abcdefg";
    assert(!is_palindrome(s1, 0, strlen(s1)-1));
    const char* s2 = "abcba";
    assert(is_palindrome(s2, 0, strlen(s2)-1));
    std::cout << "Passed, keep up the good work!" << std::endl;

    std::cout << "Level 2: Min / Max\t\t\t";
    int arr2[] = {5, 4, 3, 2, 1};
    assert(arr_max(arr2, 5) == 5);
    assert(arr_min(arr2, 5) == 1);
    std::cout << "Passed. Half way there!" << std::endl;

    std::cout << "Level 3: Multiplication:\t\t";
    assert(multiply(2, 4) == 8);
    assert(multiply(4, 0) == 0);
    std::cout << "Passed! Great job!" << std::endl;

    std::cout << "Level 4: Drawing Triangles" << std::endl;
    std::ostringstream oss;
    draw_triangle(4, 7, 1);
    draw_triangle(4, 5, 1, oss);
    assert(oss.str() == "++++\n+++++\n+++++\n++++\n");
    std::cout << "Woot woot! Great job finishing all levels!" << std::endl;
    return 0;
}