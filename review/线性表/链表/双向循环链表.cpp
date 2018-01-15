#include<stdio.h>
#include<stdlib.h>
#include <vld.h>

#include<iostream>
using namespace std;
//这是一个循环链表示例

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

bool push_back(Node* head, int data)//将数据添加到链表的尾部
{
	Node* index = head->pre;
	index->next->pre = (Node*)malloc(sizeof(Node));
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


Node*  get_ptr(Node* head, int index, bool reverse = false)//取出特定位置的元素指针 ，头元素的索引为-1
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

bool full_insert(Node* head, int index, int data,bool reverse = false)
{
	Node * ptr = get_ptr(head, index, reverse);
	if (!ptr) {
		cerr << "插入索引越界，越界索引为" << index << endl;
		return false;
	}
	if (!reverse)//正向的应该插在前面
	{
		ptr->pre->next = (Node*)malloc(sizeof(Node));

		ptr->pre->next->data = data;
		ptr->pre->next->next = ptr;
		ptr->pre->next->pre = ptr->pre;

		ptr->pre = ptr->pre->next;
	}
	else //反向的应该插在后面
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
	cerr << "欲删除索引值为" << index <<"的元素"<< endl;//返回false表示没有删除这个元素，因为索引越界
	return false;
}


void prints(Node* head)
{
	cout << "链表内元素有: ";
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
	cout << "反向链表内元素有: ";
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
	head->next = head;//这里把它置为head 才不会认为还是有东西的
	head->pre = head;//回归到初始化状态，之后又可以pushback了
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
	cout << "请输入你要添加的元素个数" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int j = 0;
		cin >> j;
		push_back(head, j);
	}
	prints(head);
	reverse_prints(head);
	cout << "利用指针遍历";
	for (int i = 0; i < n; i++)
	{
		cout << get_ptr(head, i)->data << " ";
	}
	cout << endl;

	cout << "利用指针反向遍历";
	for (int i = 0; i <n; i++)
	{
		cout << get_ptr(head, i,true)->data << " ";
	}
	cout << endl;

	cout << "准备利用另外一个头指针来遍历整个数组" << endl;
	for (int i = 0; i < n; i++)
	{
		reverse_prints(get_ptr(head, i));//虽然他有这个潜质，但是没啥用处，主要是因为咱们这里的设定就是头结点不存东西
	}
	cout << "任取头指针完成" << endl;
	/*
	//你还想弄个完美的双向循环链表吗，就是任意的取一个节点就可以遍历整个链表
	cout << "准备删除整个链表" << endl;
	for (int i = 1; i <= n; i++)
	{
		full_remove(head, n-i);
		prints(head);
	}
	cout << "删除链表完成" << endl;

	*/

	cout << "遍插茱萸少一人"<<endl;
	for (int i = 0; i < n; i++)
	{
		full_insert(head, 0, 2 * i);
		prints(head);
	}
	cout << endl;


	cout << "用别的指针替换head" << endl;
	head = get_ptr(head, 0);
	prints(head);
	reverse_prints(head);
	clean(head);
	prints(head);
	reverse_prints(head);
	free(head);
	system("pause");
}