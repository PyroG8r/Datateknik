#include "IsSorted.h"

#include <iostream>
#include <fstream>
using namespace std;

bool isSorted(string filename){

    int a, b;
    ifstream input;

    input.open(filename);

    input >> a;
    while (!input.eof())
    {
        input >> b;
        if (a > b){
            return false;
        }
        a = b;
    }
    
    return true;
}