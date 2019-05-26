 ///
 /// @file    pureVirtrualFunction.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-24 11:26:08
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
	Base() {	cout << "Base()" << endl;	}

	virtual 
	void display() = 0;//纯虚函数作为接口存在, 没有实现

	virtual void show() = 0;
};

class Derived1
: public Base
{//如果一个类继承自抽象类，该抽象类中有多个纯虚函数时，
// 只要有一个纯虚函数没有实现，那么该派生类也会成为抽象类
public:
	void display()
	{	cout << "Derived1::display()" << endl;	}

};

class Derived2
: public Derived1
{
public:
	void show() 
	{	cout << "Derived2::show()" << endl;	}
};

//定义了纯虚函数的类称为抽象类

void display(Base * pbase)
{
	pbase->display();
	pbase->show();
}

 
int main(void)
{
	//Base base;//error,抽象类不能创建对象
	Base * pbase = nullptr;

	//Derived1 derived1;
	//display(&derived1);
	
	Derived2 derived2;
	display(&derived2);
	


	return 0;
}
