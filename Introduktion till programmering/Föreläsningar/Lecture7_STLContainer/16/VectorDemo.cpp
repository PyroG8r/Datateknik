#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<double> doubleVector(7, 1.0);
	cout << "Initial contents in doubleVector: ";
	for (int i = 0; i < doubleVector.size(); i++)
		cout << doubleVector[i] << " ";

	
	doubleVector.at(0) = 22.4;  
	doubleVector[1]=22.4;

	cout <<endl<<"After the at function and ordinary indexing doubleVector: ";
	
	for( double& element: doubleVector)
		cout << element << " ";
	cout << endl;


	
	doubleVector.clear();
	cout <<endl<< "Size after clear function is: " << doubleVector.size() << endl;


	cout << "Is empty? " <<boolalpha<< (doubleVector.empty() ? true : false) << endl;
		
	
	return 0;
}

