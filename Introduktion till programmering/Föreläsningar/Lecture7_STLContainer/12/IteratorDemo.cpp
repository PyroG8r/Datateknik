#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	vector<int> intVector;
	intVector.push_back(10);
	intVector.push_back(40);
	intVector.push_back(50);
	intVector.push_back(20);
	intVector.push_back(30);
	intVector.push_back(70);

	vector<int>::iterator It; // declare a general iterator
	cout << "Tranverse the vector: ";

	// It=intVector.begin() points to the start of the data-structure = first value
	// It != intVector.end() end of intVector, that is after the last value in the vector
	// ++It increase It to point to the next value in the vector

	for (It = intVector.begin(); It != intVector.end(); It++)
	{
		cout << *It << " "; // output the current value that It is pointing to
	}
	cout << endl;

	// removes the element at position number 2 which is the 3:th number in vector
	intVector.erase(intVector.begin() + 2);

	//Finds the first position with the value 20 in the vector
	auto it = find(intVector.begin(), intVector.end(), 20);


	// Removes the position "it" points to if its not the end
	if (it != intVector.end())
		intVector.erase(it);

	for (It = intVector.begin(); It != intVector.end(); It++)
	{
		cout << *It << " "; // output the current value that It is pointing to
	}
	cout << endl;

	return 0;
}
