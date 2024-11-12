// CS 211 Fall 2024 - Week 09 Lab
// <NAMES HERE>

//---------------------------------------------------------------
// File: ArrayQueue.cpp
// Purpose: Implementation file for a queue
//---------------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
#include "ArrayQueue.h"

using namespace std;

//--------------------------------------------
// CONSTRUCTORS
//--------------------------------------------

ArrayQueue::ArrayQueue() {
    queueArray = new T[QUEUE_SIZE];
    frontIndex = 0;
    backIndex = 0;
    queueEmpty = true;
}

ArrayQueue::~ArrayQueue() {
    delete [] queueArray;
}

//--------------------------------------------
// isFull: void -> bool
// Purpose: Returns true is queue is full
// Side Effects: None
//--------------------------------------------

bool ArrayQueue::isFull() {
    cout << "CALLED isFull ";  // REMOVE THIS LINE
    return false;              // REMOVE THIS LINE
}

//--------------------------------------------
// isEmpty: void -> bool
// Purpose: Returns true if queue is empty
// Side Effects: None
//--------------------------------------------

bool ArrayQueue::isEmpty() {
    cout << "CALLED isEmpty "; // REMOVE THIS LINE
    return true;               // REMOVE THIS LINE
}

//--------------------------------------------
// firstEl: void -> T
// Purpose: Returns element at head of queue
// Side Effects: None
//--------------------------------------------

T ArrayQueue::firstEl() {
    cout << "CALLED firstEL ";  // REMOVE THIS LINE
    return -99999;              // REMOVE THIS LINE
}

//--------------------------------------------
// clearQueue: void -> void
// Purpose: Removes all items from the queue
// Side Effects: resets queue to empty
//--------------------------------------------

void ArrayQueue::clearQueue() {
    cout << "CALLED clearQueue ";  // REMOVE THIS LINE
}

//--------------------------------------------
// enQueue: T -> bool
// Purpose: Returns true if element successfully added
// Side Effects: Adds element to queue
//--------------------------------------------

bool ArrayQueue::enQueue(T el) {
    cout << "CALLED enQueue ";  // REMOVE THIS LINE
    return false;               // REMOVE THIS LINE
}

//--------------------------------------------
// deQueue: void -> T
// Purpose: Returns element at front of queue
// Side Effects: Removes element from queue
//--------------------------------------------

T ArrayQueue::deQueue() {
    cout << "CALLED deQueue ";  // REMOVE THIS LINE
    return -99999;              // REMOVE THIS LINE
}

//--------------------------------------------
// printArray: void -> void
// Purpose: Private method prints array values
//--------------------------------------------

void ArrayQueue::printArray() {
    cout << "*** Contents of array ***" << endl;
    cout << "Front at index " << frontIndex
         << ", Back at index " << backIndex << endl;
    for (int i=0; i<QUEUE_SIZE; i++) {
        cout << i << ":" << queueArray[i] << " ";
    }
    cout << endl;
    cout << "*************************" << endl;
}

