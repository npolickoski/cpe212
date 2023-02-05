//
// card.h -- CPE 212-01, Fall 2010 -- Project02 -- Classes
//
// Add the missing statements to complete the class declaration below
// and SUBMIT this file for grading !!!
//

#include <string>
using namespace std;

#ifndef CARD_H
#define CARD_H

class Card                             // Class modeling Card ADT
{
    private:
         int value;			         // Card value: 2-10 for number cards, 11-14 for JQKA; 0 for unknown
         string color;			    // Card color: "red", "black", or "unknown"
         char suit;			         // Card suit: 'H' for hearts, 'D' for diamonds, 'C' for clubs, 'S' for spades or 'U' for unknown

    public:
         //******** Add Constructor Prototypes Below  *********//
         Card();                     // Default constructor prototype: creates card with value v, color unknown, and suit U
             
         Card(int v);	             // Parameterized constructor prototype: creates card with value v, color unknown, and suit U
             
             
         //******** Add Transformer Prototypes Below *********//
         int GetValue() const;       // SetValue prototype: Sets card value equal to v
             
         string GetColor() const;    // SetColor prototype: Sets color value equal to c
             
         char GetSuit() const;       // SetSuit prototype:  Sets suit value equal to s
             
             
         //******** Add Observer Prototypes Below *********//
         void SetValue(int v); 	  // GetValue prototype: Returns current value of value
             
         void SetColor(string c);    // GetColor prototype: Returns current value of color
             
         void SetSuit(char s);       // GetSuit prototype:  Returns current value of suit
             
         virtual string Description() const; // Description prototype: Polymorphic Function!!!
                                     // Outputs card characteristics - value as a string (see sample output from p01input1.txt)
};


#endif


