/*Emil Jons
2021-11-29
Introduktion till programmering
Lab3*/
#include "IsSorted.h"

#include <iostream>
#include <fstream>
using namespace std;

bool isSorted(string filename);

int main()
{
  

  if (isSorted("B") == false){
    cout << endl << "Inte sorterad" << endl;
  }
  else {
    cout << endl << "Sorterad" << endl;
  }

  return 0;
}