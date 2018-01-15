#pragma  once 
#include"Stock.h"
#include<iostream>
template<class T>
class LinkedStock:public Stock<T>
{
private:
	struct Node
	{
		T data;
		Node * pre;
		Node * next;
	};
	Node* top;
	int size;
public:
	LinkedStock():top(new Node),size(0)
	{
		top->next = nullptr;
		top->pre = nullptr;
	}

	~LinkedStock()
	{
		while (top != nullptr)
		{
			Node* temp = top;
			top = top->pre;
			delete temp;
		}
	}

	bool push(T t)
	{
		top->next = new Node;
		if (top->next == nullptr)
			return false;
		top->next->data = t;
		top->next->pre = top;
		top = top->next;
		size++;
		return true;
	}

	bool pop(T& t)
	{
		if (top->pre == nullptr)
			return false;
		t = top->data;
		top = top->pre;
		delete top->next;
		size--;
		return true;
	}

	int get_height()
	{
		return size;
	}

	bool is_empty()
	{
		if (top->pre == nullptr)
			return true;
		return false;
	}

	bool get_top(T& t)
	{
		if (top->pre != nullptr)
		{
			t = top->data;
			return true;
		}
		return false;
	}
	void clear()
	{
		while (top->pre!= nullptr)
		{
			Node* temp = top;
			top = top->pre;
			delete temp;
		}
		size = 0;
	}


	void print()
	{
		Node * index = top;
		while (index->pre!= nullptr)
		{
			std::cout << index->data << ' ';
			index = index->pre;
		}
		std::cout << std::endl;
	}
};
