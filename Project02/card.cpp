//
// card.cpp -- CPE 212-01, Fall 2010 -- Project02 -- Classes
//
// Add the missing statements to complete each method below
// and SUBMIT this file for grading !!!
//

#include <iostream>
#include <cstdlib>
#include "card.h"

Card::Card()
// Default Constructor: Initializes value to 0, color to "unknown", and suit to 'U'
{
  value = 0;
  color = "unknown";
  suit = 'U';
} 


Card::Card(int v)
// Parameterized Constructor: Initializes value to v, color to "unknown", and suit to 'U'
{
  value = v;
  color = "unknown";
  suit = 'U';
}  


int Card::GetValue() const
// Returns variable value
{
  return value;
}


string Card::GetColor() const
// Returns variable color
{
  return color;
}


char Card::GetSuit() const
// Returns variable suit
{
  return suit;
}


void Card::SetValue(int v)
// Sets value to v
{
  value = v;
}


void Card::SetColor(string c)
// Sets color to c
{
  color = c;
}


void Card::SetSuit(char s)
// Sets suit to s
{
  suit = s;
}



string Card::Description() const   
// Outputs card characteristics - value as a string
// DO NOT MODIFY THIS METHOD !!!!
{
  string d = "Value = ";    // temporary variable used to accumulate result

  switch (value)            // Append card value to variable's value
  {
    case 2:   d = d + "2";    break;      // Number cards
    case 3:   d = d + "3";    break;
    case 4:   d = d + "4";    break;
    case 5:   d = d + "5";    break;
    case 6:   d = d + "6";    break;
    case 7:   d = d + "7";    break;
    case 8:   d = d + "8";    break;
	  case 9:   d = d + "9";    break;
    case 10:  d = d + "10";   break;
	
    case 11:  d = d + "J";    break;      // Face cards
    case 12:  d = d + "Q";    break;
	  case 13:  d = d + "K";    break;
	  case 14:  d = d + "A";    break;

	  default:  d = d + "?";    break;      // Unknown card
  }

  return d;                 // Return string describing card value
}

