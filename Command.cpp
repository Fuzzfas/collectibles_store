/**@file Command.cpp*/

/*
Tin Khuong
   Student ID: 0421141
   CSS 502B
   Program 4
   Prof. Clark Olson
   2/25/20

   This class is an abstract class that serves as a superclass for actions a Store class may take. The CommandFactory class employs polymorphism to determine which process() to call.
   process() will call different methods of Store. Its methods do not need to be implemented.
*/

#include "Command.h"

/*-------------------------------- Default Constructor ---------------------------------
@pre None
@post Creates a new Command object.
*/
Command::Command()
{
}

/*-------------------------------- Destructor ---------------------------------
 @pre Command object exists.
 @post Deallocates memory associated with this object.
 */
Command::~Command()
{
}