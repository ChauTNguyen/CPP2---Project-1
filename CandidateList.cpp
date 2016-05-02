#include "CandidateList.h"

CandidateList::CandidateList()
{

}

bool CandidateList::isEmpty() const
{
	return candidates.empty();
}

bool CandidateList::searchCandidate(int ssn) const
{
	vector<CandidateType>::const_iterator vecIter;
	return searchCandidateList(ssn, vecIter);
}

bool CandidateList::searchCandidateList
	(int ssn, vector<CandidateType>::const_iterator& vecIter) const
{
	vecIter = candidates.begin();
	bool found = false;

	while (!found && vecIter != candidates.end())
	{
		if (vecIter->getSSN() == ssn)
			found = true;
		else
			vecIter++;
	}

	if (found)
		return true;
	else
		return false;
}

void CandidateList::addCandidate(const CandidateType &c)
{
	candidates.push_back(c);
}

int CandidateList::getWinner() const
{
	vector<CandidateType>::const_iterator vecIter;

	// make the max the first element of the vector
	// to save a wee bit of time
	vector<CandidateType>::const_iterator iterWithHighestNumOfVotes = candidates.begin();
	int max = iterWithHighestNumOfVotes->getTotalVotes();

	// make sure to start at the second element
	for (vecIter = candidates.begin() + 1; vecIter != candidates.end(); vecIter++)
	{
		if (vecIter->getTotalVotes() > max)
			iterWithHighestNumOfVotes = vecIter;
	}

	return iterWithHighestNumOfVotes->getSSN();
}

void CandidateList::printCandidateName(int ssn) const
{
	vector<CandidateType>::const_iterator vecIter;

	if (searchCandidateList(ssn, vecIter))
		vecIter->printName();
}

void CandidateList::printAllCandidates() const
{
	vector<CandidateType>::const_iterator vecIter;

	for (vecIter = candidates.begin(); vecIter != candidates.end(); vecIter++)
		vecIter->printCandidateInfo();
}

void CandidateList::printCandidateDivisionVotes(int ssn, int divisionNumber) const
{
	vector<CandidateType>::const_iterator vecIter;

	if (searchCandidateList(ssn, vecIter))
		cout << "Division " << divisionNumber
			 << ": " << vecIter->getVotesByDivision(divisionNumber)
			 << endl;
}

void CandidateList::printCandidateTotalVotes(int ssn) const
{
	vector<CandidateType>::const_iterator vecIter;

	if (searchCandidateList(ssn, vecIter))
		cout << "Total Votes: " << vecIter->getTotalVotes() << endl;
}

void CandidateList::printFinalResults() const
{
	// vecIter can start at candidates.begin() + 1
	// assuming list is greater than 1
	vector<CandidateType>::const_iterator vecIter = candidates.begin() + 1;

	// prevIterWithHighestNumOfVotes will be used to
	// act as the upper bound for the next iteration of the for loop
	// it will help us print in descending order properly
	vector<CandidateType>::const_iterator prevIterWithHighestNumOfVotes = candidates.begin();

	// this will be used to save the location of the
	// candidate with the highest number of votes
	// in the current loop iteration
	vector<CandidateType>::const_iterator iterWithHighestNumOfVotes = candidates.begin();

	int max = iterWithHighestNumOfVotes->getTotalVotes();
	int size = static_cast<int>(candidates.size());

	cout << "\nFINAL RESULTS" << "\n-------------" << endl;

	for (int i = 0; i < size; i++)
	{
		if (i == 0) // find the abs max
		{
			while (vecIter != candidates.end())
			{
				if (vecIter->getTotalVotes() > max)
				{
					iterWithHighestNumOfVotes = vecIter;
					max = iterWithHighestNumOfVotes->getTotalVotes();
				}

				vecIter++;
			}
		}
		else // loop through and find the next maxes
		{	// each max must be below the previous max
			while (vecIter != candidates.end())
			{
				if (vecIter->getTotalVotes() < prevIterWithHighestNumOfVotes->getTotalVotes()
					&& vecIter->getTotalVotes() > max)
				{
					iterWithHighestNumOfVotes = vecIter;
					max = iterWithHighestNumOfVotes->getTotalVotes();
				}

				vecIter++;
			}
		}
		
		// formatting
		if (size - i < 10)
			cout << " " << size - i << "  ";
		else
			cout << size - i << "  ";

		if (max < 100)
			cout << max << " ";
		else
			cout << max;

		cout << " ";
		iterWithHighestNumOfVotes->printName();
		cout << endl;
		// end formatting

		// save the iterator with the highest num of votes
		// it'll become the upper bound for the next loop
		prevIterWithHighestNumOfVotes = iterWithHighestNumOfVotes;

		// do not reset previousIterWithhighestNumOfVotes
		vecIter = candidates.begin();
		iterWithHighestNumOfVotes = candidates.begin();
		max = 0; // max must be reset to 0 so that we have the votes in descending order
	}
}

CandidateList::~CandidateList()
{

}