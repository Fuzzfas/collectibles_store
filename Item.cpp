/**@file Item.cpp*/

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
#include "Item.h"
#include <iostream>
using namespace std;

/*-------------------------------- Default Constructor ---------------------------------
@pre A Store Object exists.
@post Creates a new Item object and initializes fields to default values.
*/
Item::Item()
{
   itemType = 'Z';
   quantity = 0;

}

/*-------------------------------- Parameterized Constructor ---------------------------------
@pre A Store Object exists. A derived class of Item calls this constructor from the create() method.
@post Creates a new Item object and assigns itemType and quantity from parameter.
*/
Item::Item(char itemType, int quantity)
{
   this->itemType = itemType;
   this->quantity = quantity;
}

/*-------------------------------- Destructor ---------------------------------
@pre An Item Object exists.
@post Deallocates memory associated with this object
*/
Item::~Item()
{}

/*-------------------------------- operator> ---------------------------------
@pre rhs is a valid Item object to compare. Overrides Comparable operator>
@post Returns true if this Item is greater than rhs, false if not.
*/
bool Item::operator>(const Comparable& rhs)const
{
   const Item&i = static_cast<const Item &>(rhs); //Static cast from derived to base class

   if (DEBUG == true)
   {
      cout << "Compare item >" << endl;
   }

   return true;
}

/*-------------------------------- operator< ---------------------------------
@pre rhs is a valid Item object to compare. Overrides Comparable operator<
@post Returns true if this Item is lesser than rhs, false if not.
*/
bool Item::operator<(const Comparable& rhs)const
{

   if (DEBUG == true)
   {
      cout << "Compare item <" << endl;
   }

   return true;
}

/*-------------------------------- operator== ---------------------------------
@pre rhs is a valid Item object to compare. Overrides Comparable operator==
@post Returns true if this Item is equal to rhs, false if not.
*/
bool Item::operator==(const Comparable& rhs)const
{
   if (DEBUG == true)
   {
      cout << "Compare item ==" << endl;
   }

   return true;
}

/*-------------------------------- create() ---------------------------------
@pre A Store object exists. itemFactory has called makeItem(), calling this method
@post Calls constructor for this object and returns pointer to newly created item.
   Returns nullptr if not called from derived class.
*/
Item* Item::create(int quantity, string input)
{
   return nullptr;
}

/*-------------------------------- printContents() ---------------------------------
@pre An Item object exists. 
@post Outputs data members of this Item.
*/
void Item::printContents()
{
   cout << itemType << ", " << quantity << endl;

}

/*-------------------------------- increaseQuantity() ---------------------------------
@pre An Item object exists. Called when Store attempts to add duplicate items during inventory initialization 
   or calls buy() if Item already exists in inventory.
@post Increases the quantity of this item by 1.
*/
void Item::increaseQuantity()
{
  
   this->quantity +=1;

   if (DEBUG == true)
      cout << "new Quantity: " << quantity <<endl;
}

/*-------------------------------- decreaseQuantity() ---------------------------------
@pre An Item object exists. Called when Store calls sell() if Item already exists.
@post Decreases the quantity of this item by 1. Will output an error if it attempts to decrease quantity below 0.
*/
void Item::decreaseQuantity()
{
   if(this->quantity > 0)
   {
      this->quantity -= 1;
   }
   else
   {
      cout << "Error, cannot decrease quantity of item below 0!" << endl;
   }
   
}