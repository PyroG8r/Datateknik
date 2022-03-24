/*
    Emil Jons
    2022-01-10
    Introduktion till programmering
    Projektarbete - Bulls & Cows
*/
#include "algorithm.h"
#include "highscore.h"
#include "constants.h"
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

// Deklarerar funktioner
void PlayerGuess(pair<int, int> bullsncows, vector<pair<int, string>> &highscore_list);
void CpuGuess(vector<pair<string, pair<int, int>>> guessed, pair<int, int> bullsncows, vector<pair<int, string>> &highscore_list);
void CpuVsCpu(vector<pair<string, pair<int, int>>> guessed, pair<int, int> bullsncows, vector<pair<int, string>> &highscore_list);
bool IsDigits(const string &str);
void WelomeScreen();
int InputBullsncows();
int InputGamemode();
string InputGissning();

int main()
{
    pair<int, int> bullsncows;
    vector<pair<string, pair<int, int>>> guessed; // Mängden G som består av gissningar med respektive svar
    int game_mode = 0;
    bool play_again = true;

    // Läser in highscorelistan och lägger den i vectorn highscore_list
    vector<pair<int, string>> highscore_list = ReadHighscore();

    WelomeScreen();

    while (true)
    {
        cout << "\n1: Datorn gissar på ett tal som du tänker på\n2: Du gissar på ett tal som datorn tänker på\n3: Datorn spelar mot sig själv\nSkriv in vad för spel du vill spela: ";
        game_mode = InputGamemode();
        switch (game_mode)
        {
        case 1:
            CpuGuess(guessed, bullsncows, highscore_list);
            break;

        case 2:
            PlayerGuess(bullsncows, highscore_list);
            break;

        case 3:
            CpuVsCpu(guessed, bullsncows, highscore_list);
            break;
        default:
            break;
        }

        // Soerterar och skriver ut highscore listan till filen highscore.txt
        UpdateHighscore(highscore_list);
    }
    return 0;
}

// Datorn spelar mot datorn
void CpuVsCpu(vector<pair<string, pair<int, int>>> guessed, pair<int, int> bullsncows, vector<pair<int, string>> &highscore_list)
{
    int count = 0;
    string secret = to_string(MIN_NUMBER);
    string guess;

    cout << "Arbetar... detta kan ta en stund...\n";

    // Itererar igenom alla möjliga tal som går att ha som hemligt tal
    while (stoi(secret) <= MAX_NUMBER)
    {

        // Gissar på talet
        guess = GenerateGuess(guessed);
        while (true)
        {

            count++;

            bullsncows = BullsAndCows(guess, secret);
            if (bullsncows.first == 4)
            {
                // cout << "\nDatorn gissade rätt på talet: " << guess << "! Efter, " << count << " försök."<< endl;
                highscore_list = NewHighscore(COMPUTER_NAME, guess, count, highscore_list);
                break;
            }

            guessed.push_back(make_pair(guess, make_pair(bullsncows.first, bullsncows.second)));
            guess = GenerateGuess(guessed);
        }

        // Inkremententerar secret till nästa giltiga tal
        secret = NextValidNumber(secret);

        //Återställer värderna för nästa gissning
        count = 0;
        guessed.clear();

        if (secret == "4012" || secret == "8012")
            cout << "Arbetar fortfarande...\n";
    }
}

// Spelaren agerar kodknäckare och programmet kodmakare
void PlayerGuess(pair<int, int> bullsncows, vector<pair<int, string>> &highscore_list)
{
    string secret = GenerateSecret();
    string guess;
    string name;
    int count = 0;

    cout << "Skriv in ditt namn som ska visas på topplistan" << endl;
    cin.ignore();

    //
    getline(cin, name);
    while (name.length() > MAX_NAME_LENGTH)
    {
        cout << "Ditt namn får inte vara längre än " << MAX_NAME_LENGTH << " karaktärer" << endl;
        getline(cin, name);
    }

    cout << "\nDatorn tänker på ett fyrsiffrigt tal, du ska gissa på det talet" << endl;
    // cout << secret << endl;

    while (true)
    {
        count++;

        guess = InputGissning();

        bullsncows = BullsAndCows(guess, secret);

        cout << "\nBulls: " << bullsncows.first << "\nCows: " << bullsncows.second << endl;

        if (bullsncows.first == 4)
        {
            cout << "\nDu gissade rätt på talet: " << guess << "! Efter, " << count << " försök." << endl;
            highscore_list = NewHighscore(name, guess, count, highscore_list);
            break;
        }
    }
}

// Programmet agerar kodknäckare och spelaren agerar kodmakare.
void CpuGuess(vector<pair<string, pair<int, int>>> guessed, pair<int, int> bullsncows, vector<pair<int, string>> &highscore_list)
{

    string guess;
    int count = 0;

    cout << "\nSpelet går ut på att du tänker på ett fyrsiffrigt tal som bara innehåller unika siffror\n";
    cout << "Du kommer därefter bli frågad att mata in antalet bulls och antalet cows\n";
    cout << "Med antalet bulls menas hur många siffror i det talet som skrivs ut som är på exakt rätt plats jämfört med ditt.\n";
    cout << "Antalet cows är hur många tal som finns med i båda talen men inte är på rätt plats.\n";

    // Genererar första gissningen
    guess = GenerateGuess(guessed);
    while (true)
    {
        count++;
        // Kontrollerar om GenerateGuess() returnerar "END", och slutar i så fall loopen pga ogiltig inmatning
        if (guess == "END")
        {
            cout << "\nOgiltig inmatning! Avslutar..." << endl;
            break;
        }
        else
        {
            cout << "\nDatorn gissade på: \"" << guess << "\". \nSkiv hur många bulls det var: ";
        }
        bullsncows.first = InputBullsncows();

        //Om inmatningen av bulls är 4, bryts loopen
        if (bullsncows.first == 4)
        {
            cout << "\nDatorn gissade rätt på talet: " << guess << "! Efter, " << count << " försök." << endl;

            highscore_list = NewHighscore(COMPUTER_NAME, guess, count, highscore_list);
            break;
        }

        cout << "Skriv hur många cows det var: ";
        bullsncows.second = InputBullsncows();

        //Lägger gissningen och bulls & cows i vectorn
        guessed.push_back(make_pair(guess, make_pair(bullsncows.first, bullsncows.second)));
        //Genererar en ny gissning
        guess = GenerateGuess(guessed);
    }
}

// Skriver ut välkomstskärmen
void WelomeScreen()
{
    cout << "\n\n\t --------------------------------\n\n";
    cout << "\t | Välkommen till Bulls & Cows! |\n\n";
    cout << "\t --------------------------------\n\n";
}

// Funktion som kollar om strängen bara innehåller siffror
bool IsDigits(const string &str)
{
    return all_of(str.begin(), str.end(), ::isdigit);
}

// Hanterar inmatninen av antalet bulls & cows för att garantera att bara siffror mellan 0-4 inmatas
int InputBullsncows()
{
    string str;
    cin >> str;
    while (IsDigits(str) == false || stoi(str) > 4 || stoi(str) < 0)
    {
        cout << "Du måste ange ett heltal, från 0-4" << endl;
        cin >> str;
    }
    return stoi(str);
}

int InputGamemode()
{
    string str;
    cin >> str;
    while (IsDigits(str) == false || stoi(str) > 3 || stoi(str) < 1)
    {
        cout << "Välj ett av alternativen, 1-3...";
        cin >> str;
    }
    return stoi(str);
}

string InputGissning()
{
    string str;
    cin >> str;
    while (IsDigits(str) == false || stoi(str) > MAX_NUMBER || stoi(str) < MIN_NUMBER || DistinctNumbers(str) == false)
    {
        cout << "Du måste ange ett fyrsiffrig heltal, där alla siffror är unika" << endl;
        cin >> str;
    }
    return str;
}
