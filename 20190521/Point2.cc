 ///
 /// @file    Point.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-21 10:04:29
 ///
 
#include <math.h>
#include <limits>
#include <iostream>
using std::cout;
using std::endl;

class Complex
{
public:
	Complex(double real = 0, double image = 0)
	: _real(real)
	, _image(image)
	{}

	void print() const
	{
		cout << _real << " + " << _image << "i" << endl;
	}

	double getReal() const {	return _real;	}	
	double getImage() const {	return _image;	}	

	//前置效率更高
	//返回值必须使用引用
	Complex & operator++()//前置形式
	{
		++_real;
		++_image;
		return *this;
	}

	//返回值是对象
	Complex operator++(int) //后置形式, int只是用来作为标记，与前置形式区分
	{
		Complex tmp(*this);
		++_real;
		++_image;
		return tmp;
	}

	//对象本身的值发生变化
	//复合赋值运算符
	Complex & operator+=(const Complex & rhs)
	{
		_real += rhs._real;
		_image += rhs._image;
		return *this;
	}

	//std::ostream operator<<();

	//friend Complex operator+(const Complex & lhs, const Complex & rhs);
	
	friend bool operator==(const Complex & lhs, const Complex & rhs);
	friend std::ostream & operator<<(std::ostream & os, const Complex & rhs);
	friend std::istream & operator>>(std::istream & is, Complex & rhs);
private:
	double _real;
	double _image;// -1 = i ^ 2
};

//内置类型数据的运算符无法重载
//int operator+(int x, int y)
//{
//	return x - y;
//}

//运算符重载之友元函数
Complex operator+(const Complex & lhs, const Complex & rhs)
{
	cout << "friend Complex operator+()" << endl;
	//return Complex(lhs._real + rhs._real, 
	//		       lhs._image + rhs._image);
	Complex tmp(lhs);
	tmp += rhs;//充分的利用已经实现的函数
	return tmp;
}

bool operator==(const Complex & lhs, const Complex & rhs)
{
	return (lhs._real == rhs._real &&
		    lhs._image == rhs._image);
}

bool operator!=(const Complex & lhs, const Complex & rhs)
{
	return !(lhs == rhs);//充分的利用已经实现的函数
}

//所有的流对象都是不能进行复制的, 表达的是对象语义
std::ostream & operator<<(std::ostream & os, const Complex & rhs)
{
	cout << rhs._real << " + " << rhs._image << "i" << endl;
	return os;
}

void readDouble(std::istream & is, double & value) 
{
	cout << ">> pls input a valid double number:" << endl;
	while(is >> value, !is.eof()) {
		if(is.bad()) {
			cout << "istream is corrupted!" << endl;
			return;
		} else if (is.fail()) {
			is.clear();
			is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ">> pls input a valid double number:" << endl;
			continue;
		}
		break;
	}
}

std::istream & operator>>(std::istream & is, Complex & rhs)
{	//对异常情况做处理
	//培养思维的完备性
	readDouble(is, rhs._real);
	readDouble(is, rhs._image);
	return is;
}

class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{	cout << "Point(int,int)" << endl;	}

	~Point() {	cout << "~Point()" << endl;	}

	//explicit
	Point(const Complex & rhs)
	: _ix(rhs.getReal())
	, _iy(rhs.getImage())
	{}


	//类型转换函数
	//
	//以成员函数形式出现
	//
	//函数形式: 
	//	1. 没有返回值'
	//  2. 没有参数
	//  3. 在函数体内必须以return 语句返回一个目标类型的对象
	//
	//该函数尽量少使用(不走寻常路), 违反常规思维
	//
	operator int()
	{
		return _ix * _iy;
	}

	operator double()
	{
		return sqrt(_ix * _ix + _iy * _iy);
	}

	operator Complex()
	{
		return Complex(_ix, _iy);
	}

	friend std::ostream & operator<<(std::ostream & os, const Point & rhs);

private:
	int _ix;
	int _iy;
};

std::ostream & operator<<(std::ostream & os, const Point & rhs)
{
	os << "(" << rhs._ix
	   << "," << rhs._iy
	   << ")";
	return os;
}
 
int test0(void)
{
	Point pt(1, 2);
	cout << "pt = " << pt << endl;

	Complex c1(3, 4);
	cout << "c1 = " << c1 << endl;

	pt = 11;
	cout << "pt = " << pt << endl;
	
	cout << endl << "执行pt = c1之后:" << endl;
	//由其他类型向自定义类型转换, 通过构造函数完成
	pt = c1;//Point = Complex
	cout << "pt = " << pt << endl;

	return 0;
}

void test1()
{
	Point pt(1, 2);
	//自定义类型向其他类型转换
	int x = pt;
	cout << "x = " << x << endl;
	double y = pt;//
	cout << "y = " << y << endl;
	Complex c = pt;
	cout << "c = " << c << endl;

}

int main(void)
{
	test1();
	return 0;
}
