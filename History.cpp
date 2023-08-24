/**@file History.cpp*/

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
#include "History.h"
#include "Store.h"

/*-------------------------------- process ---------------------------------
Overrides process from Command class.
@pre A Store object exists.
@post Calls history() method from Store.
*/
void History::process(Store* store, string input)
{
   store->history();
}