#ifndef PUZZLESETS_H
#define PUZZLESETS_H
#include <iostream>
#include <string>

class puzzleSets
{
    public:
        puzzleSets();
        virtual ~puzzleSets();
        void printHiddenSet();
        void printVisibleSet();
        bool checkWinState();
        void setDifficulty(int val);
        int visible[8][8];
        int difficulty;
        int waitTime;
        std::string easy[4][4] = { {"Germany","Japan","China","United States"},
                          {"Mexico","Italy","Brazil","France"},
                          {"Japan","Mexico", "Brazil","Italy"},
                          {"China","Germany","United States","France"} }; //Easy difficulty

        std::string medium[6][6] = { {"Syria","Iran", "Iraq", "Iran","Argentina","Canada"},
                            {"Iraq","Turkey","Sudan","Togo","Russia","Austria"},
                            {"Denmark","Syria","Spain","Libya","Peru","Jordan"},
                            {"Pakistan", "Argentina","Russia","Canada","Greece","Australia"},
                            {"Sudan","Denmark","Togo","Austria","Turkey","Libya"},
                            {"Jordan","Peru","Spain","Greece","Australia","Pakistan"} }; //medium

        std::string hard[8][8] = {   {"Azerbaijan","Mali","Somalia","Uganda","Poland","Chile","Qatar","Kuwait"},
                            {"Cambodia","Saudi Arabia","Ireland","Malaysia","Kazakhstan","Portugal","Finland","Norway"},
                            {"Bulgaria","Mali","Uzbekistan","Nicaragua","Paraguay","Venezuela","Chile","Armenia"},
                            {"Uganda","Ethiopia","Haiti","Iceland","Czech Republic","Tunisia","Qatar","Norway"},
                            {"Somalia","Uzbekistan","Ireland","Poland","Bulgaria","Luxembourg","Bangladesh","Kuwait"},
                            {"Finland","Tunisia","Haiti","Iceland","Iceland","Nicaragua","Venezuela","Paraguay"},
                            {"Portugal","Lithuania","Bangladesh","Armenia","Luxembourg","Bulgaria","Czech Republic","Imaginary Island"},
                            {"Bulgaria","Ethiopia","Zimbabwe","Zimbabwe","Malaysia","Kazakhstan","Lithuania","Azerbaijan"} };//hard
    protected:
    private:


};

#endif // PUZZLESETS_H
