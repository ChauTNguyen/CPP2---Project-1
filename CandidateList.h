// Interface for CandidateList Class. Allows you to manipulate a list of Candidate objects.

#ifndef CANDIDATELIST_H
#define CANDIDATELIST_H

#include "CandidateType.h"

#include <iostream>
#include <string>

class Node
{
public:
	Node(){}
    Node(const CandidateType& votes, Node *theLink) 
		: candidate(votes), link(theLink){}
    Node* getLink( ) const { return link; }
	CandidateType getCandidate( ) const { return candidate; }
    void setCandidate(const CandidateType& votes) { candidate = votes; }
    void setLink(Node *theLink) { link = theLink; }
private:
    CandidateType candidate;
    Node *link;		//pointer that points to next node
};

class CandidateList
{
public:
	CandidateList();

	void addCandidate(const CandidateType &c);

	int getWinner() const;

	void printCandidateName(int ssn) const;
	void printAllCandidates() const;
	void printCandidateDivisionVotes(int ssn, int divisionNumber) const;
	void printCandidateTotalVotes(int ssn) const;
	void printFinalResults() const;

	void destroyList();
	~CandidateList();
	
private:
	Node *first; 	// pointer to point to the first candidate in the list
	Node *last;		// pointer to point to last candidate in the list
	int count;		// keeps track of number of candidates in the list
};

#endif
