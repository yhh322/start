 ///
 /// @file    shared_ptr.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-03 15:15:07
 ///
 
#include <iostream>
#include <memory>
#include <vector>
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


shared_ptr<Point> getPoint()
{
	shared_ptr<Point> point(new Point(3, 4));
	return point;
}

 
int main(void)
{
	Point * pt = new Point(1, 2);
	shared_ptr<Point> ap(pt);
	cout << "ap's get = " << ap.get() << endl;
	cout << "pt = " << pt << endl;

	ap->print();
	(*ap).print();

	shared_ptr<Point> ap2(ap);//进行复制或者赋值, 将引用计数的值加1
	{
	shared_ptr<Point> ap3 = ap; //左值
	
	cout << "ap3's get = " << ap3.get() << endl;
	cout << "ap3's use_count : " << ap3.use_count() << endl;
	cout << "ap2's get = " << ap2.get() << endl;
	cout << "ap2's use_count : " << ap2.use_count() << endl;
	}//当一个共享对象被销毁时，将引用计数减1；直到引用计数为0时，才
	//真正回收堆空间的数据
	cout << "退出语句块:" << endl;
	cout << "ap2's get = " << ap2.get() << endl;
	cout << "ap2's use_count : " << ap2.use_count() << endl;
	//shared_ptr具有移动语义的
	shared_ptr<Point> up = getPoint();//调用移动构造函数
	cout << "....." << endl;
	up = ap;
	cout << "up's get = " << up.get() << endl;
	cout << "up's use_count : " << up.use_count() << endl;

#if 1
	//shared_ptr可以作为容器的元素存在
	vector<shared_ptr<Point>> points;
	points.push_back(shared_ptr<Point>(new Point(3, 4)));
	points.push_back(shared_ptr<Point>(new Point(3, 4)));
	points.push_back(shared_ptr<Point>(new Point(3, 4)));

	points.push_back(ap);
	points.push_back(up);

#endif
	return 0;
}
