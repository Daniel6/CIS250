#include "puzzleSets.h"
#include <iostream>
#include <string>


puzzleSets::puzzleSets()
{
    for(int x = 0; x < 8; x++) {
        for(int y = 0; y < 8; y++) {
            visible[x][y] = 0;
        }
    }

}

puzzleSets::~puzzleSets()
{
    //dtor
}

void puzzleSets::printHiddenSet() {
    std::cout << "   ";
    for(int i = 0; i < 4 + (2*difficulty); i++) {
        std::cout << " " << i << " ";
    }
    std::cout << std::endl << std::endl;
    for(int x = 0; x < 4 + (2*difficulty); x++) {
        std::cout << " " << x << " ";
        for(int y = 0; y < 4 + (2*difficulty); y++) {
            std::cout << " " << "X" << " ";
        }
        std::cout << std::endl << std::endl;
    }
}

void puzzleSets::printVisibleSet() {
    std::cout << "   ";
    for(int i = 0; i < 4 + (2*difficulty); i++) {
        std::cout << " " << i << " ";
    }
    std::cout << std::endl << std::endl;

    if(difficulty == 0) {
        for(int x = 0; x < 4; x++) {
            std::cout << " " << x << " ";
            for(int y = 0; y < 4; y++) {
                if(visible[x][y] == 1) {
                    std::cout << " " << easy[x][y] << " ";
                } else {
                    std::cout << " " << "X" << " ";
                }
            }
            std::cout << std::endl;
        }
    } else if(difficulty == 1) {
        for(int x = 0; x < 6; x++) {
            std::cout << " " << x << " ";
            for(int y = 0; y < 6; y++) {
                if(visible[x][y] == 1) {
                    std::cout << " " << medium[x][y] << " ";
                } else {
                    std::cout << " " << "X" << " ";
                }
            }
            std::cout << std::endl;
        }
    } else if(difficulty == 2) {
        for(int x = 0; x < 8; x++) {
            std::cout << " " << x << " ";
            for(int y = 0; y < 8; y++) {
                if(visible[x][y] == 1) {
                    std::cout << " " << hard[x][y] << " ";
                } else {
                    std::cout << " " << "X" << " ";
                }
            }
            std::cout << std::endl;
        }
    }
}

void puzzleSets::setDifficulty(int val) {
    difficulty = val;
    waitTime = (3 - difficulty) * 2; //Seconds
}

bool puzzleSets::checkWinState() {
    for(int x = 0; x < 4 + (2*difficulty); x++) {
        for(int y = 0; y < 4 + (2*difficulty); y++) {
            if(visible[x][y] == 0) {
                return false;
            }
        }
    }
    return true;
}
