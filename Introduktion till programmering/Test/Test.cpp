#include <iostream>
#include <vector>

using namespace std;

//--------------------          Ska ligga i header filen          --------------------------
string GenereraGissning(vector<pair<string, pair<int, int>>> gissade);
bool GiltigGissning(string a, vector<pair<string, pair<int, int>>> gissade);
pair<int, int> BullsAndCows(string gissning, string svar);
bool DistiktaSiffror(const string &str);
//------------------------------------------------------------------------------------

int main()
{
    string gissning;
    int bulls, cows;
    vector<pair<string, pair<int, int>>> gissade;

    cout << "Tänk på ett fyrsiffrigt tal som bara innehåller unika siffror\n";
    gissning = GenereraGissning(gissade);

    while (true)
    {

        cout << "\nDatorn gissade på: \"" << gissning << "\". \nSkiv hur många bulls det var" << endl;

        cin >> bulls;

        if (bulls == 4)
        {
            cout << "\nDatorn gissade rätt på talet: " << gissning << endl;
            break;
        }

        cout << "Skriv hur många cows det var " << endl;
        cin >> cows;

        gissade.push_back(make_pair(gissning, make_pair(bulls, cows)));
        gissning = GenereraGissning(gissade);
    }
}

//------------------------------Andra filen---------------------------

pair<int, int> BullsAndCows(string gissning, string tidigare_gissningar)
{
    pair<int, int> bullsandcows;
    bool gissning_used[4] = {false, false, false, false};
    bool tidigare_gissninar_used[4] = {false, false, false, false};

    // Om något element i de två strängarna på samma plats är lika, öka med 1  ;    med andra ord BULLS
    for (int i = 0; i < 4; i++)
    {

        if (gissning[i] == tidigare_gissningar[i])
        {

            bullsandcows.first++;

            // Sätter att den platsen är redan kontrollerad och därmed inte räknas med i cows också
            gissning_used[i] = true;
            tidigare_gissninar_used[i] = true;
        }
    }

    // Om något element i de två strängarna är lika, öka med 1  ; med andra ord antalet COWS
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {

            // Använd inte ett redan avnänt tal
            if (gissning_used[i] || tidigare_gissninar_used[j])
                continue;

            if (gissning[i] == tidigare_gissningar[j])
            {
                bullsandcows.second++;
            }
        }
    }

    // Returnerar antalet bulls och cows i ett par
    return bullsandcows;
}

// Returnerar om den nya gissningen är giltig, genom att jämföra med tidigare gissningar
bool GiltigGissning(string gissning, vector<pair<string, pair<int, int>>> gissade)
{

    // Loop för antalet element i vectorn gissade
    for (int i = 0; i < gissade.size(); i++)
    {
        // Om det nya antalet bulls & cows inte är samma som något som redan är gissat, returnera falskt
        if (BullsAndCows(gissning, gissade[i].first) != make_pair(gissade[i].second.first, gissade[i].second.second))
        {

            return false;
        }
    }
    return true;
}

// Returnerar en ny gissning baserat på tidigare gissningar
string GenereraGissning(vector<pair<string, pair<int, int>>> gissade)
{
    string gissning;

    // Skapar första gissningen, körs bara om vectorn gissade är tom
    if (gissade.empty())
    {
        gissning = "1023";
    }
    else
    {
        // Låt "gissning" vara den största gissningen i vectorn gissade, adderat med ett
        gissning = to_string(stoi(gissade.front().first) + 1);
    }

    //Öka talet tills vi hittar en giltig gissning, alltså tills GiltigGissning är true
    while (GiltigGissning(gissning, gissade) == false)
    {

        //Öka gissning till nästa tal med distinkta siffror
        gissning = to_string(stoi(gissning) + 1);
        while (DistiktaSiffror(gissning) == false)
        {
            gissning = to_string(stoi(gissning) + 1);
        }
    }
    return gissning;
}

// Itererar igenom alla karaktärer i strängen, om något är lika returnerar funktionen false, annars true
bool DistiktaSiffror(const string &str)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {
            if (str[i] == str[j])
            {
                return false;
            }
        }
    }
    return true;
}