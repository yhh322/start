 ///
 /// @file    variadicTemplates.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-28 14:34:35
 ///
 
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

template <typename... Args>
void display(Args... args)
{	//获取可变参数的个数
	cout << sizeof...(args) << endl;
	cout << sizeof...(Args) << endl;
}

//void print()
//{	cout << endl;	 }

template <typename T>
void print(T t)
{
	cout << t << endl;
}

template <typename T, typename... Args>// 模板参数包
void print(T t, Args... args)  //声明时， ... 在参数的左边, 函数参数包
{
	cout << t << " ";
	print(args...);// ...在右边时，称为解包
}
 

int main(void)
{
	string str("world");
	//display(1, 2.2, "hello", 'a', str);
	print(1, 2.2, "hello", 'a', str);
	// cout << 1 " ";
	// print(2.2, "hello", 'a', str)
	//	 cout << 2.2 << " ";
	//		print("hello", 'a', str);
	//			cout << "hello" << " ";
	//				print('a', str);
	//					cout << 'a' << " ";
	//						print(str);
	//							cout << str << " ";
	//								print();


	return 0;
}
