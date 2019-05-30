 ///
 /// @file    bind.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-30 17:31:00
 ///
 
#include <iostream>
#include <functional>
using namespace std;

void display()
{	cout << "display()" << endl;	}

void (*f)() = display;

typedef void (*Function)();

 
int test0(void)
{
	f();
	Function f1 = display;
	f1();
	return 0;
}

void add(int x, int y)
{
	cout << "x + y = " << x + y << endl;
}

struct Example
{
	void add(int x, int y)
	{
		cout << "Example::add()" << endl;
		cout << "x + y = " << x + y << endl;
	}
};

void test1()
{
	auto f = display;
	f();
	auto f1 = bind(&add, 1, 2);//可以绑定普通函数
	f1();

	Example example;

	//对于成员函数，绑定时必须要加上取地址符号
	//对于this指针而言，可以传递地址，也可以传递对象
	auto f2 = bind(&Example::add, &example, 1, 2);
	f2();

	//bind绑定参数时，采用的是值传递
	auto f3 = bind(&Example::add, example, 1, 2);
	f3();

	//占位符
	using namespace std::placeholders;
	auto f4 = bind(&Example::add, &example, _1, _2);
	f4(11, 12);
}

void print(int x1, int x2, int & x3, int x4)
{
	cout << "(" << x1
		 << "," << x2
		 << "," << x3
		 << "," << x4
		 << ")" << endl;
}

void test2()
{
	using namespace std::placeholders;
	int a = 100;

	//占位符本身所占的位置是形参的位置，
	//占位符本身的数字代表的是实参的位置
	auto f = bind(print, _1, _2, ref(a), a);
	a = 101;
	f(11, 22, 1111, 2222, 3333);
}

void test3()
{
	using namespace std::placeholders;
	int a = 100;

	//std:function称为函数的容器，只能保存一个函数
	function<void(int,int)> f = bind(print, _1, _2, ref(a), a);
	a = 101;
	f(11, 22);

	function<void(int)> f1 = bind(print, _1, 100, ref(a), a);
	f1(111);

	function<void()> f2 = display;
	f2();

	f2 = bind(&Example::add, Example(), 1, 2);
	f2();
}

int main(void)
{
	//test0();
	///test1();
	//test2();
	test3();
	return 0;
}
