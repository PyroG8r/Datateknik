#include <iostream>
#include <set>
#include <algorithm>


using namespace std;


int main()

{

 set <int> set1, set2;
 multiset <int> multiset1, multiset2;
  cout << "Set: " << endl;
  set1.insert(1);
  set1.insert(1);
  set1.insert(2);
  set2.insert(30);
  cout << "size of set1: " << set1.size() << endl;
  cout << "size of set2: " << set2.size() << endl;
  cout << "maximum size of set1: " << set1.max_size() << endl;
  cout << "maximum size of set2: " << set2.max_size() << endl;
  set1.swap(set2);
  cout << "size of set1: " << set1.size() << endl;
  cout << "size of set2: " << set2.size() << endl;
  cout << "set1 < set2? " << (set1 < set2) << endl << endl;
   
   //print out the content of set2:

    set<int>::iterator it;
   for(it = set2.begin(); it !=set2.end(); it++)
        cout << *it <<" ";
    cout <<endl;

  cout << "Multiset: " << endl;
  multiset1.insert(1);
  multiset1.insert(1);
  multiset1.insert(2);
  multiset2.insert(30);
  cout << "size of multiset1: " << multiset1.size() << endl;
  cout << "size of multiset2: " << multiset2.size() << endl;
  cout << "maximum size of multiset1: " << multiset1.max_size() << endl;
  cout << "maximum size of multiset2: " << multiset2.max_size() << endl;
  multiset1.swap(multiset2);
  cout << "size of multiset1: " << multiset1.size() << endl;
  cout << "size of multiset2: " << multiset2.size() << endl;
  cout << "multiset1 < multiset2? " << (multiset1 < multiset2) << endl << endl;
 
  return 0;
}