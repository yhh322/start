 ///
 /// @file    inserter_iterator.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-30 15:04:26
 ///
 
#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <set>
#include <unordered_set>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::set;
using std::copy;
using std::unordered_set;
using std::ostream_iterator;
using std::back_insert_iterator;// vector/list/deque  调用push_back
using std::front_insert_iterator;// list/deque  调用push_front
using std::insert_iterator;// 调用的是insert方法, 适用的容器更多
 
int main(void)
{
	vector<int> numbers1{1, 2, 3, 4 ,5};
	list<int> numbers2{11, 12, 13};
	copy(numbers1.begin(), numbers1.end(),
		back_insert_iterator<list<int>>(numbers2));
	copy(numbers2.begin(), numbers2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	copy(numbers1.begin(), numbers1.end(),
		front_insert_iterator<list<int>>(numbers2));
	copy(numbers2.begin(), numbers2.end(), ostream_iterator<int>(cout, " "));

	set<int> numbers3{22, 23, 24,25};
	auto it = numbers3.begin();
	++it;

	cout << endl;
	copy(numbers1.begin(), numbers1.end(), 
		insert_iterator<set<int>>(numbers3, it));
	copy(numbers3.begin(), numbers3.end(), ostream_iterator<int>(cout, " "));
	cout << endl;


	unordered_set<int> numbers4{22, 23, 24,25};
	auto it4 = numbers4.begin();
	++it4;

	cout << endl;
	copy(numbers1.begin(), numbers1.end(), 
		insert_iterator<unordered_set<int>>(numbers4, it4));
	copy(numbers4.begin(), numbers4.end(), ostream_iterator<int>(cout, " "));
	cout << endl;



	return 0;
}
