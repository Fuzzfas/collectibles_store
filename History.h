/**@file History.h*/

/*
Tin Khuong
   Student ID: 0421141
   CSS 502B
   Program 4
   Prof. Clark Olson
   2/25/20

  This class is a derived class of Command. The CommandFactory class employs polymorphism to determine which process() to call.
  process() will call different methods of Store.
*/

#pragma once
#include "Command.h"
class Store;

class History :
   public Command
{
private:

public:
   /*-------------------------------- process ---------------------------------
   Overrides process from Command class.
   @pre A Store object exists.
   @post Calls history() method from Store.
   */
   virtual void process(Store* store, string input);

};

