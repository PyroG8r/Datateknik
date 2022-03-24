/*
    Emil Jons
    2022-01-10
    Introduktion till programmering
    Projektarbete - Bulls & Cows
*/
#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <iostream>
#include <vector>

using namespace std;

void UpdateHighscore(vector <pair<int, string> > list);
vector<pair<int, string>> ReadHighscore();
vector<pair<int, string>> NewHighscore(string name, string guess, int count, vector<pair<int, string>> list);
void ResetHighscore();

#endif