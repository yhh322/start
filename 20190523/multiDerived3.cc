 ///
 /// @file    multiDerived3.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-23 10:54:04
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class A
{
public:
	A(double a = 0)
	: _a(a)
	{}

	void setA(double a)
	{	_a = a;	}

private:
	double _a;
};

class B
: virtual public A //发生菱形继承时，需要采用虚拟继承解决问题
{

private:
	double _b;

};
 
class C
: virtual public A
{

private:
	double _c;
};

class D
: public B
, public C
{

private:
	double _d;
};

int main(void)
{
	cout << "sizeof(D) = " << sizeof(D) << endl;
	D d;
	d.setA(10);//存储布局二义性 --> 虚拟继承
	d.A::setA(11);
	d.B::setA(12);
	d.C::setA(13);

	return 0;
}
