 ///
 /// @file    sizeof.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-20 11:27:35
 ///
 
#include <iostream>
using std::cout;
using std::endl;
 
int main(void)
{
	int number = 1;
	printf("sizeof(number) = %d\n", sizeof number);//编译时
	printf("sizeof(number) = %d\n", sizeof(int));
	cout << "sizeof(number) = " << (sizeof number) << endl;

	return 0;
}

