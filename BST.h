/**@file BST.h*/

/*
Tin Khuong
   Student ID: 0421141
   CSS 502B
   Program 4
   Prof. Clark Olson
   2/25/20

  This class will act as a Binary Search Tree to contain all of the store’s customers. Pointers to Customer objects are stored within a BSTNode. 
  The Store class will pass information to this class in order to build the Binary Search Tree. 
  Inorder traversal can be performed to visit all Customers in alphabetical order.
*/

#pragma once
#include "Comparable.h"
class BST
{
private:

   struct BSTNode
   {
      Comparable* data = nullptr; //Pointer to Comparable object
      BSTNode* left = nullptr; //Left child
      BSTNode* right = nullptr; //Right child

      //-------------------------------- BST Node Methods ---------------------------------

      /*-------------------------------- Default Constructor ---------------------------------
      @pre A BST object exists to call this constructor.
      @post Creates a new BSTNode object.
      */
      BSTNode();
      
      /*-------------------------------- Destructor ---------------------------------
       @pre A BSTNode object exists.
       @post Deallocates memory associated with this object.

       Pseudocode:
         Delete Customer object pointed to by data

       */
      ~BSTNode();
   };

   BSTNode* root; //Root pointer to BST

   /*-------------------------------- destroyTree ---------------------------------
   Recursive helper method used by Destructor.
   @pre Destructor has been called.
   @post Recursively deallocates memory associated with this object in post order.
   */
   void destroyTree(BSTNode* subTreePtr);

   /*-------------------------------- insert ---------------------------------
   @pre A Store object exists, has an InvTable which calls add(), which will call this method using parameters
      frome external text file. Comparable comparison operators assumed
      to be overridden.
   @post Calls insert() helper method, returns true if insert was successful, false if not.
   */
   bool insert(Comparable* entry, BSTNode*& subTreePtr, bool& result);

   /*-------------------------------- getExistingEntry ---------------------------------
   Recursive helper method that uses PreOrder traversal to find and return an existing Comparable Entry.
   @pre Called by InvTable class to update existing item quantities. Comparable comparison operators assumed
      to be overridden.
   @post Recursively traverses BST, finds and returns pointer to existing matching entry.
   */
   Comparable* getExistingEntry(Comparable* entry, BSTNode*& subTreePtr);

   /*-------------------------------- displayInOrder ---------------------------------
   Recursive method that uses In Order traversal to display all Comparable contents in the BST.
   @pre A Store object exists and has called history() or display(). Assumes printContents() has been overridden for
      derived classes of Comparable.
   @post Recursively traverses BST, calls printContents() of each Comparable object visited to output info.
   */
   void displayInOrder(BSTNode* subTreePtr)const;

public:

   /*-------------------------------- Default Constructor ---------------------------------
   @pre A Store object exists to call this constructor.
   @post Creates a new BST object.
   */
   BST();

   /*-------------------------------- Destructor ---------------------------------
   @pre A BST Object exists.
   @post Calls destroyTree() to recursively deallocates memory associated with this object.
   */
   ~BST();

   /*-------------------------------- insert ---------------------------------
   @pre A Store object exists, has an InvTable which calls add(), which will call this method using parameters
      frome external text file. Comparable comparison operators assumed
      to be overridden.
   @post Calls insert() helper method, returns true if insert was successful, false if not.
   */
   bool insert(Comparable* entry);

   /*-------------------------------- displayInOrder ---------------------------------
   Recursive method that uses In Order traversal to display all Comparable contents in the BST.
   @pre A Store object exists and has called history() or display(). Assumes printContents() has been overridden for
      derived classes of Comparable.
   @post Recursively traverses BST, calls printContents() of each Comparable object visited to output info.
   */
   void displayInOrder()const;
   
   /*-------------------------------- getExistingEntry ---------------------------------
   Recursive method that uses PreOrder traversal to find and return an existing Comparable Entry.
   @pre Called by InvTable class to update existing item quantities. Comparable comparison operators assumed
      to be overridden.
   @post Recursively traverses BST by passing in its root as a parameter.
   */
   Comparable* getExistingEntry(Comparable* entry);

};

