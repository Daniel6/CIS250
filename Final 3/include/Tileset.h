#ifndef TILESET_H
#define TILESET_H
#include <iostream>
#include <vector>

using namespace std;

class Tileset
{
    public:
//        Tileset();
        Tileset(int difficulty);
        void printSet();
        virtual ~Tileset();
        int getDifficulty();
        void setVisible(int x, int y);
        void setInvisible(int x, int y);
        string getElement(int x, int y);
    protected:
    private:
        int _difficulty;
        vector< vector<string> > _elements;
        int _visible[8][8];


};

#endif // TILESET_H
