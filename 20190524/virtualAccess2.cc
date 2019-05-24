 ///
 /// @file    virtualAccess.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-24 10:54:17
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
	Base(double base)
	: _base(base)
	{ cout << "Base(double)" << endl;	}

	virtual 
	void display() const
	{
		cout << "_base = " << _base << endl;
	}

	void func1()  //
	{
		this->display();//在普通成员函数中表现多态特性
	}

private:
	double _base;
};

class Derived
: public Base
{
public:
	Derived(double base, double derived)
	: Base(base)
	, _derived(derived)
	{	cout << "Derived(double,double)" << endl;}

	virtual 
	void display() const
	{	
		cout << "_derived = " << _derived << endl;
	}

private:
	double _derived;
};
 
int main(void)
{
	Base base(22.22);
	base.func1();

	Derived derived(11.11, 12.12);
	derived.func1();//Base::func1(&derived)

	return 0;
}
