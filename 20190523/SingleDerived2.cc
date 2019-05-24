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
	{	cout << "Base::_base = " << _base << endl;	}

	Base(double base) 
	: _base(base)
	{	cout << "Base()" << endl;	}

	void print() const 
	{	cout << "Base::_base = " << _base << endl;	}

private:
	double _base;
};

//2.派生类没有显式定义构造函数，但基类有, 则
//基类必须提供一个默认构造函数，这样派生类才能
//正常创建
class Derived
: public Base
{
public:
#if 0
	Derived(double derived)
	: Base()
	, _derived(derived)
	{	cout << "Derived()" << endl;	}
#endif

	void display() const
	{
		cout << "Derived::_derived = " << _derived << endl;
	}

private:
	double _derived;
};
 
int main(void)
{
	Derived d;
	d.display();
	return 0;
}
