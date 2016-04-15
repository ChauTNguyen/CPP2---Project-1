#include "CandidateList.h"

CandidateList::CandidateList()
{
	first = NULL;
	last = NULL;
	count = 0;
}

void CandidateList::addCandidate(const CandidateType &c)
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
		Node *current = first->getLink(); // no need to check the first node with current
										  // because the default max is the first node's amount of votes
		int highestNumberOfVotes = first->getCandidate().getTotalVotes();
		int ssnWithMostVotes = first->getCandidate().getSSN();

		while (current != NULL)
		{
			if (current->getCandidate().getTotalVotes() > highestNumberOfVotes)
			{
				highestNumberOfVotes = current->getCandidate().getTotalVotes();
				ssnWithMostVotes = current->getCandidate().getSSN();

				current = current->getLink();
			}
			else
				current = current->getLink();
		}

		current = NULL;

		return ssnWithMostVotes;
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
			if (current->getCandidate().getSSN() == ssn)
				found = true;
			else
				current = current->getLink();
		}

		if (found)
			current->getCandidate().printName();
		else
			cerr << "SSN not in the list.";

		current = NULL;
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

		current = NULL;
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
		{
			cout << "Division " << divisionNumber << ": "
				 << current->getCandidate().getVotesByDivision(divisionNumber) << endl;
		}

		current = NULL;
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

		current = NULL;
	}
}

void CandidateList::printFinalResults() const
{
	Node *current = first;
	Node *currentMax = first; // the current max within a single while loop iteration
	Node *previousMax = first; // used to make us ignore nodes that we already printed out (all numbers must be below the previousMax)
	
	int max = 0;

	cout << "\nFINAL RESULTS" << "\n-------------" << endl;
		
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
			previousMax = currentMax; // save the value for the next iteration
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

		// Reset the variables. Do not reset previousMax, we use that to ignore the nodes that were already printed.
		current = first;
		currentMax = first;
		max = 0;
	}
	
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