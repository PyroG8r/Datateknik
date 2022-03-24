/*Emil Jons
2021-12-08
Introduktion till programmering
Lab4*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>

using namespace std;
bool compare (pair <string, int>& a, pair <string,int>& b);

    
int main()
{
    ifstream input;
    ofstream output;
    vector<string> text;
    vector<pair<string, int> > VectorPair;
    map <string, int> word_count;
    string s;
    int antal;

    input.open("hitchhikersguide.txt");

    cout << "Skriv in hur många antal ord som ska visas: " << endl;
    cin >> antal;

    input >> s;
    while (!input.eof())
    {
        s.erase(remove_if(s.begin(), s.end(), [](char c) { return !isalpha(c); } ), s.end());  //Tar bort allt som inte är isalpha

        for (auto &c : s){      // Går igenom alla karaktärer i strängen och sätter dem till lower
            c = static_cast<char>(tolower(static_cast<int>(c)));
        }

        if (s != "")            //Tar bort strängar som inte innehåller något
            ++word_count[s];
        input >> s;                 //Läser in en ny sträng, ett nytt ord.
        
    }   

    for (auto& it : word_count) {       // Lägger Mappen i en vector pair, med string och int
        VectorPair.push_back(it);
    }
    sort(VectorPair.begin(), VectorPair.end(), compare);    // Sorterar vectorn med anseende på int, alltså VectorPair.second
    
    cout << "De " << antal << " första orden som förekommer mest är: " << endl; 

    for (int i = 0; i < antal; i++){                                            //Skriver ut vectorn, antal, antal ggr
        cout << VectorPair[i].first << " : " << VectorPair[i].second << endl;
    }
    input.close();
    return 0;
}

bool compare (pair <string, int>& a, pair <string,int>& b)      // Compare funktionen som jämför vektorparets andra värde
{
    return a.second > b.second;
}