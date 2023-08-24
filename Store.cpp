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

#include "Store.h"

/*-------------------------------- Default Constructor ---------------------------------
@pre None
@post Creates a new Store object.
*/
Store::Store()
{
   for(int i = 0; i < maxCustomers; i++)
   {
      custArray[i] = nullptr;
   }
}

/*-------------------------------- Destructor ---------------------------------
@pre A Store object exists.
@post Deallocates memory associated with this object
*/
Store::~Store()
{

}

/*-------------------------------- buildInv ---------------------------------
Reads external text file and populates BST array of InvTable with Item* (pointers to Item).
@pre A Store object exists. External text file listing inventory contents exists and is formatted
   correctly.
@post Calls makeItem from Factory using char, int, and string parsed from input stream.
Calls add() from InvTable class, passing in a char and Item*
*/
void Store::buildInv(ifstream& invStream)
{
   while (invStream.peek() != EOF) 
   {
      string type;
      string stringCount;
      int intCount;
      string description;
           
      if (invStream.eof()) break;
      getline(invStream, type, ','); 		//get type of inventory
      invStream.get(); 			//discard space 
      getline(invStream, stringCount, ','); 	//get count
      intCount = atoi(stringCount.c_str());
      invStream.get(); 			//discard space
      getline(invStream, description, '\n'); 	//get rest of info

      char itemType = type[0]; //convert string to char

      //Make Item using Factory
      Item* curItemPtr = itemFactory.makeItem(itemType, intCount, description);

      //Add to InvTable
      inventory.add(itemType, curItemPtr);
   }
}

/*-------------------------------- buildCustTree ---------------------------------
Reads external text file and populates custTree and custArray with Customer*.
Parses input stream to determine parameters to pass onto Customer parameterized constructor.
@pre A Store object exists. External text file of customer list exists and is formatted
   correctly.
@post Builds the BST custTree and custArray with BSTNodes containing Customer*.
*/
void Store::buildCustTree(ifstream& custStream)
{
   while (custStream.peek() != EOF)
   {
      string strID;
      int ID;
      string firstName;
      string lastName;
      string wholeName;
      vector<string> words;
      string tmp;

      if (custStream.eof()) break;
      getline(custStream, strID, ','); //get ID as string
      ID = atoi(strID.c_str()); //convert to integer
      custStream.get(); //skip space
      getline(custStream, wholeName, '\n'); //get ID as string
      
      if (DEBUG == true)
      {
         cout << "wholeName: " << endl;
         cout << wholeName << endl;
      }      

      stringstream str_strm (wholeName);
      while(getline(str_strm, tmp, ' '))
      {         
         words.push_back(tmp);         
      }
      
      firstName = words.front();
      if(words.size() > 1)
      {
         lastName = words.back();
      }
      else lastName = "";
      
      if(DEBUG == true)
      {
         cout << "firstName lastName: " << endl;
         cout << firstName << " " << lastName << endl;
      }
      
      Customer* curCustomer = new Customer(ID, firstName, lastName);

      if(ID < maxCustomers)
      {
         
         //Insert current customer to customer BST
         if (custTree.insert(curCustomer) == true)
         {
            //Also copy pointer to customer array
            custArray[ID] = curCustomer;
         }
         else
         {
            //Free allocated memory of temp Customer*
            delete curCustomer;
            curCustomer = nullptr;
         }

      }
      else
      {
         //Free allocated memory of temp Customer*
         delete curCustomer;
         curCustomer = nullptr;
         cout << "Error, invalid customer ID. ID must be a 3-digit integer below: " << maxCustomers << endl;
      }      
   }
}

/*-------------------------------- sell ---------------------------------
Removes an item from inventory and updates customer transaction.
@pre A Store object exists. External text file of command sequence exists and is formatted
   correctly.
@post Will call decreaseQuantity of an Item in inventory using parameters passed in from command text file,
   provided the Item exists and has quantity of more than 0.
   Updates customer transaction by calling addTransaction().
*/
void Store::sell(string input)
{
   //Accept stream or string input
   stringstream s(input);
   string custID;
   int ID;
   string type;
   int intCount = 1; //Every item transaction only involves count of 1
   char itemType;
   string description;

   getline(s, custID, ',');
   ID = atoi(custID.c_str()); //convert string ID to integer
   s.get();
   getline(s, type, ',');
   itemType = type[0]; //convert itemType to char
   s.get();
   getline(s, description, '\n');

   //create temp item entry
   Item* curItemPtr = itemFactory.makeItem(itemType, intCount, description);

   if (curItemPtr != nullptr)
   {
      //update customer
      if (custArray[ID] != nullptr)
      {
         custArray[ID]->addTransaction("Customer Purchase: " + type + ", " + description);
         inventory.remove(itemType, curItemPtr);
      }

      else
      {
         cout << "Error, customer does not exist!" << endl;
      }
   }
   else
   {
      cout << "Error, attempting to sell invalid Item Type : " << itemType << endl;
   }
   
   //Deallocate temp item entry
   delete curItemPtr;
   curItemPtr = nullptr;
}

/*-------------------------------- buy ---------------------------------
Adds an item to inventory and updates customer transaction.
@pre A Store object exists. External text file of command sequence exists and is formatted
   correctly. 
@post Calls makeItem, passing in returned Item* as parameter to indicate item type. Then calls add() in inventory to add newly created Item to inventory.
   If Item already exists in inventory, will increase quantity by 1.
   Updates customer transaction by calling addTransaction().
*/
void Store::buy(string input)
{
   //Accept stream or string input
   stringstream s(input);
   string custID;
   int ID;
   string type;
   int intCount = 1; //Every item transaction only involves count of 1
   char itemType;
   string description;

   getline(s, custID, ',');
   ID = atoi(custID.c_str()); //convert string ID to integer
   s.get();
   getline(s, type, ',');
   itemType=type[0]; //convert itemType to char
   s.get();
   getline(s, description, '\n');

   //update inventory
   Item* curItemPtr = itemFactory.makeItem(itemType, intCount, description);
   if(curItemPtr != nullptr)
   {
      //update customer
      if (custArray[ID] != nullptr && ID < maxCustomers)
      {
         custArray[ID]->addTransaction("Customer Sale: " + type + ", " + description);

         //Add to InvTable
         inventory.add(itemType, curItemPtr);
      }
      else //Item was valid, but Customer was not, so deallocate temp Item
      {
         //Deallocate temp item entry
         delete curItemPtr;
         curItemPtr = nullptr;
         cout << "Error, customer does not exist or ID is invalid!" << endl;
      }
   }
   else
   {
      cout << "Error, attempting to buy invalid Item Type : " << itemType << endl;
   }  
}

/*-------------------------------- display ---------------------------------
Outputs the entire inventory of the store, including the number of each item in inventory
@pre A Store object exists. External text files are formatted correctly and have been read to populate Store data members.
@post Outputs store inventory to console. Displays all Coins, then all Comics, then all Sports Cards.
*/
void Store::display()const
{
   inventory.displayInventory();
}

/*-------------------------------- history ---------------------------------
Outputs the history for every customer, with the customers in alphabetical order.
@pre A Store object exists. External text files are formatted correctly and have been read to populate Store data members.
@post Calls displayInOrder() of BST to traverse and retrieve transaction lists from each customer in alphabetical order.
*/
void Store::history()const
{
   //traverse custTree
   custTree.displayInOrder();
}

/*-------------------------------- processCommands ---------------------------------
Reads external file of commands and calls appropriate methods to update Store object.
@pre A Store object and CommandReader object exist. External text files are formatted correctly and have been read to populate Store data members.
@post Calls sell(), buy(), display(), showCustomerHx() and/or history().
*/
void Store::processCommands(CommandReader& commandReader)
{
   //while loop until eof
   while(!commandReader.endCommands())
   {
      commandReader.parseCommands(); //break up commands into pieces
      commandFactory.generateCommand(this, commandReader.getcomType(), commandReader.getCommandInfo());
   }   
}

/*-------------------------------- showCustomerHx ---------------------------------
Outputs the transaction history for a specific customer in chronological order
@pre A Store object exists. External text files are formatted correctly and have been read to populate Store data members.
   ID passed as parameter must be a valid integer between 0-999.
@post Outputs entire history of transactions for a customer chronologically.
*/
void Store::showCustomerHx(int id)
{
   if(id < maxCustomers)
   {
      custArray[id]->printContents();
   }
   else
   {
      cout << "Error, invalid customer ID. ID must be a 3-digit integer below: " << maxCustomers << endl;
   }
   
}