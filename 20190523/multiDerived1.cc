 ///
 /// @file    multiDerived1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-23 10:24:07
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//C++支持多重继承(多基派生)
class A
{
public:
	A() {	cout << "A()" << endl;	}
	~A() {	cout << "~A()" << endl;	}
	
	

	void print() const
	{	cout << "A::print()" << endl;	}
};

class B	
{
public:
	B() {	cout << "B()" << endl;	}
	~B() {	cout << "~B()" << endl;	}
	void display() const
	{	cout << "B::display()" << endl;	}
};

class C	
{
public:
	C() {	cout << "C()" << endl;	}
	~C() {	cout << "~C()" << endl;	}
	void show() const
	{	cout << "C::show()" << endl;	}
};

class D
: public A
, public B
, public C
{
public:
	D()
	: A()
	, B()
	, C()
	{	cout << "D()" << endl;	}

	~D() {	cout << "~D()" << endl;	}
};
 
int main(void)
{
	D d;
	d.print();
	d.display();
	d.show();
	return 0;
}
