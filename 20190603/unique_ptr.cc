 ///
 /// @file    unique_ptr.cc
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


unique_ptr<Point> getPoint()
{
	unique_ptr<Point> point(new Point(3, 4));
	return point;
}

 
int main(void)
{
#if 1
	Point * pt = new Point(1, 2);
	unique_ptr<Point> ap(pt);
	cout << "ap's get = " << ap.get() << endl;
	cout << "pt = " << pt << endl;

	ap->print();
	(*ap).print();

	//unique_ptr<Point> ap2(ap);//不能进行复制或者赋值
	//unique_ptr<Point> ap2 = ap; //左值

	//unique_ptr具有移动语义的
	unique_ptr<Point> up = getPoint();//调用移动构造函数
	cout << "....." << endl;
#endif

	//unique_ptr可以作为容器的元素存在
	vector<unique_ptr<Point>> points;
	points.push_back(unique_ptr<Point>(new Point(3, 4)));
	points.push_back(unique_ptr<Point>(new Point(3, 4)));
	points.push_back(unique_ptr<Point>(new Point(3, 4)));

	points.push_back(std::move(ap));//ap,up是有名对象，左值
	points.push_back(std::move(up));

	return 0;
}
