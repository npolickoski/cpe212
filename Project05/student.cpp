//
// student.cpp    CPE 212 Fall 2010 -- Project05 - Binary Search Tree Template
//
// DO NOT MODIFY OR SUBMIT THIS FILE
//

#include "student.h"

Student::Student()
// Constructor initializes sid to -1, lastname and firstname to empty string
{
	sid = -1;
	lastname = "";
	firstname = "";
}  // End Student::Student()

	
Student::Student(int id, string lname, string fname)
// Constructor initializes sid, lastname, firstname to id, lname, and fname respectively
{
	sid = id;
	lastname = lname;
	firstname = fname;
}  // End Student::Student()


Student::Student(const Student&  s)
// Copy constructor -- copies attributes of s into attribute variables of current object
{
	sid = s.sid;
	lastname = s.lastname;
	firstname = s.firstname;
}


bool operator==(const Student& leftop, const Student& rightop)   
// Overloaded SAME AS operator  
// Returns true if leftop.sid == rightop.sid.  Returns false otherwise
{
	return  (leftop.sid == rightop.sid);
}  // End operator== for Student class


bool operator<(const Student& leftop, const Student& rightop)  
// Overloaded LESS THAN operator  
// Returns true if leftop.sid < rightop.sid.  Returns false otherwise
{
	return  (leftop.sid < rightop.sid);
}  // End operator < for Student class
	

bool operator>(const Student& leftop, const Student& rightop)  
// Overloaded GREATER THAN operator  
// Returns true if leftop.sid > rightop.sid.  Returns false otherwise
{
	return  (leftop.sid > rightop.sid);
}  // End operator < for Student class


void Student::operator=(const Student& op)    // Overloaded ASSIGNMENT operator  
// Sets this->sid = op.sid,	this->lastname = op.lastname, this->firstname = op.firstname
{
	this->sid = op.sid;
	this->lastname = op.lastname;
	this->firstname = op.firstname;
}  // End Student::operator=()
