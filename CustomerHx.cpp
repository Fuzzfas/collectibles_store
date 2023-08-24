/**@file CustomerHx.h*/

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

#include "CustomerHx.h"
#include "Store.h"

/*-------------------------------- process ---------------------------------
Overrides process from Command class.
@pre A Store object exists.
@post Calls showCustomerHx() method from Store. Passes an input string which should contain item information from an external file.
*/
void CustomerHx::process(Store* store, string input)
{
   int ID = atoi(input.c_str()); //convert string ID to integer

   store->showCustomerHx(ID);
}