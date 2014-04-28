#include <iostream>
#include <string>
#include <ctime>
#include "inputHandler.h"
#include "puzzleSets.h"

using namespace std;

void getSetup(puzzleSets &puzzle);
void pauseFor(int time);
void printWinScreen();
void gameCycle(inputHandler &hand, puzzleSets &puzzle, bool &endState);

int main()
{
    bool terminate = false;
    inputHandler myInputHandler;
    puzzleSets mySet;
    getSetup(mySet);
    mySet.printVisibleSet();
    while(!terminate) {
        gameCycle(myInputHandler, mySet, terminate);
    }
    printWinScreen();
    return 0;
}

void getSetup(puzzleSets &puzzle) {
    std::cout << "What difficulty do you want to play at (0 - 2)? ";
    int inDif;
    std::cin >> inDif;
    puzzle.setDifficulty(inDif);
    std::cout << string(50, '\n');
    std::cout << "GAME" << std::endl << std::endl;
}

void printWinScreen() {
    std::cout << string(50, '\n');
    std::cout << "YOU ARE WINNER" << std::endl;
    std::cout << "GJ";
}

void gameCycle(inputHandler &hand, puzzleSets &puzzle, bool &endState) {

    int choice1;
    int choice2;
    int choice3;
    int choice4;
    hand.getChoice(choice2, 3 + (puzzle.difficulty*2));
    hand.getChoice(choice1, 3 + (puzzle.difficulty*2));
    puzzle.visible[choice1][choice2] = 1;
    std::cout << string(50, '\n');
    puzzle.printVisibleSet();

    hand.getChoice(choice4, 3 + (puzzle.difficulty*2));
    hand.getChoice(choice3, 3 + (puzzle.difficulty*2));
    puzzle.visible[choice3][choice4] = 1;
    std::cout << string(50, '\n');
    puzzle.printVisibleSet();

    if(puzzle.difficulty == 0) {
        if(puzzle.easy[choice1][choice2].compare(puzzle.easy[choice3][choice4]) != 0) {
            puzzle.visible[choice1][choice2] = 0;
            puzzle.visible[choice3][choice4] = 0;
            pauseFor(puzzle.waitTime);
            std::cout << string(50, '\n');
            puzzle.printVisibleSet();
        }
    } else if(puzzle.difficulty == 1) {
        if(puzzle.medium[choice1][choice2].compare(puzzle.medium[choice3][choice4]) != 0) {
            puzzle.visible[choice1][choice2] = 0;
            puzzle.visible[choice3][choice4] = 0;
            pauseFor(puzzle.waitTime);
            std::cout << string(50, '\n');
            puzzle.printVisibleSet();
        }
    } else if(puzzle.difficulty == 2) {
        if(puzzle.hard[choice1][choice2].compare(puzzle.hard[choice3][choice4]) != 0) {
            puzzle.visible[choice1][choice2] = 0;
            puzzle.visible[choice3][choice4] = 0;
            pauseFor(puzzle.waitTime);
            std::cout << string(50, '\n');
            puzzle.printVisibleSet();
        }
    }

    if(puzzle.checkWinState()) {
        endState = true;
    }
}

void pauseFor(int time) {
    std::clock_t start;
    std::clock_t start2;
    double duration;

    start = std::clock();
    start2 = std::clock();
    duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
    while(duration < (double) time) {
        duration = (std::clock() - start2) / (double) CLOCKS_PER_SEC;
        if(duration == 1) {
            std::cout << ".";
            start2 = std::clock();
        }
        duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
    }
}

