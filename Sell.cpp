/**@file Sell.cpp*/

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
#include "Sell.h"
#include "Store.h"

/*-------------------------------- process ---------------------------------
Overrides process from Command class.
@pre A Store object exists.
@post Calls sell() method from Store. Passes an input string which should contain item information from an external file.
*/
void Sell::process(Store* store, string input)
{
   store->sell(input);
}