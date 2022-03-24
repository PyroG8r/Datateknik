/*Emil Jons
2021-11-29
Introduktion till programmering
Lab3*/
#include "Merge.h"
#include "IsSorted.h"
#include <iostream>
#include <fstream>
using namespace std;

bool isSorted(string filename);
int main()
{
  string fil1, fil2;
  string filnamn;
  cout << "Skriv in filnamnet " << endl;
  for (int i = 0; i < 3; i++)                             // Ber användaren att skriva in tre filnamn, A B eller A1
  {
    cin >> filnamn;
    if (filnamn == "A" || filnamn == "A1" || filnamn == "B"){
      if (isSorted(filnamn)){
        cout << filnamn << " Is sorted"<< endl;
        
        if (fil1.empty())
          fil1 = filnamn;
        else 
          fil2 = filnamn;
        }
      else
        cout << filnamn << " Is not sorted"<< endl;
    }
    else {
      i--;
      cout << "A, A1 eller B " << endl;
    }
  }
  

  merge(fil1, fil2, "C");             //Lägger ihop fil1 och fil2 och lägger dem i en ny fil som heter "C"
  cout << "Mergering " << fil1 << " & "<< fil2 << endl << endl;     
  
  if (isSorted("C"))                //Koller om den nya filen är sorterad
    cout << "C Is sorted"<< endl;
  else 
    cout << "C Is not sorted" << endl;


  return 0;
}