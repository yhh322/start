 ///
 /// @file    Point.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-20 10:58:05
 ///
 
#include <math.h>
#include <iostream>
using std::cout;
using std::endl;

class Point; //类的前向声明
class Line
{
public:
	double distance(const Point & lhs, const Point & rhs);
	void setPoint(Point & pt, int ix, int iy);

private:
	int _iz;
};

class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	,_iy(iy)
	{
		cout << "Point(int,int)" << endl;
	}

	void print() const 
	{	
		cout << "(" << _ix 
			 << "," << _iy
			 << ")" << endl;
	}

	//友元关系是单向的, 不具备传递性, 不能被继承
	void setZ(Line & line, int z)
	{
		line._iz = z;//error
	}

	//友元之友元类
	friend Line;
private:
	int _ix;
	int _iy;
};

double Line::distance(const Point & lhs, const Point & rhs)
{
	return sqrt((lhs._ix - rhs._ix) * (lhs._ix - rhs._ix) +
				(lhs._iy - rhs._iy) * (lhs._iy - rhs._iy));
}
 
void Line::setPoint(Point & pt, int ix, int iy)
{
	pt._ix = ix;
	pt._iy = iy;
}

int main(void)
{
	Point pt(1, 2);
	pt.print();
	cout << " ---> ";
	Point pt2(11, 12);
	pt2.print();
	cout << Line().distance(pt, pt2) << endl;//临时对象
	return 0;
}
