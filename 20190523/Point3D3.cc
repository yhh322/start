 ///
 /// @file    Point3D.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-23 09:49:42
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{	cout << "Point(int,int)" << endl;}

	void print() const 
	{	
		cout << "(" << _ix
			 << "," << _iy 
			 << ")" << endl;	
	}

	int getY() const {	return _iy;	}

protected://在派生类内部可以直接访问
	int _ix;
private:
	int _iy;
};

class Point3D
: private Point  
{
public:
	Point3D(int ix, int iy, int iz)
	: Point(ix, iy)
	, _iz(iz)
	{
		cout << "Point3D(int,int,int)" << endl;
	}

	void display() const	 //private  print() 
	{						 //private getY() 
		cout << "(" << _ix	 //private 对于基类的非私有成员，无论采用哪种方式继承，都可以在派生类中直接访问, 
			 << "," << getY()// _iy   //对于基类的私有成员，无论采用哪种方式继承，都不能直接在派生类中访问
			 << "," << _iz
			 << ")" << endl;
	}

private:
	int _iz;
};


class Point4D
: public Point3D
{
public:

	void show() const
	{
		print();//error
		cout << _ix;//error
	}


};
 
int main(void)
{
	Point pt0(11, 12);
	//pt0._ix;//error

	Point3D pt(1, 2, 3);
	pt.display();
	//pt._ix;//error
	//pt.print();//private 对于派生类对象而言，只能在采用public继承时，才能访问基类的public成员
	//cout << pt.getY() << endl;//private

	return 0;
}
