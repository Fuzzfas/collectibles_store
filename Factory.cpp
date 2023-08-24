/**@file Factory.h*/

/*
Tin Khuong
   Student ID: 0421141
   CSS 502B
   Program 4
   Prof. Clark Olson
   2/25/20

   The main purpose of this class is to use the factory method to decide which derived classes of Item to create.
   This class will take advantage of polymorphism in order to decide on which of derived classes to create.
   The class will actually pass on pointers to newly created objects of derived classes to the InvClass for sorting and storage.

*/

#include "Factory.h"
/*-------------------------------- Default Constructor ---------------------------------
  @pre A Store object exists.
  @post Creates a Factory object.
  */
Factory::Factory()
{
   Coin* coinDummy = new Coin();
   Comic* comicDummy = new Comic();
   SportsCard* sportsDummy = new SportsCard();
   

   //Initialize entire table to nullptr
   for (int i = 0; i < size; i++)
   {
      factoryTable[i] = nullptr;

   }

   factoryTable[factoryHash('M')] = coinDummy;
   factoryTable[factoryHash('C')] = comicDummy;
   factoryTable[factoryHash('S')] = sportsDummy;   
}

/*-------------------------------- Destructor ---------------------------------
 @pre A Factory object exists.
 @post Deallocates memory associated with this object via traversal of factoryTable
 */
Factory::~Factory()
{
   for (int i = 0; i < size; i++)
   {
      if(factoryTable[i] != nullptr)
      {
         delete factoryTable[i];
         factoryTable[i] = nullptr;
      }
   }
}

/*-------------------------------- factoryHash ---------------------------------
 @pre A Factory object exists. makeItem() has been called with a valid char parameter
 @post Returns an int (hash code) using char parameter.
 */
int Factory::factoryHash(char itemType)
{
   if(DEBUG == true)
   {
      cout << "Factory bucket: " << (itemType - 'A') << endl;
   }

   return (itemType - 'A');
}

/*-------------------------------- makeItem ---------------------------------
Creates and returns a pointer to a derived class of Item, such as Coin, Comic, or SportsCard. Accepts a char from external text file as a parameter.
@pre A Store object exists. External inventory content and command text files are formatted correctly
@post Calls factoryHash() to determine item type to be created. Calls create() of derived class. Returns pointer to newly created derived class of Item.
   Otherwise returns nullptr if Item type is invalid.
*/
Item* Factory::makeItem(char itemType, int quantity, string input)
{
   if(factoryTable[factoryHash(itemType)] != nullptr)
   {
      return factoryTable[factoryHash(itemType)]->create(quantity, input); //pass parameters to create   
   }
   else
   {
      return nullptr;
   }
   
   
}