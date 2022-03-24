#include <iostream>
#include <string>

using namespace std;

int main()
{
    string city;
	cout << "Enter a city:";
	cin >> city;
    cout << "You entered " << city << endl;

	

	cout << "Enter a city name:";
	getline(cin,city,'\n'); 
    //getline(cin,city);
	cout << "You entered " << city << endl;


	return 0;
} 
