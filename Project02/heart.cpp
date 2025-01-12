//
// heart.cpp -- CPE 212-01, Fall 2010 -- Project02 -- Classes
//
// Add the missing statements to complete each method below
// and SUBMIT this file for grading !!!
//

#include <iostream>
#include <cstdlib>
#include "heart.h"

Heart::Heart(int v) : RedCard::RedCard(v)
// Default Constructor: creates a red card with value v and heart suit
{
    SetSuit('H');
} 


string Heart::Description() const   
// Outputs card characteristics - value as a string
{
  string d = RedCard::Description();
  d += ", Suit = H";        // added to descrition

  return d;                 // Return string describing card value
}