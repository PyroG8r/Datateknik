/*Emil Jons
2021-11-29
Introduktion till programmering
Lab2*/
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  string fnamn, enamn, pnr, adress;
  char kon;

  ifstream input;
  ofstream output;

  input.open("names.txt");
  output.open("output.txt");
  

  input >> fnamn >> enamn >> pnr; 
  input.ignore();
  getline(input, adress);

  // Read data
  while (!input.eof())
  {
  kon = static_cast<int>(pnr[8]) % 2;
	if (kon == 1 )
    kon = 'M';
  if (kon == 0 )
    kon = 'K';

  output << enamn << ", " << fnamn << " [" << kon << ']' << endl << adress << endl;
  
  input >> fnamn >> enamn >> pnr; 
  input.ignore();
  getline(input, adress);
  }

  input.close();
  output.close();
  return 0;
}