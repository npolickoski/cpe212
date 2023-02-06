//
// blackcard.cpp -- CPE 212-01, Fall 2010 -- Project02 -- Classes
//
// Add the missing statements to complete each method below
// and SUBMIT this file for grading !!!
//

#include <iostream>
#include <cstdlib>
#include "blackcard.h"

BlackCard::BlackCard(int v) : Card::Card(v)
// Default Constructor: creates a black card with value v and unknown suit
{
    SetColor("black");
} 


string BlackCard::Description() const   
// Outputs card characteristics - value as a string
{
  string d = Card::Description();
  d += ", Color = black";                 // full description

  return d;                 // Return string describing card value
}
