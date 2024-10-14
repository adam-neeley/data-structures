// CS 211 Fall 2024 - Assignment 02
// Adam Neeley

#include "assn2.h"
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

void addCommas(unsigned long long int theNumber) {
  if (theNumber < 1000) {
    cout << theNumber % 1000;
    return;
  } else {
    cout << theNumber % 1000;
    cout << ",";
  }
  addCommas(theNumber / 1000);
}

DoublyLinkedList::DoublyLinkedList() {
  headPtr = NULL;
  tailPtr = NULL;
}

void DoublyLinkedList::addToDLLHead(double el) {
  if (headPtr != NULL) {
    headPtr = new DLLNode(el, headPtr, 0);
    headPtr->nextPtr->prevPtr = headPtr;
  } else {
    tailPtr = new DLLNode(el);
    headPtr = tailPtr;
  }
}
double DoublyLinkedList::deleteFromDLLHead() {
  double el = headPtr->info;

  if (headPtr == NULL)
    throw("EMPTY");

  else if (headPtr == tailPtr) {
    delete headPtr;
    headPtr = NULL;
    tailPtr = NULL;
  }

  else {
    headPtr = headPtr->nextPtr;
    delete headPtr->prevPtr;
    headPtr->prevPtr = NULL;
  }
  return el;
}

void DoublyLinkedList::addToDLLTail(double el) {
  if (tailPtr != NULL) {
    tailPtr = new DLLNode(el, 0, tailPtr);
    tailPtr->prevPtr->nextPtr = tailPtr;
  } else {
    headPtr = new DLLNode(el);
    tailPtr = headPtr;
  }
}

double DoublyLinkedList::deleteFromDLLTail() {
  double el = tailPtr->info;

  if (tailPtr == NULL)
    throw("EMPTY");

  else if (headPtr == tailPtr) {
    delete headPtr;
    headPtr = NULL;
    tailPtr = NULL;
  }

  else {
    tailPtr = tailPtr->prevPtr;
    delete tailPtr->nextPtr;
    tailPtr->nextPtr = NULL;
  }
  return el;
}
