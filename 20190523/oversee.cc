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
	: _data(0)
	{	cout << "Base()" << _data << endl;	}

	Base(double base) 
	: _data(base)
	{	cout << "Base(double)" << endl;	}

	void display(int x) const 
	{	cout << "Base::_data = " << _data << endl;	}

protected:
	double _data;
};

class Derived
: public Base
{
public:
	Derived()
	: Base()
	, _data(0)
	{	cout << "Derived()" << endl;	}

	Derived(double base, double derived)
	: Base(base)
	, _data(derived)
	{
		cout << "Derived(double,double)" << endl;
	}

	void display() const
	{
		//cout << "Base::_data = " << Base::_data << endl;
		Base::display(0);
		cout << "Derived::_data = " << _data << endl;//隐藏了基类的同名_data
	}

private:
	double _data;
};
 
int main(void)
{
	Derived d2(11.11, 12.12);
	d2.display();//父子类， 隐藏同名的基类函数 ==> 改造基类的成员
	cout << endl;
	//d2.Base::display();
	//d2.display(10);//隐藏同名的基类函数, 只要函数名称相同，就会被隐藏
	d2.Base::display(10);
	return 0;
}
