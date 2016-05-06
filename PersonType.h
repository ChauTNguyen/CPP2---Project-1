// Interface for PersonType class. Parent of the CandidateType.

#ifndef PERSONTYPE_H
#define PERSONTYPE_H

#include <string>
#include <iostream>

using namespace std;

class PersonType
{
public:
    PersonType();
    PersonType(const string& newFirst,
               const string& newLast,
               int newSSN);

    // setter functions
    void setPersonInfo(const string& newFirst,
                       const string& newLast,
                       int newSSN);

    // getter functions
    string getFirstName() const;
    string getLastName() const;
    int getSSN() const;

    // print functions
    void printName() const;
    void printPersonInfo() const;
    void printSSN() const;

    ~PersonType();

private:
    string firstName;
    string lastName;
    int ssn;
};

#endif