#include "CandidateList.h"

// Function definitions
CandidateList::CandidateList()
{
	first = last = NULL;
	count = 0;
}

void CandidateList::addCandidate(const CandidateType& c)
{
	if (first == NULL)
		first = last = new Node(c, NULL);
	else
	{
		last->setLink(new Node(c, NULL));
		last = last->getLink();
	}
	++count;
}

int CandidateList::getWinner() const
{
	if (first == NULL)
	{
		cerr << "List is empty." << endl;
		return -1;
	}
	else
	{
		Node *current = first;
		/*Node *highest = first;
		int highestNumberOfVotes = current->getCandidate().getTotalVotes();

		while (current != NULL)
		{
			if (current->getCandidate().getTotalVotes() > highestNumberOfVotes)
			{
				highest = current;
				highestNumberOfVotes = highest->getCandidate().getTotalVotes();
			}
			current = current->getLink();
		}
		return highest->getCandidate().getSSN();*/
		int highestNumberOfVotes = current->getCandidate().getTotalVotes();
		int ssn = current->getCandidate().getSSN();
		
		while (current != NULL)
		{
			if (current->getCandidate().getTotalVotes() > highestNumberOfVotes)
			{
				highestNumberOfVotes = current->getCandidate().getTotalVotes();
				ssn = current->getCandidate().getSSN();
				
				current = current->getLink();
			}
			else
				current = current->getLink();
		}
		return ssn;
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
			current->getCandidate().PersonType::printName();
		else
			cerr << "SSN not in the list.";
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
			current->getCandidate().printCandidateInfo();
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
			if (current->getCandidate().getSSN() == ssn)
				found = true;
			else
				current = current->getLink();
		}

		if (found)
			cout << "Division " << divisionNumber << ": "
			<< current->getCandidate().getVotesByDivision(divisionNumber) << endl;
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
			if (current->getCandidate().getSSN() == ssn)
				found = true;
			else
				current = current->getLink();
		}

		if (found)
			cout << "Total Votes: " << current->getCandidate().getTotalVotes() << endl;
	}
}

void CandidateList::printFinalResults() const
{
	Node *current = first;
	Node *currentMax = first;
	Node *previousMax = first; // Used to make us skip nodes that we already printed out.
	
	int max = 0;

	for (int i = 0; i < count; i++)
	{
		if (i == 0) // Find the absolute maximum of the list. Prints 278.
		{
			while (current != NULL)
			{
				if (current->getCandidate().getTotalVotes() > max)
				{
					previousMax = current;
					max = previousMax->getCandidate().getTotalVotes();
				}
				current = current->getLink();
			}
		}
		else // Find the relative maximums, crossing out the ones we already used. 233 -> 221 -> 173 -> and so on...
		{
			while (current != NULL)
			{
				if (current->getCandidate().getTotalVotes() < previousMax->getCandidate().getTotalVotes()
					&& current->getCandidate().getTotalVotes() > max)
				{
					currentMax = current;
					max = current->getCandidate().getTotalVotes();
				}
				current = current->getLink();
			}
			previousMax = currentMax;
		}
		
		// Format and prints the current max.
		if (count - i < 10)
			cout << ' ' << (count - i) << "  ";
		else
			cout << count - i << "  ";
		if (max < 100)
			cout << max << " ";
		else
			cout << max;
		cout << " ";
		previousMax->getCandidate().printName();
		cout << endl;

		// Reset the variables. Do not reset previousMax, we use that to weed out the nodes that were already printed.
		current = first;
		currentMax = first;
		max = 0;
	}
	// Move pointers to the end and safely delete them.
	current = last->getLink();
	currentMax = last->getLink();
	previousMax = last->getLink();
	current = currentMax = previousMax = NULL;
}

void CandidateList::destroyList()
{
	if (first == NULL)
		cerr << "List is empty." << endl;
	else
	{
		Node *temp;
		
		while (first != NULL)
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