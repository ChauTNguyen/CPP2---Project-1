#include "PersonType.h"

PersonType::PersonType() : ssn(0) { }

PersonType::PersonType(const string& newFirst,
                       const string& newLast,
                       int newSSN)
    : firstName(newFirst),
      lastName(newLast),
      ssn(newSSN) { }

void PersonType::setPersonInfo(const string& newFirst,
                               const string& newLast,
                               int newSSN) {
    firstName = newFirst;
    lastName = newLast;
    ssn = newSSN;
}

string PersonType::getFirstName() const { return firstName; }

string PersonType::getLastName() const { return lastName; }

int PersonType::getSSN() const { return ssn; }

void PersonType::printName() const {
    cout << lastName + ", " + firstName;
}

void PersonType::printPersonInfo() const {
    printSSN();
    cout << " " << firstName << " " << lastName;
}

void PersonType::printSSN() const {
    cout << ssn / 100000000 << (ssn / 10000000) % 10 << (ssn / 1000000) % 10
         << "-" << (ssn / 100000) % 10 << (ssn / 10000) % 10
         << "-" << (ssn / 1000) % 10 << (ssn / 100) % 10 << (ssn / 10) % 10 << ssn % 10;
}

PersonType::~PersonType() { }