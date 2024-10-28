// CS 211 Fall 2024 - Week 10 Lab
// Adam Neeley
// Richard Bennett

//----------------------------------------------------
// File: HashTable.cpp
// Purpose: Implementation file for a hash table class
//----------------------------------------------------

#include "HashTable.h"
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// CONSTRUCTORS

HashTable::HashTable() {
  tableSize = DEFAULT_TABLE_SIZE;
  // INSERT NEEDED CODE HERE
  tableValues = new T[tableSize];
  isDeleted = new bool[tableSize];
  for (int i = 0; i < tableSize; i++) {
    tableValues[i] = 0;
    isDeleted[i] = false;
  }
}

HashTable::HashTable(int size) {
  if (size <= 1)
    tableSize = DEFAULT_TABLE_SIZE;
  else
    tableSize = size;
  // INSERT NEEDED CODE HERE
  tableValues = new T[tableSize];
  isDeleted = new bool[tableSize];
  for (int i = 0; i < tableSize; i++) {
    tableValues[i] = 0;
    isDeleted[i] = false;
  }
}

// DESTRUCTOR

HashTable::~HashTable() {
  // INSERT NEEDED CODE HERE
}

// ACCESSORS

int HashTable::getSize() const { return tableSize; }

// MUTATORS

bool HashTable::insertValue(T value) {
  if (value == EMPTY_VALUE) {
    cout << "*** CANNOT INSERT EMPTY_VALUE! ***\n";
    return false;
  }
  // INSERT NEEDED CODE HERE
  int index = this->hashFunc(value);
  for (int i = 0; i < this->getSize(); i++) {
    if (this->bucketAvailable(index)) {
      tableValues[index] = value;
      isDeleted[index] = false;
      return true;
    }
    nextIndex(index);
  }
  return false;
}

bool HashTable::deleteValue(T value) {
  // INSERT NEEDED CODE HERE

  for (int i = 0; i < getSize(); i++) {
    if (tableValues[i] == value) {
      tableValues[i] = EMPTY_VALUE;
      isDeleted[i] = true;
      return true;
    }
  }
  return false;
}

// OTHER METHODS

bool HashTable::searchValue(T value) {
  int index = this->hashFunc(value);
  for (int i = 0; i < getSize(); i++) {
    if (tableValues[index] == value)
      return true;
    this->nextIndex(index);
  }
  return false;
}

void HashTable::printTable() const {
  // INSERT NEEDED CODE HERE
  cout << "Table size = " << getSize();
  cout << ", contents =";
  for (int i = 0; i < getSize(); i++) {
    if (!bucketAvailable(i))
      cout << " " << tableValues[i];
    else
      cout << " X";
  }
  cout << endl;
  cout << "printTable called\n"; // DELETE THIS LINE
}

// PRIVATE METHODS

int HashTable::hashFunc(T value) const { return (value * value) % tableSize; }

void HashTable::nextIndex(int &currentIndex) {
  currentIndex = (currentIndex + 1) % tableSize;
}
// int HashTable::nextIndex2(int currentIndex) {
//   return (currentIndex + 1) % tableSize;
// }

bool HashTable::bucketAvailable(int currentIndex) const {
  return (tableValues[currentIndex] == EMPTY_VALUE) || isDeleted[currentIndex];
}
