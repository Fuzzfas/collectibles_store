/**@file Command.h*/

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

#pragma once
#include <string>

class Store;

using namespace std;

class Command
{
private:
   
public:

   /*-------------------------------- Default Constructor ---------------------------------
   @pre None
   @post Creates a new Command object.
   */
   Command();

   /*-------------------------------- Destructor ---------------------------------
    @pre Command object exists.
    @post Deallocates memory associated with this object.
    */
   virtual ~Command();

   /*-------------------------------- process ---------------------------------
   Pure Virtual method. To be overridden by derived classes
   @pre None
   @post None
   */
   virtual void process(Store* store, string input) = 0;

};

