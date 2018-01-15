#include"队列.h"
#include<iostream>

template<class T>
class CycleQueue
{
private:
	T * data;
	const int max_size;
	int front;
	int rear;
	int size;


	//现在rear和front要装东西
public:

	CycleQueue(int n):max_size(n),size(0),front(0),rear(0)
	{
		data = new T[max_size];
	}

	~CycleQueue()
	{
		delete[] data;
	}

	bool enQueue(T t)
	{
		if (is_full())
			return false;
		if (rear != front||size!=0)
			rear = (rear + 1) % max_size;
		data[rear] = t;
		size++;
		return true;
	}

	bool deQueue(T& t)
	{
		if (is_empty())
			return false;
		t = data[front];
		if (rear != front)
		{
			front++;
			front %= max_size;
		}
		size--;
		return true;
	}

	bool is_empty()
	{
		if (rear == front&&size==0)
			return true;
		return false;
	}

	bool is_full()
	{
		if ((rear + 1) % max_size == front)
			return true;
		return false;
	}

	void clear()
	{
		front = 0;
		rear = 0;
		size = 0;
	}

	int get_height()
	{
		return size;
	}
	
	bool get_front(T& t)
	{
		if (is_empty())
			return false;
		t=data[front];
		return true;
	}

	void print()
	{
		if (is_empty())
			return;
		for (int i = 0; i < size; i++)
		{
			int index = (i + front) % max_size;
			std::cout << data[index] << ' ';
		}
		cout << std::endl;
	}
};