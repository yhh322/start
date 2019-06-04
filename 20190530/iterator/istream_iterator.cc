 ///
 /// @file    istream_iterator.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-30 14:32:23
 ///
 
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::copy;
using std::vector;
using std::istream_iterator;
using std::ostream_iterator;
 
int main(void)
{
	vector<int> numbers;
	istream_iterator<int> isi(cin);//开始读取数据
	//begin()、end() 是用来读取容器的元素的
	//不能用来做添加元素的操作
	//copy(isi, istream_iterator<int>(), numbers.begin());
	//isi++ 时，读取下一个元素的
	//
	//back_inserter返回的是一个插入迭代器 std::back_insert_iterator
	//在赋值时调用相应的容器的push_back方法
	copy(isi, istream_iterator<int>(), std::back_inserter(numbers));

	copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
 
	return 0;
}
