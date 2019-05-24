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
	Derived d(11.11, 12.12);
	d.display();//通过对象名调用虚函数，不会展现多态机制  隐藏
				//通过对象名调用时，与是否为虚函数无关

	return 0;
}
