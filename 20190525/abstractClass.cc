 ///
 /// @file    abstractClass.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-25 10:02:22
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//定义了protected构造函数的类也称为抽象类
class Base
{
public:
	void print() const 
	{	cout << "_base = " << _base << endl;	}

protected:
	Base(double base)
	: _base(base)
	{	cout << "Base(double)" << endl;	}
private:
	double _base;
};

class Derived
: public Base
{
public:
	Derived(double base)
	: Base(base)
	{
		cout << "Derived(double base)" << endl;
	}

};
 
int main(void)
{
	Base * pbase;
	//Base base(1);
	Derived derived(11.11);
	derived.print();
	return 0;
}
