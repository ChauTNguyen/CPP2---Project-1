// Interface for CandidateType class, child of PersonType

#ifndef PROJECT_CANDIDATETYPE_H
#define PROJECT_CANDIDATETYPE_H

#include "PersonType.h"

using namespace std;

const int NUM_OF_DIVISIONS = 4;

class CandidateType : public PersonType {
public:
    CandidateType();

    void updateVotesByDivision(int divisionNumber, int newNumOfVotes);
    int getTotalVotes() const;
    int getVotesByDivision(int divisionNumber) const;

    void printCandidateInfo() const;
    void printCandidateTotalVotes() const;
    void printCandidateDivisionVotes(int divisionNumber) const;

    ~CandidateType();

private:
    int totalNumOfVotes;
    int array[NUM_OF_DIVISIONS];
};

#endif //PROJECT_CANDIDATETYPE_H