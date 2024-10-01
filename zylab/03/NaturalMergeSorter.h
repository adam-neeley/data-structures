#ifndef NATURALMERGESORTER_H
#define NATURALMERGESORTER_H

class NaturalMergeSorter {
public:
  /*
  ** GetSortedRunLength
  */
  virtual int GetSortedRunLength(int *array, int arrayLength, int startIndex) {
    return GetSortedRunLengthRec(array, startIndex, arrayLength - 1);
  }
  virtual int GetSortedRunLengthRec(int *array, int leftPos, int rightPos) {
    if (leftPos > rightPos)
      return 0;
    if (leftPos == rightPos)
      return 1;
    if (array[leftPos] > array[leftPos + 1])
      return 1;
    return 1 + GetSortedRunLengthRec(array, leftPos + 1, rightPos);
  }

  /*
  ** NaturalMergeSort
  ** | 0 | 1 | 2 | 3 | 4 | 5 |
  ** | 1 | 2 | 3 | 2 | 3 | 2 |
  ** | A | A | A | B | B | C |
  ** i = 0
  ** len1: 3
  ** len2: 2
  ** i = 1
  ** len1: 1
  ** len2: 2
  */
  virtual void NaturalMergeSort(int *array, int arrayLength) {
    for (int i = 0; i < arrayLength; i++) {
      int len1 = GetSortedRunLength(array, arrayLength, i);
      if (len1 == arrayLength)
        return;
      if (i + len1 == arrayLength) {
        i = 0;
        continue;
      }
      int len2 = GetSortedRunLength(array, arrayLength, i + len1);
      Merge(array, i, i + len1 - 1, i + len1 + len2 - 1);
      if (i + len1 + len2 - 1 == arrayLength)
        i = 0;
      else
        i = i + len1 + len2;
    }
  }

  /*
  ** Merge
  */
  virtual void Merge(int *numbers, int leftFirst, int leftLast, int rightLast) {
    int mergedSize = rightLast - leftFirst + 1;
    int *mergedNumbers = new int[mergedSize];
    int mergePos = 0;
    int leftPos = leftFirst;
    int rightPos = leftLast + 1;

    // Add smallest element from left or right partition to merged numbers
    while (leftPos <= leftLast && rightPos <= rightLast) {
      if (numbers[leftPos] <= numbers[rightPos]) {
        mergedNumbers[mergePos] = numbers[leftPos];
        leftPos++;
      } else {
        mergedNumbers[mergePos] = numbers[rightPos];
        rightPos++;
      }
      mergePos++;
    }

    // If left partition isn't empty, add remaining elements to mergedNumbers
    while (leftPos <= leftLast) {
      mergedNumbers[mergePos] = numbers[leftPos];
      leftPos++;
      mergePos++;
    }

    // If right partition isn't empty, add remaining elements to mergedNumbers
    while (rightPos <= rightLast) {
      mergedNumbers[mergePos] = numbers[rightPos];
      rightPos++;
      mergePos++;
    }

    // Copy merged numbers back to numbers
    for (mergePos = 0; mergePos < mergedSize; mergePos++) {
      numbers[leftFirst + mergePos] = mergedNumbers[mergePos];
    }

    // Free temporary array
    delete[] mergedNumbers;
  }
};

#endif
