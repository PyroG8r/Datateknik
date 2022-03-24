/*
    Emil Jons
    2022-01-10
    Introduktion till programmering
    Projektarbete - Bulls & Cows
*/
#include "highscore.h"
#include <iostream> 
#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
bool Compare(pair <int, string>& a, pair <int, string>& b);

//Sorterar och skriver ut highscore listan till highscore.txt
void UpdateHighscore(vector <pair<int, string> > list){
    ofstream output;
    output.open("highscore.txt");
    
    sort(list.begin(), list.end(), Compare);

    for (auto& it : list){
        output << it.first << it.second << endl;
    }
}


//Läser in highscore.txt och lägger varje rad i vectorn som ett par <int, string> där <antal försök, gissning>
vector<pair<int, string>> ReadHighscore(){
    string str, count;
    vector <pair<int, string> > list;
    ifstream input;
    input.open("highscore.txt");

    //Matar in första raden i textfilen
    input >> count;
    getline(input, str);    
    
    //Matar in varje rad i textfilen, första inmatningen skickas till "antal" och restan av raden till "str"
    while(!input.eof()){
        //Lägger "antal" & "str" i ett vector par <int, str>
        list.push_back(make_pair(stoi(count), str));
        input >> count;
        getline(input, str);

    }
    return list;
}
vector<pair<int, string>> NewHighscore(string name, string guess, int count, vector<pair<int, string>> list){
    string str;
    str.append(" : " + guess + " - " + name);
    list.push_back(make_pair(count, str));
    return list;
}



//Funktion för att sortera vectorn
bool Compare(pair <int, string>& a, pair <int, string>& b){
    return a.first < b.first;
}