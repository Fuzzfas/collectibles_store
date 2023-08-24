/**@file Comic.h*/

/*
Tin Khuong
   Student ID: 0421141
   CSS 502B
   Program 4
   Prof. Clark Olson
   2/25/20

   This class represents a Comic object. It overrides Comparable comparison operators based on its own unique data members
*/

#include "Comic.h"

/*-------------------------------- Default Constructor ---------------------------------
@pre A Store Object exists.
@post Creates a new Comic object and initializes fields to default values.
*/
Comic::Comic():Item()
{
   publisher = "defaultPublisher";
   title = "defaultTitle";
   year = 0;
   grade = "defaultGrade";
}

/*-------------------------------- Parameterized Constructor ---------------------------------
@pre An Inventory Dummy Object exists in the Factory class which calls this method via create() during inventory initialization
   from reading external file, or when calling buy().
@post Assigns data members from parameters to this object.
*/
Comic::Comic(char itemType, int quantity, string publisher, string title, int year, string grade): Item(itemType, quantity)
{
   this->publisher = publisher;
   this->title = title;
   this->year = year;
   this->grade = grade;
}

/*-------------------------------- Destructor ---------------------------------
@pre A Comic Object exists.
@post Deallocates memory associated with this object
*/
Comic::~Comic(){}

/*-------------------------------- operator> ---------------------------------
@pre rhs is a valid Item object to compare. Overrides Comparable operator>
@post Returns true if this Comic is greater than rhs, false if not.
*/
bool Comic::operator>(const Comparable& rhs)const
{

   const Comic& c = static_cast<const Comic&>(rhs); //Static cast from derived to base class
   //Sorting criteria:  publisher, title, year, grade
   if(this->publisher == c.publisher)
   {
      if(this->title == c.title)
      {
         if(this->year == c.year)
         {
            return this->grade > c.grade;
         }
         else
         {
            return this->year > c.year;
         }
      }
      else
      {
         return this-> title > c.title;
      }
   }
   else
   {
      return this->publisher > c.publisher;
   }
   
}

/*-------------------------------- operator< ---------------------------------
@pre rhs is a valid Item object to compare. Overrides Comparable operator<
@post Returns true if this Comic is less than rhs, false if not.
*/
bool Comic::operator<(const Comparable& rhs)const
{
   const Comic& c = static_cast<const Comic&>(rhs); //Static cast from derived to base class

   //Sorting criteria:  publisher, title, year, grade
   if (this->publisher == c.publisher)
   {
      if (this->title == c.title)
      {
         if (this->year == c.year)
         {
            return this->grade < c.grade;
         }
         else
         {
            return this->year < c.year;
         }
      }
      else
      {
         return this->title < c.title;
      }
   }
   else
   {
      return this->publisher < c.publisher;
   }
}

/*-------------------------------- operator== ---------------------------------
@pre rhs is a valid Item object to compare. Overrides Comparable operator==
@post Returns true if this Comic is equal to rhs, false if not.
*/
bool Comic::operator==(const Comparable& rhs)const
{

   const Comic& c = static_cast<const Comic&>(rhs); //Static cast from derived to base class

   if(this->publisher == c.publisher)
   {
      if(this->title == c.title)
      {
         if (this->year == c.year)
         {
            return this->grade == c.grade;
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
Comic* Comic::create(int quantity, string input)
{
   stringstream s(input);

   string publisher;
   string strYear;
   int year;   
   string grade;
   string title;

   getline(s, strYear, ',');     //get year
   year = atoi(strYear.c_str()); //convert year to int
   s.get();                      //skip space
   getline(s, grade, ',');    //get grade
   s.get();                      //skip space
   getline(s, title, ',');       //get title
   s.get();                      //skip space
   getline(s, publisher, '\0');  //get publisher

   Comic* comicPtr = new Comic('C', quantity, publisher, title, year, grade);

   return comicPtr;
}

/*-------------------------------- printContents() ---------------------------------
@pre A Comic object exists.
@post Outputs data members of this Comic.
*/
void Comic::printContents()
{
   cout << itemType << ", " << quantity << ", " << year << ", " << grade << ", " << title << ", " << publisher << endl;

}