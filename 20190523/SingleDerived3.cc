 ///
 /// @file    SingleDerived1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-23 11:12:42
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
	Base()
	: _base(0)
	{	cout << "Base()" << _base << endl;	}

	Base(double base) 
	: _base(base)
	{	cout << "Base(double)" << endl;	}

	void print() const 
	{	cout << "Base::_base = " << _base << endl;	}

private:
	double _base;
};

//3.派生类有显式定义构造函数，但基类有, 当创建派生类对象时
//都必须要在派生类构造函数的初始化列表之中显式调用基类相应的
//构造函数
class Derived
: public Base
{
public:
	Derived()
	: Base()
	{	cout << "Derived()" << endl;	}

	Derived(double derived)
	: Base()
	, _derived(derived)
	{	cout << "Derived(double)" << endl;	}

	Derived(double base, double derived)
	: Base(base)
	, _derived(derived)
	{
		cout << "Derived(double,double)" << endl;
	}

	void display() const
	{
		cout << "------" << endl;
		print();
		cout << "Derived::_derived = " << _derived << endl;
		cout << "------" << endl;
	}

private:
	double _derived;
};
 
int main(void)
{
	Derived d;
	d.display();
	cout << endl;

	Derived d1(11.11);
	d1.display();
	cout << endl;

	Derived d2(11.11, 12.12);
	d2.display();
	return 0;
}
