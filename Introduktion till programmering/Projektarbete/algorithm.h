/*
    Emil Jons
    2022-01-10
    Introduktion till programmering
    Projektarbete - Bulls & Cows
*/
#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <iostream>
#include <vector>

using namespace std;


string GenerateGuess(vector<pair<string, pair<int, int>>> guessed);
string GenerateSecret();
bool DistinctNumbers(const string &str);
pair<int, int> BullsAndCows(string guess_one, string guess_two);
string NextValidNumber(string str);

#endif