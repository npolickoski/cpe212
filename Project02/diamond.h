//
// diamond.h -- CPE 212-01, Fall 2010 -- Project02 -- Classes
//
// DO NOT MODIFY OR SUBMIT THIS FILE!!!
//

#ifndef DIAMOND_H
#define DIAMOND_H

#include "redcard.h"

class Diamond : public RedCard
{
 private:
  // No additional private members		
		
 public:
  // Constructors
  Diamond(int v);    // Creates a red diamond card with value v
	
  string Description() const override;   // Outputs card characteristics - value, color, suit
	                            // Hint: use base class Description method to generate part of 
	                            // the description and append the suit information at the end
};

#endif

