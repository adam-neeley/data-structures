// CS 211 Fall 2024 - Week 05 Lab
// Comparing "slow" sorting algorithms
// Bubble Sort, Selection Sort, Insertion Sort

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

// GLOBAL VARIABLES TO COUNT COMPARISONS MADE
// AND MOVES DONE (EACH SWAP COUNTS AS 3 MOVES)

// Insert statements in each sort that increase
// the comps count and moves count as appropriate.

long int comps = 0;
long int moves = 0;

void resetState() {
  comps = 0;
  moves = 0;
}

//---------------------------------------------------------------
// void swap(int&, int&)
// Expects two integers using Pass by Reference
// Returns nothing
// Side Effect is the integer values are swapped
//---------------------------------------------------------------

void swap(int &leftInt, int &rightInt) {
  int temp;

  moves += 3;

  temp = rightInt;
  rightInt = leftInt;
  leftInt = temp;
}

//---------------------------------------------------------------
// void sortConfirm(int[], int)
// Expects an integer array and its size
// Returns nothing
// Side Effect is message to screen if array is not sorted
//---------------------------------------------------------------

bool sortConfirm(int array[], int size) {
  bool isSorted = true;

  for (int i = 1; i <= size - 1; i++)
    if (array[i - 1] > array[i])
      isSorted = false;

  return isSorted;
}

//---------------------------------------------------------------
// void sortReport(int[], int, string)
// Expects an array, its size, and a string describing
//     which type of sort was performed
// Returns nothing
// Side effect: prints sort stats to the screen
//---------------------------------------------------------------

void sortReport(int array[], int size, string sortType) {
  // FOR DEBUGGING PURPOSES ONLY
  if (!sortConfirm(array, size)) {
    cout << "*** " << sortType << " SORT ERROR ***" << endl;
  }

  cout << sortType << " SORT REPORT: " << comps << " comparisons, " << moves
       << " moves" << endl;
}

//---------------------------------------------------------------
// void bubbleSort(int[], int)
// Expects an integer array and its size
// Returns nothing
// Side Effect is array elements are arranged in sorted order
// Side Effect is output to screen number of comparisons and swaps
//---------------------------------------------------------------

void bubbleSort(int data[], int size) {
  resetState();
  bool hasSwappedThisPass;

  for (int i = size; i > 0; i--) {
    comps++;
    hasSwappedThisPass = false;
    for (int j = 0; j < i - 1; j++) {
      comps++;
      if (data[j] > data[j + 1]) {
        comps++;
        swap(data[j], data[j + 1]);
        hasSwappedThisPass = true;
      }
    }
    if (!hasSwappedThisPass)
      break;
  }

  // Data is now sorted - print stats to screen
  sortReport(data, size, "BUBBLE   ");
}

//---------------------------------------------------------------
// void selectionSort(int[], int)
// Expects an integer array and its size
// Returns nothing
// Side Effect is array elements are arranged in sorted order
// Side Effect is output to screen number of comparisons and swaps
//---------------------------------------------------------------

void selectionSort(int data[], int size) {
  resetState();
  int indexOfLeastValueThisPass = -1;

  for (int i = 0; i < size; i++) {
    comps++;
    indexOfLeastValueThisPass = i;
    for (int j = i + 1; j < size; j++) {
      comps++;
      if (data[j] < data[indexOfLeastValueThisPass]) {
        comps++;
        indexOfLeastValueThisPass = j;
      }
    }
    if (indexOfLeastValueThisPass != i) {
      comps++;
      swap(data[indexOfLeastValueThisPass], data[i]);
    }
  }

  // Data is now sorted - print stats to screen
  sortReport(data, size, "SELECTION");
}

//---------------------------------------------------------------
// void insertionSort(int[], int)
// Expects an integer array and its size
// Returns nothing
// Side Effect is array elements are arranged into sorted order
// Side Effect is output to screen number of comparisons and swaps
//---------------------------------------------------------------

void insertionSort(int data[], int size) {
  resetState();

  for (int i = 0; i < size - 1; i++) {
    comps++;
    for (int j = i + 1; j > 0; j--) {
      comps++;
      if (data[j] < data[j - 1]) {
        comps++;
        swap(data[j], data[j - 1]);
      } else
        break;
    }
  }

  // Data is now sorted - print stats to screen
  sortReport(data, size, "INSERTION");
}
