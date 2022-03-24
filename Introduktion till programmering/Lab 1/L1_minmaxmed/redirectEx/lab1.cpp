#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  
  int tal;
  int count;
  int total;
  int max = 0;
  int min = 9999;
  int med;
  ifstream input;

  // Open a file
  input.open("values.txt");
  
  if (input.fail())
  {
    cout << "File does not exist" << endl;
    cout << "Exit program" << endl;
    return 0;
  }

  // Read data
  while (!input.eof()) // Continue if not end of file
  {
	input >> tal;
  cout << tal << endl;

  if (tal > max)
    max = tal;

  if (tal < min)
    min = tal;

  count++;
  total += tal;
  
  /*if (getch() == 'n'){
    break;
  }
    else if (getch() != 'n') {
      continue;
    } */


  }
  input.close();

  med = total / count;
  cout << "Max: " << max << endl << "Min: " << min << endl << "Med: " << med << endl;
  return 0;
}