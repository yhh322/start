 ///
 /// @file    SafeFile.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-03 14:58:47
 ///
 
#include <iostream>
using namespace std;
             

class SafeFile
{
public:
	SafeFile(FILE * fp)
	: _fp(fp)
	{}

	void write(const string & msg) {
		fwrite(msg.c_str(), 1, msg.size(), _fp);
	}

	~SafeFile()
	{
		if(_fp)  {
			fclose(_fp);
			cout << ">> fclose(_fp)" << endl;
		}
	}

private:
	FILE * _fp;
};
 
int main(void)
{
	SafeFile sf(fopen("test.txt", "a+"));
	sf.write("hello,world\n");

	return 0;
}
