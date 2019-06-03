 ///
 /// @file    abuse.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-03 17:22:07
 ///
 
#include <iostream>
#include <memory>
using namespace std;
             
class Point
: public enable_shared_from_this<Point> //辅助类
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

	//Point * add(const Point & point)
	shared_ptr<Point> add(const Point & point)
	{//在成员函数内部获取本对象的shared_ptr对象
		_ix += point._ix;
		_iy += point._iy;
		//return shared_ptr<Point>(this);
		return shared_from_this();
	}

	~Point() {	cout << "~Point()" << endl;	}

private:
	int _ix;
	int _iy;
};

void test0()
{
	Point * pt = new Point(1, 2);
	unique_ptr<Point> up1(pt);
	//unique_ptr<Point> up2(pt);

	up1->print();
	//up2->print();
}
 
void test1()
{
	Point * pt = new Point(1, 2);
	shared_ptr<Point> sp1(pt);
	//shared_ptr<Point> sp2(pt);

	sp1->print();
	//sp2->print();
}

void test2()
{	//一个对象交给一个智能指针进行托管之后，都要用智能指针
	//操作原始的对象
	shared_ptr<Point> sp1(new Point(1, 2));
	shared_ptr<Point> sp2(new Point(3, 4));

	shared_ptr<Point> sp3(sp1->add(*sp2));
	sp3->print();
}

void test3()
{
	shared_ptr<Point> sp1(new Point(1, 2));
	shared_ptr<Point> sp2(new Point(3, 4));
	
	sp2.reset(sp1.get());//不要使用
}



int main(void)
{
	//test0();
	test2();
	//test3();
	return 0;
}
