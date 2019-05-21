 ///
 /// @file    AutoReleaseSingleton3.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-21 14:47:31
 ///
 
#include <pthread.h>
#include <iostream>
using std::cout;
using std::endl;

//单例对象自动释放方法三: atexit + pthread_once
 
class Singleton
{
public:
	static Singleton * getInstance()
	{
		pthread_once(&_once, init);
		return _pInstance;
	}

	void print() const {	cout << "print()" << endl;	}	

	static void init()
	{
		_pInstance = new Singleton();
		::atexit(destroy);
	}

	static void destroy()
	{
		if(_pInstance)
			delete _pInstance;
	}

private:
	Singleton() {	cout << "Singleton()" << endl;	}
	~Singleton() {	cout << "~Singleton()" << endl;	}

	friend class AutoRelease;
private:
	static Singleton * _pInstance;
	static pthread_once_t _once;
};

Singleton * Singleton::_pInstance = nullptr;
pthread_once_t Singleton::_once = PTHREAD_ONCE_INIT;

int main(void)
{
	Singleton * p = Singleton::getInstance();
	p->print();
	return 0;
}

