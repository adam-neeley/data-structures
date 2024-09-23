// CS 211 Fall 2024 - Week 05 Lab
// Comparing "slow" sorting algorithms
// Bubble Sort, Selection Sort, Insertion Sort

#include <cstdlib>
#include <iostream>
#include <string>

#include "slowSortCompare.h"

using namespace std;

// NOTE:  ARRAY_SIZE needs to be a multiple of 100
//        for the code below to work correctly

const int ARRAY_SIZE = 10000; // Size of the array to be sorted
const int MAX_VALUE = 100000; // Values range from 0 to MAX_VALUE-1

int main() {

    // The booleans below determine which sorts
    // will be performed.  If you want to perform only
    // one type of sort, set the other booleans to false.
    // By doing this, the UNIX "time" feature can report
    // how many total seconds of CPU time used.

    const bool BUBBLE    = true;
    const bool INSERTION = true;
    const bool SELECTION = true;

    int bubbleSortArray[ARRAY_SIZE];
    int insertionSortArray[ARRAY_SIZE];
    int selectionSortArray[ARRAY_SIZE];
    int i, j, tmp, offset;

    // Seed the pseudo-random number generator
    // NOTE: This is written for CS50 - other IDEs may require
    //       that this line of code be changed in some way
    srand(time(NULL));

    // ******************************************************
    // Call sorts with RANDOM data
    // ******************************************************

    for (i = 0; i < ARRAY_SIZE; i++) {
        bubbleSortArray[i] = rand() % MAX_VALUE;
        insertionSortArray[i] = bubbleSortArray[i];
        selectionSortArray[i] = insertionSortArray[i];
    }

    cout << endl
         << "*** Running sorts on RANDOM values ***" << endl;
    if (BUBBLE)    {
        bubbleSort(bubbleSortArray, ARRAY_SIZE);
    }
    if (SELECTION) {
        selectionSort(selectionSortArray, ARRAY_SIZE);
    }
    if (INSERTION) {
        insertionSort(insertionSortArray, ARRAY_SIZE);
    }

    // ******************************************************
    // Call sorts with ALREADY SORTED data
    // ******************************************************

    for (i = 0; i < ARRAY_SIZE; i++) {
        // insert sorted data into array[i]
        bubbleSortArray[i] = i * 5;
        insertionSortArray[i] = bubbleSortArray[i];
        selectionSortArray[i] = insertionSortArray[i];
    }
    cout << "\n";

    cout << endl
         << "*** Running sorts on ALREADY SORTED values ***" << endl;
    if (BUBBLE)    {
        bubbleSort(bubbleSortArray, ARRAY_SIZE);
    }
    if (SELECTION) {
        selectionSort(selectionSortArray, ARRAY_SIZE);
    }
    if (INSERTION) {
        insertionSort(insertionSortArray, ARRAY_SIZE);
    }

    // ******************************************************
    // Call sorts with MOSTLY SORTED data
    // ******************************************************

    for (i = 0; i < ARRAY_SIZE; i++) {
        // insert sorted data into array[i]
        bubbleSortArray[i] = i * 5;
    }
    // Swap every 10th value up to +/- 5 positions in array
    for (i = 10; i <= ARRAY_SIZE - 10; i += 10) {
            offset = (rand() % 11) - 5;
            swap(bubbleSortArray[i], bubbleSortArray[i+offset]);
    }
    // Populate other sorts arrays with identical data
    for (i = 0; i < ARRAY_SIZE; i++) {
        insertionSortArray[i] = bubbleSortArray[i];
        selectionSortArray[i] = bubbleSortArray[i];
    }
    cout << "\n";

    cout << endl
         << "*** Running sorts on MOSTLY SORTED values ***" << endl;
    if (BUBBLE)    {
        bubbleSort(bubbleSortArray, ARRAY_SIZE);
    }
    if (SELECTION) {
        selectionSort(selectionSortArray, ARRAY_SIZE);
    }
    if (INSERTION) {
        insertionSort(insertionSortArray, ARRAY_SIZE);
    }

    // ******************************************************
    // Call sorts with REVERSE SORTED data
    // ******************************************************

    for (i = 0; i < ARRAY_SIZE; i++) {
        bubbleSortArray[i] = (ARRAY_SIZE - i) * 5;
        insertionSortArray[i] = bubbleSortArray[i];
        selectionSortArray[i] = bubbleSortArray[i];
    }
    cout << "\n";

    cout << endl
         << "*** Running sorts on REVERSE SORTED values ***" << endl;
    if (BUBBLE)    {
        bubbleSort(bubbleSortArray, ARRAY_SIZE);
    }
    if (SELECTION) {
        selectionSort(selectionSortArray, ARRAY_SIZE);
    }
    if (INSERTION) {
        insertionSort(insertionSortArray, ARRAY_SIZE);
    }

    // ******************************************************
    // Call sorts with RANDOM, MANY DUPLICATES data
    // ******************************************************

    for (i = 0; i < ARRAY_SIZE / 100; i++) {
        tmp = rand() % MAX_VALUE;
        for (j = 0; j < 100; j++) {
            if ((i*100) + j < ARRAY_SIZE) {
                bubbleSortArray[i*100 + j] = tmp;
                insertionSortArray[i*100 + j] = bubbleSortArray[i*100 + j];
                selectionSortArray[i*100 + j] = bubbleSortArray[i*100 + j];
           }
        }
    }
    cout << "\n";

    cout << endl
         << "*** Running sorts on MANY DUPLICATES values ***" << endl;
    if (BUBBLE)    {
        bubbleSort(bubbleSortArray, ARRAY_SIZE);
    }
    if (SELECTION) {
        selectionSort(selectionSortArray, ARRAY_SIZE);
    }
    if (INSERTION) {
        insertionSort(insertionSortArray, ARRAY_SIZE);
    }

    return EXIT_SUCCESS;
}
