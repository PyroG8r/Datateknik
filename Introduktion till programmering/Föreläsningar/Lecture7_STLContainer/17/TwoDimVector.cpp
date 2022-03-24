#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	// We want to create a 5x5 matrix

	//declaring a 2D vector 
	vector< vector<int> > matrix(5);

	// Adding a vector for each row above
	
	for (int i = 0; i < matrix.size(); i++)  
	{
		matrix[i]=vector<int>(5);
		cout << matrix[i].size() <<endl;
	}
	
	//vector< vector<int> > matrix(5,vector<int>(5)); //5*5 Matrix


	// Add column to all rows, it will be 5x5 matrix
	
	for (int i = 0; i < matrix.size(); i++) 
	{
		for(int j=0; j <matrix[j].size(); j++)
			matrix[i][j]= rand() % 20; 
	}
     
	// OR this way
	// Add column to all rows using iterator:
	//we can ofcourse use Iterator to push values into the matrix
	/*
	for (vector< vector<int> >::iterator it = matrix.begin(); it != matrix.end(); ++it) 
	{
		it->push_back((rand() % 20)+1); // Add column to all rows
	}
	*/

  
	cout << "Print the content of the 2D vector with for-loops" << endl;

	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
		{
			cout << matrix[i][j] << '\t';
		}
	cout << endl;
	}
	

	cout << "Print the content of the 2D vector using range-based loops:" << endl; 
	for (const vector<int> &v : matrix)
	{
		for (int x : v) 
			cout << x << '\t';
	cout << endl;
	}

	return 0;
}