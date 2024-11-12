// CS 211 Fall 2024 - Assignment 03
// adam neeley

//----------------------------------------------------
// File: BST.cpp
// Purpose: Implementation file for a demonstration
// of a basic binary tree
//
//----------------------------------------------------

#include "BST.h"
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

//--------------------------------------------
// Function: isEmpty()
// Purpose: determine whether a BST has no nodes
// Returns: a boolean - true if empty
//--------------------------------------------

bool BST::isEmpty() const { return (root == NULL); }

//--------------------------------------------
// Function: search(T)
// Purpose: search for a value in a binary tree
// Returns: a boolean - true is found, false if not
//--------------------------------------------

bool BST::search(int el) const {

  // Set ptr to root of tree (if tree is empty, ptr becomes NULL)
  BSTNode *p = root;
  T currVal; // Current value of the BSTNode that p points to

  // Descend the tree to search for the given input value
  while (p != NULL) {

    // Descend the tree until we find a node with the given value
    // If we hit a leaf before finding the value, it's not in the tree
    currVal = p->getEl();
    if (el < currVal)
      p = p->getLeftChild();
    else if (el > currVal)
      p = p->getRightChild();
    else
      // Value found!  Return true
      return true;
  }

  // If we reach this point, then we fell out of the search loop
  // without finding anything.  Return false
  return false;
}

//--------------------------------------------
// Function: breadthFirstTraversal()
// Purpose: Expects nothing, returns nothing
// Side Effects: prints values in breadth-first order
//--------------------------------------------

void BST::breadthFirstTraversal() const {
  const int QUEUE_SIZE = 50;
  BSTNode *queue[QUEUE_SIZE];
  int headIndex = 0;
  int tailIndex = 0;

  if (root == NULL) {
    cout << "*** Tree is empty ***" << endl;
    return;
  }

  queue[tailIndex] = root;

  while (headIndex != tailIndex + 1) {
    if (queue[headIndex]->getLeftChild() != NULL) {
      tailIndex = (tailIndex + 1) % QUEUE_SIZE;
      queue[tailIndex] = queue[headIndex]->getLeftChild();
    }
    if (queue[headIndex]->getRightChild() != NULL) {
      tailIndex = (tailIndex + 1) % QUEUE_SIZE;
      queue[tailIndex] = queue[headIndex]->getRightChild();
    }
    cout << queue[headIndex]->getEl() << " ";
    headIndex = (headIndex + 1) % QUEUE_SIZE;
  }
  cout << endl;
}

//--------------------------------------------
// Function: insert(T)
// Purpose: insert a BSTNode into the BST
// Returns: true is successful, false if not
//--------------------------------------------

bool BST::insert(T el) {
  // Pointers to keep track of where we are in descending
  // through the tree to find an insertion point
  BSTNode *p = root;
  BSTNode *prev = NULL;
  T currVal;

  // If tree is empty, then insert the first node at root

  if (this->isEmpty()) {
    root = new BSTNode(el);
    return true;
  }

  // Descend the tree for a proper place to put the input value
  // The input value will become a new leaf on the tree
  // NOTE: This does NOT perform any tree balancing!

  while (p != NULL) {
    // prev remembers where we were, so when ptr becomes
    // NULL, prev will point to the node where we will
    // attach the new value as a child
    prev = p;

    // Descend the tree until we hit a leaf - go left if value
    // is less than current node, go right if greater
    currVal = p->getEl();
    if (el < currVal)
      p = p->getLeftChild();
    else if (el > currVal)
      p = p->getRightChild();
    else {
      // If the value matches one already in the tree, we
      // DON'T add it to the tree and simply return
      cout << "Value NOT inserted - already in the tree! \n";
      return false;
    }
  }

  // If we get here, we've found the place to attach the new node
  // Create the new node and attach it to the node that prev
  // is pointing to

  if (el < prev->getEl())
    prev->setLeftChild(new BSTNode(el));
  else
    prev->setRightChild(new BSTNode(el));
  return true;
}

// **********************************************************
// ADD CODE FOR METHODS HERE
// **********************************************************

void BST::preorderTraversal() const {}

void BST::inorderTraversal() const {}

void BST::postorderTraversal() const {}

int BST::countNodes() const {
  return 0; // DELETE THIS LINE
}

int BST::countLeafs() const {
  return 0; // DELETE THIS LINE
}

int BST::countInterior() const {
  return 0; // DELETE THIS LINE
}

int BST::treeHeight() const {
  return -1; // DELETE THIS LINE
}

bool BST::deleteNode(T el) {
  return false; // DELETE THIS LINE
}

bool BST::leftRotation(BSTNode &gr, BSTNode &par, BSTNode &ch) {
  return false; // DELETE THIS LINE
}

bool BST::rightRotation(BSTNode &gr, BSTNode &par, BSTNode &ch) {
  return false; // DELETE THIS LINE
}
