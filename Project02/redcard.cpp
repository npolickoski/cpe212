//
// redcard.cpp -- CPE 212-01, Fall 2010 -- Project02 -- Classes
//
// Add the missing statements to complete each method below
// and SUBMIT this file for grading !!!
//

#include <iostream>
#include <cstdlib>
#include "redcard.h"

RedCard::RedCard(int v) : Card::Card(v)
// Default Constructor: creates a red card with value v and unknown suit
{
    SetColor("red");
} 


string RedCard::Description() const   
// Outputs card characteristics - value as a string
{
 string d = Card::Description();
  d += ", Color = red";      // full description

  return d;                 // Return string describing card value
}