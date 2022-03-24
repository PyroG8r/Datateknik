#include <iostream>
#include <cmath>   // for mathematical functions
#include <ctime>    // for time functions
#include <string>   //for string manipulation
using namespace std;

int main()
{
    int a, b, c ;
    srand(time(0));
    //time(0) returns a time_t value which needs to be
    //converted into actuall time.

    time_t current_time = time(0); 

    cout << "Enter coefficients a, b and c: ";
   cin >> a >> b >> c; 

    //starting to calculate
   
    int discriminant = pow(b,2) - 4*a*c;

    int x1 = (-b + sqrt(discriminant)) / (2*a);
    int x2 = (-b - sqrt(discriminant)) / (2*a);

    cout << "Roots are:" << endl;

    cout << "x1 = " << x1 << endl;
    cout << "x2 = " << x2 << endl;

    
   string now = ctime(&current_time);
   cout <<"Current time is: "<< now << endl; //ctime() returns current time

    return 0;
}