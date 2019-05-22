 ///
 /// @file    cowString.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-21 16:03:35
 ///
 
#include <string.h>

#include <iostream>
using std::cout;
using std::endl;

class CowString
{
	class CharProxy
	{
	public:
		CharProxy(int idx, CowString & self)
		: _idx(idx)
		, _self(self)
		{}

		char & operator=(const char & ch);
		
		friend std::ostream & operator<<(std::ostream & os, const CharProxy & rhs);
	
	private:
		int _idx;
		CowString & _self;
	};
	friend std::ostream & operator<<(std::ostream & os, const CharProxy & rhs);
public:
	CowString();
	CowString(const char * pstr);
	CowString(const CowString & rhs);
	CowString & operator=(const CowString & rhs);
	~CowString();

	const char * c_str() const {	return _pstr;	}
	int size() const {	return strlen(_pstr);	}
	int refcount() const {	return *((int*)(_pstr - 4));	}

	CharProxy operator[](int idx);
	const char & operator[](int idx) const {	return _pstr[idx];	}

	//char & operator[](int idx);

	friend std::ostream & operator<<(std::ostream & os, const CowString & rhs);


private://inline
	void initRefcount() {	*((int*)(_pstr - 4)) = 1; }
	void increaseRefcount() {	++*((int*)(_pstr - 4));	}
	void decreaseRefcount() {	--*((int*)(_pstr - 4)); }
	void release() 
	{
		decreaseRefcount();
		if(refcount() == 0) {
			delete [] (_pstr - 4);
			cout << ">>> delete data!" << endl;
		}
	}

private:
	char * _pstr;//_pstr永远指向字符串的第一个元素
};

CowString::CowString()
: _pstr(new char[1 + 4]() + 4)
{
	cout << "CowString()" << endl;
	initRefcount();
}

CowString::CowString(const char * pstr)
: _pstr(new char[strlen(pstr) + 5]() + 4)
{
	initRefcount();
	strcpy(_pstr, pstr);
	cout << "CowString(const char * )" << endl;
}

CowString::CowString(const CowString & rhs)
: _pstr(rhs._pstr)
{
	cout << "CowString(const CowString &)" << endl;
	increaseRefcount();
}

CowString & CowString::operator=(const CowString & rhs)
{
	cout << "CowString & operator=(const CowString &)" << endl;
	if(this != & rhs) {
		release();

		_pstr = rhs._pstr;
		increaseRefcount();
	}
	return *this;
}

CowString::~CowString()
{
	release();
}

CowString::CharProxy CowString::operator[](int idx)
{
	return CharProxy(idx, *this);
}
 
char & CowString::CharProxy::operator=(const char & ch)
{
	int sz = _self.size();
	if(_idx >= 0 && _idx < sz) {
		if(_self.refcount() > 1) {
			//执行深拷贝
			_self.decreaseRefcount();

			char * ptmp = new char[sz + 5]() + 4;
			strcpy(ptmp, _self._pstr);
			_self._pstr = ptmp;
			_self.initRefcount();
		}
		_self._pstr[_idx] = ch;
		return _self._pstr[_idx];
	}else {
		cout << "下标越界!" << endl;
		static char nullchar = '\0';
		return nullchar;
	}
}

std::ostream & operator<<(std::ostream & os, const CowString::CharProxy & rhs)
{
	os << rhs._self._pstr[rhs._idx];
	return os;
}

std::ostream & operator<<(std::ostream & os, const CowString & rhs)
{
	os << rhs._pstr;
	return os;
}

int main(void)
{
	CowString s0;
	cout << "s0 = " << s0 << endl;

	CowString s1("hello,world");
	CowString s2(s1);

	CowString s3("shenzhen");
	s3[0] = 'S';//refcount = 1

	s3 = s2;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	printf("s1's address: %p\n", s1.c_str());
	printf("s2's address: %p\n", s2.c_str());
	printf("s3's address: %p\n", s3.c_str());
	cout << "s1's refcount() = " << s1.refcount() << endl;
	cout << "s2's refcount() = " << s2.refcount() << endl;
	cout << "s3's refcount() = " << s3.refcount() << endl;

	cout << endl << ">>> 执行s1[0] = 'x' 之后:" << endl; 
	s1[0] = 'x';
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	printf("s1's address: %p\n", s1.c_str());
	printf("s2's address: %p\n", s2.c_str());
	printf("s3's address: %p\n", s3.c_str());
	cout << "s1's refcount() = " << s1.refcount() << endl;
	cout << "s2's refcount() = " << s2.refcount() << endl;
	cout << "s3's refcount() = " << s3.refcount() << endl;
	//&s1[0];
	//s1[0] =  (s2[0]  = 'x');

	cout << endl << ">>> 执行 cout << s2[0] << endl 之后:" << endl; 
	cout << "s2[0] == " << s2[0] << endl;// 在这里不应该进行深拷贝
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	printf("s1's address: %p\n", s1.c_str());
	printf("s2's address: %p\n", s2.c_str());
	printf("s3's address: %p\n", s3.c_str());
	cout << "s1's refcount() = " << s1.refcount() << endl;
	cout << "s2's refcount() = " << s2.refcount() << endl;
	cout << "s3's refcount() = " << s3.refcount() << endl;

	return 0;
}
