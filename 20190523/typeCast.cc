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

class Derived
: public Base
{
public:
	Derived()
	: Base()
	, _derived(0)
	{	cout << "Derived()" << endl;	}

	Derived(double base, double derived)
	: Base(base)
	, _derived(derived)
	{
		cout << "Derived(double,double)" << endl;
	}

	void display() const
	{
		cout << "Derived::_derived = " << _derived << endl;
	}

private:
	double _derived;
};

//基类与派生类之间的转换:
//	--> 向上转型 是合法的
//可以把派生类对象赋值给基类对象
//可以把基类指针指向派生类对象
//可以把基类引用绑定到派生类对象
//
//派生类的功能大于等于基类
 
int main(void)
{
	Base base(11.11);
	base.print();
	cout << endl;
	Derived derived(22.22, 33.33);
	derived.display();
	cout << endl;

	base = derived;//Base & operator=(const Base & rhs);
	base.operator=(derived);//const Base & rhs = derived;
	base.print();


	//derived = base;//error, derived.operator=(base);
	//Derived & operator=(const Derived & rhs);
	//const Derived & rhs = base;
	
	Base * pbase = &derived;
	pbase->print();

	//Derived * pderived = &base;//error, 有风险, 有可能会造成踩内存
	//pderived->display();
	
	Base & ref = derived;//
	ref.print();



	return 0;
}
