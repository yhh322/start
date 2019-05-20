 ///
 /// @file    Complex.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-20 11:16:44
 ///
 
#include <iostream>
#include <limits>
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


int test0(void)
{
	int a = 1, b = 2;
	int c = a + b;

	Complex c1(1, 2);
	Complex c2(3, 4);

	Complex c3 = c1 + c2;
	c3.print();

	return 0;
}

void test1()
{
	int a = 1;
	cout << "a = " << a << endl;
	cout << "(++a) = "<<  (++a) << endl; 
	&(++a);//ok
	cout << "a = " << a << endl;

	cout << "(a++) = "<<  (a++) << endl;  //
	//&(a++);//error
	cout << "a = " << a << endl << endl;

	Complex c1(1, 2);
	cout << "c1 = ";
	c1.print();
	cout << "++c1 = ";
	(++c1).print();
	&(++c1);
	cout << "c1 = ";
	c1.print();
	cout << "c1++ = ";
	(c1++).print();
	cout << "c1 = ";
	c1.print();
}

void test2()
{
	int a = 1, b = 2;
	a += b;//a = a + b

	Complex c1(1, 2), c2(3, 4);
	cout << "c1 = ";
	c1.print();
	c1 += c2;
	cout << "c1 = ";
	c1.print();
}

void test3()
{
	int a = 1;
	cout << "a = " << a << endl;

	Complex c1(1, 2), c2(3, 4);
	cout << "c1 = " << c1 << endl
		 << "c2 = " << c2 << endl;//链式编程
	//operator<<(operator<<(cout, "c1 = "), c1);
}

void test4()
{
	cout << ">> pls input a interger number:" << endl;
	int a;
	std::cin >> a;

	Complex c1;
	std::cin >> c1;
	cout << "c1 = " << c1 << endl; 
}

int main(void)
{
	//test1();
	//test2();
	//test3();
	test4();
	return 0;
}
