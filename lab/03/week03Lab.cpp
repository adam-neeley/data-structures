// CS 211 Fall 2024 - Week 03 Lab
// Adam Neeley

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int factorial(unsigned int n) {
  if (n <= 1)
    return 1;
  else
    return factorial(n);
}

// sumDownBy2: unsigned int -> int
// Expects a non-negative integer
// Returns the sum of all positive integers n, n-2, n-4, etc.

int sumDownBy2(unsigned int n) {
  if (n <= 1)
    return n;
  else
    return n + sumDownBy2(n - 2);
}

// recursiveMult: unsigned int, unsigned int -> int
// Expects two non-negative integers
// Returns the product of those integers

int recursiveMult(unsigned int j, unsigned int k) {
  if (k == 0) {
    return 0;
  }
  return j + recursiveMult(j, k - 1);
}

// isPalindrome: string -> bool
// Expects a string
// Returns true is the string is a palindrome

bool isPalindrome(const string str) {
  int len = str.length();
  int left = 0;
  int right = len - 1;

  if (len == 1)
    return true;
  if (str[left] == str[right])
    return isPalindrome(str.substr(left + 1, right - 1));
  return false;
}

// geometricSum: unsigned int -> double
// Expects: A non-negative integer n
// Returns the sum of 1 + 1/2 + 1/4 + ... + 1/(2^n)

double geometricSum(unsigned int n) {
  if (n == 0) {
    return 1.0;
  } else {
    return 1.0 + 0.5 * geometricSum(n - 1);
  }
}
