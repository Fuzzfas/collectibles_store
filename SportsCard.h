/**@file SportsCard.h*/

/*
Tin Khuong
   Student ID: 0421141
   CSS 502B
   Program 4
   Prof. Clark Olson
   2/25/20

   This class represents a Sports Card object. It overrides Comparable comparison operators based on its own unique data members
*/

#pragma once
#include "Item.h"
class SportsCard :
   public Item //inherits from Item
{
private: //Sorting priority of data members goes from top to bottom

   string player; //Name of athlete
   int year; //Year card was released
   string manufacturer; //Manufacturer's name
   string grade; //Quality of Card (i.e. Mint, Excellent)

public:
 
   /*-------------------------------- Default Constructor ---------------------------------
   @pre A Store Object exists.
   @post Creates a new SportsCard object and initializes fields to default values.
   */
   SportsCard();

   /*-------------------------------- Parameterized Constructor ---------------------------------
   @pre An Inventory Dummy Object exists in the Factory class which calls this method via create() during inventory initialization
      from reading external file, or when calling buy().
   @post Assigns data members from parameters to this object.
   */
   SportsCard(char itemType, int quantity, string player, int year, string manufacturer, string grade);

   /*-------------------------------- Destructor ---------------------------------
   @pre A SportsCard Object exists.
   @post Deallocates memory associated with this object
   */
   virtual ~SportsCard();   

   /*-------------------------------- operator> ---------------------------------
   @pre rhs is a valid Item object to compare. Overrides Comparable operator>
   @post Returns true if this SportsCard is greater than rhs, false if not.
   */
   virtual bool operator>(const Comparable& rhs)const;

   /*-------------------------------- operator< ---------------------------------
   @pre rhs is a valid Item object to compare. Overrides Comparable operator<
   @post Returns true if this SportsCard is less than rhs, false if not.
   */
   virtual bool operator<(const Comparable& rhs)const;

   /*-------------------------------- operator== ---------------------------------
   @pre rhs is a valid Item object to compare. Overrides Comparable operator==
   @post Returns true if this SportsCard is equal to rhs, false if not.
   */
   virtual bool operator==(const Comparable& rhs)const;

   /*-------------------------------- create() ---------------------------------
   @pre A Store object exists. itemFactory has called makeItem(), calling this method
   @post Calls parameterized constructor for this object and returns pointer to newly created item.
   */
   virtual SportsCard* create(int quantity, string input);

   /*-------------------------------- printContents() ---------------------------------
   @pre A Coin object exists.
   @post Outputs data members of this SportsCard.
   */
   virtual void printContents();
};

