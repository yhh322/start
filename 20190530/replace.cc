 ///
 /// @file    replace.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-30 17:01:08
 ///
 
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;
             
bool greaterThan(int number)
{
	return number > 5;
}


 
int main(void)
{
	vector<int> numbers{1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::less<int> lt;// operator()(const int & lhs, const int & rhs);
	//replace_if(numbers.begin(), numbers.end(), bind1st(lt, 5), 10);
	replace_if(numbers.begin(), numbers.end(), bind2nd(lt, 5), 10);
	//replace_if(numbers.begin(), numbers.end(), greaterThan, 10);

	copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	return 0;
}
