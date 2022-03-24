#include <iostream>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

// convert map to multimap
multimap<int, string> map_to_mutlimap(map<string, int> & MyMap);

int main()
{
	// making MyMap
	map<string, int>MyMap = 
	{
	  {"Nayeb", 1}, {"Maleki", 5}, {"Kahriz", 3}, {"Intro", 4}
	};

	cout << "The map, sorted by keys, is: " << endl;
	map<string, int> :: iterator it;
	for (it=MyMap.begin(); it!=MyMap.end(); it++) 
	{ 
		cout << it->first << ": " << it->second << endl;
	}
	cout << endl;

	// call map_to_multimap to convert
	multimap<int, string> MyMultiMap = map_to_mutlimap(MyMap);
    MyMultiMap.insert(make_pair(1,"Nayeb"));
	// print the multimap
	cout << "The multimap content is: " << endl;
 	multimap<int, string> :: iterator iter;
	for (iter=MyMultiMap.begin(); iter!=MyMultiMap.end(); iter++) 
	{
        cout << iter->first<< ": " << iter->second << endl; 
	}

	return 0;
}


// convert map to multimap
multimap<int, string> map_to_mutlimap(map<string, int> & MyMap)
{
	multimap<int, string> multiMap;

	map<string, int> :: iterator it;
	for (it=MyMap.begin(); it!=MyMap.end(); it++) 
	{
		multiMap.insert(make_pair(it->second, it->first));
	}

	return multiMap;
}
