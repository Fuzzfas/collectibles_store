/**@file InvTable.h*/

/*
Tin Khuong
   Student ID: 0421141
   CSS 502B
   Program 4
   Prof. Clark Olson
   2/25/20

   This class will contain the entire store inventory. The Store class will pass information about the items to this class, and using the hash function(s), will decide which buckets of BSTs to pass the items into.
   It will be assumed that the maximum number of item types is 26 since each itemType is representing by a single capital letter in this program.
*/
#pragma once
#include "Item.h"
#include "BST.h"

class InvTable
{
private:

   static const int size = 26; //size of array
   BST table[size]; //array of BST, 1 for each type of item

public:

   /*-------------------------------- Default Constructor ---------------------------------
   @pre A Store Object has been created from Main. Store calls this constructor to initialize its inventory data member.
   @post Creates a new Customer object and assigns data members from parameters.
   */
   InvTable();

   /*-------------------------------- Destructor ---------------------------------
   @pre An InvTable Object exists.
   @post Deallocates memory associated with this object.
   */
   virtual ~InvTable();

   /*-------------------------------- Add ---------------------------------
   @pre A Store Object exists, and successfully reads external files containing inventory contents,
      customer list, and sequence of commands. Store will call buildInv() or buy(), which will call this method.
   @post Adds an Item object to inventory if successful. Otherwise, will return an error message if item is invalid,
   or may simply increase existing item quantity. Deallocates entry item if item is invalid.
   */
   void add(char itemType, Item* entry);

   /*-------------------------------- Remove ---------------------------------
   @pre A Store Object exists, and successfully reads external files containing inventory contents,
      customer list, and sequence of commands. Store will call sell(), which will call this method.
   @post Decreases the quantity of Item in inventory if it exists, otherwise will return an error if
   Item does not exists or quantity is already at 0.
   */
   void remove(char itemType, Item* entry);


   /*-------------------------------- hashFunction ---------------------------------
   @pre A Store Object exists, and successfully reads external files containing inventory contents,
      customer list, and sequence of commands. Used by the add(), remove() and displayInventory() methods.
   @post Returns a hash code (an integer) to determine which bucket to work with.
   */
   int hash(char itemType)const;

   /*-------------------------------- displayInventory ---------------------------------
   @pre A Store Object exists, and successfully reads external files containing inventory contents,
      customer list, and sequence of commands.
   @post Outputs current store inventory in this order: All Coins, then all Comics, then all Sports Cards.
   */
   void displayInventory()const;

};

