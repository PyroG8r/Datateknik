#include <iostream>
using namespace std;

char getGrade(double score);

int main()
{
  cout << "Enter a score: ";
  double score;
  cin >> score;

  cout << "The grade is ";
  cout << getGrade(score) << endl;

  return 0;
}

// Return the grade for the score 
char getGrade(double score)
{
  if (score >= 90.0)
    return 'A';
  else if (score >= 80.0)
    return 'B';
  else if (score >= 70.0)
    return 'C';
  else if (score >= 60.0)
    return 'D';
  else
    return 'F';
}
