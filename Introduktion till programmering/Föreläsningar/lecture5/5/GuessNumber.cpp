#include <iostream>
#include <ctime>
using namespace std;

int main()
{
  // Generate a random number to be guessed
  int number = rand() % 101;
  int guess = -1;

  srand(time(0));

  cout << "Guess a magic number between 0 and 100";

 
  while (guess != number)
  {
    // Prompt the user to guess the number
    cout <<endl<<"Enter your guess: ";
    cin >> guess;

    if (guess == number)
      cout << "Yes, the number is " << number << endl;
    else if (guess > number)
      cout << "Your guess is too high" << endl;
    else
      cout << "Your guess is too low" << endl;
  } // End of loop

  return 0;
}
