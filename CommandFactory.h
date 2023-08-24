/**@file CommandFactory.h*/

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
#pragma once
#include "Command.h"
#include "Sell.h"
#include "Buy.h"
#include "Display.h"
#include "CustomerHx.h"
#include "History.h"
#include <iostream>
using namespace std;

class CommandFactory
{
private:

   static const int numCommands = 26; //Maxmimum possible Command types. It is assumed Commands will only be represented by a single capital letter
   Command* commandTable[numCommands]; //Hash Table of Command*

public:

   /*-------------------------------- Default Constructor ---------------------------------
   @pre A Store object exists.
   @post Creates a CommandFactory object. Initializes commandTable with dummy pointers to derived
   Command classes.
   */
   CommandFactory();

   /*-------------------------------- Destructor ---------------------------------
    @pre A CommandFactory object exists.
    @post Deallocates memory associated with this object via traversal through commandTable
    */
   virtual ~CommandFactory();

   /*-------------------------------- hash ---------------------------------
   Simple hash function to determine which bucket to use in hash table.
    @pre A CommandFactory object exists.
    @post returns an integer based on comType.
    */
   int hash(char comType);

   /*-------------------------------- generateCommand ---------------------------------
    @pre A CommandFactory object exists. comType must be a valid type.
    @post Calls process() of derived Command class based on comType passed in as parameter.
      Otherwise will print an error message if command is invalid
    */
   void generateCommand(Store* store, char comType, string input);

};

