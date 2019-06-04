 ///
 /// @file    Queue.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-01 09:36:52
 ///
 
#include <iostream>
using namespace std;

template <class T, int kSize = 10>
class Queue
{
public:
	Queue()
	: _front(0)
	, _rear(0)
	, _data(new T[kSize]())
	{ }

	bool empty() const
	{	return _front == _rear;	}

	bool full() const
	{
		return _front == (_rear + 1) % kSize;
	}

	void push(const T & t) 
	{
		if(!full()) {
			_data[_rear++] = t;
			_rear %= kSize;
		} else {
			cout << "queue is full, cannot push any more data!" << endl;
		}
	}

	void pop()
	{
		if(!empty()) {
			++_front;
			_front %= kSize;
		} else {
			cout << "queue is empty." << endl;
		}
	}

	T & front() 
	{	
		cout << "_front = " << _front << endl;
		return _data[_front];	
	}

	T & back()
	{	
		cout << "_rear = " << _rear << endl;
		return _data[(_rear - 1 + kSize) % kSize];	
	
	}

private:
	int _front;
	int _rear;
	T * _data;
};
             
 
int main(void)
{
	Queue<int> que;
	cout << "队列是否为空? " << que.empty() << endl;
	que.push(1);
	cout << "队列是否为空? " << que.empty() << endl;

	for(int idx = 2; idx != 12; ++idx) {
		que.push(idx);
	}
	cout << "队列是否已满? " << que.full() << endl;
	
	que.pop();
	que.push(10);
	cout << "队头的元素: " << que.front() << endl
		 << "队尾的元素:" << que.back() << endl;


	while(!que.empty()) {
		cout << que.front() << " ";
		que.pop();
	}
	cout << "队列是否为空? " << que.empty() << endl;
	return 0;
}
