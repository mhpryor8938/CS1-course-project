//     ***************************************************************
//     **                    PROGRAM DESCRIPTION                    **
//     ***************************************************************
//     ** This program is designed to perform a lottery for a local **
//     **             universities computer science club            **
//     ***************************************************************
//     ** The program should:                                       **
//     ** 1. Prompt input for seven different winning numbers       **
//     ** 2. Calculate the winners of the lottery                   **
//     ** 3. display a general report for students who entered      **
//     ** 4. display a winning report for students who won          **
//     ***************************************************************
//     **                   Maximum of 50 students                  **
//     ***************************************************************

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <math.h>

using namespace std;

// GLOBAL VARIABLES:
const int StudentCOUNT = 50;
const int LOTTO = 7;

// STRUCTURE DECLARATIONS:
struct StudentINFO
{
    int studentID;
    string studentName;
    int sNum1, sNum2, sNum3, sNum4, sNum5, sNum6, sNum7;
    int numsMatched = 0;
    double Prize;
};

// FUNCTION DECLARATIONS:
void studentRegistrations(StudentINFO student[StudentCOUNT]);
void determineWinners(StudentINFO student[StudentCOUNT], int number[LOTTO]);
void reportResults(StudentINFO student[StudentCOUNT]);
void reportWinners(StudentINFO student[StudentCOUNT]);

// PROGRAM BODY:
int main()
{
    // STRUCTURE DEFINITIONS:
    StudentINFO student[StudentCOUNT];

    // VARIABLE DECLARATION:
    char repeat;
    int number[LOTTO] = { 0 };

    // PROGRAM HEADER:
    cout << "-----------------------------------------------------------------------------" << endl;
    cout << "* * * * * * * * * * * * COMPUTER SCIENCE CLUB LOTTERY * * * * * * * * * * * *" << endl;
    cout << "-----------------------------------------------------------------------------" << endl << endl << endl;

    // REPEAT PROGRAM:
    do
    {
        // GET THE WINNING LOTTERY NUMBERS FROM USER:
        cout << "\nEnter the 7 different, random numbers between 1 and 50 that were selected:" << endl;
        cout << "--------------------------------------------------------------------------" << endl << endl;

        for (int j = 0; j < LOTTO; j++)
        {
            cout << "\nNumber " << j + 1 << ": ";
            cin >> number[j];
        }

        // FUNCTION CALLS:
        studentRegistrations(student);
        determineWinners(student, number);
        reportResults(student);
        reportWinners(student);

        cout << "\n\nWould you like to run another lottery? (Y or N): ";
        cin >> repeat;
    } while (repeat == 'y' || repeat == 'Y');

    cout << "\n\nEnd of Program.";
    cout << endl << endl;
    return 0;

}

// FUNCTION DEFINITIONS:

void studentRegistrations(StudentINFO student[StudentCOUNT]) // GET THE STUDENT INFORMATION FROM THE SPECIFIED FILE:
{
    int i = 0;
    ifstream inFile;

    // FILE NAME:
    inFile.open("guesses1.txt");
    if (!inFile)
        cout << "\n\n**** ERROR OPENING FILE. ******\n" << endl;
    else
    {
        while (!inFile.eof())
        {
            inFile >> student[i].studentID;
            getline(inFile, student[i].studentName);
            inFile >> student[i].sNum1 >> student[i].sNum2 >> student[i].sNum3 >> student[i].sNum4 >> student[i].sNum5 >> student[i].sNum6 >> student[i].sNum7;
            i++;
        }
    }
    inFile.close();
}

// FUNCTION BODY:
void determineWinners(StudentINFO student[StudentCOUNT], int number[LOTTO]) // DETERMINE THE LOTTERY WINNERS AND THEIR REWARD:
{
    // DETERMINE HOW MANY NUMBERS MATCH:
    for (int i = 0; i < StudentCOUNT; i++)
    {
        for (int j = 0; j < LOTTO; j++)
        {
            if (student[i].sNum1 == number[j])
                student[i].numsMatched = student[i].numsMatched + 1;
            if (student[i].sNum2 == number[j])
                student[i].numsMatched = student[i].numsMatched + 1;
            if (student[i].sNum3 == number[j])
                student[i].numsMatched = student[i].numsMatched + 1;
            if (student[i].sNum4 == number[j])
                student[i].numsMatched = student[i].numsMatched + 1;
            if (student[i].sNum5 == number[j])
                student[i].numsMatched = student[i].numsMatched + 1;
            if (student[i].sNum6 == number[j])
                student[i].numsMatched = student[i].numsMatched + 1;
            if (student[i].sNum7 == number[j])
                student[i].numsMatched = student[i].numsMatched + 1;
        }
    }

    // DETERMINE STUDENT REWARDS:
    for (int i = 0; i < StudentCOUNT; i++)
    {
        if (student[i].numsMatched == 5)
            student[i].Prize = 5.00;
        else if (student[i].numsMatched == 6)
            student[i].Prize = 10.00;
        else if (student[i].numsMatched == 7)
            student[i].Prize = 20.00;
        else
            student[i].Prize = 0.00;
    }
}

// FUNCTION BODY:
void reportResults(StudentINFO student[StudentCOUNT]) // REPORT THE RESULTS OF THE LOTTERY:
{
    // OUTPUT GENERAL LOTTERY RESULTS:
    cout << endl << endl << endl;
    cout << "-----------------------------------------------------------------------------------------------" << endl;
    cout << "* * * * * * * * * * * * * * * * * * * * LOTTERY RESULTS * * * * * * * * * * * * * * * * * * * *" << endl;
    cout << "-----------------------------------------------------------------------------------------------" << endl;
    cout << "Student ID:          Student Name:           Chosen Numbers:          Matches:         Prize $:" << endl;
    cout << "-----------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < StudentCOUNT; i++)
    {
        if (student[i].studentID > 1)
        {
            cout << setw(20) << left << student[i].studentID;
            cout << setw(25) << student[i].studentName;
            cout << setw(3) << student[i].sNum1 << setw(3) << student[i].sNum2 << setw(3) << student[i].sNum3 << setw(3) << student[i].sNum4 << setw(3) << student[i].sNum5 << setw(3) << student[i].sNum6 << setw(3) << student[i].sNum7;
            cout << setw(8) << right << student[i].numsMatched;
            cout << setprecision(2) << fixed << showpoint;
            cout << setw(18) << right << student[i].Prize;
            cout << endl;
        }
    }
    cout << "-----------------------------------------------------------------------------------------------";
    cout << endl << endl << endl;
}

// FUNCTION BODY:
void reportWinners(StudentINFO student[StudentCOUNT]) // REPORT THE WINNERS OF THE LOTTERY:
{
    // OUTPUT WINNING RESULTS:
    cout << "---------------------------------------------------------------------" << endl;
    cout << "* * * * * * * * * * * * * * WINNINGS REPORT * * * * * * * * * * * * *" << endl;
    cout << "---------------------------------------------------------------------" << endl << endl << endl;

    // STUDENTS WHO CORRECTLY GUESSED ALL NUMBERS:
    cout << "---------------------------------------------------------------------" << endl;
    cout << "***************** STUDENTS WHO GUESSED EVERY NUMBER *****************" << endl;
    cout << "---------------------------------------------------------------------" << endl;
    cout << "Student ID:          Student Name:          Matches:         Prize $:" << endl;
    cout << "---------------------------------------------------------------------" << endl;
    for (int i = 0; i < StudentCOUNT; i++)
    {
        if (student[i].numsMatched == 7)
        {
            cout << setw(20) << left << student[i].studentID;
            cout << setw(25) << student[i].studentName;
            cout << setw(3) << right << student[i].numsMatched;
            cout << setprecision(2) << fixed << showpoint;
            cout << setw(18) << right << student[i].Prize;
            cout << endl;
        }
    }
    cout << "---------------------------------------------------------------------" << endl;

    cout << endl << endl;

    // STUDENTS WHO CORRECTLY GUESSED SIX NUMBERS:
    cout << "---------------------------------------------------------------------" << endl;
    cout << "****************** STUDENTS WHO GUESSED SIX NUMBERS *****************" << endl;
    cout << "---------------------------------------------------------------------" << endl;
    cout << "Student ID:          Student Name:          Matches:         Prize $:" << endl;
    cout << "---------------------------------------------------------------------" << endl;
    for (int i = 0; i < StudentCOUNT; i++)
    {
        if (student[i].numsMatched == 6)
        {
            cout << setw(20) << left << student[i].studentID;
            cout << setw(25) << student[i].studentName;
            cout << setw(3) << right << student[i].numsMatched;
            cout << setprecision(2) << fixed << showpoint;
            cout << setw(18) << right << student[i].Prize;
            cout << endl;
        }
    }
    cout << "---------------------------------------------------------------------" << endl;

    cout << endl << endl;

    // STUDENTS WHO CORRECTLY GUESSED FIVE NUMBERS:
    cout << "---------------------------------------------------------------------" << endl;
    cout << "***************** STUDENTS WHO GUESSED FIVE NUMBERS *****************" << endl;
    cout << "---------------------------------------------------------------------" << endl;
    cout << "Student ID:          Student Name:          Matches:         Prize $:" << endl;
    cout << "---------------------------------------------------------------------" << endl;
    for (int i = 0; i < StudentCOUNT; i++)
    {
        if (student[i].numsMatched == 5)
        {
            cout << setw(20) << left << student[i].studentID;
            cout << setw(25) << student[i].studentName;
            cout << setw(3) << right << student[i].numsMatched;
            cout << setprecision(2) << fixed << showpoint;
            cout << setw(18) << right << student[i].Prize;
            cout << endl;
        }
    }
    cout << "---------------------------------------------------------------------" << endl;

    cout << endl << endl;
}