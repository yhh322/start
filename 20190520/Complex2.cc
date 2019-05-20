 ///
 /// @file    Complex.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-20 11:16:44
 ///
 
#include <iostream>
using std::cout;
using std::endl;

// <<重温微积分>>
// <<随机过程>>
// <<矩阵论>>
// <<机器学习>>
// <<计算理论>>
class Complex
{
public:
	Complex(double real, double image)
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

	//friend Complex operator+(const Complex & lhs, const Complex & rhs);
	
	friend bool operator==(const Complex & lhs, const Complex & rhs);
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

int main(void)
{
	//test1();
	test2();
	return 0;
}
