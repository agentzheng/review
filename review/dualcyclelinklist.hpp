#pragma once
#include<iostream>
using namespace std;

template<class T>
class DualCycleLinkList
{
private:
	struct Node
	{
		T data;
		Node* next;
		Node* pre;
	};

	Node* head;

	Node*  get_ptr(int index, bool reverse = false)//取出特定位置的元素指针 ，头元素的索引为-1
	{
		int i = 0;
		if (!reverse)
		{
			Node* now = head->next;
			Node* pre = head;
			for (; i < index&&now != head; i++)
			{
				pre = now;
				now = now->next;
			}
			if (i == index&&now != head)
				return now;
		}
		else
		{
			Node* now = head->pre;
			Node* next = head;
			for (; i < index&&now != head; i++)
			{
				next = now;
				now = now->pre;
			}
			if (i == index&&now != head)
				return now;
		}
		cerr << "ERROR:索引越界" << endl;
		return nullptr;
	}

public:
	DualCycleLinkList()
	{
		head = new Node;
		if (head == nullptr)
		{
			cerr << "初始化都失败了，那不是凉凉" << endl;
		}
		head->next = head;
		head->pre = head;
	}

	bool push_back( T data)//将数据添加到链表的尾部
	{
		Node* index = head->pre;
		index->next->pre =new Node;
		if (index->next == nullptr)
		{
			//申请空间失败，返回false
			return false;
		}
		index->next->pre->data = data;
		index->next->pre->next = head;
		index->next->pre->pre = index;
		index->next = index->next->pre;
		return true;
	}

	bool insert(int index, T data, bool reverse = false)
	{
		Node * ptr = get_ptr( index, reverse);
		if (!ptr) {
			cerr << "插入索引越界，越界索引为" << index << endl;
			return false;
		}
		if (!reverse)//正向的应该插在前面
		{
			ptr->pre->next = new Node;

			ptr->pre->next->data = data;
			ptr->pre->next->next = ptr;
			ptr->pre->next->pre = ptr->pre;

			ptr->pre = ptr->pre->next;
		}
		else //反向的应该插在后面
		{
			ptr->next->pre = new Node;

			ptr->next->pre->data = data;
			ptr->next->pre->next = ptr->next;
			ptr->next->pre->pre = ptr;

			ptr->next = ptr->next->pre;
		}
		return true;
	}

	bool remove( int index, bool reverse = false)
	{
		Node* ptr = get_ptr(head, index, reverse);
		if (ptr != nullptr)
		{
			ptr->pre->next = ptr->next;
			ptr->next->pre = ptr->pre;
			delete ptr;
			return true;
		}
		cerr << "欲删除索引值为" << index << "的元素" << endl;//返回false表示没有删除这个元素，因为索引越界
		return false;
	}

	void prints(bool reverse=false)
	{
		if (!reverse)
		{
			cout << "链表内元素有: ";
			Node* index = head->next;
			while (index != head)
			{
				cout << index->data<<' ';
				index = index->next;
			}
		}
		else 
		{
			cout << "反向链表内元素有: ";
			Node* index = head->pre;
			while (index != head)
			{
				cout << index->data << " ";
				index = index->pre;
			}
		}
		cout << endl;
		
	}

	void clean()
	{
		Node* index = head->next;
		Node * pre = nullptr;
		while (index != head)
		{
			pre = index;
			index = index->next;
			delete pre;
		}
		head->next = head;//这里把它置为head 才不会认为还是有东西的
		head->pre = head;//回归到初始化状态，之后又可以pushback了
	}

	T& get(int index,bool reverse=false)
	{
		Node * ptr=get_ptr(index, reverse);
		if (ptr == nullptr)
		{
			cerr << "ERROR:get() 获取出错" << endl;
			return head->data;
		}
		else
			return ptr-> data;
	}

	~DualCycleLinkList()
	{
		clean();
		delete head;
	}

	T& operator[](int index)
	{
		return get(index, false);
	}
};