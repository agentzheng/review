#pragma once
//我既然都封装成类了，我还管C能不能用得上？？？还在想是要用malloc 还是用new ？？？
//你封装成类难道C还能用，挺搞笑的呀兄弟
#include <iostream>
#include"Stock.h"
template<class T>
class SeqStack:public Stock<T>
{
	static const int MAX_SIZE = 100000;
	T * data;
	int top;//栈顶索引
	const int size;//在这边我把size 写死了
public:
	SeqStack(int n = MAX_SIZE):size(n),top(-1)//初始化列表是很重要的
	{
		data = new T[size];
	}

	~SeqStack()
	{
		delete[] data;
	}

	void clear()//清空栈
	{
		delete[] data;
		data = new T[size];
		top = -1;
	}

	bool is_empty()//判断栈是否为空
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

	int get_height()//获取当前栈的高度
	{
		return top + 1;
	}

	void print()
	{
		if (is_empty())
		{
			std::cout << "当前栈为空" << std::endl;
			return;
		}
		std::cout << "正在遍历栈" << endl;
		for (int i = 0; i <=top; i++)
		{
			std::cout << data[i]<<' ';
		}
		cout << std::endl;

	}
};