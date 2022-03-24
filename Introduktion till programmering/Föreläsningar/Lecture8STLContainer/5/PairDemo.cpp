#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>


using namespace std;
bool compare (pair <string, int>& a, pair <string,int>& b);
void print (pair <string,int> );

int main()
{
    pair< string,int > MyPair;
    MyPair.first="Nayeb";
    MyPair.second =1;

    cout << MyPair.first << " associated with :" << MyPair.second <<endl;
    vector< pair<string, int> > VectorOfPair;
    VectorOfPair.push_back(MyPair);
    MyPair.first="Maleki";
    MyPair.second =2;
    VectorOfPair.push_back(MyPair);

    for (const auto& element :VectorOfPair)
        cout << element.first << ":" <<element.second <<endl;
    
    sort(VectorOfPair.begin(),VectorOfPair.end(),compare);

    for (const auto& element :VectorOfPair)
    cout << element.first << ":" <<element.second <<endl;
    
    for_each(VectorOfPair.begin(),VectorOfPair.end(),print);

    return 0;
}

bool compare (pair <string, int>& a, pair <string,int>& b)
{
    return a.second > b.second;
}

void print (pair <string,int> MyPair )
{
    cout << MyPair.first << " : " << MyPair.second <<endl;
}
