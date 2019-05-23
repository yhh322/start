 ///
 /// @file    virutalFunction.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-23 16:10:22
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
	Base(double base) 
	: _base(base)
	{	cout << "Base(double)" << endl;	}

	//虚函数的实现原理是什么??
	//答: 虚函数表。 当一个类定义了虚函数之后，会在其对象的
	//存储布局的开始位置多一个虚函数指针，该虚函数指针指向了
	//一张虚函数表，虚函数表里面存放的就是虚函数的入口地址
	//
	//多态机制(动态多态)是如何被激活的??
	//答:1. 基类定义虚函数
	//   2. 派生类覆盖基类虚函数
	//   3. 创建派生类对象
	//   4. 通过基类指针(引用)指向派生类对象
	//   5. 通过基类指针(引用)调用虚函数
	virtual 
	void display() const
	{	cout << "_base " << _base << endl;}

private:
	double _base;
};

class Derived1
: public Base
{
public:
	Derived1(double base, double derived)
	: Base(base)
	, _derived1(derived)
	{	cout << "Derived(double, double)" << endl;}

	//当基类设置虚函数，在派生类内部覆盖(重定义)虚函数之后，
	//即使派生类同名函数之前没有加上virtual关键字
	//它也是虚函数
	virtual 
	void display() const override
	{	cout << "_derived1 = " << _derived1 << endl;	}
private:
	double _derived1;
};

class Derived2
: public Base
{
public:
	Derived2(double base, double derived)
	: Base(base)
	, _derived2(derived)
	{	cout << "Derived(double, double)" << endl;}

	//virtual 
	void display() const override
	{	cout << "_derived2 = " << _derived2 << endl;	}
private:
	double _derived2;
};

void display(Base * pbase) 
{
	pbase->display();//同一条指令
}
 
int main(void)
{
	cout << "sizeof(Base) = " << sizeof(Base) << endl;
	cout << "sizeof(Derived1) = " << sizeof(Derived1) << endl;
	cout << "sizeof(Derived2) = " << sizeof(Derived2) << endl;
	Base base(11.11);
	Derived1 derived1(22.22, 33.33);
	Derived2 derived2(44.44, 55.55);
	
	display(&base);
	display(&derived1);
	display(&derived2);

	//Base *pbase = &derived1;
	//pbase->display(10);
	
	cout << endl;
	Base & ref = derived1;//引用也可以表现动态多态特性
	ref.display();

	Base & ref2 = derived2;
	ref2.display();

	return 0;
}
