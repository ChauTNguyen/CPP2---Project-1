#include "CandidateList.h"

CandidateList::CandidateList() {
    candidates = new vector<CandidateType>;
}

CandidateList::CandidateList(const CandidateList& otherList) {
    candidates = new vector<CandidateType>;
    for (const auto &otherCandidate : *otherList.candidates) {
        candidates->push_back(otherCandidate);
    }
}

CandidateList& CandidateList::operator=(const CandidateList& otherList) {
    if (this != &otherList) {
        if (this->candidates->size() != otherList.candidates->size()) {
            delete candidates;
            candidates = new vector<CandidateType>;
        }

        for (const auto &otherCandidate : *otherList.candidates) {
            candidates->push_back(otherCandidate);
        }
    } else {
        cerr << "Attempted self assignment." << endl;
    }

    return *this;
}

bool CandidateList::isEmpty() const {
    return candidates->empty();
}

bool CandidateList::searchCandidate(int ssn) const {
    vector<CandidateType>::const_iterator vecIter;
    return searchCandidateList(ssn, vecIter);
}

bool CandidateList::searchCandidateList(int ssn,
    vector<CandidateType>::const_iterator& vecIter)
    const {
    vecIter = candidates->begin();
    bool found = false;

    while (!found && vecIter != candidates->end())
    {
        if (vecIter->getSSN() == ssn) {
            found = true;
        }
        else {
            vecIter++;
        }
    }

    if (found)
        return true;
    else
        return false;
}

void CandidateList::addCandidate(const CandidateType &c) const {
    candidates->push_back(c);
}

int CandidateList::getWinner() const {
    vector<CandidateType>::const_iterator vecIter;

    // max <= first element to save a bit of time
    vector<CandidateType>::const_iterator iterWithHighestNumOfVotes = candidates->begin();
    int max = iterWithHighestNumOfVotes->getTotalVotes();

    // vecIter can then start on the element after
    for (vecIter = candidates->begin() + 1; vecIter != candidates->end(); vecIter++) {
        if (vecIter->getTotalVotes() > max) {
            iterWithHighestNumOfVotes = vecIter;
        }
    }

    return iterWithHighestNumOfVotes->getSSN();
}

void CandidateList::printCandidateName(int ssn) const {
    vector<CandidateType>::const_iterator vecIter;
    if (searchCandidateList(ssn, vecIter))
        vecIter->printName();
}

void CandidateList::printAllCandidates() const {
    for (const auto &candidate : *candidates) {
        candidate.printCandidateInfo();

    }
}

void CandidateList::printCandidateDivisionVotes(int ssn, int divisionNumber) const {
    vector<CandidateType>::const_iterator vecIter;

    if (searchCandidateList(ssn, vecIter)) {
        cout << "Division " << divisionNumber
             << ": " << vecIter->getVotesByDivision(divisionNumber)
             << endl;
    }
}

void CandidateList::printCandidateTotalVotes(int ssn) const {
    vector<CandidateType>::const_iterator vecIter;
    if (searchCandidateList(ssn, vecIter))
        cout << "Total Votes: " << vecIter->getTotalVotes() << endl;
}

void CandidateList::printFinalResults() const {
    map<int, string> votesAndNames;
    for (const auto &candidate : *candidates) {
        votesAndNames.insert(
            pair<int, string>(
            candidate.getTotalVotes(),
            candidate.getFirstName() + " " + candidate.getLastName())
            );
    }

    map<int, string>::const_reverse_iterator mapIter;
    int count = 1; // to display the row number
    for (mapIter = votesAndNames.rbegin(); mapIter != votesAndNames.rend(); ++mapIter) {
        cout.width(5); cout << count << " | ";
        cout.width(3); cout << right << mapIter->first << " | " << mapIter->second << endl;
        ++count;
    }
}

CandidateList::~CandidateList() {
    delete candidates;
    candidates = nullptr;
}