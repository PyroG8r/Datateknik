#include <iostream>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	map<int, string> myMap; //create a map called myMap



	//1) Assignment using array index notation, the keys are unique but the values doesnt need
		//to be unique

	myMap[100] = "John Smith";
	myMap[101] = "Peter King";
	myMap[102] = "Jane Smith";
	myMap[103] = "Jeff Reed";
	myMap[104] = "Jeff Reed";
	
	cout << "The size of the map is: " << myMap.size() << endl;
	
	for(auto& mapElement:myMap)
		cout << mapElement.first <<":" <<mapElement.second <<endl;

	cout << "Initial contents in myMap:\n";
	map<int, string>::iterator p;
	for (p = myMap.begin(); p != myMap.end(); p++)
		cout << p->first << " " << p->second << endl;
	
	return 0;
}

