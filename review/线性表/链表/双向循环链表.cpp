#include<stdio.h>
#include<stdlib.h>
#include <vld.h>

#include<iostream>
using namespace std;
//����һ��ѭ������ʾ��

struct Node
{
	int data;
	Node* next;
	Node* pre;
};


Node* init_list()
{
	Node* head = (Node*)malloc(sizeof(Node));
	if (head == nullptr)
		return nullptr;
	head->next = head;
	head->pre = head;
	return head;
}

bool push_back(Node* head, int data)//��������ӵ������β��
{
	Node* index = head->pre;
	index->next->pre = (Node*)malloc(sizeof(Node));
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


Node*  get_ptr(Node* head, int index, bool reverse = false)//ȡ���ض�λ�õ�Ԫ��ָ�� ��ͷԪ�ص�����Ϊ-1
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

bool full_insert(Node* head, int index, int data,bool reverse = false)
{
	Node * ptr = get_ptr(head, index, reverse);
	if (!ptr) {
		cerr << "��������Խ�磬Խ������Ϊ" << index << endl;
		return false;
	}
	if (!reverse)//�����Ӧ�ò���ǰ��
	{
		ptr->pre->next = (Node*)malloc(sizeof(Node));

		ptr->pre->next->data = data;
		ptr->pre->next->next = ptr;
		ptr->pre->next->pre = ptr->pre;

		ptr->pre = ptr->pre->next;
	}
	else //�����Ӧ�ò��ں���
	{
		ptr->next->pre= (Node*)malloc(sizeof(Node));

		ptr->next->pre->data = data;
		ptr->next->pre->next = ptr->next;
		ptr->next->pre->pre = ptr;

		ptr->next = ptr->next->pre;
	}
	return true;
}


bool full_remove(Node* head, int index,bool reverse=false)//
{
	Node* ptr=get_ptr(head, index, reverse);
	if (ptr!=nullptr)
	{
		ptr->pre->next = ptr->next;
		ptr->next->pre = ptr->pre;
		free(ptr);
		return true;
	}
	cerr << "��ɾ������ֵΪ" << index <<"��Ԫ��"<< endl;//����false��ʾû��ɾ�����Ԫ�أ���Ϊ����Խ��
	return false;
}


void prints(Node* head)
{
	cout << "������Ԫ����: ";
	Node* index = head->next;
	while (index != head)
	{
		printf("%d ", index->data);
		index = index->next;
	}
	cout << endl;
}

void reverse_prints(Node* head)
{
	cout << "����������Ԫ����: ";
	Node* index = head->pre;
	while (index != head)
	{
		cout << index->data << " ";
		index = index->pre;
	}
	cout << endl;
}


void clean(Node* head)
{
	Node* index = head->next;
	Node * pre = nullptr;
	while (index != head)
	{
		pre = index;
		index = index->next;
		free(pre);
	}
	head->next = head;//���������Ϊhead �Ų�����Ϊ�����ж�����
	head->pre = head;//�ع鵽��ʼ��״̬��֮���ֿ���pushback��
}



bool is_empty(Node * head)
{
	if (head->next == head)
		return true;
	if (head->pre == head)
		return true;
	return false;
}


int main()
{
	Node* head = init_list();
	int n = 0;
	cout << "��������Ҫ��ӵ�Ԫ�ظ���" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int j = 0;
		cin >> j;
		push_back(head, j);
	}
	prints(head);
	reverse_prints(head);
	cout << "����ָ�����";
	for (int i = 0; i < n; i++)
	{
		cout << get_ptr(head, i)->data << " ";
	}
	cout << endl;

	cout << "����ָ�뷴�����";
	for (int i = 0; i <n; i++)
	{
		cout << get_ptr(head, i,true)->data << " ";
	}
	cout << endl;

	cout << "׼����������һ��ͷָ����������������" << endl;
	for (int i = 0; i < n; i++)
	{
		reverse_prints(get_ptr(head, i));//��Ȼ�������Ǳ�ʣ�����ûɶ�ô�����Ҫ����Ϊ����������趨����ͷ��㲻�涫��
	}
	cout << "��ȡͷָ�����" << endl;
	/*
	//�㻹��Ū��������˫��ѭ�������𣬾��������ȡһ���ڵ�Ϳ��Ա�����������
	cout << "׼��ɾ����������" << endl;
	for (int i = 1; i <= n; i++)
	{
		full_remove(head, n-i);
		prints(head);
	}
	cout << "ɾ���������" << endl;

	*/

	cout << "���������һ��"<<endl;
	for (int i = 0; i < n; i++)
	{
		full_insert(head, 0, 2 * i);
		prints(head);
	}
	cout << endl;


	cout << "�ñ��ָ���滻head" << endl;
	head = get_ptr(head, 0);
	prints(head);
	reverse_prints(head);
	clean(head);
	prints(head);
	reverse_prints(head);
	free(head);
	system("pause");
}