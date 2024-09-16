// CS 211 Fall 2024 - Week 04 Lab
// Adam Neeley
// Mikey Thoreson

#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

// euclideanGCD: unsigned long long int, unsigned long long int
//               --> unsigned long long int
// Expects two integers from 1 to 18,446,744,073,709,551,615 (2^64 - 1)
// Returns the grestest common factor of the two values
//     employing Tail Recursion

unsigned long long int euclideanGCD(unsigned long long int a,
                                    unsigned long long int b) {
  if (b == 0)
    return a;
  if (a < b)
    return euclideanGCD(b, a);
  return euclideanGCD(b, a % b);
}

// geometricSum: unsigned int -> double
// Expects a non-negative integer (we'll call it n)
// Returns the sum of terms 1 + 1/2 + 1/4 + ... + 1/(2^n)
//     employing Tail Recursion
//     HINT:  Consider using two functions, one that is called
//            by main(), and a "helper" function called by
//            geometricSum to perform the Tail Recursion
// Remember, the recurrence relation is f(n) = 1 + (0.5 * f(n-1))

double geometricSumRec(unsigned int n, double sum, double c) {
  if (n == 0)
    return sum + c;
  return geometricSumRec(n - 1, sum + c, c / 2);
}

double geometricSum(unsigned int n) { return geometricSumRec(n, 0, 1); }

// smallestElement: double[], int -> double
// Epxects an array of values, and the array's size
// Returns the smallest (least) value of the elements in the array
//     employing Tail Recursion
//     HINT:  Consider using two functions, one that is called
//            by main(), and a "helper" function called by
//            smallestElement to perform the Tail Recursion

double smallestElementRec(double arr[], int size, int smallest, int index) {
  if (index == size)
    return smallest;
  if (index == 0 || arr[index] < smallest)
    smallest = arr[index];
  return smallestElementRec(arr, size, smallest, index + 1);
}

double smallestElement(double anArray[], int size) {
  return smallestElementRec(anArray, size, 0, 0);
}
