 ///
 /// @file    multimap.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-29 14:32:32
 ///
 
#include <iostream>
#include <map>
#include <string>
using std::cout;
using std::endl;
using std::multimap;
using std::string;

template <typename Container>
void display(const Container & c)
{
	typename Container::const_iterator it = c.begin();
	for(; it != c.end(); ++it) {
		cout << it->first << " ---> "
			 << it->second << endl;
	}
}

void test0()
{
	//multimap默认情况下采用升序方式进行排列
	//可以存放关键字相同的元素
	//
	//底层实现红黑树
	//
	multimap<string, string> cities{
		std::pair<string, string>("010", "北京"),
		std::make_pair("021", "上海"),
		std::make_pair("0755", "深圳"),
		std::make_pair("0571", "杭州"),
		std::make_pair("027", "武汉"),
		std::make_pair("027", "合肥")
	};
	display(cities);

	//std::pair<multimap<string,string>::iterator, bool> ret 
	auto iter = cities.insert(std::make_pair("021", "天津"));
	cout << iter->first << " --> " << iter->second << endl;
	display(cities);
	cout << endl;

	//multimap不支持下标访问运算符
	display(cities);
	cout << endl;

	//查找元素
	auto it = cities.find("024");//时间复杂度O(logN)  二分查找
	if(it !=cities.end()) {
		cout << "查找元素成功!" << endl;
		cout << it->first << " --> " << it->second << endl;
	} else {
		cout << "查找元素失败" << endl;
	}

	//范围查找
	cout << endl;
	auto ret = cities.equal_range("027");
	while(ret.first != ret.second) {
		cout << ret.first->first << " --> " << ret.first->second << endl;
		++ret.first;
	}
}

 
void test1()
{
	//multimap默认情况下采用升序方式进行排列
	//不能存放关键字相同的元素
	//
	//底层实现红黑树
	//
	multimap<string, string, std::greater<string>> cities{
		std::pair<string, string>("010", "北京"),
		std::make_pair("021", "上海"),
		std::make_pair("0755", "深圳"),
		std::make_pair("0571", "杭州"),
		std::make_pair("027", "武汉"),
		std::make_pair("027", "合肥")
	};
	display(cities);
}

int main(void)
{
	//test0();
	test1();
	return 0;
}
