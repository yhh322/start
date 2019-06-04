 ///
 /// @file    127.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-11-06 17:21:53
 ///
 
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <queue>
#include <unordered_map>
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::set;
using std::queue;
using std::unordered_map;
 
//Word Ladder
//首先考虑层级关系，如从beginword开始为第一层，和beginword
//相邻（只有一个字母不同，且不包含beginword）的单词为第二层，
//而和所有beginword相邻集合内单词相邻的所有单词集合为第三层。
//以此类推。直到在某一层遇到可以转化为endword的单词，则表示
//该层为最低层。期间可以舍弃被访问过的在字典中的单词。

class Solution 
{
public:
	int ladderLength(const string & start, const string & end, const set<string> & dict)
	{
		if(dict.count(end) == 0) {
			return 0;
		}
		unordered_map<string, string> paths;

		set<string> visited;
		//visited.insert(start);

		int level = 0;
		bool found = false;
		auto nextStates = [&](const string & word) {
			vector<string> result;
			for(size_t idx = 0; idx != word.size(); ++idx) {
				string copy(word);//hit
				for(char ch = 'a'; ch <= 'z'; ++ch) {
					if(ch == copy[idx]) 
						continue;
					std::swap(ch, copy[idx]);//变换  ait
					if((dict.count(copy) > 0 || copy == end) && !visited.count(copy)) {
						result.push_back(copy);		
						visited.insert(copy);
					}
					std::swap(ch, copy[idx]);//恢复 hit
				}
			}
			return result;
		};
		auto printPath = [&paths](const string & state) {
			string s(state);
			cout << s;
			while(paths.count(s)) {
				s = paths[s];
				cout << " <- " << s;
			}
			cout << endl;
		};

		queue<string> current, next;
		current.push(start);
		while(!current.empty() && !found) {
			++level;
			while(!current.empty() && !found) { //查找下一层
				string str = current.front();
				current.pop();
				const auto newStates = nextStates(str);	
				
			//	cout << "level " << level - 1 << " " << str << "->";
			//	cout << "level " << level << "：";
			//	for(auto & elem : newStates)
			//	{	cout << elem << " ";}
			//	cout << endl;
				for(auto & state : newStates) {
					next.push(state);
					paths[state] = str;
					if(state == end) {
						found = true;
						printPath(state);
						break;
					}
				}
			}
			swap(next, current);
		}
		if(found) 
			return level + 1;
		else 
			return 0;
	}
};
int main(void)
{
#if 0
	string start = "hit";
	string end = "cog";
	set<string> dict{"hot", "dot", "dog", "log", "lot"};
#endif

#if 1
	string start = "hit";
	string end = "cog";
	set<string> dict{"hot", "dot", "dog", "log", "lot", "cog"};
#endif

	Solution s;
	cout << s.ladderLength(start, end, dict) << endl;
	return 0;
}
