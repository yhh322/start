 ///
 /// @file    map.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-29 14:32:32
 ///
 
#include <iostream>
#include <map>
#include <string>
using std::cout;
using std::endl;
using std::map;
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
	//map默认情况下采用升序方式进行排列
	//不能存放关键字相同的元素
	//
	//底层实现红黑树
	//
	map<string, string> cities{
		std::pair<string, string>("010", "北京"),
		std::make_pair("021", "上海"),
		std::make_pair("0755", "深圳"),
		std::make_pair("0571", "杭州"),
		std::make_pair("027", "武汉"),
		std::make_pair("027", "合肥")
	};
	display(cities);

	//std::pair<map<string,string>::iterator, bool> ret 
	auto ret = cities.insert(std::make_pair("021", "天津"));
	if(ret.second) {
		cout << "元素添加成功!" << endl;
		cout << ret.first->first << " --> " 
			 << ret.first->second << endl;
	} else {
		cout << "元素添加失败!" << endl;
		cout << ret.first->first << " --> " 
			 << ret.first->second << endl;
	}
	display(cities);
	cout << endl;

	//下标访问运算符
	//1. 当元素存在时，通过key直接拿到相应的value
	//2. 当元素不存在时，会通过key添加一个元素, 但对应的value的默认值
	//3. 当元素存在时，还可以通过它直接修改value的值
	cout << cities["021"] << endl;
	cout << cities["023"] << endl;
	cout << endl;
	display(cities);
	cities["023"] = "重庆";//时间复杂度为O(logN)
	cout << endl;
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
}
 
void test1()
{
	//map默认情况下采用升序方式进行排列
	//不能存放关键字相同的元素
	//
	//底层实现红黑树
	//
	map<string, string, std::greater<string>> cities{
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
