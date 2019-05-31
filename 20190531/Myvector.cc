 ///
 /// @file    Myvector.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-31 11:08:25
 ///
 
#include <iostream>
#include <memory>
using namespace std;

template <typename T>
class Myvector
{
public:
	typedef T value_type;
	typedef T * pointer;
	typedef T * iterator;
	typedef const T * const_iterator;

	Myvector()
	: _start(nullptr)
	, _finish(nullptr)
	, _end_of_storage(nullptr)
	{}

	size_t size() const
	{	return _finish - _start;	}
	size_t capacity() const
	{	return _end_of_storage - _start;	}

	void push_back(const T & t);
	void pop_back();

	const_iterator begin() const
	{	return _start;	}
	const_iterator end() const
	{	return _finish;	}

	T & operator[](size_t idx) const
	{	return _start[idx];	}

private:
	void reallocate();

private:
	static allocator<T> _alloc;
	T * _start;
	T * _finish;
	T * _end_of_storage;
};

template <typename T>
allocator<T> Myvector<T>::_alloc; 

template <typename T>
void Myvector<T>::push_back(const T & t)
{
	if(size() == capacity()) {
		reallocate();
	}
	
	_alloc.construct(_finish++, t);//对象的构造
}

template <typename T>
void Myvector<T>::pop_back()
{
	if(size() > 0) {
		_alloc.destroy(--_finish);
	}
}

template <typename T>
void Myvector<T>::reallocate()
{
	size_t oldSpace = capacity();
	size_t newSpace = 2 * oldSpace > 0? 2 * oldSpace : 1;

	T * ptmp = _alloc.allocate(newSpace);//开辟未类型化的新空间, 没有对象
	if(_start) {
		//copy();// 调用赋值运算符
		uninitialized_copy(_start, _finish, ptmp);
		
		while(_finish != _start) {
			_alloc.destroy(--_finish);
		}
		_alloc.deallocate(_start, oldSpace);
	}

	_start = ptmp;
	_finish = _start + oldSpace;
	_end_of_storage = _start + newSpace;
}

template <typename Container>
void display(const Container & c)
{
	typename Container::const_iterator it = c.begin();
	while(it != c.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;

	cout << "c' size = " << c.size() << endl
		 << "c' capacity = " << c.capacity() << endl;
}

             
 
int main(void)
{
	Myvector<int> numbers;
	display(numbers);

	for(int idx = 0; idx != 10; ++idx)
	{
		numbers.push_back(idx);
		display(numbers);
	}
	
	cout << "numbers[6] = " << numbers[6] << endl;


	return 0;
}
