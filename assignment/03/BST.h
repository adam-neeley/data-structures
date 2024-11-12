// CS 211 Fall 2024 - Assignment 03
// <INSERT YOUR NAME HERE>

#ifndef BST_H
#define BST_H

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

// Set data type of node contents
typedef int T;


//   class: BSTNode
//
//   purpose: To create a BSTNode for use in a BST
//   NOTE: All code for the class is in this .h file
//   Do NOT alter this class's code in any way!
//   by: David Tuttle
//   last modified: 03 Nov 2024

class BSTNode {
public:
    // Two constructors:
    //    BSTNode() creates an "empty" node with no value for el
    //    BSTNode() crates a node with the given el value and
    //              (optionally) two pointers to "children"
    BSTNode(): leftChild(NULL), rightChild(NULL) {}
    BSTNode(T e, BSTNode *l = NULL, BSTNode *r = NULL)
           { el = e; leftChild = l; rightChild = r; }

    // Accessors
    T getEl()                { return el; }
    BSTNode *getLeftChild()  { return leftChild; }
    BSTNode *getRightChild() { return rightChild; }

    // Mutators
    void setEl(T newEl)            { el = newEl; }
    void setLeftChild(BSTNode *p)  { leftChild = p; }
    void setRightChild(BSTNode *p) { rightChild = p; }

private:
    T el;
    BSTNode *leftChild;
    BSTNode *rightChild;
};


//   class: BST
//
//   purpose: To implement a binary search tree
//   using the given BSTNode class
//     *   Constructor BST() sets root pointer to NULL
//     *   isEmpty returns TRUE if the tree is empty
// 	   *   search returns TRUE if value is found in tree
//     *   breadthFirstTraversal prints out node values
// 	   *   insert places a node into tree

class BST {
public:
    // Constructor
    BST(): root(NULL) {}

    // Accessor
    BSTNode *getRoot() { return root; }

    // Methods
    bool isEmpty() const;
    bool search(T el) const;
    void breadthFirstTraversal() const;
    bool insert(T el);

    // *****************************************************
    // METHODS TO BE WRITTEN
    // *****************************************************

    void preorderTraversal() const;
    void inorderTraversal() const;
    void postorderTraversal() const;

    int countNodes() const;
    int countLeafs() const;
    int countInterior() const;
    int treeHeight() const;

    bool deleteNode(T el);
    bool leftRotation(BSTNode& gr, BSTNode& par, BSTNode& ch);
    bool rightRotation(BSTNode& gr, BSTNode& par, BSTNode& ch);

private:
    BSTNode *root;

};

#endif /* BST_H */

