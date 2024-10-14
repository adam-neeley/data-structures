// CS 211 Fall 2024 - Assignment 02 Test File
// Do NOT Submit This File With Your Assignment!

#include "assn2.h"
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  cout << boolalpha;

  // UNCOMMENT the following code when you're ready to
  // run tests

  cout << endl << "*** TESTING addCommas ***" << endl;

  unsigned long long int initial_n;
  cout << "Please enter a non-negative integer value: ";
  cin >> initial_n;
  cout << "The number with commas is: ";
  addCommas(initial_n);
  cout << " \n";

  cout << "*** TESTING Class DoublyLinkedList ***" << endl;
  double el; // Place to hold a node's value

  cout << "Simple DLL Demonstration\n";
  cout << "Creating a DLL\n";

  DoublyLinkedList *theDLLPtr = new DoublyLinkedList(); // Create a DLL object

  cout << "DLL created...\n";

  // Test Insert and Delete methods

  el = 100;
  cout << "Inserting value " << el << " at end of DLL\n";
  theDLLPtr->addToDLLTail(el);
  el = 200;
  cout << "Inserting value " << el << " at end of DLL\n";
  theDLLPtr->addToDLLTail(el);
  el = 300;
  cout << "Inserting value " << el << " at end of DLL\n";
  theDLLPtr->addToDLLTail(el);
  el = 400;
  cout << "Inserting value " << el << " at end of DLL\n";
  theDLLPtr->addToDLLTail(el);
  el = 500;
  cout << "Inserting value " << el << " at end of DLL\n";
  theDLLPtr->addToDLLTail(el);

  cout << "Deleting from tail of DLL \n";
  el = theDLLPtr->deleteFromDLLTail();
  cout << "Got back value " << el << "\n";
  cout << "Deleting from tail of DLL \n";
  el = theDLLPtr->deleteFromDLLTail();
  cout << "Got back value " << el << "\n";

  // Insert inputted numbers into the DLL
  cout << "Enter the first number (-1 stops input): ";
  cin >> el;
  while (el != -1) {
    theDLLPtr->addToDLLTail(el);
    cout << "Enter the next number (-1 stops input): ";
    cin >> el;
  }

  // Delete DLLNodes and print their values
  cout << "Time to delete some DLLNodes!  \n";
  el = theDLLPtr->deleteFromDLLTail();
  cout << "Deleted " << el << " from DLL \n";
  el = theDLLPtr->deleteFromDLLTail();
  cout << "Deleted " << el << " from DLL \n";
  el = theDLLPtr->deleteFromDLLTail();
  cout << "Deleted " << el << " from DLL \n";

  // UNCOMMENT the following code when you're ready to
  // run tests

  cout << endl << "*** TESTING addToDLLHead, deleteFromDLLHead ***" << endl;

  el = 1000;
  cout << "Inserting value " << el << " at head of DLL\n";
  theDLLPtr->addToDLLHead(el);
  el = 2000;
  cout << "Inserting value " << el << " at head of DLL\n";
  theDLLPtr->addToDLLHead(el);
  el = 3000;
  cout << "Inserting value " << el << " at head of DLL\n";
  theDLLPtr->addToDLLHead(el);

  // Delete DLLNodes from head and print their values
  cout << "Time to delete some DLLNodes!  \n";
  el = theDLLPtr->deleteFromDLLHead();
  cout << "Deleted " << el << " from DLL \n";
  el = theDLLPtr->deleteFromDLLHead();
  cout << "Deleted " << el << " from DLL \n";
  el = theDLLPtr->deleteFromDLLHead();
  cout << "Deleted " << el << " from DLL \n";

  cout << "...done.\n";

  return EXIT_SUCCESS;
}
