//
// blackcard.h -- CPE 212-01, Fall 2010 -- Project02 -- Classes
//
// DO NOT MODIFY OR SUBMIT THIS FILE!!!
//

#ifndef BLACKCARD_H
#define BLACKCARD_H

#include "card.h"

class BlackCard : public Card
{
 private:
  // No additional private members
	
 public:
  // Constructors
  BlackCard(int v);             // Creates a black card with value v and unknown suit
	
  string Description() const override;   // Outputs card characteristics - value and color as a string
	                            // Hint: use base class Description method to generate part of 
	                            // the description and append the color information at the end
};

#endif

