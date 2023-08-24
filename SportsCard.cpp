/**@file SportsCard.cpp*/

/*
Tin Khuong
   Student ID: 0421141
   CSS 502B
   Program 4
   Prof. Clark Olson
   2/25/20

   This class represents a Sports Card object. It overrides Comparable comparison operators based on its own unique data members
*/
#include "SportsCard.h"

/*-------------------------------- Default Constructor ---------------------------------
@pre A Store Object exists.
@post Creates a new SportsCard object and initializes fields to default values.
*/
SportsCard::SportsCard():Item()
{
   player = "defaultPlayer";
   year = 0;
   manufacturer = "defaultManufacturer";
   grade = "defaultGrade";
}

/*-------------------------------- Parameterized Constructor ---------------------------------
@pre An Inventory Dummy Object exists in the Factory class which calls this method via create() during inventory initialization
   from reading external file, or when calling buy().
@post Assigns data members from parameters to this object.
*/
SportsCard::SportsCard(char itemType, int quantity, string player, int year, string manufacturer, string grade):Item(itemType, quantity)
{
   this->player = player;
   this->year = year;
   this->manufacturer = manufacturer;
   this->grade = grade;

}

/*-------------------------------- Destructor ---------------------------------
@pre A SportsCard Object exists.
@post Deallocates memory associated with this object
*/
SportsCard::~SportsCard(){}

/*-------------------------------- operator> ---------------------------------
@pre rhs is a valid Item object to compare. Overrides Comparable operator>
@post Returns true if this SportsCard is greater than rhs, false if not.
*/
bool SportsCard::operator>(const Comparable& rhs)const
{
   const SportsCard& s = static_cast<const SportsCard&>(rhs); //Static cast from derived to base class

   //Sorting criteria: player, year, manufacturer, grade
   if(this->player == s.player)
   {
      if (this->year == s.year)
      {
         if (this->manufacturer == s.manufacturer)
         {
            return this->grade > s.grade;
         }
         else
         {
            return this->manufacturer > s.manufacturer;
         }
      }
      else
      {
         return this->year > s.year;
      }
   }
   else
   {
      return this->player > s.player;
   }
}

/*-------------------------------- operator< ---------------------------------
@pre rhs is a valid Item object to compare. Overrides Comparable operator<
@post Returns true if this SportsCard is less than rhs, false if not.
*/
bool SportsCard::operator<(const Comparable& rhs)const
{
   const SportsCard& s = static_cast<const SportsCard&>(rhs); //Static cast from derived to base class

   //Sorting criteria: player, year, manufacturer, grade
   if (this->player == s.player)
   {
      if (this->year == s.year)
      {
         if (this->manufacturer == s.manufacturer)
         {
            return this->grade < s.grade;
         }
         else
         {
            return this->manufacturer < s.manufacturer;
         }
      }
      else
      {
         return this->year < s.year;
      }
   }
   else
   {
      return this->player < s.player;
   }
}

/*-------------------------------- operator== ---------------------------------
@pre rhs is a valid Item object to compare. Overrides Comparable operator==
@post Returns true if this SportsCard is equal to rhs, false if not.
*/
bool SportsCard::operator==(const Comparable& rhs)const
{

   const SportsCard& s = static_cast<const SportsCard&>(rhs); //Static cast from derived to base class
   //Sorting criteria: player, year, manufacturer, grade
   if(this->player == s.player)
   {
      if (this->year == s.year)
      {
         if (this->manufacturer == s.manufacturer)
         {
            return this->grade == s.grade;
         }
         else
         {
            return false;
         }
      }
      else
      {
         return false;
      }
   }
   else
   {
      return false;
   }
}

/*-------------------------------- create() ---------------------------------
@pre A Store object exists. itemFactory has called makeItem(), calling this method
@post Calls parameterized constructor for this object and returns pointer to newly created item.
*/
SportsCard* SportsCard::create(int quantity, string input)
{
   stringstream s(input);

   string strYear;
   int year;
   string grade;
   string player;
   string manufacturer;
   
   

   getline(s, strYear, ',');     //get year
   year = atoi(strYear.c_str()); //convert year to int
   s.get();                      //skip space
   getline(s, grade, ',');    //get grade
   s.get();                      //skip space
   getline(s, player, ',');       //get title
   s.get();                      //skip space
   getline(s, manufacturer, '\0');  //get manufacturer
   

   SportsCard* sportsPtr = new SportsCard('S', quantity, player, year, manufacturer, grade);

   return sportsPtr;
}

/*-------------------------------- printContents() ---------------------------------
@pre A SportsCard object exists.
@post Outputs data members of this SportsCard.
*/
void SportsCard::printContents()
{
   cout << itemType << ", " << quantity << ", " << year << ", " << grade << ", " << player << ", " << manufacturer << endl;

}