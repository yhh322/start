 ///
 /// @file    multiDerived.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-25 10:48:06
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class A
{
public:
	virtual	void a(){	cout << "A::a()" << endl;	}
	virtual	void b(){	cout << "A::b()" << endl;	}
	virtual	void c(){	cout << "A::c()" << endl;	}
};
 
class B
{
public:
	virtual	void a(){	cout << "B::a()" << endl;	}
	virtual	void b(){	cout << "B::b()" << endl;	}
	void c(){	cout << "B::c()" << endl;	}
	void d(){	cout << "B::d()" << endl;	}
};

class C
: public A
, public B
{
public:
	virtual	void a(){	cout << "C::a()" << endl;	}
	void c(){	cout << "C::c()" << endl;	}
	void d(){	cout << "C::d()" << endl;	}
};

class D
: public C
{
public:
	void c() {	cout << "D::c()" << endl;	}

};
int main(void)
{
	C c;
	c.a();
	//c.b();//成员名冲突问题
	c.c();
	c.d();
	cout << endl;

	A * pa = &c;
	cout << "pa = " << pa << endl;
	pa->a();//C::a()
	pa->b();//A::b()
	pa->c();//C::c() ==> 虚函数

	cout << endl;
	B * pb = &c;
	cout << "pb = " << pb << endl;
	pb->a();//C::a()
	pb->b();//B::b()
	pb->c();//B::c() ==> 非虚函数
	pb->d();//B::d()

	cout << endl;
	C * pc = &c;
	cout << "pc = " << pc << endl;
	pc->a();//C::a()
	//pc->b();
	pc->c();//C::c() ==> 虚函数

	pc->d();//C::d()
	cout << endl;

	D d;
	pc = &d;
	pc->c();

	return 0;
}

