// CS 211 Fall 2024 - Week 06 Lab
// Comparing "slow" and "fast" sorting algorithms
// "Slow" Sorts, Merge Sort, Quicksort

#include <cstdlib>
#include <iostream>
#include <string>

#include "fastSortCompare.h"

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
    // how many total seconds of CPU time used for a sort.

    const bool BUBBLE    = true;
    const bool SELECTION = true;
    const bool INSERTION = true;
    const bool MERGESORT = true;
    const bool QUICKSORT = true;

    int bubbleSortArray[ARRAY_SIZE];
    int insertionSortArray[ARRAY_SIZE];
    int selectionSortArray[ARRAY_SIZE];
    int mergeSortArray[ARRAY_SIZE];
    int quickSortArray[ARRAY_SIZE];
    int i, j, tmp, offset;

    // Seed the pseudo-random number generator
    // NOTE: This is written for CS50 - other IDEs may require
    //       that this line of code be changed in some way
    srand(time(NULL));

    // ******************************************************
    // Call sorts with RANDOM data
    // ******************************************************

    for (i = 0; i < ARRAY_SIZE; i++) {
        bubbleSortArray[i]    = rand() % MAX_VALUE;
        selectionSortArray[i] = bubbleSortArray[i];
        insertionSortArray[i] = bubbleSortArray[i];
        mergeSortArray[i]     = bubbleSortArray[i];
        quickSortArray[i]     = bubbleSortArray[i];
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
    if (MERGESORT) {
        mergeSort(mergeSortArray, ARRAY_SIZE);
    }
    if (QUICKSORT) {
        quickSort(quickSortArray, ARRAY_SIZE);
    }

    // ******************************************************
    // Call sorts with ALREADY SORTED data
    // ******************************************************

    for (i = 0; i < ARRAY_SIZE; i++) {
        bubbleSortArray[i]    = i * 5;
        selectionSortArray[i] = bubbleSortArray[i];
        insertionSortArray[i] = bubbleSortArray[i];
        mergeSortArray[i]     = bubbleSortArray[i];
        quickSortArray[i]     = bubbleSortArray[i];
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
    if (MERGESORT) {
        mergeSort(mergeSortArray, ARRAY_SIZE);
    }
    if (QUICKSORT) {
        quickSort(quickSortArray, ARRAY_SIZE);
    }

    // ******************************************************
    // Call sorts with MOSTLY SORTED data
    // ******************************************************

    for (i = 0; i < ARRAY_SIZE; i++) {
        bubbleSortArray[i] = i * 5;
    }
    // Swap every 10th value up to +/- 5 positions in array
    for (i = 10; i <= ARRAY_SIZE - 10; i += 10) {
            offset = (rand() % 11) - 5;
            swap(bubbleSortArray[i], bubbleSortArray[i+offset]);
    }
    for (i = 0; i < ARRAY_SIZE; i++) {
        selectionSortArray[i] = bubbleSortArray[i];
        insertionSortArray[i] = bubbleSortArray[i];
        mergeSortArray[i]     = bubbleSortArray[i];
        quickSortArray[i]     = bubbleSortArray[i];
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
    if (MERGESORT) {
        mergeSort(mergeSortArray, ARRAY_SIZE);
    }
    if (QUICKSORT) {
        quickSort(quickSortArray, ARRAY_SIZE);
    }

    // ******************************************************
    // Call sorts with REVERSE SORTED data
    // ******************************************************

    for (i = 0; i < ARRAY_SIZE; i++) {
        bubbleSortArray[i]    = (ARRAY_SIZE - i) * 5;
        selectionSortArray[i] = bubbleSortArray[i];
        insertionSortArray[i] = bubbleSortArray[i];
        mergeSortArray[i]     = bubbleSortArray[i];
        quickSortArray[i]     = bubbleSortArray[i];
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
    if (MERGESORT) {
        mergeSort(mergeSortArray, ARRAY_SIZE);
    }
    if (QUICKSORT) {
        quickSort(quickSortArray, ARRAY_SIZE);
    }

    // ******************************************************
    // Call sorts with RANDOM, MANY DUPLICATES data
    // ******************************************************

    for (i = 0; i < ARRAY_SIZE / 100; i++) {
        tmp = rand() % MAX_VALUE;
        for (j = 0; j < 100; j++)
            if ((i*100) + j < ARRAY_SIZE)
                bubbleSortArray[i*100 + j] = tmp;
    }
    for (i = 0; i < ARRAY_SIZE; i++) {
        selectionSortArray[i] = bubbleSortArray[i];
        insertionSortArray[i] = bubbleSortArray[i];
        mergeSortArray[i]     = bubbleSortArray[i];
        quickSortArray[i]     = bubbleSortArray[i];
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
    if (MERGESORT) {
        mergeSort(mergeSortArray, ARRAY_SIZE);
    }
    if (QUICKSORT) {
        quickSort(quickSortArray, ARRAY_SIZE);
    }

    return EXIT_SUCCESS;
}
