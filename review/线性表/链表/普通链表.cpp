#include<stdio.h>
#include<stdlib.h>
#define CANTFIND -23231

#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

Node* init_list()
{
	Node* head = (Node*)malloc(sizeof(Node));
	if (head == nullptr)
		return nullptr;
	head->next = nullptr;
	return head;
}

bool push_back(Node* head,int data)//��������ӵ������β��
{
	Node* index = head;
	while (index->next != nullptr)
	{
		index = index->next;
	}
	index->next = (Node*)malloc(sizeof(Node));
	if (index->next == nullptr) 
	{
		//����ռ�ʧ�ܣ�����false
		return false;
	}
	index = index->next;
	index->next = nullptr;
	index->data = data;
	return true;
}

bool insert(Node* head,int index,int data)
{
	Node* now = head->next;
	Node* pre = head;
	int i = 0;
	for (; i < index&&now != nullptr; i++)
	{
		pre = now;
		now = now->next;
	}
	if (i == index)
	{
		pre->next = (Node* )malloc(sizeof(Node));
		pre = pre->next;
		pre->data = data;
		pre->next = now;
		return true;
	}
	printf("����Խ��");//����false��ʾû��ɾ�����Ԫ�أ���Ϊ����Խ��
	return false;
}

bool remove(Node* head, int index)
{
	Node* now = head->next;
	Node* pre = head;
	int i = 0;
	
	for (; i < index&&now != nullptr; i++)
	{
		pre = now;
		now= now->next;
	}

	if (i == index)
	{
		pre->next = now->next;
		free(now);
		return true;
	}
	printf( "����Խ��");//����false��ʾû��ɾ�����Ԫ�أ���Ϊ����Խ��
	return false;
}


int  get(Node* head, int index)//ȡ���ض�λ�õ�Ԫ�� ��ͷԪ�ص�����Ϊ-1
{
	Node* ide = head->next;
	int i = 0;
	for (; i < index&&ide!=nullptr; i++)
		ide = ide->next;
	if (i == index&&ide!=nullptr)
	{
		return ide->data;
	}
	cerr << "����Խ��" << endl;
	return CANTFIND;
}

void prints(Node* head)
{
	cout << "������Ԫ����: ";
	head = head->next;
	while (head != nullptr)
	{
		printf("%d ", head->data);
		head = head->next;
	}
	cout << endl;
}

void clean(Node* head)
{
	Node* index = head->next;
	Node * pre = nullptr;
	while (index != nullptr)
	{
		pre = index;
		index = index->next;
		free(pre);
	}
	head->next = nullptr;//���������Ϊnullptr �Ų�����Ϊ�����ж�����
}


void InsertSort(Node * head)
{
	if (head->next == nullptr)
		return;
	Node * sorted = head->next;
	while (sorted->next != nullptr)
	{
		Node *j = sorted->next;
		Node * index = head->next;
		Node * pre = head;
		while ((index->data > j->data) &&index != j)
		{
			pre = index;
			index = index->next;
		}

		if (index != j)
		{
			pre->next = j;
			sorted->next= j->next;
			j->next = index;
		}
		else
			sorted = sorted->next;
	}
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
	InsertSort(head);
	prints(head);







	free(head);
	system("pause");
}