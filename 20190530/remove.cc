 ///
 /// @file    remove.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-30 16:31:42
 ///
 
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;
 
int test0(void)
{
	vector<int> numbers{1, 2, 3, 4, 5, 6, 7, 8, 9};

	numbers[0] = numbers[3] = numbers[4] = 66;
	copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	auto it = remove(numbers.begin(), numbers.end(), 66);
	//cout << *it << endl;
	//erase-remove惯用法
	numbers.erase(remove(numbers.begin(), numbers.end(), 66), numbers.end());
	copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	return 0;
}

//建议: 一般情况下，在遍历容器的过程中，不要做删除和添加元素的操作
//	    防止发生迭代器失效的行为

void test1()
{
	vector<int> numbers;
	numbers.push_back(1);

	bool flag = true;
	for(auto it = numbers.begin(); it != numbers.end(); ++it) {
		//cout << "numbers' capacity = " << numbers.capacity() << endl;
		cout << *it << " ";
		if(flag) {
			numbers.push_back(2);//当扩容操作执行完毕之后，原来的迭代器已经失效
			flag = false;		// 此时必须要重新去获取迭代器，才能正常运行
			it = numbers.begin();
		}
	}
	cout << endl;
}

int main(void)
{
	test1();
	return 0;
}

