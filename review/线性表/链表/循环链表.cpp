#include<stdio.h>
#include<stdlib.h>
#define CANTFIND -23231

#include<iostream>
using namespace std;
//这是一个循环链表示例

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

bool push_back(Node* head, int data)//将数据添加到链表的尾部
{
	Node* index = head;
	while (index->next != head)
	{
		index = index->next;
	}
	index->next = (Node*)malloc(sizeof(Node));
	if (index->next == nullptr)
	{
		//申请空间失败，返回false
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
	printf("索引越界");//返回false表示没有删除这个元素，因为索引越界
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
	printf("索引越界");//返回false表示没有删除这个元素，因为索引越界
	return false;
}


int  get(Node* head, int index)//取出特定位置的元素 ，头元素的索引为-1
{
	Node* ide = head->next;
	int i = 0;
	for (; i < index&&ide != head; i++)
		ide = ide->next;
	if (i == index&&ide !=head)
	{
		return ide->data;
	}
	cerr << "索引越界" << endl;
	return CANTFIND;
}

void prints(Node* head)
{
	cout << "链表内元素有: ";
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
	head->next = head;//这里把它置为head 才不会认为还是有东西的
}




int main()
{
	Node* head = init_list();
	int n = 0;
	cout << "请输入你要添加的元素个数" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int j = 0;
		cin >> j;
		push_back(head, j);
	}
	prints(head);
	int index = -1;
	cout << "请输入你要移除的元素的位置" << endl;
	cin >> index;
	while (!remove(head, index))
	{
		cout << "请输入你要移除的元素的位置" << endl;
		cin >> index;
	}
	prints(head);
	cout << "请输入你要插入的元素的位置，以及元素的值" << endl;
	int data = 0;
	cin >> index >> data;
	while (!insert(head, index, data))
	{
		cout << "请输入你要插入的元素的位置，以及元素的值" << endl;
		cin >> index >> data;
	}
	prints(head);
	cout << "请输入你要获得的元素的索引" << endl;
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