/*
Name：Matrix
Auther：Elliott Zheng
Date: 2017.12.8
Modified date：2018.1.16
一个很基础的矩阵类，不带任何矩阵操作方法，只能访问矩阵元素，隐藏复杂的指针，帮你省去内存管理这一步，做邻接矩阵的题目应该比较方便
想要使用输出的话需要自己重载T对象的<<操作符

*/
#pragma once
#include<iostream>

template<class Type>
class Matrix
{
private:
	Type * * pointer;
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
	// 行数，列数, 把整个矩阵初始化为一个值
	Matrix(int row, int col) :pointer(NULL)
	{
		Resize(row, col);
	}
	//额外参数ori是将所有元素置为同一值
	Matrix(int row, int col, Type ori) :pointer(NULL)
	{
		Resize(row, col);
		SetAllTo(ori);
	}

	//拷贝构造函数
	Matrix(Matrix& other) :pointer(NULL)
	{
		Copy(other);
	}

	//转移构造函数
	Matrix(Matrix&& other) :rows(other.rows),cols(other.cols)
	{
		pointer = other.pointer;
		other.pointer = NULL;
	}

	//拷贝other
	void Copy(Matrix& other)
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
	void Resize(int row, int col, Type ori)
	{
		Resize(row, col);
		SetAllTo(ori);
	}

	//将所有元素设置为ori
	void SetAllTo(Type ori)
	{
		for (int i = 0; i < rows; i++)
		{
			fill(pointer[i], pointer[i] + cols, ori);
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
	Type* operator[](const int row)
	{
		if (row >= rows || row < 0)
		{
			std::cerr << "ERROR:数组访问越界,已自动返回空指针" << endl;
			return NULL;
		}
		else
			return pointer[row];
	}

	//推荐使用函数操作符访问矩阵元素
	Type& operator()(const int row, const int col)
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
	~Matrix()
	{
		clean();
	}

	Matrix<Type>& operator=(Matrix<Type>& other)
	{
		Copy(other);
		return *this;
	}

};