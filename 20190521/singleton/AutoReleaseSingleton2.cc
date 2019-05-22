 ///
 /// @file    Singleton.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-21 11:27:15
 ///
 
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

//自动释放方法二: atexit + 静态方法
//
//atexit注册的函数指针，在程序退出时，会被自动调用

class Singleton
{
public:
	static Singleton * getInstance()
	{//在多线程环境下是非线程安全的
		//MutexLockGuard autoLock(mutex);// 加锁就可以
		if(_pInstance == nullptr) {
			_pInstance = new Singleton();
			atexit(destroy);
		}
		return _pInstance;
	}

	void print() const {	cout << "print()" << endl;	}	

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
};


//Singleton * Singleton::_pInstance = nullptr; //饿(懒加载)汉模式
//
//初始化, 有类作用域, 还是相当于在类内部
Singleton * Singleton::_pInstance = getInstance(); //饱汉模式

int main(void)
{
	Singleton * p = Singleton::getInstance();
	p->print();


	return 0;
}
