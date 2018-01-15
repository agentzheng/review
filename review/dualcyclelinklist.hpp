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

	Node*  get_ptr(int index, bool reverse = false)//ȡ���ض�λ�õ�Ԫ��ָ�� ��ͷԪ�ص�����Ϊ-1
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
		cerr << "ERROR:����Խ��" << endl;
		return nullptr;
	}

public:
	DualCycleLinkList()
	{
		head = new Node;
		if (head == nullptr)
		{
			cerr << "��ʼ����ʧ���ˣ��ǲ�������" << endl;
		}
		head->next = head;
		head->pre = head;
	}

	bool push_back( T data)//��������ӵ������β��
	{
		Node* index = head->pre;
		index->next->pre =new Node;
		if (index->next == nullptr)
		{
			//����ռ�ʧ�ܣ�����false
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
			cerr << "��������Խ�磬Խ������Ϊ" << index << endl;
			return false;
		}
		if (!reverse)//�����Ӧ�ò���ǰ��
		{
			ptr->pre->next = new Node;

			ptr->pre->next->data = data;
			ptr->pre->next->next = ptr;
			ptr->pre->next->pre = ptr->pre;

			ptr->pre = ptr->pre->next;
		}
		else //�����Ӧ�ò��ں���
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
		cerr << "��ɾ������ֵΪ" << index << "��Ԫ��" << endl;//����false��ʾû��ɾ�����Ԫ�أ���Ϊ����Խ��
		return false;
	}

	void prints(bool reverse=false)
	{
		if (!reverse)
		{
			cout << "������Ԫ����: ";
			Node* index = head->next;
			while (index != head)
			{
				cout << index->data<<' ';
				index = index->next;
			}
		}
		else 
		{
			cout << "����������Ԫ����: ";
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
		head->next = head;//���������Ϊhead �Ų�����Ϊ�����ж�����
		head->pre = head;//�ع鵽��ʼ��״̬��֮���ֿ���pushback��
	}

	T& get(int index,bool reverse=false)
	{
		Node * ptr=get_ptr(index, reverse);
		if (ptr == nullptr)
		{
			cerr << "ERROR:get() ��ȡ����" << endl;
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