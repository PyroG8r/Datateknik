#include <iostream>
#include <vector>

using namespace std;

int main()
{
  //declarations

  vector<int> vector1, vector2;  
  
  //vector1 and vector2 can expand in size up to max_size()
  //size of vector1 and vector2 at this point is 0

  vector<int> vector3(20); 
  //vector3 has a size of 20 elements but can be "resized" later.

  vector<double> vector4(5,3.5 ); 
  //vector4 has a size of 5 elements filled with 3.5

  vector<int> vector5(vector4.begin(),vector4.end()) ;
 //vector5 has a size of 5 elements with the elements filled with 3.5 from vector4
  //Printing out sizes
  cout << "size of vector1: " << vector1.size() << endl;
  cout << "size of vector2: " << vector2.size() << endl;
  cout << "size of vector3: " << vector3.size() << endl;
  cout << "size of vector4: " << vector4.size() << endl;
  cout << "size of vector5: " << vector5.size() << endl;


  cout << "Pushing values into the Vector: " << endl;
  vector1.push_back(1);
  vector1.push_back(2);
  vector2.push_back(30);

  cout << "size of vector1: " << vector1.size() << endl;
  cout << "size of vector2: " << vector2.size() << endl;

  cout << "maximum size of vector1: " << vector1.max_size() << endl;
 
  vector1.swap(vector2);  //Swap the content of vector1 with vector2 

  cout << "size of vector1: " << vector1.size() << endl;
  cout << "size of vector2: " << vector2.size() << endl << endl;
  
  return 0;
}
