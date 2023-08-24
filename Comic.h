/**@file Comic.h*/

/*
Tin Khuong
   Student ID: 0421141
   CSS 502B
   Program 4
   Prof. Clark Olson
   2/25/20

   This class represents a Comic object. It overrides Comparable comparison operators based on its own unique data members
*/

#pragma once
#include "Item.h"
class Comic :
   public Item //inherits from Item
{

private: //Sorting priority of data members goes from top to bottom

   string publisher; //publisher name (i.e. Marvel)
   string title; //title of Comic book
   int year; //year Comic was published
   string grade; //Quality of Comic(i.e. Mint, Excellent)

public:

   /*-------------------------------- Default Constructor ---------------------------------
   @pre A Store Object exists.
   @post Creates a new Comic object and initializes fields to default values.
   */
   Comic();

   /*-------------------------------- Parameterized Constructor ---------------------------------
   @pre An Inventory Dummy Object exists in the Factory class which calls this method via create() during inventory initialization
      from reading external file, or when calling buy().
   @post Assigns data members from parameters to this object.
   */
   Comic(char itemType, int quantity, string publisher, string title, int year, string grade);

   /*-------------------------------- Destructor ---------------------------------
   @pre A Comic Object exists.
   @post Deallocates memory associated with this object
   */
   virtual ~Comic();

   /*-------------------------------- operator> ---------------------------------
   @pre rhs is a valid Item object to compare. Overrides Comparable operator>
   @post Returns true if this Comic is greater than rhs, false if not.
   */
   virtual bool operator>(const Comparable& rhs)const;

   /*-------------------------------- operator< ---------------------------------
   @pre rhs is a valid Item object to compare. Overrides Comparable operator<
   @post Returns true if this Comic is less than rhs, false if not.
   */
   virtual bool operator<(const Comparable& rhs)const;

   /*-------------------------------- operator== ---------------------------------
   @pre rhs is a valid Item object to compare. Overrides Comparable operator==
   @post Returns true if this Comic is equal to rhs, false if not.
   */
   virtual bool operator==(const Comparable& rhs)const;

   /*-------------------------------- create() ---------------------------------
   @pre A Store object exists. itemFactory has called makeItem(), calling this method
   @post Calls parameterized constructor for this object and returns pointer to newly created item.
   */
   virtual Comic* create(int quantity, string input);

   /*-------------------------------- printContents() ---------------------------------
   @pre A Comic object exists.
   @post Outputs data members of this Comic.
   */
   virtual void printContents();

};

