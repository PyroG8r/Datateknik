#include <iostream>
using namespace std;

int main()
{
  int sum = 0;
  int number = 0;
  
  while (number < 20) 
  {
	  number++;
	  if (number == 10 || number == 11) 
		  continue;
	  sum += number;
  }


//Can we rewrite the while without continue?!

  cout << "The number is " << number << endl;
  cout << "The sum is " << sum << endl;

  return 0;
}
