/**@file Factory.h*/

/*
Tin Khuong
   Student ID: 0421141
   CSS 502B
   Program 4
   Prof. Clark Olson
   2/25/20

   The main purpose of this class is to use the factory method to decide which derived classes of Item to create.
   This class will take advantage of polymorphism in order to decide on which of derived classes to create. 
   The class will actually pass on pointers to newly created objects of derived classes to the InvClass for sorting and storage.

*/
#pragma once
#include "Item.h"
#include "Coin.h"
#include "Comic.h"
#include "SportsCard.h"
class Factory
{
private:

   static const int numTypes = 4; //The number of different possible item types that can be created
   static const int size = 26; //Maxmimum possible item types. It is assumed items will only be represented by a single capital letter
   Item* factoryTable[size]; //Array of pointers to derived classes of Item

public:

   /*-------------------------------- Default Constructor ---------------------------------
     @pre A Store object exists.
     @post Creates a Factory object.
     */
   Factory();

   /*-------------------------------- Destructor ---------------------------------
    @pre A Factory object exists.
    @post Deallocates memory associated with this object via traversal of factoryTable
    */
   virtual ~Factory();

   /*-------------------------------- factoryHash ---------------------------------
    @pre A Factory object exists. makeItem() has been called with a valid char parameter
    @post Returns an int (hash code) using char parameter.
    */
   int factoryHash(char itemType);

   /*-------------------------------- makeItem ---------------------------------
   Creates and returns a pointer to a derived class of Item, such as Coin, Comic, or SportsCard. Accepts a char from external text file as a parameter.
   @pre A Store object exists. External inventory content and command text files are formatted correctly
   @post Calls factoryHash() to determine item type to be created. Calls create() of derived class. Returns pointer to newly created derived class of Item.
      Otherwise returns nullptr if Item type is invalid.
   */
   Item* makeItem(char itemType, int quantity, string input);
};

