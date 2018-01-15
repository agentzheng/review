#pragma once
//�Ҽ�Ȼ����װ�����ˣ��һ���C�ܲ����õ��ϣ�������������Ҫ��malloc ������new ������
//���װ�����ѵ�C�����ã�ͦ��Ц��ѽ�ֵ�
#include <iostream>
#include"Stock.h"
template<class T>
class SeqStack:public Stock<T>
{
	static const int MAX_SIZE = 100000;
	T * data;
	int top;//ջ������
	const int size;//������Ұ�size д����
public:
	SeqStack(int n = MAX_SIZE):size(n),top(-1)//��ʼ���б��Ǻ���Ҫ��
	{
		data = new T[size];
	}

	~SeqStack()
	{
		delete[] data;
	}

	void clear()//���ջ
	{
		delete[] data;
		data = new T[size];
		top = -1;
	}

	bool is_empty()//�ж�ջ�Ƿ�Ϊ��
	{
		if (top == -1)
			return true;
		return false;
	}

	bool push(T t)
	{
		if (top >= size - 1)
			return false;
		top++;
		data[top] = t;
		return true;
	}

	bool pop(T& t)
	{
		if (is_empty())
			return false;
		t = data[top];
		top--;
		return true;
	}

	bool get_top(T& t)
	{
		if (is_empty())
			return false;
		t = data[top];
		return true;
	}

	int get_height()//��ȡ��ǰջ�ĸ߶�
	{
		return top + 1;
	}

	void print()
	{
		if (is_empty())
		{
			std::cout << "��ǰջΪ��" << std::endl;
			return;
		}
		std::cout << "���ڱ���ջ" << endl;
		for (int i = 0; i <=top; i++)
		{
			std::cout << data[i]<<' ';
		}
		cout << std::endl;

	}
};