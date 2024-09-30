// CS 211 Fall 2024 - Week 06 Lab
// Comparing "slow" and "fast" sorting algorithms
// "Slow" Sorts, Merge Sort, Quicksort

#ifndef SORTCOMPARE_H
#define SORTCOMPARE_H

// Swap function used by main() to create arrays
// used to test sorts in various scenarios
void swap(int&, int&);

void bubbleSort(int[], int);
void selectionSort(int[], int);
void insertionSort(int[], int);
void mergeSort(int[], int);
void quickSort(int[], int);

#endif /* SORTCOMPARE_H */

