#include"����.h"
#include<iostream>
template<class T>
class LinkedQueue :public Queue<T>
{
private:
	struct Node
	{
		T data;
		Node* next;
	};
	Node*  front;
	Node*  rear;
	int size;

	//front����Ӧ��Ҫװ�Ŷ�����,rearʵ�ģ����ǲ�װ����

public:
	LinkedQueue():front(new Node),size(0)
	{
		if (front == nullptr)
		{
			std::cerr << "��ʼ��������ʧ��,�벻Ҫ����������" << std::endl;
			return;
		}
		rear = front;
		front->next = nullptr;
	}

	~LinkedQueue()
	{
		clear();
		delete front;
	}

	bool enQueue(T t)
	{
		rear->data = t;
		rear->next=new Node;
		if (rear->next == nullptr)
			return false;
		rear = rear->next;
		rear->next = nullptr;
		size++;
		return true;	
	}

	bool deQueue(T& t)
	{
		if (is_empty())
			return false;
		t = front->data;
		Node* temp = front;
		front = front->next;
		delete temp;
		size--;
		return true;
	}

	 bool is_empty()
	 {
		 if (front == rear)
			 return true;
		 return false;
	 }

	 bool is_full()
	 {
		 Node * temp = new Node;
		 if (temp == nullptr)
			 return true;
		 else
			 return false;
	 }

	 void clear() 
	 {
		 while (front != rear)
		 {
			 Node* temp = front;
			 front = front->next;
			 delete temp;
		 }
		 size = 0;
	 }

	 int get_height()
	 {
		 return size;
	 }

	 void print()
	 {
		 if (is_empty())
			 return;
		 Node * index = front;
		 while (index != rear)
		 {
			std::cout << index->data << ' ';
			index = index->next;
		 }
		 std::cout << std::endl;
	 }

	 bool get_front(T& t)
	 {
		 if (is_empty())
			 return false;
		 t = front->data;
		 return true;
	 }

};