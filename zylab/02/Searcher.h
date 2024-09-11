#ifndef SEARCHER_H
#define SEARCHER_H

#include "Comparer.h"
#include <iostream>
#include <string>
#include <sys/types.h>
#include <valarray>

using namespace std;

template <typename T> class Searcher {
public:
  // Returns the index of the key in the sorted array, or -1 if the key is not
  // found
  static int BinarySearch(T *array, int arraySize, const T &key,
                          Comparer<T> &comparer) {

    if (arraySize == 0)
      return -1;

    int left = 0;
    int right = arraySize - 1;
    int mid;

    if (arraySize % 2 == 0)
      mid = arraySize / 2;
    else
      mid = (arraySize - 1) / 2;

    cout << "mid: " << mid << endl;

    switch (comparer.Compare(key, array[mid])) {
    case 1:
      return BinarySearch(sliceArray(array, mid, right), right - mid, key,
                          comparer);
    case -1:
      return BinarySearch(sliceArray(array, left, mid), mid - left, key,
                          comparer);
    default:
    case 0:
      return mid;
    }
  }

private:
  static T *sliceArray(T *array, int start, int end) {
    T *res = new T[end - start + 1];
    for (int i = 0; i <= end - start; i++) {
      res[i] = array[start + i];
    }
    return res;
  }
};

#endif
