#include <iostream>
using namespace std;

int main()
{
	int data;
	
	// Keep reading data until the input is 0
	int sum = 0;

	do{
		// Read the next data
		cout << "Enter an int value (the program exits " <<
			"if the input is 0): ";
		cin >> data;
		sum += data;

	} while (data != 0);

	cout << "The sum is " << sum << endl;

	return 0;
}