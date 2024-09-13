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
  static int BinarySearch(T *array, int arraySize, const T &key,
                          Comparer<T> &comparer) {
    return BinarySearchRec(array, 0, arraySize - 1, key, comparer);
  }

private:
  static int BinarySearchRec(T *array, int left, int right, const T &key,
                             Comparer<T> &comparer) {
    if (right >= left) {
      const int len = right - left;
      const int mid = left + len / 2;
      if (comparer.Compare(array[mid], key) < 0)
        return BinarySearchRec(array, mid + 1, right, key, comparer);
      if (comparer.Compare(array[mid], key) > 0)
        return BinarySearchRec(array, left, mid - 1, key, comparer);
      return mid;
    }

    return -1;
  }
};
#endif
