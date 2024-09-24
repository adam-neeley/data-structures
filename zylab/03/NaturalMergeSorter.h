#ifndef NATURALMERGESORTER_H
#define NATURALMERGESORTER_H

class NaturalMergeSorter {
public:
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

  virtual void NaturalMergeSort(int *array, int arrayLength) {
    int i = 0;
    while (true) {
      int firstRunLength = GetSortedRunLength(array, arrayLength, i);
      if (firstRunLength == arrayLength)
        return;
      if (firstRunLength == 0)
        return;
      if (i + firstRunLength == arrayLength) {
        i = 0;
        continue;
      }
      int secondRunLength =
          GetSortedRunLength(array, arrayLength, i + firstRunLength);
      Merge(array, i, i + firstRunLength - 1, arrayLength - 1);
      i = (i + firstRunLength + secondRunLength) % arrayLength;
    }
  }

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
