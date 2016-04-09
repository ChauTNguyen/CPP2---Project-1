#include "CandidateType.h"

/*
    @brief Initializes the member variables.
 */
CandidateType::CandidateType()
{
    totalNumOfVotes = 0;

    // set all array elements to 0
    for (int i = 0; i < NUM_OF_DIVISIONS; i++)
        array[i] = 0;
}

/*
    @brief Updates votes of a certain division.

    @param divisionNumber
    @param newNumVotes is the number of votes that will be added
 */
void CandidateType::updateVotesByDivision(int divisionNumber, int newNumOfVotes)
{
    totalNumOfVotes += newNumOfVotes;
    array[divisionNumber] += newNumOfVotes;
}

/*
    @brief Returns the total number of votes.

    @return the total number of votes.
 */
int CandidateType::getTotalVotes() const
{
    return totalNumOfVotes;
}

/*
    @brief Returns the number of votes of a certain division.

    @param divisionNumber
    @return the number of votes of a certain division.
 */
int CandidateType::getVotesByDivision(int divisionNumber) const
{
    return array[divisionNumber];
}

/*
    @brief Prints the candidate's SSN, last name, and first name, in a specific format.
 */
void CandidateType::printCandidateInfo() const
{
    printSSN();
	printName();
    cout << endl;
}

/*
    @brief Prints the candidate's total votes (across all divisions) in a specific format.
 */
void CandidateType::printCandidateTotalVotes() const
{
    printName();
    cout << "\n\tTotal Votes (all divisions): " << getTotalVotes() << endl;  // check if tab is right later
}

/*
    @brief Prints the candidate's votes for the specified division in a specific format.

    @param divisionNumber
 */
void CandidateType::printCandidateDivisionVotes(int divisionNumber) const
{
    printName();
    cout << "\n\tDivision " << divisionNumber << " total votes: " << getVotesByDivision(divisionNumber) << endl;
}

/*
    @brief Deconstructor
 */
CandidateType::~CandidateType()
{

}