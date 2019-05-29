 ///
 /// @file    set.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-29 10:57:20
 ///
 
#include <cmath>
#include <iostream>
#include <set>
using std::cout;
using std::endl;
using std::set;
using std::string;

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
	//set中默认情况下按升序的方式进行排列
	//set中不能存放关键字相同的元素 
	set<int> numbers{1, 1, 6, 6, 2, 3, 5, 1, 6, 4};
	display(numbers);

	//numbers[0];//不支持下标访问，双向迭代器
	for(auto it = numbers.begin(); it != numbers.end(); ++it)
	{
		cout << *it << endl;
	}

	//std::pair<set<int>::iterator, bool> ret = numbers.insert(1);
	auto ret = numbers.insert(7);
	if(ret.second) {
		cout << "添加元素成功!" << endl;
		cout << *ret.first << endl;
	} else {
		cout << "添加元素失败" << endl;
		cout << *ret.first << endl;
	}


	auto it = numbers.begin();
	//set底层实现是红黑树 --> 近似平衡二叉树 ---> 访问某一个节点的时间复杂度为O(logN)
	//特点:
	//	1. 节点不是红色就是黑色
	//	2. 根节点是黑色的
	//	3. 所有叶子节点是黑色
	//	4. 不能有两个连续的红色节点
	//	5. 从根节点到任意一个叶子节点的路径之上的黑色
	//     节点的个数相同
	//*it = 10;//error不能修改已经添加到其中的元素，是只读的

	//如果只要判断set中是否包含某个元素，使用count
	size_t count = numbers.count(0);//o(logN)
	cout << "count = " << count << endl;

	//如果要查找元素并进行访问，可以使用find
	auto it2 = numbers.find(10);
	if(it2 != numbers.end()) {
		cout << "*it2 = " << *it2 << endl;
	} else {
		cout << "无法找到相关的元素！" << endl;
	}
}

void test1()
{
	std::pair<int, string> value(1, "hello");
	cout << value.first << " --> " << value.second << endl;
}
 
class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{	cout << "Point(int,int)" << endl;	}

	float getDistance() const
	{
		return sqrt(_ix * _ix + _iy * _iy);
	}

	friend std::ostream & operator<<(std::ostream &os, const Point & rhs);
private:
	int _ix;
	int _iy;
};

std::ostream & operator<<(std::ostream &os, const Point & rhs)
{
	os << "(" << rhs._ix
	   << "," << rhs._iy
	   << ")";
	return os;
}


#if 0
bool operator<(const Point & lhs, const Point & rhs)
{
	return lhs.getDistance() < rhs.getDistance();
}

bool operator>(const Point & lhs, const Point & rhs)
{
	return lhs.getDistance() > rhs.getDistance();
}
#endif

struct PointComparator
{
	bool operator()(const Point & lhs, const Point & rhs)
	{
		return lhs.getDistance() > rhs.getDistance();
	}
};

void test2()
{
	//对于自定类类型，如果要放入关联式容器时，要指定排序方式
	//set<Point, std::greater<Point>> numbers{
	set<Point, PointComparator> numbers{
		Point(1, 2),
		Point(3, 4),
		Point(1, 2),
		Point(5, 6),
		Point(7, 8)
	};
	display(numbers);

	//numbers[0];//不支持下标访问，双向迭代器
	for(auto it = numbers.begin(); it != numbers.end(); ++it)
	{
		cout << *it << endl;
	}

#if 0
	//std::pair<set<int>::iterator, bool> ret = numbers.insert(1);
	auto ret = numbers.insert(7);
	if(ret.second) {
		cout << "添加元素成功!" << endl;
		cout << *ret.first << endl;
	} else {
		cout << "添加元素失败" << endl;
		cout << *ret.first << endl;
	}


	auto it = numbers.begin();
	//set底层实现是红黑树 --> 近似平衡二叉树 ---> 访问某一个节点的时间复杂度为O(logN)
	//特点:
	//	1. 节点不是红色就是黑色
	//	2. 根节点是黑色的
	//	3. 所有叶子节点是黑色
	//	4. 不能有两个连续的红色节点
	//	5. 从根节点到任意一个叶子节点的路径之上的黑色
	//     节点的个数相同
	//*it = 10;//error不能修改已经添加到其中的元素，是只读的

	//如果只要判断set中是否包含某个元素，使用count
	size_t count = numbers.count(0);//o(logN)
	cout << "count = " << count << endl;

	//如果要查找元素并进行访问，可以使用find
	auto it2 = numbers.find(10);
	if(it2 != numbers.end()) {
		cout << "*it2 = " << *it2 << endl;
	} else {
		cout << "无法找到相关的元素！" << endl;
	}
#endif
}
int main(void)
{
	//test0();
	//test1();
	test2();
	return 0;
}
