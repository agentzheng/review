/*
Name��Matrix
Auther��Elliott Zheng
Date: 2017.12.8
Modified date��2018.1.16
һ���ܻ����ľ����࣬�����κξ������������ֻ�ܷ��ʾ���Ԫ�أ����ظ��ӵ�ָ�룬����ʡȥ�ڴ������һ�������ڽӾ������ĿӦ�ñȽϷ���
��Ҫʹ������Ļ���Ҫ�Լ�����T�����<<������

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
	// ����������, �����������ʼ��Ϊһ��ֵ
	Matrix(int row, int col) :pointer(NULL)
	{
		Resize(row, col);
	}
	//�������ori�ǽ�����Ԫ����Ϊͬһֵ
	Matrix(int row, int col, Type ori) :pointer(NULL)
	{
		Resize(row, col);
		SetAllTo(ori);
	}

	//�������캯��
	Matrix(Matrix& other) :pointer(NULL)
	{
		Copy(other);
	}

	//ת�ƹ��캯��
	Matrix(Matrix&& other) :rows(other.rows),cols(other.cols)
	{
		pointer = other.pointer;
		other.pointer = NULL;
	}

	//����other
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

	//����������������һ����ѡ������ֵ
	void Resize(int row, int col)
	{
		clean();
		if (row <= 0 || col <= 0)
		{
			std::cerr << "ERROR:����������������������ԣ�û������,���Զ���Ϊ1" << std::endl;
		}
		rows = row <= 0 ? 1 : row;
		cols = col <= 0 ? 1 : col;
		//��ֹ����˵��������Ϊo ����
		pointer = new   int*[rows];
		for (int i = 0; i<rows; i++)
			pointer[i] = new  int[cols];
	}

	//��������������ֵ
	void Resize(int row, int col, Type ori)
	{
		Resize(row, col);
		SetAllTo(ori);
	}

	//������Ԫ������Ϊori
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

	//�Ƚϲ��Ƽ��������㶮����˼�ɣ���ʵ�������Ҫ�����ܵ�ͨ������������������Ӧ�ó����⣬��������������Ǻ������İ�
	Type* operator[](const int row)
	{
		if (row >= rows || row < 0)
		{
			std::cerr << "ERROR:�������Խ��,���Զ����ؿ�ָ��" << endl;
			return NULL;
		}
		else
			return pointer[row];
	}

	//�Ƽ�ʹ�ú������������ʾ���Ԫ��
	Type& operator()(const int row, const int col)
	{
		if (row >= rows || row < 0 || col >= cols || col<0)
		{
			std::cerr << "ERROR:�������Խ��,���Զ���������Ԫ��[0][0]�����ã���������Ƿ����" << endl;
			return pointer[0][0];
		}
		else
			return pointer[row][col];
	}

	//��������
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