#include <iostream>
using namespace std;

void printArea(double radius=1);

int main()
{
  printArea();
  printArea(4);

  return 0;
}


// Display area of a circle 
void printArea(double radius)
{
  double area = radius * radius * 3.14159;
  cout << "area is " << area << endl;
}
