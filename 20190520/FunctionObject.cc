 ///
 /// @file    FunctionObject.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-20 15:00:21
 ///
 
#include <iostream>
using std::cout;
using std::endl;

struct FunctionObject
{
	//() 小括号 --> 函数调用运算符
	//携带了状态的函数对象又称为闭包  ==> lambda表达式 ==>匿名函数
	int operator()(int x, int y)
	{	
		++_count;
		return x + y;	
	}

	int operator()(int x, int y, int z)
	{
		return x * y * z;
	}

	int getCount() const {	return _count;	}
private:
	int _count = 0;//函数对象的状态
};

//print被执行后，啥也不剩
void print()
{
	cout << "print()" << endl;
}

//
int add(int x, int y)
{
	static int count = 0;//函数的状态, 但是只有一个
	++count;
	cout << ">> add函数被调用了" << count << " 次" << endl;
	return x + y;
}
 
int main(void)
{
	int a = 3, b = 4;
	add(a, b);
	cout << "add(a, b) = " << add(a, b) << endl;

	FunctionObject fo;
	cout << "fo(a, b) = " << fo(a, b) << endl;//fo 函数对象
	fo(a, b);
	cout << "函数被调用了 " << fo.getCount() << " 次" << endl;
	add(a, b);
	add(a, b);

	FunctionObject fo2;
	fo2(a,b);
	fo2(a,b);
	fo2(a,b);
	cout << "函数被调用了 " << fo2.getCount() << " 次" << endl;

	cout << "fo2(a, b, 3) = " << fo2(a, b, 3) << endl;

	return 0;
}
