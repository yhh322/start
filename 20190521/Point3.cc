

#include <math.h>
#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{	cout << "Point(int,int)" << endl;	}

	~Point() {	cout << "~Point()" << endl;	}

#if 0
	operator int()
	{
		return _ix;
	}
#endif

	//explicit
	operator double()
	{
		cout << "operator double()" << endl;
		return sqrt(_ix * _ix + _iy * _iy);
	}

private:
	int _ix;
	int _iy;
};

int main(void)
{
	Point pt(1, 2);
	cout << "pt = " << pt << endl;

	return 0;
}
