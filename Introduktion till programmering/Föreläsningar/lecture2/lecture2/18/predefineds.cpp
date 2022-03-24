#include <iostream>
#include <cmath>   // for mathematical functions
#include <ctime>    // for time functions
#include <string>   //for string manipulation
using namespace std;

int main()
{
    int a, b, c ;
    

    cout << "Enter coefficients a, b and c: ";
   cin >> a >> b >> c; 

    //starting to calculate
   
    int discriminant = pow(b,2) - 4*a*c;

    int x1 = (-b + sqrt(discriminant)) / (2*a);
    int x2 = (-b - sqrt(discriminant)) / (2*a);

    cout << "Roots are:" << endl;

    cout << "x1 = " << x1 << endl;
    cout << "x2 = " << x2 << endl;

    return 0;
}