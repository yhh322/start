 ///
 /// @file    copyControlDerived1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-23 15:16:27
 ///
 
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;
 
class Base
{
public:
	Base(const char * base)
	: _base(new char[strlen(base) + 1]())
	{	
		cout << "Base(const char *)" << _base << endl;	
		strcpy(_base, base);
	}

	Base(const Base & rhs)
	: _base(new char[strlen(rhs._base) + 1]())
	{
		strcpy(_base, rhs._base);
		cout << "Base(const Base & )" << endl;
	}

	Base & operator=(const Base & rhs)
	{
		cout << "Base & operator=(const Base &) " << endl;
		if(this != &rhs) {
			delete [] _base;

			_base = new char[strlen(rhs._base) + 1]();
			strcpy(_base, rhs._base);
		}
		return *this;
	}

	~Base()
	{
		if(_base)
			delete [] _base;
	}

	friend std::ostream & operator<<(std::ostream & os, const Base & rhs);

private:
	char * _base;
};

std::ostream & operator<<(std::ostream & os, const Base & rhs)
{
	os << rhs._base;
	return os;
}


//当派生类对象之间进行复制控制时，如果派生类没有显式定义复制控制函数
// 但基类有显式定义复制控制函数，则会自动调用基类相应复制控制函数

class Derived
: public Base
{
public:
	Derived(const char * base)
	: Base(base)
	{	cout << "Derived()" << endl;	}

	~Derived()
	{
		cout << "~Derived()" << endl;
	}
};

int main(void)
{
	Derived d1("hello");
	cout << "d1 = " << d1 << endl;
	Derived d2(d1);
	cout << "d2 = " << d2 << endl;

	Derived d3("world");
	d3 = d1;
	cout << "d3 = " << d3 << endl;
	return 0;
}
