#include "inputHandler.h"
#include <iostream>
inputHandler::inputHandler()
{
    //ctor
}

inputHandler::~inputHandler()
{
    //dtor
}

void inputHandler::getChoice(int &val, int bound)
{
    std::cout << "Enter # of choice: ";
    std::cin >> val;
    if (val > bound)
    {
        std::cout << "Value out of bounds, try again." << std::endl;
        getChoice(val, bound);
    }
}
