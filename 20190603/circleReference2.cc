 ///
 /// @file    circleReference.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-03 16:18:48
 ///
 
#include <iostream>
#include <memory>
using namespace std;


class Parent;
class Child
{
public:
	Child() {	cout << "Child()" << endl;	}
	~Child(){	cout << "~Child()" <<endl;	}

	weak_ptr<Parent> _pParent;
};
             
class Parent 
{
public:
	Parent() {	cout << "Parent()" << endl;	}
	~Parent(){	cout << "~Parent()" <<endl;	}

	shared_ptr<Child> _pChild;
};
 
int main(void)
{
	//weak_ptr与shared_ptr联合使用，可以解决循环引用的问题
	shared_ptr<Parent> pParent(new Parent());
	shared_ptr<Child> pChild(new Child());

	cout << "pParent's use_count= " << pParent.use_count() << endl;
	cout << "pChild's use_count= " << pChild.use_count() << endl;

	pParent->_pChild = pChild;//weak_ptr = shared_ptr, 不会导致引用计数加1
	pChild->_pParent = pParent;//shared_ptr = shared_ptr， 引用计数加1
	cout << "pParent's use_count= " << pParent.use_count() << endl;
	cout << "pChild's use_count= " << pChild.use_count() << endl;

	return 0;
}
