/**@file Coin.cpp*/

/*
Tin Khuong
   Student ID: 0421141
   CSS 502B
   Program 4
   Prof. Clark Olson
   2/25/20

   This class represents a Coin object. It overrides Comparable comparison operators based on its own unique data members
*/

#include "Coin.h"
#include <iostream>
using namespace std;

/*-------------------------------- Default Constructor ---------------------------------
@pre A Store Object exists.
@post Creates a new Coin object and initializes fields to default values.
*/
Coin::Coin():Item()
{
   coinType = "defaultCoin";
   grade = 0;
   year = 0;
}

/*-------------------------------- Parameterized Constructor ---------------------------------
   @pre An Inventory Dummy Object exists in the Factory class which calls this method via create() during inventory initialization
      from reading external file, or when calling buy().
   @post Assigns data members from parameters to this object.
   */
Coin::Coin(char itemType, int quantity, string coinType, int year, int grade) : Item(itemType, quantity)
{
   this->coinType = coinType;
   this->year = year;
   this->grade = grade;
}

/*-------------------------------- Destructor ---------------------------------
@pre A Coin Object exists.
@post Deallocates memory associated with this object
*/
Coin::~Coin(){}

/*-------------------------------- operator> ---------------------------------
@pre rhs is a valid Coin object to compare. Overrides Comparable operator>
@post Returns true if this Coin is greater than rhs, false if not.
*/
bool Coin::operator>(const Comparable& rhs)const
{

   if (DEBUG == true)
   {
      cout << "Compare coin >" << endl;
   }

   const Coin& c = static_cast<const Coin&>(rhs); //Static cast from derived to base class

   //Sorting Criteria: Type, Year, Grade
   if(this->coinType == c.coinType)
   {
      if(this->year == c.year)
      {
         return(this->grade > c.grade);
      }
      else
      {
         return this->year > c.year;
      }
   }
   else
   {
      return this->coinType > c.coinType;
   }
}

/*-------------------------------- operator< ---------------------------------
@pre rhs is a valid Coin object to compare. Overrides Comparable operator<
@post Returns true if this Coin is less than rhs, false if not.
*/
bool Coin::operator<(const Comparable& rhs)const
{

   if (DEBUG == true)
   {
      cout << "Compare coin <" << endl;
   }

   const Coin& c = static_cast<const Coin&>(rhs); //Static cast from derived to base class

   //Sorting Criteria: Type, Year, Grade
   if (this->coinType == c.coinType)
   {
      if (this->year == c.year)
      {
         return(this->grade < c.grade);
      }
      else
      {
         return this->year < c.year;
      }
   }
   else
   {
      return this->coinType < c.coinType;
   }
}

/*-------------------------------- operator== ---------------------------------
   @pre rhs is a valid Item object to compare. Overrides Comparable operator==
   @post Returns true if this Coin is less than rhs, false if not.
   */
bool Coin::operator==(const Comparable& rhs)const
{

   if (DEBUG == true)
   {
      cout << "Compare coin <" << endl;
   }

   const Coin& c = static_cast<const Coin&>(rhs); //Static cast from derived to base class

   //Sorting Criteria: Type, Year, Grade
   if (this->coinType == c.coinType)
   {
      if (this->year == c.year)
      {

         if (DEBUG == true)
         {
            cout << "Matching coin ?" << endl;
         }

         return(this->grade == c.grade);
      }
      else
      {
         return false;
      }
   }
   else
   {
      if(DEBUG == true)
      {
         cout << "Not a matching coin " << endl;
      }

      return false;
   }
}

/*-------------------------------- create() ---------------------------------
@pre A Store object exists. itemFactory has called makeItem(), calling this method
@post Calls parameterized constructor for this object and returns pointer to newly created item.
*/
Coin* Coin::create(int quantity, string input)
{
   

   stringstream s(input);

   string coinType;
   string strYear;
   int year;
   int grade;
   string strGrade;


   getline(s, strYear, ',');
   year = atoi(strYear.c_str());
   s.get();
   getline(s, strGrade, ',');
   grade = atoi(strGrade.c_str());
   s.get();
   getline(s, coinType, '\0');

   Coin* coinPtr = new Coin('M', quantity, coinType, year, grade);

   return coinPtr;

}

/*-------------------------------- printContents() ---------------------------------
@pre A Coin object exists.
@post Outputs data members of this Coin.
*/
void Coin::printContents()
{
   cout << itemType << ", " << quantity << ", " << year << ", " << grade << ", " << coinType << endl; 

}