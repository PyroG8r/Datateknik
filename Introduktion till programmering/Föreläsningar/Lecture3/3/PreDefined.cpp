#include <iostream>
#include <iomanip>
#include <cmath>   //math-functions pow(), log(),etc.
#include <algorithm>    // std::max

using namespace std;
int main()
{
  double kron_dollar_kurs = 10.43;
  double kronor = 345.50;
  double dollars;
  
  dollars = kronor / kron_dollar_kurs;
  
  cout <<kronor << " svenska kronor blir " << endl

	   << "ceil(kronor): " << ceil(kronor) << endl; //

  cout << "floor(kronor): " << floor(kronor) << " svenska kronor blir ";
  cout << dollars << " amerikanska dollar" << endl;
  cout <<" max(2.5, 3.0): " << max(2.5, 3.0) << endl;
		
  return 0;
}
