#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  string fnamn, enamn, pnr, gata, gatanr, postnr1, postnr2, stad;
  ifstream input;
  ofstream output;

  // Open a file
  input.open("names.txt");
  output.open("output.txt");
  
  input >> fnamn >> enamn >> pnr >> gata >> gatanr >> postnr1 >> postnr2; 
  getline(input, stad);

  // Read data
  while (!input.eof())
  {
	

  output << fnamn << ", " << enamn << endl << pnr << endl << gata << ' ' << gatanr << ' ' << postnr1 << ' ' << postnr2 << stad << endl;
  
  input >> fnamn >> enamn >> pnr >> gata >> gatanr >> postnr1 >> postnr2; 
  getline(input, stad);
  }
  input.close();
  output.close();
  return 0;
}