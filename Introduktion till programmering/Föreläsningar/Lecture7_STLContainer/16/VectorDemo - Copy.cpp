#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<double> doubleVector(7, 1);
	cout << "Initial contents in doubleVector: ";
	for (int i = 0; i < doubleVector.size(); i++)
		cout << doubleVector[i] << " ";

	doubleVector.assign(4, 11.5);  //4 copies of 11.5 will be assinged, the size of the vector will also shrink if that is bigger than 4

	cout << "\nAfter the assign function, doubleVector: ";
	for (int i = 0; i < doubleVector.size(); i++)
		cout << doubleVector[i] << " ";
	
	doubleVector.at(0) = 22.4;  //same as doublevector[0]=22.4;

	cout << "\nAfter the at function, doubleVector: ";
	for (int i = 0; i < doubleVector.size(); i++)
		cout << doubleVector[i] << " ";
	cout << endl;

	auto itr = doubleVector.begin();
	doubleVector.insert(itr + 1, 555); //where can i find the new value? 
	doubleVector.insert(itr + 1, 666); //where can i find the new value? 

	cout << "\nAfter the insert function, doubleVector: ";
	for (int i = 0; i < doubleVector.size(); i++)
		cout << doubleVector[i] << " ";
	cout << endl;

	
	doubleVector.erase(itr + 2, itr + 4); //  it+4 is not included: 0,1,2,3
	cout << "\nAfter the erase function, doubleVector: ";
	for (int i = 0; i < doubleVector.size(); i++)
		cout << doubleVector[i] << " ";
	
	doubleVector.clear();
	cout << "\nSize is " << doubleVector.size() << endl;


	cout << "Is empty? " <<boolalpha<< (doubleVector.empty() ? true : false) << endl;
		

	return 0;
}

