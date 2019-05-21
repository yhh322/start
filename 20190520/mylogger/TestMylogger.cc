 ///
 /// @file    TestMylogger.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-20 10:00:32
 ///
 
#include "Mylogger.h"
#include <iostream>
#include <sstream>
using std::cout;
using std::endl;
using std::string;

//string int2str(int number) {
//	  std::ostringstream oss;
//	  oss << number;
//	  return oss.str();
//}


void test0()
{
	wd::Mylogger::getInstance()->error("error message");
	wd::Mylogger::getInstance()->info("info message");
	wd::Mylogger::getInstance()->warn("warn message");
	wd::Mylogger::getInstance()->debug("debug message");
}

void test2()
{
	wd::Mylogger::getInstance()->error(prefix("error message").c_str());
}

void test3()
{
	LogError("error message");
	LogInfo("Info message");
	LogWarn("Warn message");
	LogDebug("Debug message");
}

void test4()
{
	int number = 1;
	const char * p = "hello,world";

	LogError("error message");
	LogError("error message, %d, %s", number, p);
}

void test1()
{
	//编译器提供的内置宏定义, 定位信息
	cout << __FILE__ << endl
		 << __FUNCTION__ << endl
		 << __LINE__ << endl;
}
 
int main(void)
{
	//test0();
	//test1();
	//test2();
	//test3();
	test4();

	wd::Mylogger::destroy();
	return 0;
}
