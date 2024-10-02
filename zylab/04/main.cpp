#include "SortedNumberList.h"
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  bool includeRemovals = false;

  // Numbers to insert during first loop:
  vector<double> numbersToInsert = {77.75, 15.25, -4.25, 63.5, 18.25,
                                    -3.5,  10,    200,   -30,  -4};
  vector<double> numbersToInsert2 = {9, 999, 99, 9, 9999, 99, 9999, 9};

  // Insert each number and print sorted list's contents after each insertion
  SortedNumberList list;
  cout << fixed << setprecision(2);
  for (auto number : numbersToInsert) {
    cout << "List after inserting " << number << ": ";
    list.Insert(number);
    list.Print(cout, ", ", "", "\n");
  }

  cout << endl;

  vector<double> numbersToRemove = {77.75, // List's last element
                                    -4.25, // List's first element
                                    18.25, // Neither first nor last element

                                    // Remaining elements:
                                    -3.5, 15.25, 63.5, 10, 200, -30, -4};
  vector<double> numbersToRemove2 = {9, 9999, 99, 9999, 9};

  // Remove numbers
  for (auto toRemove : numbersToRemove) {
    cout << "List after removing " << toRemove << ": ";
    list.Remove(toRemove);
    list.Print(cout, ", ", "", "\n");
  }

  //
  //

  // Insert each number and print sorted list's contents after each insertion
  cout << fixed << setprecision(2);
  for (auto number : numbersToInsert2) {
    cout << "List after inserting " << number << ": ";
    list.Insert(number);
    list.Print(cout, ", ", "", "\n");
  }

  // Remove numbers
  for (auto toRemove : numbersToRemove2) {
    cout << "List after removing " << toRemove << ": ";
    list.Remove(toRemove);
    list.Print(cout, ", ", "", "\n");
  }

  cout << endl;
  return 0;
}
