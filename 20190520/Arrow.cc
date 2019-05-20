 ///
 /// @file    Arrow.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-20 16:36:31
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Data
{
public:
	Data(int ix = 0)
	: _ix(ix)
	{	cout << "Data(int=0)" << endl;}

	int ix() const {	return _ix;	}

	~Data() {	cout << "~Data()" << endl;	}

private:
	int _ix;
};

class MiddleLayer
{
public:
	MiddleLayer(Data * pdata)
	: _pdata(pdata)
	{	cout << "MiddleLayer()" << endl;	}

	//指针访问运算符
	Data * operator->()
	{	return _pdata;	}

	//解引用运算符
	Data & operator*()
	{	return *_pdata;	}

	~MiddleLayer()
	{	
		cout << "~MiddleLayer()" << endl;
		if(_pdata) 
			delete _pdata;
	}

private:
	Data * _pdata;
};

class ThridLayer
{
public:
	ThridLayer(MiddleLayer * ml)
	: _ml(ml)
	{	cout << "ThridLayer()" << endl;	}

	MiddleLayer & operator->()
	{	return *_ml;	}

	~ThridLayer() {	cout << "~ThridLayer()" << endl;	}

private:
	MiddleLayer * _ml;
};
 
int test0(void)
{
	MiddleLayer ml(new Data(10));
	cout << ml->ix() << endl;
	cout << ml.operator->()->ix() << endl;
	cout << endl;

	ThridLayer tl(new MiddleLayer(new Data(11)));
	cout << tl->ix() << endl;
	cout << tl.operator->().operator->()->ix() << endl;

	return 0;
}

void test1()
{
	//智能指针的雏形
	MiddleLayer pData(new Data(10));
	pData->ix();
	(*pData).ix();
}

int main(void)
{
	test1();
	return 0;
}
