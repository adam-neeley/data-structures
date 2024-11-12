//    CS 211 Fall 2024 - Programming Assignment 03
//    Binary Search Tree methods
//
//    Last Modified: 03 Nov 2024
//    DO NOT SUBMIT THIS FILE!
//    You may alter it to perform more tests if desired

#include <cstdlib>
#include <iostream>
#include <string>
#include "BST.h"

using namespace std;

int main() {
    cout << boolalpha;

    // Create some test trees to perform tests with

    int t1Nodes[7] = {20, 10, 30, 5, 15, 25, 35};
    int t2Nodes[20] = {500, 250, 750, 150, 350,
                       650, 850, 125, 175, 325,
                       375, 625, 675, 825, 875,
                       110, 330, 670, 870, 873};
    int t3Nodes[6] = {6, 5, 4, 3, 2, 1};
    // tree4 will be a tree with one node with value 1000
    // tree5 will be an empty tree with no nodes

    // Pointers for rotation tests - child, parent, grandparent
    BSTNode *chPtr, *parPtr, *grPtr;

    // Create and populate the trees
    BST *tree1 = new BST();
    for (int i=0; i<7; i++)
        tree1->insert(t1Nodes[i]);

    BST *tree2 = new BST();
    for (int i=0; i<20; i++)
        tree2->insert(t2Nodes[i]);

    BST *tree3 = new BST();
    for (int i=0; i<6; i++)
        tree3->insert(t3Nodes[i]);

    BST *tree4 = new BST();
    tree4->insert(1000);

    BST *tree5 = new BST();

    //*******************************************
    // Demontration of exampleTraversal on tree1
    //*******************************************

    // tree1 starts as:
    //               +----20----+
    //           +--10--+    +--30--+
    //           5     15    25    35

    cout << "*** READY FOR TESTING! ***" << endl;

    // UNCOMMENT LINES BELOW TO RUN TESTS USING ALL THE TREES

   cout << endl << "*** TREE 1 TEST ***";
   cout << endl << "Preorder traversal" << endl << "    ";
   tree1->preorderTraversal();
   cout << endl << "Inorder traversal" << endl << "    ";
   tree1->inorderTraversal();
   cout << endl << "Postorder traversal" << endl << "    ";
   tree1->postorderTraversal();
   cout << endl << "Node count (should be 7): "
        << tree1->countNodes() << endl;
   cout << "Leaf count (should be 4): "
        << tree1->countLeafs() << endl;
   cout << "Interior count (should be 3): "
        << tree1->countInterior() << endl;
   cout << "Tree height (should be 2): "
        << tree1->treeHeight() << endl;
   cout << endl;

   cout << endl << "Breadth Traversal of tree1" << endl << "  ";
   tree1->breadthFirstTraversal();
   cout << endl;

   cout << endl << "Deleting interior node 10: "
        << tree1->deleteNode(10) << endl;
   cout << endl << "Deleting interior node 20: "
        << tree1->deleteNode(20) << endl;

   cout << endl << "Breadth Traversal of tree1" << endl << "  ";
   tree1->breadthFirstTraversal();
   cout << endl;

   cout << endl << "*** TREE 2 TEST ***";
   cout << endl << "Preorder traversal" << endl << "  ";
   tree2->preorderTraversal();
   cout << endl << "Inorder traversal" << endl << "  ";
   tree2->inorderTraversal();
   cout << endl << "Postorder traversal" << endl << "  ";
   tree2->postorderTraversal();
   cout << endl << "Node count (should be 20): "
        << tree2->countNodes() << endl;
   cout << "Leaf count (should be 8): "
        << tree2->countLeafs() << endl;
   cout << "Interior count (should be 12): "
        << tree2->countInterior() << endl;
   cout << "Tree height (should be 5): "
        << tree2->treeHeight() << endl;
   cout << endl;

   cout << "Perform Left Rotation on tree2: ";
   grPtr = tree2->getRoot();
   parPtr = tree2->getRoot()->getRightChild();
   chPtr = tree2->getRoot()->getRightChild()->getRightChild();
   cout << tree2->leftRotation(*grPtr, *parPtr, *chPtr) << endl;

   cout << "Breadth Traversal of tree2" << endl << "  ";
   tree2->breadthFirstTraversal();
   cout << endl;

   cout << "Perform Right Rotation on tree2: ";
   grPtr = tree2->getRoot();
   parPtr = tree2->getRoot()->getLeftChild();
   chPtr = tree2->getRoot()->getLeftChild()->getLeftChild();
   cout << tree2->rightRotation(*grPtr, *parPtr, *chPtr) << endl;

   cout << endl << "Breadth Traversal of tree2" << endl << "  ";
   tree2->breadthFirstTraversal();
   cout << endl;

   cout << "The next two calls should return false!" << endl;
   cout << "(The nodes are not in the correct relative positions): ";
   cout << tree2->leftRotation(*grPtr, *parPtr, *chPtr) << " ";
   cout << tree2->rightRotation(*grPtr, *parPtr, *chPtr) << endl;

   cout << endl << "Breadth Traversal of tree2" << endl << "  ";
   tree2->breadthFirstTraversal();
   cout << endl;

   cout << endl << "*** TREE 3 TEST ***";
   cout << endl << "Preorder traversal" << endl << "  ";
   tree3->preorderTraversal();
   cout << endl << "Inorder traversal" << endl << "  ";
   tree3->inorderTraversal();
   cout << endl << "Postorder traversal" << endl << "  ";
   tree3->postorderTraversal();
   cout << endl << "Node count (should be 6): "
        << tree3->countNodes() << endl;
   cout << "Leaf count (should be 1): "
        << tree3->countLeafs() << endl;
   cout << "Interior count (should be 5): "
        << tree3->countInterior() << endl;
   cout << "Tree height (should be 5): "
        << tree3->treeHeight() << endl;
   cout << endl;

   cout << endl << "*** TREE 4 TEST ***";
   cout << endl <<"Preorder traversal" << endl << "  ";
   tree4->preorderTraversal();
   cout << endl << "Inorder traversal" << endl << "  ";
   tree4->inorderTraversal();
   cout << endl << "Postorder traversal" << endl << "  ";
   tree4->postorderTraversal();
   cout << endl << "Node count (should be 1): "
        << tree4->countNodes() << endl;
   cout << "Leaf count (should be 1): "
        << tree4->countLeafs() << endl;
   cout << "Interior count (should be 0): "
        << tree4->countInterior() << endl;
   cout << "Tree height (should be 0): "
        << tree4->treeHeight() << endl;
   cout << endl;

   cout << endl << "*** TREE 5 TEST ***";
   cout << endl << "Preorder traversal" << endl << "  ";
   tree5->preorderTraversal();
   cout << endl << "Inorder traversal" << endl << "  ";
   tree5->inorderTraversal();
   cout << endl << "Postorder traversal" << endl << "  ";
   tree5->postorderTraversal();
   cout << endl << "Node count (should be 0): "
        << tree5->countNodes() << endl;
   cout << "Leaf count (should be 0): "
        << tree5->countLeafs() << endl;
   cout << "Interior count (should be 0): "
        << tree5->countInterior() << endl;
   cout << "Tree height (should be -1): "
        << tree5->treeHeight() << endl;
   cout << endl;

    return EXIT_SUCCESS;
}
