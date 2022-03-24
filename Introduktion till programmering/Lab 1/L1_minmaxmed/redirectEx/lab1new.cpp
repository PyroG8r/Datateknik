/*Emil Jons
2021-11-29
Introduktion till programmering
Lab1*/
#include <iostream>
using namespace std;

int main()
{
  int tal, total;
  int max;
  int min;
  int count = 0;
  double med;
  bool firstrun = true;

  while (cin>>tal)
  {
    if(firstrun){
      max = tal;
      min = tal;
      firstrun = false;
    }
    if (tal > max)     // räknar ut max värdet
      max = tal;

    if (tal < min)    // räknar ut min värdet
      min = tal;

    count++;          // Antal angivna tal
    total += tal;     // Totalen på de angivna talen
  }

  med = static_cast<double>(total) / count;
  cout << "Max: " << max << endl << "Min: " << min << endl << "Med: " << med << endl;

  return 0;
}