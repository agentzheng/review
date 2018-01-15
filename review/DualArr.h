/*
Name��Two Dimensional Array
Auther��Elliott Zheng
Date: 2017.12.8
�Է�װ�Ķ�ά���飬���ڽӾ������ĿӦ�ñȽϷ���
��Ҫʹ������Ļ���Ҫ�Լ�����T�����<<������
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
	// ����������(�ɲ��Ĭ��Ϊ��������ͬ) �����������ʼ��Ϊһ��ֵ
	DualArr(int row, int col) :pointer(NULL)
	{
		Resize(row, col);
	}
	//�������ori�ǽ�����Ԫ����Ϊͬһֵ
	DualArr(int row, int col, T ori) :pointer(NULL)
	{
		Resize(row, col);
		SetAllTo(ori);
	}

	//�������캯��
	DualArr(DualArr& other) :pointer(NULL)
	{
		Copy(other);
	}

	//�ƶ����캯��
	DualArr(DualArr&& other) :rows(other.rows)
	{
		pointer = other.pointer;
		other.pointer = NULL;
	}

	//����other
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
	void Resize(int row, int col, T ori)
	{
		Resize(row, col);
		SetAllTo(ori);
	}

	//������Ԫ������Ϊori
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

	//�Ƚϲ��Ƽ��������㶮����˼�ɣ���ʵ�������Ҫ�����ܵ�ͨ������������������Ӧ�ó����⣬��������������Ǻ������İ�
	T* operator[](const int row)
	{
		if (row >= rows || row < 0)
		{
			std::cerr << "ERROR:�������Խ��,���Զ����ؿ�ָ��" << endl;
			return NULL;
		}
		else
			return pointer[row];
	}

	//�Ƽ�ʹ�ú������������ʶ�ά����Ԫ��
	T& operator()(const int row, const int col)
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