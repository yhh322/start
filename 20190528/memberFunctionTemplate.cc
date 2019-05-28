 ///
 /// @file    memberFunctionTemplate2.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-28 11:40:34
 ///
 
#include <iostream>
#include <vector>
#include <list>
using std::cout;
using std::endl;
using std::vector;
using std::list;

class Point
{
public:
	Point(double dx, double dy)
	: _dx(dx)
	, _dy(dy)
	{	cout << "Point(double,double)" << endl;	}

	template <typename T>
	T cast(T t) {
		return T(t * _dx);
	}

private:
	double _dx;
	double _dy;
};

class Data
{
public:
	Data(int sz)
	: _sz(sz)
	, _data(new int[_sz]())
	{
		cout << "Data(int)" << endl;
	}

	template <typename Iterator>
	Data(Iterator beg, Iterator end)
	: _sz(end - beg)
	, _data(new int[_sz]())
	{
		setData(beg, end);
	}

	//成员函数模板
	template <typename Iterator>
	void setData(Iterator beg, Iterator end)
	{
		int idx = 0;
		while(beg != end) {
			_data[idx] = *beg;
			++beg;
			++idx;
		}
	}

	~Data()
	{
		if(_data) {
			delete [] _data;
			cout << "~Data()" << endl;
		}
	}

	void print() const
	{
		for(int idx = 0; idx != _sz; ++idx) {
			cout << _data[idx] << " ";
		}
		cout << endl;
	}
private:
	int _sz;
	int * _data;
};
 
int test0(void)
{
	Point pt(1.11, 2.22);
	int a = 1;
	cout << pt.cast(a) << endl;

	return 0;
}

void test1()
{
	//int array[10] = {0, 1, 2, 3, 4,  5, 6, 7, 8, 9};
	vector<int> numbers {0, 1, 2, 3, 4,  5, 6, 7, 8, 9};
	std::list<int> numbers2 {0, 1, 2, 3, 4,  5, 6, 7, 8, 9};
	
	Data data(10);
	//data.setData(array, array + 10);
	//data.setData(numbers.begin(), numbers.end());
	data.setData(numbers2.begin(), numbers2.end());
	data.print();
}

void test2()
{
	vector<int> numbers {0, 1, 2, 3, 4,  5, 6, 7, 8, 9};
	//std::list<int> numbers2 {0, 1, 2, 3, 4,  5, 6, 7, 8, 9};
	Data data(numbers.begin(), numbers.end());
	data.print();
}

int main(void)
{
	//test1();
	test2();
	return 0;
}
