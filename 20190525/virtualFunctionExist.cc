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
private:
	long _a = 100;
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
	A a;
	long ** pVtable = (long **)&a;
	
	long address = pVtable[0][0];
	typedef void (* Function)();
	Function f = (Function)address;
	f();

	f= (Function)pVtable[0][1];

	f();
	f= (Function)pVtable[0][2];
	f();

	pVtable[1] = (long*)1000;
	long value = (long)pVtable[1];
	cout << "value = " << value << endl;

	return 0;
}

