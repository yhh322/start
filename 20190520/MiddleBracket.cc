 ///
 /// @file    MiddleBracket.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-20 15:19:21
 ///
 
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Buffer
{
public:
	Buffer(size_t sz)
	: _sz(sz)
	, _data(new char[_sz]())
	{
		cout << "Buffer(size_t) " << endl;
	}

	size_t size() const
	{	return strlen(_data);}

	size_t capacity() const 
	{	return _sz;	}

	//第二个参数可以是任意类型
	char & operator[](size_t idx) 
	{
		if(idx < capacity()) {
			return _data[idx];
		} else {
			static char nullchar = '\0';
			cout << ">> error 下标越界!!" << endl;
			return nullchar;
		}
	}

	~Buffer()
	{
		if(_data)
			delete [] _data;
	}
private:
	size_t _sz;
	char * _data;
};
 
int main(void)
{
	//vector<int> numbers;
	//numbers[0];
	std::string s1 = "hello,wrold";
	//const char * p1 = (const char *)&s1;//error 错误用法
	//cout << *p1 << endl;

	const char * pstr = "hello,world!"; 
	cout << "pstr = " << pstr << endl;
	Buffer buffer(20);
	size_t sz = strlen(pstr);
	for(size_t idx = 0; idx != sz; ++idx) {
		buffer[idx] = pstr[idx];
		//buffer.operator[](idx) = pstr[idx];
	}

	cout << "buffer中的数据是:";
	for(size_t idx = 0; idx != buffer.size(); ++idx) {
		cout << buffer[idx] << " ";
	}
	cout << endl;

	return 0;
}
