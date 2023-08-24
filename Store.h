/**@file Store.h*/

/*
Tin Khuong
   Student ID: 0421141
   CSS 502B
   Program 4
   Prof. Clark Olson
   2/25/20

   This class will handle building the inventory and customer list by reading external text files. 
   Store also handles any global actions such as displaying overall inventory, all customer history, and error messages.
*/

#pragma once
#include <fstream>
#include "InvTable.h"
#include "BST.h"
#include "Factory.h"
#include "Coin.h"
#include "Comic.h"
#include "SportsCard.h"
#include "Customer.h"
#include "CommandFactory.h"
#include "CommandReader.h"
#include <vector>

class Store
{
private:

   static const int maxCustomers = 1000; //Maximum number of allowed customers. Customer IDs must be 3-digits from 000 to 999.
   InvTable inventory; //HashTable to store BST of Items
   BST custTree; //Binary Search Tree containing Customers
   Customer* custArray[maxCustomers] = {nullptr}; //Array of pointers to Customers
   Factory itemFactory; //Factory to determine item creation
   CommandFactory commandFactory; //Factory to determine command execution

public:

   /*-------------------------------- Default Constructor ---------------------------------
   @pre None
   @post Creates a new Store object.
   */
   Store();

   /*-------------------------------- Destructor ---------------------------------
    @pre A Store object exists.
    @post Deallocates memory associated with this object
    */
   ~Store();

   /*-------------------------------- buildInv ---------------------------------
   Reads external text file and populates BST array of InvTable with Item* (pointers to Item).
   @pre A Store object exists. External text file listing inventory contents exists and is formatted
      correctly.
   @post Calls makeItem from Factory using char, int, and string parsed from input stream.
   Calls add() from InvTable class, passing in a char and Item*
   */
   void buildInv(ifstream& invStream);

   /*-------------------------------- buildCustTree ---------------------------------
   Reads external text file and populates custTree and custArray with Customer*.
   Parses input stream to determine parameters to pass onto Customer parameterized constructor.
   @pre A Store object exists. External text file of customer list exists and is formatted
      correctly.
   @post Builds the BST custTree and custArray with BSTNodes containing Customer*.
   */
   void buildCustTree(ifstream& custStream);

   /*-------------------------------- sell ---------------------------------
   Removes an item from inventory and updates customer transaction.
   @pre A Store object exists. External text file of command sequence exists and is formatted
      correctly.
   @post Will call decreaseQuantity of an Item in inventory using parameters passed in from command text file,
      provided the Item exists and has quantity of more than 0.
      Updates customer transaction by calling addTransaction().
   */
   void sell(string input);

   /*-------------------------------- buy ---------------------------------
   Adds an item to inventory and updates customer transaction.
   @pre A Store object exists. External text file of command sequence exists and is formatted
      correctly.
   @post Calls makeItem, passing in returned Item* as parameter to indicate item type. Then calls add() in inventory to add newly created Item to inventory.
      If Item already exists in inventory, will increase quantity by 1.
      Updates customer transaction by calling addTransaction().
   */
   void buy(string input);

   /*-------------------------------- display ---------------------------------
   Outputs the entire inventory of the store, including the number of each item in inventory
   @pre A Store object exists. External text files are formatted correctly and have been read to populate Store data members.
   @post Outputs store inventory to console. Displays all Coins, then all Comics, then all Sports Cards.
   */
   void display()const;

   /*-------------------------------- history ---------------------------------
   Outputs the history for every customer, with the customers in alphabetical order.
   @pre A Store object exists. External text files are formatted correctly and have been read to populate Store data members.
   @post Calls displayInOrder() of BST to traverse and retrieve transaction lists from each customer in alphabetical order.
   */
   void history()const;

   /*-------------------------------- processCommands ---------------------------------
   Reads external file of commands and calls appropriate methods to update Store object.
   @pre A Store object and CommandReader object exist. External text files are formatted correctly and have been read to populate Store data members.
   @post Calls sell(), buy(), display(), showCustomerHx() and/or history().
   */
   void processCommands(CommandReader& commandReader);

   /*-------------------------------- showCustomerHx ---------------------------------
   Outputs the transaction history for a specific customer in chronological order
   @pre A Store object exists. External text files are formatted correctly and have been read to populate Store data members.
      ID passed as parameter must be a valid integer between 0-999.
   @post Outputs entire history of transactions for a customer chronologically.
   */
   void showCustomerHx(int id);
};

