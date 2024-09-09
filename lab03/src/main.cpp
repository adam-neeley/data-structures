// CS 211 Fall 2024 – Week 03 Lab
// Adam Neeley
//---------------------------------------------------------------
// File: main.cpp

// #include "Bag.h"
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {

  string lines[] = {"Lab 3", "Adam", "9/9/24"};

  cout << boolalpha;
  cout << endl;
  for (const string line : lines)
    cout << line << endl;
  cout << endl;

  return EXIT_SUCCESS;
}
