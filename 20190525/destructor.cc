 ///
 /// @file    abstractClass.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-25 10:02:22
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
	Base(double base)
	: _base(new double(base))
	{	cout << "Base(double)" << endl;	}

	virtual
	void print() const 
	{	cout << "*_base = " << *_base << endl;	}

	//一般情况下，只要基类中有一个虚函数，都要将析构函数设为虚函数
	virtual 
	~Base()   //析构函数只有一个
	{
		if(_base)  {
			delete _base;
			cout << "~Base() " << endl;
		}
	}

private:
	double * _base;
};

class Derived
: public Base
{
public:
	Derived(double base, double derived)
	: Base(base)
	, _derived(new double(derived))
	{
		cout << "Derived(double, double)" << endl;
	}

	//virtual 
	void print() const
	{
		Base::print();//直接去方法区拿
		cout << "*_derived = " << *_derived << endl;
	}

	//virtual
	~Derived()
	{
		if(_derived) {
			delete _derived;
			cout << "~Derived() " << endl;
		}
	}
private:
	double * _derived;
};
 
int main(void)
{
	Base * pbase = new Derived(11.11, 12.12);
	pbase->print();

	delete pbase;
	return 0;
}
