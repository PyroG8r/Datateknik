#include <iostream>
using namespace std;

int main()
{

  char lowercaseLetter,uppercaseLetter ;
  cout << "Enter a lowercase letter: ";
  cin >> lowercaseLetter;

  uppercaseLetter = static_cast<char>('A' + (lowercaseLetter - 'a'));


  cout << "The corresponding uppercase letter is " 
    << uppercaseLetter << endl;

  return 0;
}