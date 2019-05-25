 ///
 /// @file    Line.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-21 11:04:46
 ///
 
#ifndef __LINE_H__
#define __LINE_H__

class Line
{//作为接口存在
 //PIMPL设计模式
 //
 //优势: 1. 实现信息隐藏
 //		 2. 接口稳定，可以以最小的代价，实现库的平滑升级
 //		 3. 减小编译依赖，提高编译速度
public:
	Line(int, int, int, int);
	~Line();

	void printLine() const;
	
	class LineImpl;//类的前向声明, 嵌套类(内部类)
private:
	LineImpl * _pimpl;
};

#endif
