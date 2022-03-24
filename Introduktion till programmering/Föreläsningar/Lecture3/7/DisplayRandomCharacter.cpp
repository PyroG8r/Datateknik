#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	char startChar, endChar;

	cout << "Enter a starting character: ";
	cin >> startChar;  // Example 'A'=65

	cout << "Enter an ending character: ";
	cin >> endChar;  // Example 'F'=70

	// Get a random character
	char randomChar = static_cast<char>(startChar + rand() % (endChar - startChar +1));

  cout << "The random character between " << startChar << " and " << endChar << " is " << randomChar << endl;

	
  return 0;
}