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
	void print() const
	{	cout << "B::print()" << endl;	}
};

class C	
{
public:
	void print() const
	{	cout << "C::print()" << endl;	}
};

class D
: public A
, public B
, public C
{

};
 
int main(void)
{
	D d;//成员名访问冲突 --> 作用域限定符
	//d.print();
	d.A::print();
	d.B::print();
	d.C::print();
	return 0;
}
