/**@file Coin.h*/

/*
Tin Khuong
   Student ID: 0421141
   CSS 502B
   Program 4
   Prof. Clark Olson
   2/25/20

   This class represents a Coin object. It overrides Comparable comparison operators based on its own unique data members
*/

#pragma once
#include "Item.h"
class Coin :
   public Item //inherits from Item
{
private: //Sorting priority of data members goes from top to bottom

   string coinType; //identifies the type of coin (i.e. Lincoln Cent)
   int year; //year coin was minted
   int grade; //quality rating (1-100 scale)

public:

   /*-------------------------------- Default Constructor ---------------------------------
   @pre A Store Object exists.
   @post Creates a new Coin object and initializes fields to default values.
   */
   Coin();

   /*-------------------------------- Parameterized Constructor ---------------------------------
   @pre An Inventory Dummy Object exists in the Factory class which calls this method via create() during inventory initialization
      from reading external file, or when calling buy().
   @post Assigns data members from parameters to this object.
   */
   Coin(char itemType, int quantity, string coinType, int year, int grade);

   /*-------------------------------- Destructor ---------------------------------
   @pre A Coin Object exists.
   @post Deallocates memory associated with this object
   */
   virtual ~Coin(); 

   /*-------------------------------- operator> ---------------------------------
   @pre rhs is a valid Item object to compare. Overrides Comparable operator>
   @post Returns true if this Coin is greater than rhs, false if not.
   */
   virtual bool operator>(const Comparable& rhs)const;

   /*-------------------------------- operator< ---------------------------------
   @pre rhs is a valid Item object to compare. Overrides Comparable operator<
   @post Returns true if this Coin is less than rhs, false if not.
   */
   virtual bool operator<(const Comparable& rhs)const;

   /*-------------------------------- operator== ---------------------------------
   @pre rhs is a valid Item object to compare. Overrides Comparable operator==
   @post Returns true if this Coin is less than rhs, false if not.
   */
   virtual bool operator==(const Comparable& rhs)const;

   /*-------------------------------- create() ---------------------------------
   @pre A Store object exists. itemFactory has called makeItem(), calling this method
   @post Calls constructor for this object and returns pointer to newly created item.
   */
   virtual Coin* create(int quantity, string input);

   /*-------------------------------- printContents() ---------------------------------
   @pre A Coin object exists.
   @post Outputs data members of this Coin.
   */
   virtual void printContents();

};

