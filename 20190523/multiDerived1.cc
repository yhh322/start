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
	void print() const
	{	cout << "A::print()" << endl;	}
};

class B	
{
public:
	void display() const
	{	cout << "B::display()" << endl;	}
};

class C	
{
public:
	void show() const
	{	cout << "C::show()" << endl;	}
};

class D
: public A
, public B
, public C
{

};
 
int main(void)
{
	D d;
	d.print();
	d.display();
	d.show();
	return 0;
}
