 ///
 /// @file    mem_fn.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-31 10:24:53
 ///
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;


class Number
{
public:
	Number(int data = 0)
	: _data(data)
	{}

	void display() const 
	{	cout << _data << " ";}

	bool isEven() const
	{
		return  !(_data % 2);
	}

	bool isPrime() const
	{
		if(_data == 1) {
			return false;
		}
		for(int idx = 2; idx <= _data / 2; ++idx) {
			if(!(_data % idx))
				return false;
		}
		return true;
	}

private:
	int _data;
};
             
 
int main(void)
{
	vector<Number> numbers;
	for(int idx = 1; idx != 21; ++idx) {
		numbers.push_back(Number(idx));
	}
	for_each(numbers.begin(), numbers.end(),  mem_fn(&Number::display));
	
	using namespace placeholders;
	for_each(numbers.begin(), numbers.end(),  bind(&Number::display, _1));
	cout << endl;

	numbers.erase(
		remove_if(numbers.begin(), numbers.end(), mem_fn(&Number::isPrime)),
		numbers.end());
	for_each(numbers.begin(), numbers.end(),  mem_fn(&Number::display));
	cout << endl;


	return 0;
}
