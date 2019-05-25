 ///
 /// @file    TestLine.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-21 10:59:11
 ///
 
#include "Line.h"
#include <iostream>
using std::cout;
using std::endl;
 
int main(void)
{
	Line line(1, 2, 3, 4);
	line.printLine();

	//Line::Point pt(11, 22);//error
	//pt.print();

	return 0;
}
