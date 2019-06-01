 ///
 /// @file    TemplateSingleton.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-01 09:59:49
 ///
 
#include <iostream>
using namespace std;



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

	~Point() {	cout << "~Point()" << endl;}

private:
	int _ix;
	int _iy;
};

template <class T>
class Singleton
{
public:
	class AutoRelease
	{
	public:
		AutoRelease() {	cout << "AutoRelease()" << endl;	}
		~AutoRelease()
		{
			if(_pInstance)	
				delete _pInstance;

			cout << "~AutoRelease()" << endl;
		}
	};

	template <class... Args>
	static T * getInstance(Args... args)
	{
		if(nullptr == _pInstance) {
			_pInstance = new T(args...);
			(void)_auto;//必须要加，不加的话，_auto对象无法推导
		}
		return _pInstance;
	}

private:
	Singleton() {}
	~Singleton() {}

private:
	static T * _pInstance;
	static AutoRelease _auto;
};

template <class T>
T * Singleton<T>::_pInstance = nullptr;

template <class T>
class Singleton<T>::AutoRelease Singleton<T>::_auto;
             
 
int main(void)
{
	//Point pt(1, 2);
	//Point * p1 = Singleton<Point>::getInstance(pt);
	
	Point * p1 = Singleton<Point>::getInstance(1, 2);
	Point * p2 = Singleton<Point>::getInstance(1, 2);
	p1->print();
	p2->print();
	cout << "p1 = " << p1 << endl;
	cout << "p2 = " << p2 << endl;


	return 0;
}
