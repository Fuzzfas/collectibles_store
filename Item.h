/**@file Item.h*/

/*
Tin Khuong
   Student ID: 0421141
   CSS 502B
   Program 4
   Prof. Clark Olson
   2/25/20

   Item will serve as a base class for the three types of items to be tracked in this particular assignment: Coins, Comic books, and Sports cards. 
   The derived classes will be labeled Coin, Comic, and SportsCard, respectively. 
   These derived classes will contain Data Members specific for that item type, while Item will contain Data Members and Operations common to all item types. 
   Each of the derived classes will also contain overridden comparison operators to assist with sorting.
*/

#pragma once
#include<string>
#include<iostream>
#include <sstream>
#include "Comparable.h"
using namespace std;

//const bool DEBUG = true;

class Item : public Comparable
{
protected: //protected allows derived classes to access this

   int quantity; //Quantity of items stored in inventory. Cannot be less than 0.
   char itemType; /*identifier denoting type of item. 
                    Valid Identifiers:
                    M = Coin (ASCII value: 77)
                    C = Comic Book (ASCII value: 67)
                    S = Sports card (ASCII value: 83)
                    Z = Invalid Entry (ASCII value: 90)
                    */

public:

   /*-------------------------------- Default Constructor ---------------------------------
   @pre A Store Object exists. 
   @post Creates a new Item object and initializes fields to default values.
   */
   Item();

   /*-------------------------------- Parameterized Constructor ---------------------------------
   @pre A Store Object exists. A derived class of Item calls this constructor from the create() method.
   @post Creates a new Item object and assigns itemType and quantity from parameter.
   */
   Item(char itemType, int quantity);

   /*-------------------------------- Destructor ---------------------------------
   @pre An Item Object exists. 
   @post Deallocates memory associated with this object
   */
   virtual ~Item();

   /*-------------------------------- operator> ---------------------------------
   @pre rhs is a valid Item object to compare. Overrides Comparable operator>
   @post Returns true if this Item is greater than rhs, false if not.
   */
   virtual bool operator>(const Comparable& rhs)const;

   /*-------------------------------- operator< ---------------------------------
   @pre rhs is a valid Item object to compare. Overrides Comparable operator>
   @post Returns true if this Item is lesser than rhs, false if not.
   */
   virtual bool operator<(const Comparable& rhs)const;

   /*-------------------------------- operator== ---------------------------------
   @pre rhs is a valid Item object to compare. Overrides Comparable operator==
   @post Returns true if this Item is equal to rhs, false if not.
   */
   virtual bool operator==(const Comparable& rhs)const;

   /*-------------------------------- create() ---------------------------------
   @pre A Store object exists. itemFactory has called makeItem(), calling this method
   @post Calls constructor for this object and returns pointer to newly created item.
      Returns nullptr if not called from derived class.
   */
   virtual Item* create(int quantity, string input);

   /*-------------------------------- printContents() ---------------------------------
   @pre An Item object exists.
   @post Outputs data members of this Item.
   */
   virtual void printContents();

   /*-------------------------------- increaseQuantity() ---------------------------------
   @pre An Item object exists. Called when Store attempts to add duplicate items during inventory initialization
      or calls buy() if Item already exists in inventory.
   @post Increases the quantity of this item by 1.
   */
   void increaseQuantity();

   /*-------------------------------- decreaseQuantity() ---------------------------------
   @pre An Item object exists. Called when Store calls sell() if Item already exists.
   @post Decreases the quantity of this item by 1. Will output an error if it attempts to decrease quantity below 0.
   */
   void decreaseQuantity();
};

