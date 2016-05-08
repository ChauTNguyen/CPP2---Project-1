// Interface for CandidateList Class. Allows you to manipulate a list of CandidateType objects.

#ifndef CANDIDATELIST_H
#define CANDIDATELIST_H

#include "CandidateType.h"

#include <vector>
#include <map>

class CandidateList {
public:
    CandidateList();
    CandidateList(const CandidateList& otherList);
    CandidateList& operator=(const CandidateList& otherList);

    bool isEmpty() const;
    bool searchCandidate(int ssn) const;

    void addCandidate(const CandidateType &c) const;

    int getWinner() const;

    void printCandidateName(int ssn) const;
    void printAllCandidates() const;
    void printCandidateDivisionVotes(int ssn, int divisionNumber) const;
    void printCandidateTotalVotes(int ssn) const;
    void printFinalResults() const;

    ~CandidateList();

private:
    vector<CandidateType> *candidates;

    bool searchCandidateList(int ssn, vector<CandidateType>::const_iterator& vecIter) const;
};

#endif
