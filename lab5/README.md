# Recursion

A lab entirely about solving problems via recursive practices.

## About

For this lab, you are charged with completing the provided `recursion.cpp` file. Using this README as your guide, 
you will start from relatively simple problems, and work your way up to more complex use cases for recursion.

Recursion itself is a method of programming where the problem is reduced until it has a trivial solution, which is then propagated back through the recursive calls to arrive at the final solution.

## Submitting your code

Please submit your `recursion.cpp` file to Mimir.

## Level 0: List Summation

The first task in this lab is to sum all elements of a provided list. For example:

```c++
int arr[] = {1, 2, 3, 4, 5};
int s = sum_arr(arr, 5); // Length gets passed because int arrays don't know their own length!
std::cout << s << std::endl; // Prints 15 to the command line.
``` 

The crux of this problem is that we know how to add 2 numbers together, and we also know that the sum of 1 number is itself; but, when presented with `n` numbers, we must somehow reduce the number of elements to either 1 or 2.

If we were to expand the above example, it may read something like:

> 1 + (2 + (3 + (4 + (5))))

## Level 1: Palindrome Testing

A palindrome is a string that reads the same both forwards and backwards, such as "abcba". To test if a given string is a palindrome, you can ask: is there only one character? If so, the answer is yes, since "a" is still "a" in reverse. Second, you may ask: is the first character equal to the last character? If so, continue traversing the string until there is just one character left. 

This process of narrowing the problem down until there is either one or zero characters left, is recursion!

> Hint: Do a few test runs by hand, try and formulate a plan before putting down any code.

## Level 2: Min / Max Finding

For this level you must complete both functions, one for finding the minimum of any given list, the other to find the maximum. For these problems you may create a helper function, **but you must have your recursive call in the pre-declared function**.

## Level 3: Multiplication

Multiply two numbers together, *without* using the `*` operator. 

> Hint: Think about how multiplication works, and how you can use other mathematical operations to replicate that effect. 

## Level 4: Printing a triangle

To pass level three, you must write a function to print triangles to std::cout that takes three positive integers: a, b, and c as input. The function should print the '+' character a times, then a + c times, then a + c + c times, and so on. This pattern should repeat until the line is b characters long. At which point, the pattern is repeated backwards. For example, calling `draw_triangle(4, 7, 1)` will output:

```c++
++++
+++++
++++++
+++++++
+++++++
++++++
+++++
++++
``` 

> Hint 1: The order of the recursive call is the most important part about this level.
> Hint 2: Don't forget to pass the os object in your recursive calls, otherwise Mimir can't test it! 

