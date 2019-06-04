 ///
 /// @file    RAII.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-03 15:05:04
 ///
 
#include <iostream>
using namespace std;
             

template <class T>
class RAII
{
public:
	RAII(T * data)
	: _data(data)
	{}

	T * operator->()
	{	return _data;	}

	T & operator*()
	{	return *_data;	}

	T * get() {	return _data;	}

	void reset(T * data) 
	{
		if(_data)
			delete _data;
		_data = data;
	}

	~RAII()
	{
		if(_data) {
			delete _data;
			cout << ">> delete heap data!" << endl;
		}
	}

private:
	T * _data;
};

class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{	cout << "Point(int,int)" << endl;	}

	void print() const
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}

	~Point() {	cout << "~Point()" << endl;	}

private:
	int _ix;
	int _iy;
};
 
int main(void)
{
	Point * pt = new Point(3, 4);
	pt->print();
	(*pt).print();
	delete pt;
	cout << endl;

	RAII<Point> p(new Point(1, 2));
	p->print();
	(*p).print();

	p.reset(new Point(5, 6));
	p->print();
	(*p).print();


	return 0;
}
