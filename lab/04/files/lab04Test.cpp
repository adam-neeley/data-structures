// CS 211 Fall 2024 - Week 04 Lab

#include <cstdlib>
#include <iostream>
#include <string>
#include "week04Lab.h"

using namespace std;

int main() {
     cout << boolalpha;

    // *** INTERACTIVE TEST OF euclideanGCD ***

    unsigned long long int a, b;
    cout << endl << "*** TESTING euclideanGCD ***" << endl;
    cout << "Please enter two non-negative integer values " << endl
         << "       (enter one value as 0 to exit): ";
    cin >> a >> b;

     while (a != 0 && b != 0) {
          cout << "The function euclideanGCD returned "
             << euclideanGCD(a,b) << endl << endl;
        cout << "Please enter the next integer values " << endl
             << "  (enter one value as 0 to exit): ";
          cin >> a >> b;
    }

    // *** INTERACTIVE TEST OF geometricSum ***

    int n = 0;
    cout << endl << "*** TESTING geometricSum ***" << endl;
    cout << "Please enter a non-negative integer value " << endl
         << "       (enter a negative integer to exit): ";
    cin >> n;

    while (n >= 0) {
        cout << "The function geometricSum returned "
             << geometricSum(n) << endl << endl;
        cout << "Please enter the next integer value " << endl
             << "  (enter a negative integer to exit): ";
        cin >> n;
    }

    // *** INTERACTIVE TEST OF smallestElement ***

    int size = 0;
    double *inputArray;
    cout << endl << "*** TESTING smallestElement ***" << endl;
    cout << "What size array do you want to create? ";
    cin >> size;
    inputArray = new double[size];
    cout << "Please enter values for the array separated by spaces: " << endl;
    for (int i=0; i<size; i++) {
     cin >> inputArray[i];
    }
    cout << "Done with inputting values!" << endl;

    cout << "The function smallestElement returned "
             << smallestElement(inputArray, size) << endl << endl;

    return EXIT_SUCCESS;
}
