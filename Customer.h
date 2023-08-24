/**@file Customer.h*/

/*
Tin Khuong
   Student ID: 0421141
   CSS 502B
   Program 4
   Prof. Clark Olson
   2/25/20

   Customer will contain all Data Members and Operations for customer-related actions and information such as purchasing and individual history of transactions. 
   It will also contain a linked list of Transaction Struct that will store transaction history.

*/

#pragma once
#include "Item.h"
#include <list>
#include <iterator>
#include "Comparable.h"
#include <iomanip>


class Customer : public Comparable
{
private:

   struct Transaction
   {
      string transType; //Type of transaction (purchase, sale, etc.)

      /*-------------------------------- Parameterized Constructor ---------------------------------
      @pre A Customer Object exists. addTransaction() calls this constructor
      @post Creates a new Customer object and assigns data members from parameters.
      */
      Transaction(string transType);

      /*-------------------------------- Destructor ---------------------------------
      @pre A Transaction Object exists.
      @post Deallocates memory associated with this object
      */
      ~Transaction();
   };

   int id = -1; //Unique 3-digit customer identifier (i.e. 007)
   string firstName = ""; //Customers will be alphabetically sorted by firstName
   string lastName = ""; //Not all customers will have a lastName
   list<Transaction> transactions; //Linked list of transactions, maintained in chronological order

public:

   /*-------------------------------- Default Constructor ---------------------------------
   @pre A Store Object exists.
   @post Creates a new Customer object and initializes fields to default values.
   */
   Customer();

   /*-------------------------------- Parameterized Constructor ---------------------------------
   @pre A Store Object exists and upon reading an external file containing the customer list, calls this constructor
   @post Creates a new Customer object and assigns data members from parameters.
   */
   Customer(int id, string firstName, string lastName);

   /*-------------------------------- Destructor ---------------------------------
   @pre A Customer Object exists.
   @post Deallocates memory associated with this object
   */
   virtual ~Customer();

   /*-------------------------------- operator> ---------------------------------
   @pre rhs is a valid Customer object to compare. Overrides Comparable operator>
   @post Returns true if Customer is greater than rhs, false if not.
   */
   virtual bool operator>(const Comparable& rhs)const;

   /*-------------------------------- operator< ---------------------------------
   @pre rhs is a valid Customer object to compare. Overrides Comparable operator<
   @post Returns true if Customer is less than rhs, false if not.
   */
   virtual bool operator<(const Comparable& rhs)const;

   /*-------------------------------- operator== ---------------------------------
  @pre rhs is a valid Customer object to compare. Overrides Comparable operator==
  @post Returns true if Customer is equal to rhs, false if not.
  */
   virtual bool operator==(const Comparable& rhs)const;

   /*-------------------------------- addTransaction ---------------------------------
   @pre A Store object and Customer Object exists. Store calls buy() or sell() which calls this method.
   @post Adds a new transaction to list of transactions for this customer.
   */
   void addTransaction(string transType);

   /*-------------------------------- printContents() ---------------------------------
   @pre A Store object exists and calls showCustomerHx() or history().
   @post Outputs transactions of this Customer via traversal through its linked list.
   */
   virtual void printContents();

   //-------------------------------- unused methods---------------------------------
   //These methods needed to be included since Customer inherits from an Abstract class, Comparable 
   virtual void increaseQuantity();
   virtual void decreaseQuantity();

};

