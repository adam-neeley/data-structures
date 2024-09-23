// CS 211 Fall 2023 - Week 05 Lab
// Comparing "slow" sorting algorithms
// Bubble Sort, Selection Sort, Insertion Sort

#ifndef SORTCOMPARE_H
#define SORTCOMPARE_H

// Swap function used by main() to create arrays
// used to test sorts in various scenarios
void swap(int&, int&);

void bubbleSort(int[], int);
void selectionSort(int[], int);
void insertionSort(int[], int);

#endif /* SORTCOMPARE_H */

