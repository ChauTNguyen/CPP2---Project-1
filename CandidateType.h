/*
	Nguyen, Chau
	Nguyen, Allan
	Mulkey, Ashton
	CS A250
	March 7, 2016

	Project 1
*/
// Interface for CandidateType class

#ifndef PROJECT_CANDIDATETYPE_H
#define PROJECT_CANDIDATETYPE_H

#include "PersonType.h"

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
