 ///
 /// @file    list.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-01 11:32:33
 ///
 
#include <iostream>
#include <list>
using namespace std;
             
 
int main(void)
{
	list<int> numbers{1, 2, 3, 4, 5, 6};
	for(auto & number : numbers) 
		cout << number << " ";
	cout << endl;

	numbers.splice(numbers.begin(), numbers, --numbers.end());
	for(auto & number : numbers) 
		cout << number << " ";
	cout << endl;

	return 0;
}
