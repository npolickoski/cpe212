//
// diamond.cpp -- CPE 212-01, Fall 2010 -- Project02 -- Classes
//
// Add the missing statements to complete each method below
// and SUBMIT this file for grading !!!
//

#include <iostream>
#include <cstdlib>
#include "diamond.h"

Diamond::Diamond(int v) : RedCard::RedCard(v)
// Default Constructor: creates a black card with value v and diamond suit
{
    SetSuit('D');
} 


string Diamond::Description() const   
// Outputs card characteristics - value as a string
{
  string d = RedCard::Description();
  d += ", Suit = D";        // full description

  return d;                 // Return string describing card value
}