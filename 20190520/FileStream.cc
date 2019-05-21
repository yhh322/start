 ///
 /// @file    FileStream.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-20 16:15:40
 ///
 
#include <iostream>
#include <fstream>
using std::cout;
using std::endl;
using std::ifstream;
 
int main(void)
{
	ifstream ifs("Complex2.cc");
	ifstream ifs2(ifs);//error, 系统资源，不能进行复制


	return 0;
}
