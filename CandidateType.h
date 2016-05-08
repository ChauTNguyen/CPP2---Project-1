// Interface for CandidateType class, child of PersonType

#ifndef PROJECT_CANDIDATETYPE_H
#define PROJECT_CANDIDATETYPE_H

#include "PersonType.h"

using namespace std;

const int NUM_OF_DIVISIONS = 4;

class CandidateType : public PersonType {
public:
    CandidateType(); // default constructor

    // Function updateVotesByDivision()
    void updateVotesByDivision(int divisionNumber, int newNumOfVotes);

    // Function getTotalVotes()
    int getTotalVotes() const;

    // Function getVotesByDivision()
    int getVotesByDivision(int divisionNumber) const;

    // Function printCandidateInfo()
    void printCandidateInfo() const;

    // Function printCandidateTotalVotes()
    void printCandidateTotalVotes() const;

    // Function printCandidateDivisionVotes()
    void printCandidateDivisionVotes(int divisionNumber) const;

    ~CandidateType(); // deconstructor

private:
    int totalNumOfVotes;
    int array[NUM_OF_DIVISIONS]; // does this have to be a dynamic array?
};

#endif //PROJECT_CANDIDATETYPE_H