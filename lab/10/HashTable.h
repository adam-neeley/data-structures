// CS 211 Fall 2024 - Week 10 Lab
// Adam Neeley
// Richard Bennett

//  class: HashTable
//
//  purpose: To implement a hash table of int values

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

// We'll set a typedef statement here
// The type T represents the data type stored in the hash table
// For the data type stored in the hash table buckets,
// it'd be great if you used T instead of int in your code :-)

typedef unsigned int T;

class HashTable {
public:
  // For the zero-argument constructor, use this
  // constant for the size of the table

  const int DEFAULT_TABLE_SIZE = 17;

  // Value to initialize the empty buckets

  const int EMPTY_VALUE = 0;

  // Constructors
  //    Create an "empty" hash table and
  //    initialize its values

  HashTable();
  HashTable(int table_size);

  // Destructor
  ~HashTable();

  // Accessors
  int getSize() const;

  // Mutators
  bool insertValue(T);
  bool deleteValue(T);

  // Othe Methods
  bool searchValue(T);
  void printTable() const;

private:
  int hashFunc(T) const;
  void nextIndex(int &);
  bool bucketAvailable(int) const;

  int tableSize;   // size of hash table
  T *tableValues;  // pointer to array (substitute vector if desired)
  bool *isDeleted; // pointer to array (substitute vector if desired)
};

#endif /* HASHTABLE_H */
