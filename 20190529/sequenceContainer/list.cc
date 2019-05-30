 ///
 /// @file    list.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-29 10:19:36
 ///
 
#include <iostream>
#include <list>
using std::cout;
using std::endl;
using std::list;

template <typename Container>
void display(const Container & c)
{
	for(auto & elem : c) { //& 不可少，如果没加，就会复制的
		cout << elem << " ";
	}
	cout << endl;
}

void test0()
{
	list<int> numbers1{3, 6, 2, 3, 4, 7, 6,9, 7, 2, 1, 4, 5};
	list<int> numbers2{11, 22, 33};
	display(numbers1);
	display(numbers2);
	cout << " 移动元素之后:" << endl;
	auto it1 = numbers1.begin();
	++it1;
	*it1 = 100;

	//numbers2.splice(numbers2.begin(), numbers1);
	//numbers2.splice(numbers2.begin(), numbers1, it1);
	//numbers2.splice(numbers2.begin(), numbers1, it1, numbers1.end());
	//display(numbers1);
	//display(numbers2);
	numbers1.reverse();
	display(numbers1);
	std::greater<int> gt;
	numbers1.sort(gt);
	display(numbers1);
	numbers1.unique();
	display(numbers1);
	


}
 
int main(void)
{
	test0();
}
