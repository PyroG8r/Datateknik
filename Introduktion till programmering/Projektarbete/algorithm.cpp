/*
    Emil Jons
    2022-01-10
    Introduktion till programmering
    Projektarbete - Bulls & Cows
*/
#include "algorithm.h"
#include "constants.h"
#include <iostream> 
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

//Deklarerar funktionerna som inte behöver kommas åt utanför
bool ValidGuess(string new_guess, vector<pair<string, pair<int, int>>> gissade);

//Returnerar ett par, antalet bulls och cows <bulls, cows> när två fyrsiffriga tal jämförs
pair<int, int> BullsAndCows(string guess_one, string guess_two){   
    pair<int, int> bullsandcows;
    bool guess_used[4] = {false, false, false, false};

    //Om något element i de två strängarna på samma plats är lika, öka med 1  ;    med andra ord BULLS
    for (int i = 0; i < 4; i++){  

        if (guess_one[i] == guess_two[i]){

            bullsandcows.first++;

            //Sätter att den platsen är redan kontrollerad och därmed inte räknas med i cows också
            guess_used[i] = true;
        }
        
        //Om något element i de två strängarna är lika, öka med 1  ; med andra ord antalet COWS
        for (int j = 0; j < 4; j++){

            //Använd inte ett redan avnänt tal
            if (guess_used[i])         
                continue;

            if (guess_one[i] == guess_two[j]){     
                bullsandcows.second++;
            }
        }
    }

    //Returnerar antalet bulls och cows i ett par
    return bullsandcows; 

}

//Returnerar om den nya gissningen är giltig, genom att jämföra med tidigare gissningar
bool ValidGuess(string new_guess, vector<pair<string, pair<int, int>>> guessed){

    //Loop för antalet element i vectorn gissade
    for (int i = 0; i < guessed.size(); i++)
    {
        //Om det nya antalet bulls & cows inte är samma som något som redan är gissat, returnera falskt
        if (BullsAndCows(new_guess, guessed[i].first) != make_pair(guessed[i].second.first, guessed[i].second.second) )
        {
            
            return false;
        }
    }
    return true;

}

//Returnerar en ny gissning baserat på tidigare gissningar
string GenerateGuess(vector<pair<string, pair<int, int>>> guessed){
    string guess;

    //Skapar första gissningen, körs bara om vectorn gissade är tom
    if (guessed.empty()){
        guess = to_string(MIN_NUMBER);
    }
    else{
        
        //Låt "gissning" vara den största gissningen i vectorn guessed, adderat med ett
        guess = to_string(stoi(guessed.front().first) + 1);
    }
    
    //Öka talet tills vi hittar en giltig gissning, alltså tills ValidGissning är true
    while (ValidGuess(guess, guessed) == false){


        //Öka gissning till nästa tal med distinkta siffror
        guess = NextValidNumber(guess);
        if (stoi(guess) > MAX_NUMBER){
            return "END";
        }
    }

    //Returnerar den nya gissningen
    return guess;
}

//Itererar igenom alla karaktärer i strängen, om något är lika returnerar funktionen false, annars true
bool DistinctNumbers(const string &str){
    for (int i = 0; i < 4; i++){ 
            for (int j = i + 1; j < 4; j++){
                if (str[i] == str[j]){
                    return false;
                }
            }

        }
    return true;

}

//Generar ett slumpmässigt fyrsiffrig distinkt tal
string GenerateSecret(){
    //En array med talen 0 - 9
    int numbers[10] = {0,1,2,3,4,5,6,7,8,9};
    string str;
    srand(unsigned(time(0)));

    while (true){
        //Slumpar arrayen
        random_shuffle(numbers, numbers + 10);
        //Sätter str till första 4 talen i arrayen
        for (int i = 0; i < 4; i++)
            str.append(to_string(numbers[i]));
        //Om talet är mindre än det minsta tillåtna, gör ett nytt tal
        if(stoi(str) < MIN_NUMBER)
            str.erase();
        else
            break;
    }
    return str;

}

//Ökar talet till nästa distinkta tal
string NextValidNumber(string str){
    str = to_string(stoi(str) + 1);
    while (DistinctNumbers(str) == false){
        str = to_string(stoi(str) + 1);
    }
    return str;
}

