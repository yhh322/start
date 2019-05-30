 ///
 /// @file    unordered_set.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-30 10:00:08
 ///
 
#include <cmath>
#include <iostream>
#include <unordered_set>
using std::cout;
using std::endl;
using std::unordered_set;


class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{	cout << "Point(int,int)" << endl;	}

	float getDistance() const
	{
		return sqrt(_ix * _ix + _iy * _iy);
	}

	int getX() const {	return _ix;	}
	int getY() const {	return _iy;	}

	friend std::ostream & operator<<(std::ostream &os, const Point & rhs);
private:
	int _ix;
	int _iy;
};

std::ostream & operator<<(std::ostream &os, const Point & rhs)
{
	os << "(" << rhs._ix
	   << "," << rhs._iy
	   << ")";
	return os;
}


#if 0
bool operator<(const Point & lhs, const Point & rhs)
{
	return lhs.getDistance() < rhs.getDistance();
}

bool operator>(const Point & lhs, const Point & rhs)
{
	return lhs.getDistance() > rhs.getDistance();
}
#endif

struct PointComparator
{
	bool operator()(const Point & lhs, const Point & rhs)
	{
		return lhs.getDistance() > rhs.getDistance();
	}
};

bool operator==(const Point & lhs, const Point & rhs) 
{
	return (lhs.getX() == rhs.getX()) && 
		   (lhs.getY() == rhs.getY());
}

namespace std
{
template <>
struct hash<Point>
{
	size_t operator()(const Point & rhs) const
	{
		return ((rhs.getX() * rhs.getX()) >> 1) ^
				(rhs.getY() * rhs.getY() >> 1);
	}
};

}//end of namespace std

struct PointHasher
{
	size_t operator()(const Point & rhs) const
	{
		return ((rhs.getX() * rhs.getX()) >> 1) ^
				(rhs.getY() * rhs.getY() >> 1);
	}
};

struct PointEqual
{
	bool operator()(const Point & lhs, const Point & rhs) const
	{
		return (lhs.getX() == rhs.getX()) && 
			   (lhs.getY() == rhs.getY());
	}
};


void test0()
{
	//不能存放关键字相同的元素
	//
	//基本上可以以O(1)的时间复杂度操作元素,
	//但同时是以牺牲空间来达到提升时间复杂度效率
	//
	//以空间换时间 (有一半的空间是没有利用上的)
	//
	//unordered_set<Point> points{
	unordered_set<Point, PointHasher, PointEqual> points{
		Point(1, 2),
		Point(1, 2),
		Point(3, 4),
		Point(5, 6),
		Point(-1, 2),
		Point(7, 8)
	};

	auto it = points.begin();
	for(; it != points.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	//添加元素
	//时间复杂度为O(1)
	auto ret = points.insert(Point(-1, 4));
	if(ret.second) {
		cout << "添加成功!" << endl;
		cout << *ret.first << endl;
	} else {
		cout << "添加失败!" << endl;
		cout << *ret.first << endl;
	}
}

 
int main(void)
{
	test0();
	return 0;
}
