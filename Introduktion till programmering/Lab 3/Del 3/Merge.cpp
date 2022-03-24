#include "Merge.h"

#include <iostream>
#include <fstream>
using namespace std;

void merge(string fil1, string fil2, string fil3){
    int a, b;
    ifstream input1, input2;
    ofstream output;
    input1.open(fil1);
    input2.open(fil2);
    output.open(fil3);

    input1 >> a;
    input2 >> b;
    while (!input1.eof() && !input2.eof()){
        if (a < b){
            output << a << ' ';
            input1 >> a;
        }
        else {
            output << b << ' ';
            input2 >> b;
        }
    }
    while (!input1.eof()){
        output << a << ' ';
        input1 >> a;
    }
    while (!input2.eof()){
        output << b << ' ';
        input2 >> b;
    }
    input1.close();
    input2.close();
    output.close();



}