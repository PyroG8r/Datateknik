// Se https://en.wikipedia.org/wiki/Redirection_(computing)

#include <iostream>
using namespace std;

int main()
{
  int tal1, tal2, svar;

  cout << "Ange 2 heltal: " << endl;
  cin >> tal1;
  cin >> tal2;

  svar = tal1 + tal2;
  cout << tal1 << " + " << tal2 << " blir " << svar << endl;

  svar = tal1 * tal2;
  cout << tal1 << " · " << tal2 << " blir " << svar << endl << endl;

  return 0;
}
