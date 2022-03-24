#include "IsSorted.h"
#include <iostream>
#include <fstream>

bool isSorted(std::string filename){
    int a, b;
    std::ifstream input;

    input.open(filename);

    input >> a;
    while (!input.eof())
    {
        input >> b;
        if (a > b){
            input.close();
            return false;
        }
        a = b;
    }
    input.close();
    return true;
}