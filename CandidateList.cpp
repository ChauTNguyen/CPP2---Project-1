//
// Created by Chau Nguyen on 3/5/16.
//

#include "CandidateList.h"

// Function definitions
CandidateList::CandidateList()
{
	first = NULL;
	last = NULL;
	count = 0;
}

void CandidateList::addCandidate(CandidateType &c)
{
	if (first == NULL)
	{
		Node *newNode = new Node(c, NULL);
		first = newNode;
		last = newNode;
		count++;
	}
	else
	{
		Node *current = first;

		while (current->getLink() != NULL)
			current = current->getLink();

		Node *newNode = new Node(c, NULL);
		current->setLink(newNode);
		last = newNode;
		count++;
	}
}

int CandidateList::getWinner() const
{
	if (first == NULL)
	{
		cerr << "List is empty." << endl;
		return 0;
	}
	else
	{
		Node *current = first;
		Node *highest = first;
		int highestNumberOfVotes = 0;

		while (current != NULL)
		{
			if (current->getCandidate().CandidateType::getTotalVotes() > highestNumberOfVotes)
			{
				highest = current;
				highestNumberOfVotes = highest->getCandidate().CandidateType::getTotalVotes();
			}
			current = current->getLink();
		}
		return highest->getCandidate().PersonType::getSSN();
	}
}

void CandidateList::printCandidateName(int ssn) const
{
	if (first == NULL)
		cerr << "List is empty." << endl;
	else
	{
		Node *current = first;
		bool found = false;
		 
		while (current != NULL && !found)
		{
			if (current->getCandidate().PersonType::getSSN() == ssn)
				found = true;
			else
				current = current->getLink();
		}

		if (found)
		{
			current->getCandidate().PersonType::printName();
		}
		else
			cout << "SSN not in the list." << endl;
	}
}

void CandidateList::printAllCandidates() const
{
	if (first == NULL)
		cerr << "List is empty." << endl;
	else
	{
		Node *current = first;

		while (current != NULL)
		{
			current->getCandidate().CandidateType::printCandidateInfo();
			current = current->getLink();
		}
	}
}

void CandidateList::printCandidateDivisionVotes(int ssn, int divisionNumber) const
{
	if (first == NULL)
		cerr << "List is empty." << endl;
	else
	{
		Node *current = first;
		bool found = false;

		while (current != NULL && !found)
		{
			if (current->getCandidate().PersonType::getSSN() == ssn)
				found = true;
			else
				current = current->getLink();
		}

		if (found)
			cout << "Division " << divisionNumber << ": "
			<< current->getCandidate().CandidateType::getVotesByDivision(divisionNumber) << endl;
	}
}

void CandidateList::printCandidateTotalVotes(int ssn) const
{
	if (first == NULL)
		cerr << "List is empty." << endl;
	else
	{
		Node *current = first;
		bool found = false;

		while (current != NULL && !found)
		{
			if (current->getCandidate().CandidateType::getSSN() == ssn)
				found = true;
			else
				current = current->getLink();
		}

		if (found)
			cout << "Total Votes: " << current->getCandidate().CandidateType::getTotalVotes();
	}
}

void CandidateList::destroyList()
{
	if (first == NULL)
		cerr << "List is empty." << endl;
	else
	{
		Node *temp;
		
		while (first->getLink() != NULL)
		{
			temp = first;
			first = first->getLink();
			delete temp;
			temp = NULL;
		}
		// first is already NULL from the loop
		last = NULL;
		count = 0;
	}
}

CandidateList::~CandidateList()
{
	destroyList();
}