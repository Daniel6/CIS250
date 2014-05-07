#include "Tileset.h"
#include <iostream>
#include <iomanip>

using namespace std;


Tileset::Tileset(int difficulty)
{
    _difficulty = difficulty;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            _visible[i][j] = 0;
        }
    }
    if (difficulty == 0) {
        //Setup array of elements
        string x[4][4] = { {"Li","C","N","He"},
                           {"B","K","Cs","Sn"},
                           {"C","B", "Cs","K"},
                           {"N","Li","He","Sn"} }; //Easy difficulty

        _elements.resize(4);
        for (int i = 0; i < 4; i++) {
            _elements[i].resize(4);
            for(int j = 0; j < 4; j++) {
                _elements[i][j] = x[i][j];
            }
        }

    } else if (difficulty == 1) {
        string x[6][6] = { {"H","Be", "O", "Be","Fe","V"},
                                {"O","Ti","Mg","Pb","I","Po"},
                                {"Cl","H","Ca","Ra","Sg","S"},
                                {"Al", "Fe","I","V","Si","P"},
                                {"Mg","Cl","Pb","Po","Ti","Ra"},
                                {"S","Sg","Ca","Si","P","Al"} }; //medium

        _elements.resize(6);
        for (int i = 0; i < 6; i++) {
            _elements[i].resize(6);
            for(int j = 0; j < 6; j++) {
                _elements[i][j] = x[i][j];
            }
        }

    } else if (difficulty == 2) {
        string x[8][8] = { {"Cu","W","Ne","At","Cn","Ni","Mo","Ag"},
                                {"Eu","Hg","Hf","Cr","Zn","Y","Xe","Hf"},
                                {"F","Se","Ar","Zn","Bk","W","F","Na"},
                                {"Ga","Te","Mn","Cu","Sr","Ag","Hg","U"},
                                {"Ni","Xe","Sr","Na","Y","Bk","Co","Ce"},
                                {"Rn","Ne","Co","Mo","Ar","Se","Te","Sb"},
                                {"Sb","Mn","Ga","Cr","Eu","Rn","Kr","Au"},
                                {"Au","Cn","Kr","Ce","U","As","As","At"} };//hard

        _elements.resize(8);
        for (int i = 0; i < 8; i++) {
            _elements[i].resize(8);
            for(int j = 0; j < 8; j++) {
                _elements[i][j] = x[i][j];
            }
        }
    }
}

void Tileset::printSet() {
    cout << string(50, '\n');
    int width = 4 + (_difficulty * 2);
    int height = 4 + (_difficulty * 2);
    cout << "     ";
    for (int y = 0; y < height; y++) {
        cout << setw(3) << y;
    }
    cout << endl << endl;
    for (int x = 0; x < width; x++) {
        cout << "  " << x << "  ";
        for (int y = 0; y < height; y++) {
            if(_visible[x][y] == 1) {
                cout << setw(3) << _elements[x][y];
            } else {
                cout << setw(3) << "X";
            }
        }
        cout << endl;
    }
//    while (cin.get() != '\n') { //Hang until enter is pressed
//
//    }
}

string Tileset::getElement(int x, int y) {
    if (_visible[x][y] == 1) {
        return _elements[x][y];
    }
    return "";
}

int Tileset::getDifficulty() {
    return _difficulty;
}

void Tileset::setVisible(int x, int y) {
    _visible[x][y] = 1;
}

void Tileset::setInvisible(int x, int y) {
    _visible[x][y] = 0;
}

Tileset::~Tileset()
{
    //dtor
}
