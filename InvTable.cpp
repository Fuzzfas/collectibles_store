/**@file InvTable.cpp*/

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
#include "InvTable.h"

/*-------------------------------- Default Constructor ---------------------------------
@pre A Store Object has been created from Main. Store calls this constructor to initialize its inventory data member.
@post Creates a new Customer object and assigns data members from parameters.
*/
InvTable::InvTable()
{
}

/*-------------------------------- Destructor ---------------------------------
@pre An InvTable Object exists.
@post Deallocates memory associated with this object.
*/
InvTable::~InvTable()
{
}

/*-------------------------------- Add ---------------------------------
@pre A Store Object exists, and successfully reads external files containing inventory contents,
   customer list, and sequence of commands. Store will call buildInv() or buy(), which will call this method.
@post Adds an Item object to inventory if successful. Otherwise, will return an error message if item is invalid,
or may simply increase existing item quantity. Deallocates entry item if item is invalid.
*/
void InvTable::add(char itemType, Item* entry)
{

   if(itemType == 'Z' || entry == nullptr) 
   {
      cout << "Error, attempting to add invalid Item Type: " << itemType << endl;
   }

   //Run itemType through hash to figure out which index in array of BST it will go into
   //and call insert() of that BST

   //if insert() returns false(duplicate is found)
   else if(table[hash(itemType)].insert(entry) == false)
   {      
    
      if (DEBUG == true)
      {
         cout << "duplicate item exists, increasing quantity: " << endl;
         table[hash(itemType)].getExistingEntry(entry)->printContents();
      }

      //return pointer to correct node in BST
      //increase existing item's quantity
      table[hash(itemType)].getExistingEntry(entry)->increaseQuantity();

      //delete extra temp item
      delete entry;
      entry = nullptr;

   }
   else
   {
      if (DEBUG == true)
      {
         cout << "new item was added: " << endl;
         entry->printContents();
      }
   }
}

/*-------------------------------- Remove ---------------------------------
@pre A Store Object exists, and successfully reads external files containing inventory contents,
   customer list, and sequence of commands. Store will call sell(), which will call this method.
@post Decreases the quantity of Item in inventory if it exists, otherwise will return an error if
Item does not exists or quantity is already at 0.
*/
void InvTable::remove(char itemType, Item* entry)
{
   if(table[hash(itemType)].getExistingEntry(entry) != nullptr)
   {
      table[hash(itemType)].getExistingEntry(entry)->decreaseQuantity();
   }
   else
   {
      cout << "Error, item does not exist or out of stock!" << endl;
   }
}

/*-------------------------------- hashFunction ---------------------------------
@pre A Store Object exists, and successfully reads external files containing inventory contents,
   customer list, and sequence of commands. Used by the add(), remove() and displayInventory() methods.
@post Returns a hash code (an integer) to determine which bucket to work with.
*/
int InvTable::hash(char itemType)const
{
   if (DEBUG == true)
   {
      cout << "BST Table bucket: " << itemType - 'A' <<endl;
   }   

   //Same as Factory's hashFunction
   return (itemType - 'A');
}

/*-------------------------------- displayInventory ---------------------------------
@pre A Store Object exists, and successfully reads external files containing inventory contents,
   customer list, and sequence of commands. 
@post Outputs current store inventory in this order: All Coins, then all Comics, then all Sports Cards.
*/
void InvTable::displayInventory()const
{
   
      table[hash('M')].displayInOrder();
      table[hash('C')].displayInOrder();
      table[hash('S')].displayInOrder();
   
}