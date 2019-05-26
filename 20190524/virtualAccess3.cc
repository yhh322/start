 ///
 /// @file    virtualAccess.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-24 10:54:17
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Grandpa
{
public:
	Grandpa(double base)
	: _base(base)
	{ 
		cout << "Grandpa(double)" << endl;	
		display();
	}

	virtual 
	void display() const
	{
		cout << "Grandpa::display() " << endl;
	}

	virtual 
	void show() const 
	{	cout << "Grandpa::show() " << endl;}

	~Grandpa() 
	{	
		cout << "~Grandpa()" << endl;	
		show();
	}

private:
	double _base;
};

class Parent 
: public Grandpa 
{
public:
	Parent(double base, double derived)
	: Grandpa(base)
	, _derived(derived)
	{	
		cout << "Parent(double,double)" << endl;
		display();//在构造函数中调用虚函数，不表现动态多态，表现的是静态联编
	}

#if 0
	virtual 
	void display() const
	{	
		cout << "Parent::display() " << endl;
	}

	virtual 
	void show() const 
	{	cout << "Parent::show() " << endl;}
#endif

	~Parent()
	{
		cout << "~Parent()" << endl;
		show();
	}
private:
	double _derived;
};

class Son
: public Parent
{
public:
	Son()
	: Parent(11, 12)
	{	cout << "Son()" << endl;	}

	virtual 
	void display() const
	{	
		cout << "Son::display() " << endl;
	}

	virtual 
	void show() const 
	{	cout << "Son::show() " << endl;}

	~Son()
	{ cout << "~Son()" << endl; }
};
 
int main(void)
{
	Son son;

	return 0;
}
