#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  string firstName,lastName;
  char mi;
  int score;
  
  ifstream input;

  // Open a file
  input.open("scores.txt");

  if (input.fail())
  {
    cout << "File does not exist" << endl;
    cout << "Exit program" << endl;
    return 0;
  }

  // Read data
  while (!input.eof()) // Continue if not end of file
  {
    input >> firstName >> mi >> lastName >> score;
    cout << firstName << " " << mi << " " << lastName
      << " " << score << endl;
  }

  input.close();

  cout << "Done" << endl;
  return 0;
}
