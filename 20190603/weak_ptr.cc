 ///
 /// @file    weak_ptr.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-03 16:41:22
 ///
 
#include <iostream>
#include <memory>
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

	~Point() {	cout << "~Point()" << endl;	}

private:
	int _ix;
	int _iy;
};

void test0()
{
	weak_ptr<Point> wp;
	
	{
		shared_ptr<Point> sp(new Point(1, 2));
		wp = sp;//不会导致引用计数加1

		cout << "wp's use_count = " << wp.use_count() << endl;
		cout << "sp's use_count = " << sp.use_count() << endl;
		//weak_ptr其所托管的对象是否还存活
		cout << "wp's expired = " << wp.expired() << endl;//没有到期

		shared_ptr<Point> sp2 = wp.lock();//对weak_ptr进行提升
		if(sp2) {
			cout << "wp提升成功!" << endl;
			sp2->print();
		} else {
			cout << "wp提升失败!" << endl;
			//sp2->print();
		}
	}

	cout << endl << "退出语句块:" << endl;
	cout << "wp's expired = " << wp.expired() << endl;//对象已经被销毁，到期

	//weak_ptr内部没有提供访问资源的方法,必须要提升成shared_ptr才能访问
	shared_ptr<Point> sp2 = wp.lock();//对weak_ptr进行提升
	if(sp2) {
		cout << "wp提升成功!" << endl;
		sp2->print();
	} else {
		cout << "wp提升失败!" << endl;
		//sp2->print();
	}

	cout << ">> sp3: " << endl;
	shared_ptr<Point> sp3;
	sp3->print();
}
             
 
int main(void)
{
	test0();
	return 0;
}
