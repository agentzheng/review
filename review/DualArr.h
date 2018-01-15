/*
Name：Two Dimensional Array
Auther：Elliott Zheng
Date: 2017.12.8
自封装的二维数组，做邻接矩阵的题目应该比较方便
想要使用输出的话需要自己重载T对象的<<操作符
*/
#pragma once
#include<iostream>

template<class T>
class DualArr
{
private:
	T * * pointer;
	int rows;
	int cols;


	void clean()
	{
		if (!pointer)
			return;
		for (int i = 0; i < rows; i++)
			delete[] pointer[i];
		delete[] pointer;
	}

public:
	// 行数，列数(可不填，默认为与行数相同) 把整个数组初始化为一个值
	DualArr(int row, int col) :pointer(NULL)
	{
		Resize(row, col);
	}
	//额外参数ori是将所有元素置为同一值
	DualArr(int row, int col, T ori) :pointer(NULL)
	{
		Resize(row, col);
		SetAllTo(ori);
	}

	//拷贝构造函数
	DualArr(DualArr& other) :pointer(NULL)
	{
		Copy(other);
	}

	//移动构造函数
	DualArr(DualArr&& other) :rows(other.rows)
	{
		pointer = other.pointer;
		other.pointer = NULL;
	}

	//拷贝other
	void Copy(DualArr& other)
	{
		if (&other == this)
		{
			return;
		}
		clean();
		rows = other.rows;
		cols = other.cols;
		pointer = new   int*[rows];
		for (int i = 0; i<rows; i++)
		{
			pointer[i] = new   int[cols];
			for (int j = 0; j < cols; j++)
			{
				pointer[i][j] = other.pointer[i][j];
			}
		}
	}

	//行数，列数，还有一个可选参数初值
	void Resize(int row, int col)
	{
		clean();
		if (row <= 0 || col <= 0)
		{
			std::cerr << "ERROR:你输入的行数或者列数不对，没有意义,已自动置为1" << std::endl;
		}
		rows = row <= 0 ? 1 : row;
		cols = col <= 0 ? 1 : col;
		//防止出现说行数列数为o 或负数
		pointer = new   int*[rows];
		for (int i = 0; i<rows; i++)
			pointer[i] = new  int[cols];
	}

	//行数，列数，初值
	void Resize(int row, int col, T ori)
	{
		Resize(row, col);
		SetAllTo(ori);
	}

	//将所有元素设置为ori
	void SetAllTo(T ori)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				pointer[i][j] = ori;
			}
		}
	}

	int  get_rows()
	{
		return rows;
	}

	int  get_cols()
	{
		return cols;
	}

	//比较不推荐，但是你懂我意思吧，其实如果你想要程序跑得通，那这两个函数都不应该出问题，但是数组出问题是很正常的啊
	T* operator[](const int row)
	{
		if (row >= rows || row < 0)
		{
			std::cerr << "ERROR:数组访问越界,已自动返回空指针" << endl;
			return NULL;
		}
		else
			return pointer[row];
	}

	//推荐使用函数操作符访问二维数组元素
	T& operator()(const int row, const int col)
	{
		if (row >= rows || row < 0 || col >= cols || col<0)
		{
			std::cerr << "ERROR:数组访问越界,已自动返回数组元素[0][0]的引用，请检查程序是否出错" << endl;
			return pointer[0][0];
		}
		else
			return pointer[row][col];
	}

	//析构函数
	~DualArr()
	{
		clean();
	}

	friend std::ostream& operator<<(std::ostream& out, DualArr<T>& s)
	{
		for (int i = 0; i < s.rows; i++)
		{
			for (int j = 0; j < s.cols; j++)
			{
				out << s[i][j] << '\t';
			}
			out << std::endl;
		}
		return out;
	}

	DualArr<T>& operator=(DualArr<T>& other)
	{
		Copy(other);
		return *this;
	}

};