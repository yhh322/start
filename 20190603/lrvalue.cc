 ///
 /// @file    lrvalue.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-03 11:04:21
 ///
 
#include <iostream>
#include <vector>
#include <string>
using namespace std;
             
 
int main(void)
{
	int a = 1;
	int b = 2;

	&a;
	&b;
	//&(a+b);//右值
	
	//&(a++);//后置形式 是右值
	&(++a);//前置形式是 左值
	vector<int> numbers;
	&numbers;
	numbers.push_back(1);
	&numbers[0];

	//&100;//字面值常量   右值
	//&string("hello");// 右值, 匿名对象
	string str1("hello");
	string str2("world");
	//&(str1 + str2); //右值
	
	const int & m = 100;//C++11之前，只有const引用能绑定到右值
	&m;//左值
	const int & n = a;//const引用同时还能绑定到左值

	//右值引用 C++11
	int && ref1 = 100;//右值引用可以绑定到右值
	//int && ref2 = a;//error 右值引用不能绑定到左值
	
	const int && ref3 = 100;//使用右值引用就意味着修改
							//右值引用加上const没有意义
 
	return 0;
}
