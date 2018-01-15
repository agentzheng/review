#include<stdio.h>
#include<stdlib.h>
#define CANTFIND -23231

#include<iostream>
using namespace std;
//����һ��ѭ������ʾ��

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
	head->next = head;
	return head;
}

bool push_back(Node* head, int data)//��������ӵ������β��
{
	Node* index = head;
	while (index->next != head)
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
	index->next = head;
	index->data = data;
	return true;
}

bool insert(Node* head, int index, int data)
{
	Node* now = head->next;
	Node* pre = head;
	int i = 0;
	for (; i < index&&now != head; i++)
	{
		pre = now;
		now = now->next;
	}
	if (i == index)
	{
		pre->next = (Node*)malloc(sizeof(Node));
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
	for (; i < index&&now !=head; i++)
	{
		pre = now;
		now = now->next;
	}

	if (i == index)
	{
		pre->next = now->next;
		free(now);
		return true;
	}
	printf("����Խ��");//����false��ʾû��ɾ�����Ԫ�أ���Ϊ����Խ��
	return false;
}


int  get(Node* head, int index)//ȡ���ض�λ�õ�Ԫ�� ��ͷԪ�ص�����Ϊ-1
{
	Node* ide = head->next;
	int i = 0;
	for (; i < index&&ide != head; i++)
		ide = ide->next;
	if (i == index&&ide !=head)
	{
		return ide->data;
	}
	cerr << "����Խ��" << endl;
	return CANTFIND;
}

void prints(Node* head)
{
	cout << "������Ԫ����: ";
	Node* index= head->next;
	while (index != head)
	{
		printf("%d ", index->data);
		index= index->next;
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
	int index = -1;
	cout << "��������Ҫ�Ƴ���Ԫ�ص�λ��" << endl;
	cin >> index;
	while (!remove(head, index))
	{
		cout << "��������Ҫ�Ƴ���Ԫ�ص�λ��" << endl;
		cin >> index;
	}
	prints(head);
	cout << "��������Ҫ�����Ԫ�ص�λ�ã��Լ�Ԫ�ص�ֵ" << endl;
	int data = 0;
	cin >> index >> data;
	while (!insert(head, index, data))
	{
		cout << "��������Ҫ�����Ԫ�ص�λ�ã��Լ�Ԫ�ص�ֵ" << endl;
		cin >> index >> data;
	}
	prints(head);
	cout << "��������Ҫ��õ�Ԫ�ص�����" << endl;
	cin >> index;
	data = get(head, index);
	if (data != CANTFIND)
		cout << data << endl;
	prints(head);
	clean(head);
	prints(head);
	free(head);
	system("pause");
}