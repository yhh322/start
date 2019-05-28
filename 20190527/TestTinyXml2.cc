 ///
 /// @file    TestTinyXml2.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-27 09:54:11
 ///
 
#include "tinyxml2.h"
#include <iostream>
using std::cout;
using std::endl;

using namespace tinyxml2;
 
int main(void)
{
	XMLDocument doc;

	doc.LoadFile("coolshell.xml");

	return 0;
}
