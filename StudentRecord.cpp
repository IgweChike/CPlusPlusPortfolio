/*Authors: Angelou May Abrajano (ama0917); Vic Johnson (vlj0048); Favour Asogwa; Denzel Chike*/
//#ifndef EUIDPROJECT2_HEADER_H
//#define EUIDPROJECT2_HEADER_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct Student
{
    string nameOfStudent;
    int stuID;
    int numStuTest;
    int* arryP;
    double avgTestScores;
};

string add_Student()
{
    string name;
    cout << "Student Name: " << endl;
    cin.ignore();
    getline(cin, name);
    return name;
}

int id_num()
{
    int IDnum;
    cout << "Student ID: " << endl;
    cin >> IDnum;
    return IDnum;
}

double grades()
{
    double score;
    int scr;
    cout << "How many scores? ";
    cin >> scr;

    double sum = 0.0;
    for (int i = 0; i < scr; i++)
    {
        cout << "Test Score #" << i + 1 << ": ";
        cin >> score;

        if (score < 0)
        {
            cout << "Scores cannot be less than 0, try again.\n";
            i--; // Decrement i to retry input for the same index
        }
        else
        {
            sum += score;
        }
    }

    return sum / scr;
}

void search(int userID)
{
    ifstream inFile("student.dat");
    if (!inFile)
    {
        cout << "Could not open input file" << endl;
        exit(1);
    }

    bool isMatch = false;
    Student searching;

    while (!isMatch && inFile >> searching.nameOfStudent)
    {
        inFile >> searching.stuID >> searching.numStuTest;

        searching.arryP = new int[searching.numStuTest];
        for (int i = 0; i < searching.numStuTest; i++)
        {
            inFile >> searching.arryP[i];
        }

        if (searching.stuID == userID)
        {
            isMatch = true;
        }
        else
        {
            isMatch = false;
            delete[] searching.arryP;
        }
    }

    if (isMatch)
    {
        cout << setw(30) << searching.nameOfStudent;
        cout << setw(15) << searching.stuID;
        for (int i = 0; i < searching.numStuTest; i++)
        {
            cout << setw(5) << searching.arryP[i];
        }
        cout << endl;
        delete[] searching.arryP;
    }
    else
    {
        cout << "Student does not exist." << endl;
    }

    inFile.close();
}

// ... (other functions remain the same)

enum Menu { Add = 1, Remove = 2, Display = 3, Search = 4, Results = 5, Quit = 6 };

int main()
{
    int choice;
    bool correct = true;
    int userID;

    do
    {
        cout << "---Menu---" << endl;
        cout << "1. ADD" << endl;
        cout << "2. REMOVE" << endl;
        cout << "3. DISPLAY" << endl;
        cout << "4. SEARCH" << endl;
        cout << "5. RESULTS" << endl;
        cout << "6. QUIT" << endl;
        cout << "Choose the option by typing the number associated with the option: ";
        cin >> choice;

        switch (static_cast<Menu>(choice))
        {
            case Add:
                cout << "ADD" << endl;
                // add_Student();
                correct = false;
                break;

            case Remove:
                cout << "REMOVE" << endl;
                // Implement the removal functionality
                correct = false;
                break;

            case Display:
                cout << "DISPLAY" << endl;
                // display();
                correct = false;
                break;

            case Search:
                cout << "Enter ID of student to search: ";
                cin >> userID;
                // search(userID);
                correct = false;
                break;

            case Results:
                cout << "RESULTS" << endl;
                // exportResults();
                correct = false;
                break;

            case Quit:
                cout << "PROGRAM END:" << endl;
                correct = false;
                break;

            default:
                cout << "INVALID CHOICE TRY AGAIN:" << endl;
                break;
        }
    } while (correct);

    return 0;
}
