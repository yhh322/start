 ///
 /// @file    LRUCache.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-01 11:17:45
 ///
 
#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache
{
public:
	LRUCache(int capacity)
	: _capacity(capacity)
	{}

	void put(int key, int value)
	{
		auto it = _hashMap.find(key);
		if(it == _hashMap.end()) {
			//添加新元素
			if(_cacheList.size() == _capacity) {
				//进行淘汰操作
				int key = _cacheList.back().key;
				_hashMap.erase(key);
				_cacheList.pop_back();
			}
			_cacheList.push_front(CacheNode(key, value));
			_hashMap.insert(make_pair(key, _cacheList.begin()));
		} else {
			//key存在的情况
			it->second->value = value;
			_cacheList.splice(_cacheList.begin(), _cacheList, it->second);
			_hashMap[key] = _cacheList.begin();
		}
	}

	int get(int key)
	{
		auto it = _hashMap.find(key);
		if(it == _hashMap.end())
			return -1;
		else {
			//查找成功
			int value = it->second->value;
			_cacheList.splice(_cacheList.begin(), _cacheList, it->second);
			_hashMap[key] = _cacheList.begin();
			return value; 
		}
	}

	struct CacheNode
	{
		int key;
		int value;
		CacheNode(int k, int v): key(k), value(v){}
	};

private:
	size_t _capacity;
	//list中头部的元素是最近被访问过的，尾部是待淘汰的元素
	list<CacheNode> _cacheList;
	unordered_map<int, list<CacheNode>::iterator> _hashMap;
};
             
 
int main(void)
{
	LRUCache cache(2);
	cache.put(1, 1);
	cache.put(2, 2);
	cout << cache.get(1) << endl;
	cache.put(3, 3);
	cout << cache.get(2) << endl;
	cache.put(4, 4);
	cout << cache.get(1) << endl;
	cout << cache.get(3) << endl;
	cout << cache.get(4) << endl;
	

	return 0;
}
