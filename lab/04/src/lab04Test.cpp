// CS 211 Fall 2024 - Week 04 Lab
// Adam Neeley
// Mikey Thoreson

#include "week04Lab.h"
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

void expect(string desc, bool predicate) {
  std::cout << desc << ":" << predicate << std::endl;
}

int main() {
  cout << boolalpha;

  // *** INTERACTIVE TEST OF euclideanGCD ***

  unsigned long long int a, b;
  // cout << endl << "*** TESTING euclideanGCD ***" << endl;
  // cout << "Please enter two non-negative integer values " << endl
  //      << "       (enter one value as 0 to exit): ";
  // cin >> a >> b;

  expect("gcd(5, 7) = 1", euclideanGCD(5, 7) == 1);
  expect("gcd(7, 5) = 1", euclideanGCD(7, 5) == 1);

  // *** INTERACTIVE TEST OF geometricSum ***

  // int n = 0;
  // cout << endl << "*** TESTING geometricSum ***" << endl;
  // cout << "Please enter a non-negative integer value " << endl
  //      << "       (enter a negative integer to exit): ";
  // cin >> n;
  expect("geoSum(0) = 1", geometricSum(0) == 1);
  expect("geoSum(1) = 1.5", geometricSum(1) == 1.5);

  // while (n >= 0) {
  //   cout << "The function geometricSum returned " << geometricSum(n) << endl
  //        << endl;
  //   cout << "Please enter the next integer value " << endl
  //        << "  (enter a negative integer to exit): ";
  //   cin >> n;
  // }

  double input[3] = {100, -1, 200};
  expect("smallestElement([100, -1, 200], 3)", smallestElement(input, 3) == -1);

  // *** INTERACTIVE TEST OF smallestElement ***

  // int size = 0;
  // double *inputArray;
  // cout << endl << "*** TESTING smallestElement ***" << endl;
  // cout << "What size array do you want to create? ";
  // cin >> size;
  // inputArray = new double[size];
  // cout << "Please enter values for the array separated by spaces: " <<
  // endl; for (int i = 0; i < size; i++) {
  //   cin >> inputArray[i];
  // }
  // cout << "Done with inputting values!" << endl;

  // cout << "The function smallestElement returned "
  //      << smallestElement(inputArray, size) << endl
  //      << endl;

  return EXIT_SUCCESS;
}
