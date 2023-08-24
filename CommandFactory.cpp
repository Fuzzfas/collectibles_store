/**@file CommandFactory.cpp*/

/*
Tin Khuong
   Student ID: 0421141
   CSS 502B
   Program 4
   Prof. Clark Olson
   2/25/20

   This class contains a hash table of dummy pointers to derived classes of Command. It employs polymorphism to determine which process() to call.
   process() will call different methods of Store. Its methods do not need to be implemented.
*/
#include "CommandFactory.h"

/*-------------------------------- Default Constructor ---------------------------------
@pre A Store object exists.
@post Creates a CommandFactory object. Initializes commandTable with dummy pointers to derived
Command classes.
*/
CommandFactory::CommandFactory()
{
   for(int i = 0; i < numCommands; i++)
   {
      commandTable[i] = nullptr;
   }

   Sell* sellDummy = new Sell();
   Buy* buyDummy = new Buy();
   Display* displayDummy = new Display();
   CustomerHx* customerDummy = new CustomerHx();
   History* historyDummy = new History();

   commandTable[hash('S')] = sellDummy;
   commandTable[hash('B')] = buyDummy;
   commandTable[hash('D')] = displayDummy;
   commandTable[hash('C')] = customerDummy;
   commandTable[hash('H')] = historyDummy;

}

/*-------------------------------- Destructor ---------------------------------
 @pre A CommandFactory object exists.
 @post Deallocates memory associated with this object via traversal through commandTable
 */
CommandFactory::~CommandFactory()
{
   for (int i = 0; i < numCommands; i++)
   {
      if (commandTable[i] != nullptr)
      {
         delete commandTable[i];
         commandTable[i] = nullptr;
      }
   }
}

/*-------------------------------- hash ---------------------------------
Simple hash function to determine which bucket to use in hash table.
 @pre A CommandFactory object exists.
 @post returns an integer based on comType.
 */
int CommandFactory::hash(char comType)
{

   return (comType - 'A');
}

/*-------------------------------- generateCommand ---------------------------------
 @pre A CommandFactory object exists. comType must be a valid type.
 @post Calls process() of derived Command class based on comType passed in as parameter.
   Otherwise will print an error message if command is invalid
 */
void CommandFactory::generateCommand(Store* store, char comType, string input)
{
   if(commandTable[hash(comType)] != nullptr)
   {
      return commandTable[hash(comType)]->process(store, input);
   }
   else
   {
      cout << "Error, invalid command!" << endl;
   }
   
}