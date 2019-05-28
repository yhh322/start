 ///
 /// @file    TestAdd.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-28 11:15:16
 ///
 
#include "add.h"

//为了将C++头文件与C头文件区分，可以*.hpp  *.hh
 
#include <iostream> //模板实现，要看到全部的实现内容
using std::cout;
using std::endl; 


int main(void)
{
	int a = 1, b = 2;
	cout << "add(a, b) = " << add(a, b) << endl;

	return 0;
}
