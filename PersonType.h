/*
	Nguyen, Chau
	Nguyen, Allan
	Mulkey, Ashton
	CS A250
	March 7, 2016

	Project 1
*/
// Interface for PersonType class. Parent of the CandidateType.

#ifndef PERSONTYPE_H
#define PERSONTYPE_H

#include <string>
#include <iostream>

using namespace std;

class PersonType
{
public:
	PersonType(); // default constructor
	PersonType(const string& newFirst, const string& newLast,
		int newSSN);

	// getter functions
	string getFirstName() const;
	string getLastName() const;
	int getSSN() const;

	// setter functions
	void setPersonInfo(const string& newFirst,
		const string& newLast, int newSSN);

	// print functions
	void printName() const;
	void printPersonInfo() const;
	void printSSN() const;

	~PersonType(); // deconstructor

private:
	string firstName;
	string lastName;
	int ssn;
};

#endif