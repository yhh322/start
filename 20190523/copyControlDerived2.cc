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
		cout << "~Base()" << endl;
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


//2. 当派生类对象之间进行复制控制时，如果派生类没有显式定义复制控制函数
// 但基类有显式定义复制控制函数，则会自动调用基类相应复制控制函数

class Derived
: public Base
{
public:
	Derived(const char * base, const char * derived)
	: Base(base)
	, _derived(new char[strlen(derived) + 1]())
	{	
		cout << "Derived(cons char *, const char *)" << endl;	
		strcpy(_derived, derived);
	}

	Derived(const Derived & rhs)
	: Base(rhs)// const Base & ref = rhs;
	, _derived(new char[strlen(rhs._derived) + 1]())
	{ 
		cout << "Derived(const Derived&)" << endl;
		strcpy(_derived, rhs._derived);
	}

	Derived & operator=(const Derived & rhs)
	{
		if(this != &rhs) {
			Base::operator=(rhs);//显式调用
			delete [] _derived;
			_derived = new char[strlen(rhs._derived) + 1]();
			strcpy(_derived, rhs._derived);
		}
		cout << "Derived & operator =(const Derived&)" << endl;
		return *this;
	}


	~Derived()
	{
		cout << "~Derived()" << endl;
	}

	friend std::ostream & operator<<(std::ostream & os, const Derived & rhs);

private:
	char * _derived;
};

std::ostream & operator<<(std::ostream & os, const Derived & rhs)
{
	const Base & ref = rhs;
	os << ref;
	os << rhs._derived;
	return os;
}

int main(void)
{
	Derived d1("hello,", "world");
	cout << "d1 = " << d1 << endl;

	Derived d2(d1);
	cout << "d2 = " << d2 << endl;

#if 1
	Derived d3("shenzhen,", "wangdao");
	cout << "d3 = " << d3 << endl << endl;
	d3 = d1;
	cout << "d3 = " << d3 << endl;
#endif
	return 0;
}
