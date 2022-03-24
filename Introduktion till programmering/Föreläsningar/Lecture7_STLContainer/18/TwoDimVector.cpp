#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//prints out the matrix
void printOutMatrix (const vector <vector<int>> &twoDimVector);

//prints out sum of each row in order
int printOutSumOfRows(const vector<int>& v);

int main()
{

    //we want a 5x5 matrix

    //declaring a 2D vector of 5 rows
	vector< vector<int> > twoDimVector(5);

	// Adding 5 columns to each row.
	for (int i = 0; i < twoDimVector.size(); i++)
		twoDimVector[i]=vector<int>(5,0); 


    //Or you can create a 5x5 matrix this way:
    //vector<vector<int>> matrix(rows, vector<int>(columns, default_value));
    vector<std::vector<int>> matrix(5, std::vector<int>(5,0));
    

    for(int i=0;i <twoDimVector.size();i++)
        for(int j=0; j <twoDimVector[i].size();j++)
            twoDimVector[i][j]= rand()%20;


    printOutMatrix (twoDimVector);
    printOutMatrix (matrix);

    for (const vector<int> &v : twoDimVector)
    {
        cout << printOutSumOfRows(v) <<endl;
    }

    return 0;
}

void printOutMatrix (const vector <vector<int>> &twoDimVector)
{
    cout << "Print the content of the 2D vector" << endl; 
    for (const vector<int> &v : twoDimVector)
    {
	    for (int x : v) 
		    cout << x << '\t';
	    cout << endl;
    }
	

}

int printOutSumOfRows(const vector<int>& v)
{
    int sum =0;
    for (int x : v) 
     sum +=x;
    return sum;
}