#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> intVector;
	intVector.push_back(10);
	intVector.push_back(30);
	intVector.push_back(20);
	
	cout << "intVector.front() :" << intVector.front() << endl;
	cout <<"intVector.back() : " <<  intVector.back() << endl;

	vector<int> v;
	v.assign(10, 42);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;

	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}

	vector<int> v2;
	v2.assign(v1.begin(), v1.end());

	for (int i = 0; i < v2.size(); i++) {
		cout << v2[i] << " ";
	}
	cout << endl;



	return 0;
}
