// CS 211 Fall 2024 - Week 06 Lab
// Comparing "slow" and "fast" sorting algorithms
// "Slow" Sorts, Merge Sort, Quicksort

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

// GLOBAL VARIABLES TO COUNT COMPARISONS MADE
// AND MOVES DONE (EACH SWAP COUNTS AS 3 MOVES)

// Insert statements in each sort that increase
// the comps count, the moves count, and the
// recursive function calls count as appropriate.

long int comps = 0;
long int moves = 0;
long int calls = 0;

//---------------------------------------------------------------
// void swap(int&, int&)
// Expects two integers using Pass by Reference
// Returns nothing
// Side Effect is the integer values are swapped
//---------------------------------------------------------------

void swap(int& leftInt, int& rightInt) {
    moves += 3;
    int temp;

    temp = rightInt;
    rightInt = leftInt;
    leftInt = temp;
}

//---------------------------------------------------------------
// void sortConfirm(int[], int)
// Expects an integer array and its size
// Returns nothing
// Side Effect is message to screen if array is not sorted
// NOTE: This function should NOT count its comps, as it's just
//     a confirmation of the sort, NOT the sort itself!
//---------------------------------------------------------------

bool sortConfirm(int array[], int size) {
    bool isSorted = true;

    for (int i=1; i<=size-1; i++)
        if (array[i-1] > array[i])
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

    cout << sortType << " SORT REPORT: "
         << comps << " comparisons, " << moves << " moves";

    if (sortType == "MERGESORT" || sortType == "QUICKSORT")
        cout << ", " << calls << " recursive calls ";

    cout << endl;

}

// **************************************************************
// *** BUBBLE SORT
// **************************************************************
//---------------------------------------------------------------
// void bubbleSort(int[], int)
// Expects an integer array and its size
// Returns nothing
// Side Effects: array elements are arranged in sorted order
//               sortReport is called to output stats to screen
//---------------------------------------------------------------

// NOTE: CODE TO COUNT COMPS AND MOVES IS ALREADY COMPLETED HERE!

void bubbleSort(int data[], int size) {
    bool hasSwappedThisPass = false;
    comps = moves = 0;

    for (int i=size; i>0; i--) {
        hasSwappedThisPass = false;
        for (int j=0; j<i-1; j++) {
            comps++;
            if (data[j] > data[j + 1]) {
                swap(data[j], data[j + 1]);
                hasSwappedThisPass = true;
            }
        }
        if (!hasSwappedThisPass) break;
    }

    // Data is now sorted - print stats to screen
    sortReport(data, size, "BUBBLE   ");
}

// **************************************************************
// *** SELECTION SORT
// **************************************************************
//---------------------------------------------------------------
// void selectionSort(int[], int)
// Expects an integer array and its size
// Returns nothing
// Side Effect is array elements are arranged in sorted order
// Side Effect is output to screen number of comparisons and swaps
//---------------------------------------------------------------

// NOTE: CODE TO COUNT COMPS AND MOVES IS ALREADY COMPLETED HERE!

void selectionSort(int data[], int size) {
    int indexOfLeastValueThisPass = -99999;
    comps = moves = 0;

    for (int i=0; i<size; i++) {
        indexOfLeastValueThisPass = i;
        for (int j=i+1; j<size; j++) {
            comps++;
            if (data[j] < data[indexOfLeastValueThisPass])
                indexOfLeastValueThisPass = j;
        }
        if (indexOfLeastValueThisPass != i)
            swap(data[indexOfLeastValueThisPass], data[i]);
    }

    // Data is now sorted - print stats to screen
    sortReport(data, size, "SELECTION");
}

// **************************************************************
// *** INSERTION SORT
// **************************************************************
//---------------------------------------------------------------
// void insertionSort(int[], int)
// Expects an integer array and its size
// Returns nothing
// Side Effect is array elements are arranged into sorted order
// Side Effect is output to screen number of comparisons and swaps
//---------------------------------------------------------------

// NOTE: CODE TO COUNT COMPS AND MOVES IS ALREADY COMPLETED HERE!

void insertionSort(int data[], int size) {
    comps = moves = 0;

    for (int i=0; i<size-1; i++) {
        for (int j=i+1; j>0; j--) {
            comps++;
            if (data[j] < data[j - 1])
                swap(data[j], data[j - 1]);
            else break;
        }
    }

    // Data is now sorted - print stats to screen
    sortReport(data, size, "INSERTION");
}

// **************************************************************
// *** MERGE SORT (WITH HELPER FUNCTIONS)
// **************************************************************

// Helper function mergeSortedArrays
// Merge two sorted parts of an array to maintain sorted property

// NOTE: CODE TO COUNT COMPS AND MOVES NEEDS TO BE INSERTED HERE!

void mergeSortedArrays(int data[], int left, int mid, int right) {

    // NOTE: data[mid] will be part of the left half
    int sizeLeftArray = mid - left + 1;  // Size of left half
    int sizeRightArray = right - mid;    // Size of right half

    // Create temporary storage to hold left and right halves
    int *leftArray = new int[sizeLeftArray];
    int *rightArray = new int[sizeRightArray];

    // Copy values from data[] into leftArray[] and rightArray[]
    // This way, when we merge, we can copy sorted values back into data[]
    // NOTE: These count as moves!

    for (int i = 0; i < sizeLeftArray; i++) {
        leftArray[i] = data[left+i];
    }
    for (int i = 0; i < sizeRightArray; i++) {
        rightArray[i] = data[mid+1+i];
    }

    int indexOfLeftArray = 0;      // Relative index within left array
    int indexOfRightArray = 0;     // Relative index within right array
    int indexOfDataArray = left;   // Relative index within data array

    // Merge the temp arrays back into data[left..right]

    while (indexOfLeftArray < sizeLeftArray &&
           indexOfRightArray < sizeRightArray) {

        // If smaller value is in left array, copy it to data[]
        // NOTE: comparisons of data in leftArray and rightArray count as comps!
        if (leftArray[indexOfLeftArray] <= rightArray[indexOfRightArray]) {
            data[indexOfDataArray] = leftArray[indexOfLeftArray];
	        indexOfLeftArray++;
    	}

        // If smaller value is in right array, copy it to data[]
    	else {
            data[indexOfDataArray] = rightArray[indexOfRightArray];
            indexOfRightArray++;
    	}
        // One sorted value has been placed to data[], so increment index
        indexOfDataArray++;
    }

    // At this point, one of the arrays (either left or right) is done
    // Copy the remaining elements of whichever array is not done yet

    while (indexOfLeftArray < sizeLeftArray) {
        data[indexOfDataArray] = leftArray[indexOfLeftArray];
	    indexOfLeftArray++;
	    indexOfDataArray++;
    }

    while (indexOfRightArray < sizeRightArray) {
        data[indexOfDataArray] = rightArray[indexOfRightArray];
    	indexOfRightArray++;
	    indexOfDataArray++;
    }
    // Merged portion of data[] is now complete
}

// Helper function mergeSortRecursive
// Sort left half, Sort right half, Merge the two halves
// For each call, begin and end define which part of the array to sort

// NOTE: CODE TO COUNT COMPS, MOVES, AND RECURSIVE CALLS NEEDS TO BE INSERTED HERE!

void mergeSortRecursive(int data[], int begin, int end) {

    // Base case - just return, nothing to be sorted here!
    if (begin >= end)
        return;

    // Find index of midway point between begin and end
    int mid = begin + (end - begin) / 2;

    // Recursively sort left half of array
    mergeSortRecursive(data, begin, mid);

    // Recursively sort right half of array
    mergeSortRecursive(data, mid+1, end);

    // The two halves are now sorted, so it's time to merge them
    mergeSortedArrays(data, begin, mid, end);
}

//---------------------------------------------------------------
// mergeSort(int[], int)
// Expects an integer array and its size
// Returns nothing
// Side Effects: array elements are arranged in sorted order
//               sortReport is called to report sort stats
//---------------------------------------------------------------

void mergeSort(int data[], int size) {
    comps = moves = calls = 0;

    // The recursive helper function does all the sorting
    mergeSortRecursive(data, 0, size-1);

    sortReport(data, size, "MERGESORT");
}

// **************************************************************
// *** QUICKSORT (WITH HELPER FUNCTIONS)
// **************************************************************

// Helper function findPivot
// Given three indexes in the array, determines which is best for pivot
// Left, mid, and right are indexes of candidates for best pivot value

// The method for counting the number of comparisons is tricky, so it's
// been done for you :-).  Just uncomment the lines below that increment
// comps.  It's 2 or 3 total each time findPivot is called.

int findPivot(int data[], int left, int mid, int right) {
    // NOTE that if we simply used a strategy of choosing one index,
    // this function can simply set pivotIndex to one of left, mid,
    // or right.
    // Uncomment the next line to choose a single value as pivot
    // (choosing, if you wish, to replace left with mid or right)
    // instead of performing the best-of-3 strategy.

    // return left;

    // At this point, we're employing a "best-of-3" strategy,
    // which should improve worst-case performance greatly!
    // So we'll make a few comparisons to find the "best" pivot.

    // NOTE: SIMPLY UNCOMMENT comps++ LINES BELOW TO COUNT COMPS
    // (It's devilishly tricky to get this right, so it's already done here :-)
    // No swaps and no recursive calls in this code -- only count comps.

    int pivotIndex = -99999;

    // comps++;  // left and mid
    if (data[left] > data[mid]) {
        // comps++;  // mid and right
        if (data[mid] > data[right]) {
            pivotIndex = mid;
        }
        else if (data[left] > data[right]) {
            // comps++;  // left > right is true
            pivotIndex = right;
        }
        else {
            // comps++;  // left > right is false
            pivotIndex = left;
        }
    }
    else {
        // comps++;  // left and right
        if (data[left] > data[right]) {
            pivotIndex = left;
        }
        else if (data[mid] > data[right]) {
            // comps++;  // mid > right is true
            pivotIndex = right;
        }
        else {
            // comps++;  // mid > right is false
            pivotIndex = mid;
        }
    }
    // pivotIndex is now set to left, mid, or right
    return pivotIndex;
}

// Helper function quickSortPartition
// Chooses a pivot, performs partition, returns index where
// pivot value is when done

// NOTE: CODE TO COUNT COMPS NEEDS TO BE INSERTED HERE!

int quickSortPartition(int data[], int start, int end) {
    // Pre-condition: there are at least three elements to partition
    // (This is checked by calling function before we get here)
    int mid = (start + end) / 2;
    int pivotIndex = -99999;

    // Select pivot - findPivot will be set to an index for the pivot
    // and the comps will be counted in tne findPivot function
    pivotIndex = findPivot(data, start, mid, end);

    // Swap pivot value to be the leftmost item temporarily
    // (it'll be moved back after other values are partitioned)
    swap(data[pivotIndex], data[start]);

    // Now that the pivot value is at data[start], let's partition!
    int i = start;
    for (int j=start+1; j<=end; j++) {
        if (data[j] < data[start]) {
            i++;
            // swap smaller value to left partition
            swap(data[i], data[j]);
        }
    }

    // Now swap pivot value back into correct position
    swap(data[start], data[i]);
    return i;
}

//*********************************************************************

// Helper function quickSortRecursive
// Handle base cases, use partition function, make recursive calls
// For each call, start and end define which part of the array to sort

// NOTE: CODE TO COUNT COMPS AND MOVES NEEDS TO BE INSERTED HERE!

void quickSortRecursive(int data[], int start, int end) {

    // Base cases - array of size 0 or 1
    if (end - start < 1) {
        return;
    }

    // Base case - array of size 2 - swap items if needed
    if (end - start == 1) {
        if (data[end] < data[start]) {
            swap(data[start], data[end]);
        }
        return;
    }

    // Call partition to perform partitioning and return index
    // NOTE: *Not* a recursive call, so DON'T count it as a recursive call!

    int partitionIndex = quickSortPartition(data, start, end);

    // At this point, we have, in order, from left to right:
    //    * All values <= pivot value
    //    * The pivot value itself (at index partitionIndex)
    //    * All values >= pivot value

    // Now we recursively apply this sort to those 2 partitioned parts
    // (Not including pivot value, as it doesn't need to be moved now!)

    quickSortRecursive(data, start, partitionIndex-1);
    quickSortRecursive(data, partitionIndex+1, end);

    // After these calls recurse all the way to the base cases, we're sorted!
}

//---------------------------------------------------------------
// quickSort(int[], int)
// Expects an integer array and its size
// Returns nothing
// Side Effects: Array elements are arranged in sorted order
//               sortReport is called to output stats
//---------------------------------------------------------------

void quickSort(int data[], int size) {
    comps = moves = calls = 0;

    // The recursive helper function does all the work
    quickSortRecursive(data, 0, size-1);

    sortReport(data, size, "QUICKSORT");

}
