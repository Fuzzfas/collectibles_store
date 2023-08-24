/**@file BST.h*/

/*
Tin Khuong
   Student ID: 0421141
   CSS 502B
   Program 4
   Prof. Clark Olson
   2/25/20

  BST Class: This class will act as a Binary Search Tree to contain all types of Comparables (including Customers and Items).
   Pointers to Comparable objects are stored within a BSTNode. The Store class will pass information to this
   class in order to build the Binary Search Tree. Inorder traversal can be performed to visit all Comparables according to their
   sorting criteria.

*/

#include "BST.h"

//-------------------------------- BST Node Methods ---------------------------------

/*-------------------------------- Default Constructor ---------------------------------
@pre A BST object exists to call this constructor.
@post Creates a new BSTNode object.
*/
BST::BSTNode::BSTNode()
{
   data = nullptr;
   left = nullptr;
   right = nullptr;
}

/*-------------------------------- Destructor ---------------------------------
 @pre A BSTNode object exists.
 @post Deallocates memory associated with this object.
 */
BST::BSTNode::~BSTNode()
{
   if(data != nullptr)
   {
      delete data;
      data = nullptr;
   }
}
//-------------------------------- End BST Node Methods ---------------------------------

//-------------------------------- BST Methods ---------------------------------

/*-------------------------------- Default Constructor ---------------------------------
@pre A Store object exists to call this constructor.
@post Creates a new BSTNode object.
*/
BST::BST()
{
   root = nullptr;
}

/*-------------------------------- Destructor ---------------------------------
@pre A BST Object exists.
@post Calls destroyTree() to recursively deallocate memory associated with this object.
*/
BST::~BST()
{
   destroyTree(root);
}

/*-------------------------------- destroyTree ---------------------------------
Recursive helper method used by Destructor.
@pre Destructor has been called.
@post Recursively deallocates memory associated with this object in post order.
*/
void BST::destroyTree(BSTNode* subTreePtr)
{
   if (subTreePtr != nullptr)
   {
      destroyTree(subTreePtr->left);
      destroyTree(subTreePtr->right);
      if(subTreePtr->data != nullptr)
      {
         delete subTreePtr->data;
         subTreePtr->data = nullptr;
      }
      delete subTreePtr;
      subTreePtr = nullptr;
   }
}

/*-------------------------------- insert ---------------------------------
@pre A Store object exists, has an InvTable which calls add(), which will call this method using parameters
   frome external text file. Comparable comparison operators assumed
   to be overridden.
@post Calls insert() helper method, returns true if insert was successful, false if not.
*/
bool BST::insert(Comparable* entry)
{
   //Call Helper method
   bool result = true;
   insert(entry, root, result);
   return result;
}

/*-------------------------------- insert ---------------------------------
Recursive helper method used by add
@pre A Store object exists, has an InvTable which calls add(), which will call this method using parameters
   frome external text file. Comparable comparison operators assumed
   to be overridden.
@post If successful, will create a new BSTNode object and set data to point to entry, otherwise returns false.
*/
bool BST::insert(Comparable* entry, BSTNode*& subTreePtr, bool& result)
{
   if (subTreePtr != nullptr)
   {

      if (DEBUG == true)
      {
         cout << "current node != nullptr" << endl;
      }
   
      //Pre Order Traversal
      if (*(subTreePtr->data) == *entry) //If duplicate is found
      {
         if (DEBUG == true)
         {
            cout << "duplicate entry exists, BST insert = false " << endl;
         }

         result = false;
         return result;
         
      }
      else if (*(subTreePtr->data) > * entry) //Entry is less than current node's data
      {
         return insert(entry, subTreePtr->left, result); //Try left child
      }
      else//Entry is greater than current node's data
      {
         return insert(entry, subTreePtr->right, result); //Try right child
      }
   }
   else //Entry not found, add new entry
   {
      if (DEBUG == true)
      {
         cout << "New entry, BST insert = true" << endl;
      }

      subTreePtr = new BSTNode;
      subTreePtr->data = entry;
      return result;
   }
   return result;
}

/*-------------------------------- getExistingEntry ---------------------------------
Recursive method that uses PreOrder traversal to find and return an existing Comparable Entry.
@pre Called by InvTable class to update existing item quantities. Comparable comparison operators assumed
   to be overridden.
@post Recursively traverses BST by passing in its root as a parameter.
*/
Comparable* BST::getExistingEntry(Comparable* entry)
{
   return getExistingEntry(entry, root);
}

/*-------------------------------- getExistingEntry ---------------------------------
Recursive helper method that uses PreOrder traversal to find and return an existing Comparable Entry.
@pre Called by InvTable class to update existing item quantities. Comparable comparison operators assumed
   to be overridden.
@post Recursively traverses BST, finds and returns pointer to existing matching entry.
*/
Comparable* BST::getExistingEntry(Comparable* entry, BSTNode*& subTreePtr)
{
   if (subTreePtr != nullptr)
   {
      //Pre Order Traversal
      if (*(subTreePtr->data) == *entry) //If duplicate is found
      {
         return subTreePtr->data;
      }
      else if (*(subTreePtr->data) > * entry) //Entry is less than current node's data
      {
         return getExistingEntry(entry, subTreePtr->left); //Try left child
      }
      else //Entry is greater than current node's data
      {
         return getExistingEntry(entry, subTreePtr->right); //Try right child
      }
   }
   else //Entry not found
   {
      return nullptr;
   }
}

/*-------------------------------- displayInOrder ---------------------------------
Recursive method that uses In Order traversal to display all Comparable contents in the BST.
@pre A Store object exists and has called history() or display(). Assumes printContents() has been overridden for 
   derived classes of Comparable.
@post Recursively traverses BST, calls printContents() of each Comparable object visited to output info.
*/
void BST::displayInOrder()const
{
   displayInOrder(root);
}

/*-------------------------------- displayInOrder ---------------------------------
Recursive method that uses In Order traversal to display all Comparable contents in the BST.
@pre A Store object exists and has called history() or display(). Assumes printContents() has been overridden for 
   derived classes of Comparable.
@post Recursively traverses BST, calls printContents() of each Comparable object visited to output info.
*/
void BST::displayInOrder(BSTNode* subTreePtr)const
{
   if (subTreePtr != nullptr)
   {  
      //traverse left child
      displayInOrder(subTreePtr->left);
      
      //display contents of Comparable
      subTreePtr->data->printContents();

      //traverse right child
      displayInOrder(subTreePtr->right);
   }
}


