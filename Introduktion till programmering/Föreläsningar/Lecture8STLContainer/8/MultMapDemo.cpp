#include <iostream>
#include <map>
#include <algorithm>


using namespace std;

int main()

{
    multimap <string, int> MyMultiMap;
    MyMultiMap.insert(make_pair("nayeb",1));
    MyMultiMap.insert(make_pair("nayeb",1));
    MyMultiMap.insert(make_pair("nayeb",1));
    MyMultiMap.insert(make_pair("nayeb",1));
    
    multimap<string,int>:: iterator it;
    for (it=MyMultiMap.begin();it != MyMultiMap.end(); it++)
    {
        cout << it->first << " : " <<it->second <<endl;
    }

    return 0;
}