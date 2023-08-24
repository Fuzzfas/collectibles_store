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
#include "Customer.h"

//-------------------------------- Transaction Methods ---------------------------------

/*-------------------------------- Parameterized Constructor ---------------------------------
 @pre A Customer Object exists. addTransaction() calls this constructor
 @post Creates a new Customer object and assigns data members from parameters.
 */
Customer::Transaction::Transaction(string transType)
{
   this->transType = transType;
}

/*-------------------------------- Destructor ---------------------------------
@pre A Transaction Object exists.
@post Deallocates memory associated with this object
*/
Customer::Transaction::~Transaction(){}

//-------------------------------- End Transaction Methods ---------------------------------

/*-------------------------------- Default Constructor ---------------------------------
@pre A Store Object exists.
@post Creates a new Customer object and initializes fields to default values.
*/
Customer::Customer()
{
}

/*-------------------------------- Parameterized Constructor ---------------------------------
@pre A Store Object exists and upon reading an external file containing the customer list, calls this constructor
@post Creates a new Customer object and assigns data members from parameters.
*/
Customer::Customer(int id, string firstName, string lastName)
{
   this->id = id;
   this->firstName = firstName;
   this->lastName = lastName;
}

/*-------------------------------- Destructor ---------------------------------
@pre A Customer Object exists.
@post Deallocates memory associated with this object
*/
Customer::~Customer()
{
}

/*-------------------------------- operator> ---------------------------------
@pre rhs is a valid Customer object to compare. Overrides Comparable operator>
@post Returns true if Customer is greater than rhs, false if not.
*/
bool Customer::operator>(const Comparable& rhs)const
{
   const Customer& c = static_cast<const Customer&>(rhs); //Static cast from derived to base class
   if (this->firstName == c.firstName)
   {
      return this->lastName > c.lastName;
   }
   else
   {
      return (this->firstName > c.firstName);
   }
}

/*-------------------------------- operator< ---------------------------------
@pre rhs is a valid Customer object to compare. Overrides Comparable operator<
@post Returns true if Customer is less than rhs, false if not.
*/
bool Customer::operator<(const Comparable& rhs)const
{
   const Customer& c = static_cast<const Customer&>(rhs); //Static cast from derived to base class
   if(this->firstName == c.firstName)
   {
      return this->lastName < c.lastName;
   }
   else
   {
      return (this->firstName < c.firstName);
   }
   
}

/*-------------------------------- operator== ---------------------------------
@pre rhs is a valid Customer object to compare. Overrides Comparable operator==
@post Returns true if Customer is equal to rhs, false if not.
*/
bool Customer::operator==(const Comparable& rhs)const
{
   const Customer& c = static_cast<const Customer&>(rhs); //Static cast from derived to base class
   if(this->firstName == c.firstName)
   {
      return (this->lastName == c.lastName);
   }
   else
   {
      return false;
   }
   
}

/*-------------------------------- addTransaction ---------------------------------
@pre A Store object and Customer Object exists. Store calls buy() or sell() which calls this method.
@post Adds a new transaction to list of transactions for this customer.
*/
void Customer::addTransaction(string transType)
{   
   transactions.push_back(Transaction(transType));
}

/*-------------------------------- printContents() ---------------------------------
@pre A Store object exists and calls showCustomerHx() or history().
@post Outputs transactions of this Customer via traversal through its linked list.
*/
void Customer::printContents()
{
   if(lastName != "")
   {
      cout << setfill('0') << setw(3) << id << ", " << firstName << " " << lastName << " Transactions: " << endl;
   }
   else
   {
      cout << id << ", " << firstName << " " << "Transactions: " << endl;
   }

   //Traverse linked list of transactions:
   list<Transaction> :: iterator it;
   for(it = transactions.begin(); it != transactions.end(); it++)
   {
      cout << it->transType << " " << endl;
   }
}

//-------------------------------- unused methods---------------------------------
//These methods needed to be included since Customer inherits from an Abstract class, Comparable 
void Customer::increaseQuantity()
{

}

void Customer::decreaseQuantity()
{

}