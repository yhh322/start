 ///
 /// @file    stackTemplate.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-28 14:59:24
 ///
 
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

template <typename Type, int kSize = 10>
class Stack
{
public:
	Stack()
	: _top(-1)
	, _data(new Type[kSize]())
	{}

	~Stack()
	{
		if(_data) {
			delete [] _data;
			cout << "~Stack()" << endl;	
		}
	}

	bool empty() const;
	bool full() const;
	void push(const Type & t);
	void pop();
	Type top();

private:
	int _top;
	Type * _data;
};
 
template <typename Type, int kSize>
bool Stack<Type, kSize>::empty() const
{
	return _top == -1;
}

template <typename Type, int kSize>
bool Stack<Type, kSize>::full() const
{
	return _top == kSize - 1;
}


template <typename Type, int kSize>
void Stack<Type, kSize>::push(const Type & t)
{
	if(!full()) {
		_data[++_top] = t;
	} else {
		cout << "stack is full, cannnot push any more data!" << endl;
	}
}


template <typename Type, int kSize>
void Stack<Type, kSize>::pop()
{
	if(!empty()) {
		--_top;
	} else {
		cout << "stack is empty, no more data!" << endl;
	}
}


template <typename Type, int kSize>
Type Stack<Type, kSize>::top()
{
	return _data[_top];
}

int test0(void)
{
	Stack<int> stack;
	cout << "此时栈是否为空? " << stack.empty() << endl;
	stack.push(1);
	cout << "此时栈是否为空? " << stack.empty() << endl;

	for(int idx = 2; idx != 12; ++idx) {
		stack.push(idx);
	}
	cout << "此时栈是否已满? " << stack.full() << endl;

	while(!stack.empty()) {
		cout << stack.top() << " ";
		stack.pop();
	}
	cout << endl;
	cout << "此时栈是否为空? " << stack.empty() << endl;

	return 0;
}

int main(void)
{
	Stack<string> stack;
	cout << "此时栈是否为空? " << stack.empty() << endl;
	stack.push("aaa");
	cout << "此时栈是否为空? " << stack.empty() << endl;

	for(int idx = 1; idx != 12; ++idx) {
		stack.push(string(3, 'a' + idx));
	}
	cout << "此时栈是否已满? " << stack.full() << endl;

	while(!stack.empty()) {
		cout << stack.top() << " ";
		stack.pop();
	}
	cout << endl;
	cout << "此时栈是否为空? " << stack.empty() << endl;

	return 0;
}
