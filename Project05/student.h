//
// student.h    CPE 212 Fall 2010 -- Project05 - Binary Search Tree Template
//
// DO NOT MODIFIY OR SUBMIT THIS FILE
//

#include <iostream>
using namespace std;

#ifndef STUDENT_H
#define STUDENT_H

class Student
{
private:
	int      sid;           // Student ID number
	string   lastname;      // Student last name
	string   firstname;     // Student first name

public:
	/**** Start of functions to implement ****/
	
	Student();
	// Default constructor initializes sid to -1, firstname and lastname to empty string
	
	Student(int id, string lname, string fname);   
	// Constructor initializes sid, lastname, firstname to id, lname, and fname respectively
	
	Student(const Student&  s);
	// Copy constructor -- copies attributes of s into attribute variables of current object

	friend bool operator==(const Student& leftop, const Student& rightop);   // Overloaded SAME AS operator  
	// Returns true if leftop.sid == rightop.sid.  Returns false otherwise

	friend bool operator<(const Student& leftop, const Student& rightop);    // Overloaded LESS THAN operator  
	// Returns true if leftop.sid < rightop.sid.  Returns false otherwise
	
	friend bool operator>(const Student& leftop, const Student& rightop);    // Overloaded GREATER THAN operator  
	// Returns true if leftop.sid > rightop.sid.  Returns false otherwise
	
	void operator=(const Student& op);                                       // Overloaded ASSIGNMENT operator  
	// Sets this->sid = op.sid,	this->lastname = op.lastname, this->firstname = op.firstname
	
	/***** End of functions to implement *****/
	
	/***** Below are additional functions for your Student class -- DO NOT MOVE OR MODIFY THE CODE BELOW *****/ 
	
    friend istream& operator>>(istream& leftop, Student& rightop)            // Overloaded >> operator
	// This allows all data associated with a Student object to be input simultaneously from an input stream
	{
		leftop >> rightop.sid >> rightop.lastname >> rightop.firstname;
		
		return leftop;
	}

	friend ostream& operator<<(ostream& leftop, const Student& rightop)      // Overloaded << operator
	// This allows all data associated with a Student object to be output simultaneously to an output stream
	{
		leftop << "(" << rightop.sid << ", " << rightop.firstname << " " << rightop.lastname << ")";
		
		return leftop;
	}	
	
	void Print() const      // Outputs student information in desired format.  DO NOT MOVE OR MODIFY
	{
		cout << "SID: " << sid << "  Name: ";
		
		if (lastname == "")
			cout << "NULL";
		else
			cout << lastname;
		cout << ", ";
		
		if (firstname == "")
			cout << "NULL";
		else
			cout << firstname;
	}  // End Print()
};

#endif


