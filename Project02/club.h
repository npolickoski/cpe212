//
// club.h -- CPE 212-01, Fall 2010 -- Project02 -- Classes
//
// DO NOT MODIFY OR SUBMIT THIS FILE!!!
//

#ifndef CLUB_H
#define CLUB_H

#include "blackcard.h"

class Club : public BlackCard
{
 private:
  // No additional private members		
		
 public:
  // Constructors
  Club(int v);   // Creates a black club card with value v
	
  string Description() const override;   // Outputs card characteristics - value, color, suit
	                                     // Hint: use base class Description method to generate part of 
	                                     // the description and append the suit information at the end	                  
};

#endif

