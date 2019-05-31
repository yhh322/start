 ///
 /// @file    vector.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-31 10:58:55
 ///
 
#include <iostream>
#include <vector>
using namespace std;
             

class X
{
public:
	X(): _data(0) {	cout << "X()" << endl;	}
	X(int x) : _data(x) {	cout << "X(int)" << endl;	}

	X(const X & rhs) 
	: _data(rhs._data)
	{
		cout << "X(const X & )" << endl; 
	}

	operator int()
	{	return _data; }

	~X(){	cout << "~X()" << endl;	}
private:
	int _data;
};
 
int main(void)
{
	//对于容器来说，空间的分配与对象的构造是分离的
	vector<X> numbers;
	numbers.reserve(100);
	cout << numbers.size() << endl;
	cout << numbers.capacity() << endl;
	numbers.push_back(X());
	numbers.push_back(X(1));
	numbers.push_back(X(2));
	for(auto & elem : numbers)
		cout << elem << " ";
	cout << endl;
	cout << numbers.size() << endl;
	cout << numbers.capacity() << endl;
	
	numbers.pop_back();
	cout << numbers.size() << endl;
	cout << numbers.capacity() << endl;
	cout << endl;
	for(auto & elem : numbers)
		cout << elem << " ";
	cout << endl;

	return 0;
}
