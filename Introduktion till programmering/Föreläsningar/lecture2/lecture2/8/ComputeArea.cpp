#include <iostream>
using namespace std;

int main()
{
  double radius; //Deklaration av en variabel med namnet radius
  
  double area;

  int heltal =20; //Deklaration och initiering ...
  
  
  // Step 1: Read in radius
  radius = 20;     //tilldelar värdet 20 till radius

  // Step 2: Compute area
  area = radius * radius * 3.14159;

  // Step 3: Display the area
  cout << "The area is ";
  cout << area << endl;

  return 0;
}
