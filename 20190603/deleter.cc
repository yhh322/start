 ///
 /// @file    deleter.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-03 17:13:50
 ///

 
#include <stdio.h>
#include <iostream>
#include <memory>
using namespace std;

struct FileCloser
{
	void operator()(FILE * fp) const
	{
		if(fp) {
			fclose(fp);
			cout << ">> fclose(fp) " << endl;
		}
	}
};

void test0()
{
	unique_ptr<FILE, FileCloser> up(fopen("test.txt", "a+"));
	string msg("this is a new line\n");
	fwrite(msg.c_str(), 1, msg.size(), up.get());
}

void test1()
{
	shared_ptr<FILE> sp(fopen("test.txt", "a+"), FileCloser());
	string msg("this is a new line\n");
	fwrite(msg.c_str(), 1, msg.size(), sp.get());
}
 
int main(void)
{
	//test0();
	test1();
	return 0;
}
