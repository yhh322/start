 ///
 /// @file    template.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-28 10:51:50
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//template <class T>
template <typename T>  //模板形参列表
T add(T x, T y);

//函数模板与函数模板之间也可以进行重载的
template <typename T>
T add(T x, T y, T z)
{
	return x + y + z;
}

	     //实例化
//函数模板 ---> 模板函数
//	    模板参数推导
//
//模板  ==》 代码生成器
//
//
//函数模板与普通函数之间是可以重载的
//而且普通函数的执行要优先于函数模板

#if 0
//在编译期有函数模板进行参数推导实例化的一个模板函数
int add(int x, int y)
{
	cout << "int add(int,int)" << endl;
	return x + y;
}
#endif
 
int main(void)
{
	int x1 = 3, x2 = 4, x9 = 5;;
	double x3 = 1.11, x4 = 2.22;
	char x5 = 'a', x6 = 1;
	long x7 = 100, x8 = 101;

	cout << "add(x1, x2) = " << add(x1, x2) << endl;//隐式实例化
	cout << "add(x3, x4) = " << add<double>(x3, x4) << endl;//显式实例化
	cout << "add(x5, x6) = " << add(x5, x6) << endl;
	cout << "add(x7, x8) = " << add(x7, x8) << endl;
	cout << "add(x1, x2, x9) = " << add(x2, x2, x9) << endl;

	//cout << add(x1, x3) << endl;//error

	return 0;
}

template <typename T>  //模板形参列表
T add(T x, T y)
{
	cout << "T add(T,T)" << endl;
	return x + y;
}
