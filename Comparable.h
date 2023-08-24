/**@file Comparable.h*/

/*
Tin Khuong
   Student ID: 0421141
   CSS 502B
   Program 4
   Prof. Clark Olson
   2/25/20

   This class serves as an abstract super class for the Item class and its derived classes.
   It has pure virtual methods which do not need to be implemented here. (But derived classes
   will need to implement them).
*/

#pragma once
#include <iostream>
using namespace std;

const bool DEBUG = false; //For Debugging

class Item; //Forward declarations
class Customer; //Forward declarations
#pragma once
class Comparable
{
private:

public:

   Comparable();
   
   virtual ~Comparable();

   //-------------------------------- Pure Virtual Methods---------------------------------
   
   virtual bool operator>(const Comparable& rhs)const = 0;

   virtual bool operator<(const Comparable& rhs)const = 0;

   virtual bool operator==(const Comparable& rhs)const = 0;

   virtual void printContents() = 0;

   virtual void increaseQuantity() = 0;

   virtual void decreaseQuantity() = 0;

};

