/**@file CommandFactory.cpp*/

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
#include "CommandReader.h"
#include <fstream>
#include <sstream>

/*-------------------------------- Default Constructor ---------------------------------
@pre None
@post Creates a new CommandReader object.
*/
CommandReader::CommandReader()
{
}

/*-------------------------------- Parameterized Constructor ---------------------------------
@pre None
@post Creates a new CommandReader object and commandFile opens the filename input passed in as a string.
*/
CommandReader::CommandReader(string& input)
{
   commandFile.open(input);
   
   if(commandFile.fail())
   {
      cout << "Error, invalid command text file!" << endl;
      return;
   }

}

/*-------------------------------- Destructor ---------------------------------
 @pre A CommandReader object exists.
 @post Deallocates memory associated with this object
 */
CommandReader::~CommandReader()
{
}

/*-------------------------------- parseCommands() ---------------------------------
 @pre A Store object exists and calls processCommands().
 @post Parses string from ifstream object commandFile into a char repreenting 
   type of command and a string of the rest of the description, which may be further
   parsed by other methods down the line.
 */
void CommandReader::parseCommands()
{
   string strCom;
  
   if (commandFile.eof()) return;

   getline(commandFile, strCom, '\n');
   comType = strCom[0];

   //Special case, single letter commands D and H
   if(comType == 'D' || comType == 'H')
   {
      commandInfo = "";
      return; //Early function exit
   }
   //Parse rest of stream
   else
   {
      stringstream s(strCom);
      s.ignore(2, ' '); //throw away comma and space
      
      getline(s, commandInfo, '\n');
   }
}

/*-------------------------------- endCommands() ---------------------------------
Checks to see if the CommandReader has reached the end of the commandFile
 @pre A Store object exists and calls processCommands().
 @post returns true if at end of file, otherwise false.
 */
bool CommandReader::endCommands()
{
   return commandFile.peek() == EOF;
}

/*-------------------------------- getcomType() ---------------------------------
 @pre A Store object exists and calls processCommands(). A CommandFactory calls 
   generateCommand()
 @post returns a char indicating the command type
 */
char CommandReader::getcomType()
{
   return comType;
}

/*-------------------------------- getCommandInfo() ---------------------------------
 @pre A Store object exists and calls processCommands(). A CommandFactory calls
   generateCommand()
 @post returns a string indicating the rest of the command information, which
   may be further parsed down the line.
 */
string CommandReader::getCommandInfo()
{
   return commandInfo;
}