 ///
 /// @file    SingleDerived1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-23 11:12:42
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//错误说法: 创建派生类对象时，先调用基类构造函数，再调用派生类构造函数
//
//正确说法: 派生类对象创建时，调用的是派生类构造函数，在执行派生类构造函数的
//过程中(先执行初始化表达式，再执行函数执行体)，调用了基类的构造函数



class Base
{
public:
	Base() {	cout << "Base()" << endl;	}

};

//1.派生类有显式定义构造函数，但基类没有, 此时
//会自动执行基类的默认构造函数
class Derived
: public Base
{
public:
	Derived(double derived)
	: Base()
	, _derived(derived)
	{	cout << "Derived()" << endl;	}

	void display() const
	{
		cout << "Derived::_derived = " << _derived << endl;
	}


private:
	double _derived;
};
 
int main(void)
{
	Derived d(11.1);
	d.display();
	return 0;
}
