//
// spade.cpp -- CPE 212-01, Fall 2010 -- Project02 -- Classes
//
// Add the missing statements to complete each method below
// and SUBMIT this file for grading !!!
//

#include <iostream>
#include <cstdlib>
#include "spade.h"

Spade::Spade(int v) : BlackCard::BlackCard(v)
// Default Constructor: creates a black card with value v and spade suit
{
    SetSuit('S');
} 


string Spade::Description() const   
// Outputs card characteristics - value as a string
// DO NOT MODIFY THIS METHOD !!!!
{
  string d = BlackCard::Description();

  d += ", Suit = S";    // full description

  return d;                 // Return string describing card value
}