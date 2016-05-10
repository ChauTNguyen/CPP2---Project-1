/*
    Nguyen, Chau
    Nguyen, Allan
    Mulkey, Ashton
    CS A250
    March 7, 2016

    Project 1
    */
// Handles the input.

#include "CandidateList.h"
#include "InputHandler.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void displayMenu();
void processChoice(CandidateList &candidateList);

int main() {
    CandidateList candidateList;

    readCandidateData(candidateList);
    displayMenu();
    processChoice(candidateList);

    cout << endl;
    system("Pause");
    return 0;
}

void displayMenu() {
    cout << "\n*** MAIN MENU ***\n";
    cout << "\nSelect one of the following:\n\n";
    cout << "    1: Print all candidates" << endl;
    cout << "    2: Print a candidate's division votes" << endl;
    cout << "    3: Print a candidate's total votes" << endl;
    cout << "    4: Print winner" << endl;
    cout << "    5. Print final results" << endl;
    cout << "    6: To exit" << endl;
}

void processChoice(CandidateList &candidateList) {
    int choice;
    cout << "\nEnter your choice: ";
    cin >> choice;

    while (choice > 0 && choice < 6) {
        string fName, lName;
        int division = 0,
                 ssn = 0;

        switch (choice) {
            // Print all candidates
        case 1:
            cout << endl;

            if (candidateList.isEmpty()) {
                cerr << "List is empty." << endl;
            } else {
                candidateList.printAllCandidates();
            }

            cout << endl;
            system("Pause");
            break;

            // Print a candidates's division votes
        case 2:
            if (candidateList.isEmpty()) {
                cerr << "List is empty." << endl;
            } else {
                cout << "\nEnter candidate's social security number (no dashes): ";
                cin >> ssn;
                cout << endl;

                if (candidateList.searchCandidate(ssn)) {
                    candidateList.printCandidateName(ssn);
                    cout << endl;
                    for (int i = 0; i < NUM_OF_DIVISIONS; ++i)
                        candidateList.printCandidateDivisionVotes(ssn, i);
                } else {
                    cout << "SSN not found." << endl;
                }
            }

            cout << endl;
            system("Pause");
            break;

            // Print a candidate's total votes
        case 3:
            if (candidateList.isEmpty()) {
                cerr << "List is empty." << endl;
            }  else {
                cout << "\nEnter candidate's social security number (no dashes): ";
                cin >> ssn;
                cout << endl;

                if (candidateList.searchCandidate(ssn)) {
                    candidateList.printCandidateName(ssn);
                    cout << endl;
                    candidateList.printCandidateTotalVotes(ssn);
                } else {
                    cout << "SSN not found." << endl;
                }
            }

            cout << endl;
            system("Pause");
            break;

            // Print winner
        case 4:
            if (candidateList.isEmpty()) {
                cerr << "\nList is empty." << endl;
            } else {
                ssn = candidateList.getWinner();
                cout << "\nElection winner: ";
                candidateList.printCandidateName(ssn);
                cout << endl;
                candidateList.printCandidateTotalVotes(ssn);
            }

            cout << endl;
            system("Pause");
            break;

            // Print final results in descending order
        case 5:
            if (candidateList.isEmpty()) {
                cerr << "\nList is empty." << endl;
            } else {
                candidateList.printFinalResults();
            }

            cout << endl;
            system("Pause");
            break;
        default:
            cout << "Sorry. That is not a selection." << endl;
        }

        displayMenu();
        cout << "\nEnter your choice: ";
        cin >> choice;
    }
}