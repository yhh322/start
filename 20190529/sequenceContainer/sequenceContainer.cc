 ///
 /// @file    sequenceContainer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-29 09:53:18
 ///
 
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{	cout << "Point(int,int)" << endl;	}

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

template <typename Container>
void display(const Container & c)
{
	for(auto & elem : c) { //& 不可少，如果没加，就会复制的
		cout << elem << " ";
	}
	cout << endl;
}
	
 
int main(void)
{
	vector<Point> points(10, Point(1, 2));
	display(points);

	return 0;
}
