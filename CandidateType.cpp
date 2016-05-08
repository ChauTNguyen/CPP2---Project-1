#include "CandidateType.h"

CandidateType::CandidateType() {
    totalNumOfVotes = 0;

    for (int i = 0; i < NUM_OF_DIVISIONS; i++)
        array[i] = 0;
}

void CandidateType::updateVotesByDivision(int divisionNumber, int newNumOfVotes) {
    totalNumOfVotes += newNumOfVotes;
    array[divisionNumber] += newNumOfVotes;
}

int CandidateType::getTotalVotes() const {
    return totalNumOfVotes;
}

int CandidateType::getVotesByDivision(int divisionNumber) const {
    return array[divisionNumber];
}

void CandidateType::printCandidateInfo() const {
    printSSN();
    cout << " - ";
    printName();
    cout << endl;
}

void CandidateType::printCandidateTotalVotes() const {
    printName();
    cout << "\n\tTotal Votes (all divisions): " << getTotalVotes() << endl;
}

void CandidateType::printCandidateDivisionVotes(int divisionNumber) const {
    printName();
    cout << "\n\tDivision " << divisionNumber
         << " total votes: " << getVotesByDivision(divisionNumber)
         << endl;
}

CandidateType::~CandidateType() { }