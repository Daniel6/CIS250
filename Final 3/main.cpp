#include <iostream>
#include <unistd.h>
#include <windows.h>
#include <ctime>
#include <math.h>
#include "Tileset.h"

using namespace std;

void printStartScreen();
void getSettings();
void getInput();
void checkScore(int x1, int y1, int x2, int y2);
void startCountdown(int time);
void printWinScreen();

Tileset *mySet;
int difficulty;
int matches;
clock_t gameStartTime;
bool _terminate; //Set this to true to end the game

int main()
{
    matches = 0;
    gameStartTime = clock();
    _terminate = false;
    printStartScreen();
    getSettings();
    while(!_terminate) { //Main process
        //Standard Game Cycle
//        cout << "Cycle!" << endl;
        mySet->printSet();
        getInput();
    }
    printWinScreen();
    return 0;
}

void getInput() {
//    cout << "entered getInput()" << endl;
    int colNum1;
    int colNum2;
    int rowNum1;
    int rowNum2;
    //Get first choice
    rowNum1 = 4 + (mySet->getDifficulty()); //Make the following loops run at least once
    colNum1 = 4 + (mySet->getDifficulty()); //Fixes bug where after guessing two blocks game would soft lock
    while (colNum1 >= 4 + (mySet->getDifficulty())) { //Same as with the columns
        cout << "Enter column #: ";
        cin >> colNum1;
        if (colNum1 >= 4 + (mySet->getDifficulty())) {
            cout << "Invalid column #." << endl;
        }
    }
    while (rowNum1 >= 4 + (mySet->getDifficulty())) { //Keep repeating until valid number is set
        cout << "Enter row #: ";
        cin >> rowNum1;
        if (rowNum1 >= 4 + (mySet->getDifficulty())) {
            cout << "Invalid row #." << endl;
        }
    }
    mySet->setVisible(rowNum1, colNum1);
    //Set up the loop to run once
    colNum2 = colNum1;
    rowNum2 = rowNum1;
    //Get second choice
    while (colNum2 == colNum1 && rowNum2 == rowNum1) { //Keep prompting the user for input if they try to select the same block twice
        //Setting the two variables so the following while loops run at least once
        colNum2 = 4 + (mySet->getDifficulty());
        rowNum2 = 4 + (mySet->getDifficulty());
        while (colNum2 >= 4 + (mySet->getDifficulty())) { //Keep repeating until valid number is set
            cout << "Enter second column #: ";
            cin >> colNum2;
            if (colNum2 >= 4 + (mySet->getDifficulty())) {
                cout << "Invalid column #." << endl;
            }
        }
        while (rowNum2 >= 4 + (mySet->getDifficulty())) { //Same as with the columns
            cout << "Enter second row #: ";
            cin >> rowNum2;
            if (rowNum2 >= 4 + (mySet->getDifficulty())) {
                cout << "Invalid row #." << endl;
            }
        }
        if (colNum2 == colNum1 && rowNum2 == rowNum1) {
            cout << "You can't choose the same spot twice." << endl;
        }
    }

    mySet->setVisible(rowNum2, colNum2);
    mySet->printSet();
    checkScore(colNum1, rowNum1, colNum2, rowNum2);
}

void checkScore(int x1, int y1, int x2, int y2) { //Pass coordinates of two choices
    string choice1 = mySet->getElement(y1, x1);
    string choice2 = mySet->getElement(y2, x2);
    if (choice1 == "" || choice2 == "") { //If either of the choices were not supposed to be visible for some reason
        //Do nothing
    } else {
        if (choice1 == choice2) {
            //Score!
            matches++;
            if (matches == pow(4 + (mySet->getDifficulty() * 2), 2) / 2.0) {
//                cout << "TERMINATORED: " << matches << endl;
                _terminate = true;
            }
        } else {
            //The two choices did not match
            mySet->setInvisible(y1, x1);
            mySet->setInvisible(y2, x2);
            startCountdown(5 - mySet->getDifficulty());
        }
    }
}

void printStartScreen() {
    cout << "Welcome to Try and Daniels' Game" << endl << "Press ENTER to continue...";
    while (cin.get() != '\n') { //Hang until enter is pressed

    }
}

void startCountdown(int time) { //Wait for (time) in seconds
    for (int i = 0; i < time; i++) {
        cout << "." ;
        Sleep(1000);
    }
}

void printWinScreen() {
    cout << string(50, '\n'); //Clear screen
    cout << "You are the winner!" << endl;
    double duration = (clock() - gameStartTime) / (double) CLOCKS_PER_SEC;
    cout << "It took you " << duration << " seconds to beat the game on "; //Print how long it took and at what difficulty
    if (mySet->getDifficulty() == 0) {
        cout << "easy." << endl;
    } else if (mySet->getDifficulty() == 1) {
        cout << "medium." << endl;
    } else if (mySet->getDifficulty() == 2) {
        cout << "hard!" << endl;
    }
}

void getSettings() { //Get difficulty
    cout << "What difficulty would you like? (0-2)" << endl;
    cin >> difficulty; //If input is not a number, difficulty = 0
    if (difficulty > 2) { //If difficulty too high, set to cap
        difficulty = 2;
    }
    mySet = new Tileset(difficulty);
}
