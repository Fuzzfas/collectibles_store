/**@file CommandFactory.h*/

/*
Tin Khuong
   Student ID: 0421141
   CSS 502B
   Program 4
   Prof. Clark Olson
   2/25/20

   This class is used to read text files and parse the strings to be used as parameters for methods.
   A Store object must call its processCommands() method, which accepts a CommandReader object, and there the CommandReader will
   run its methods.
*/
#pragma once
#include <fstream>
#include <iostream>
using namespace std;

class CommandReader
{
private:
   ifstream commandFile;
   char comType = ' ';
   string commandInfo = "";

public:

   /*-------------------------------- Default Constructor ---------------------------------
   @pre None
   @post Creates a new CommandReader object.
   */
   CommandReader();

   /*-------------------------------- Parameterized Constructor ---------------------------------
   @pre None
   @post Creates a new CommandReader object and commandFile opens the filename input passed in as a string.
   */
   CommandReader(string& input);

   /*-------------------------------- Destructor ---------------------------------
    @pre A CommandReader object exists.
    @post Deallocates memory associated with this object
    */
   ~CommandReader();

   /*-------------------------------- parseCommands() ---------------------------------
    @pre A Store object exists and calls processCommands().
    @post Parses string from ifstream object commandFile into a char repreenting
      type of command and a string of the rest of the description, which may be further
      parsed by other methods down the line.
    */
   void parseCommands();

   /*-------------------------------- endCommands() ---------------------------------
   Checks to see if the CommandReader has reached the end of the commandFile
    @pre A Store object exists and calls processCommands().
    @post returns true if at end of file, otherwise false.
    */
   bool endCommands();

   /*-------------------------------- getcomType() ---------------------------------
    @pre A Store object exists and calls processCommands(). A CommandFactory calls
      generateCommand()
    @post returns a char indicating the command type
    */
   char getcomType();
      
   /*-------------------------------- getCommandInfo() ---------------------------------
   @pre A Store object exists and calls processCommands(). A CommandFactory calls
     generateCommand()
   @post returns a string indicating the rest of the command information, which
     may be further parsed down the line.
   */
   string getCommandInfo();
};

