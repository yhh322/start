 ///
 /// @file    ostream_iterator.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-30 11:37:30
 ///
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using std::cout;
using std::endl;
using std::vector;
using std::copy;
using std::ostream_iterator;
 
int main(void)
{
	vector<int> numbers{1, 2, 3, 4, 5};
	
	//ostream_iterator内部要重载相应的运算符，模拟
	//出一个迭代器功能来 ==> 适配器模式
	ostream_iterator<int> osi(cout, ",");
	copy(numbers.begin(), numbers.end(), osi);
	cout << endl;

	return 0;
}
