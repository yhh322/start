 ///
 /// @file    atexit.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-21 14:32:27
 ///
 
#include <iostream>
using std::cout;
using std::endl;

void display(void)
{
	cout << "display()" << endl;
}
 
int main(void)
{
	cout << "main start ...." << endl;
	atexit(display);
	atexit(display);
	atexit(display);

	cout << "main exit...." << endl;
	return 0;
}
