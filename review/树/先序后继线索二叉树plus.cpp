#include<iostream>
using namespace std;


class BinaryClueTree
{
	struct Node
	{
		char data;
		Node* rchild;
		Node* lchild;
		bool tag;
	};
	//false ��ʾװ�Ĳ��Ǻ��ӣ����Ǻ��

	Node * root;
	Node * pre;
public:
	BinaryClueTree() :root(nullptr), pre(nullptr)
	{
		PreOrderFormTree(root, 1);
	}


	//��򵥵������������
	void PreOrderFormTree(Node*& root, int index) //���򹹽�������
	{
		char ch = '#';
		cin >> ch;
		if (ch == '#')
		{
			root = nullptr;
			return;
		}

		//����һ���½ڵ�
		root = new Node;
		if (root == nullptr)
		{
			cerr << "ERROR:�ڴ治��" << endl;
			return;
		}

		root->data = ch;
		//�ڵ㱾�������
		cout << "����������" << index << endl;
		PreOrderFormTree(root->lchild, index + 1);

		cout << "����������" << index << endl;
		PreOrderFormTree(root->rchild, index + 1);
	}

	void PD()
	{
		PreOrder(root);
		cout << endl;
	}

	void PreOrder(Node * root)
	{
		if (root == nullptr)
		{
			return;
		}
		cout << root->data << ' ';
		PreOrder(root->lchild);
		if(root->tag)//��֪���ˣ��������������һ�£���Ϊ��������������£�rootû���Һ��ӣ���������rchild����Ϊ�գ����Բ�����Ϊ��Ҫ���ݣ�Ӧ����root->tag��Ϊ��Ҫ����
			PreOrder(root->rchild);
	}


	//��ʵ�������ģ�����������ӣ���ô��̾������ӣ������û�����ӣ���ô���ʱ�����Ǵ����Һ��ӵĺ�̾������ó���
	void PreOrderVisit()
	{
		Node * index = root;
		while (index != nullptr)
		{
			while (index->lchild != nullptr)
			{
				cout << index->data << ' ';
				index = index->lchild;
			}
			cout << index->data << ' ';
			index = index->rchild;
		}
		cout << endl;
	}

	void PreOrderForm()
	{
		PreOrderForm(root);
	}

	void PreOrderForm(Node* root)
	{
		if (root == nullptr)
			return;
		if (pre != nullptr)
		{
			pre->rchild = root;
			pre =nullptr;
		}

		if (root->rchild == nullptr)
		{
			root->tag = false;
			if (root->lchild != nullptr)
				root->rchild = root->lchild;
			else
				pre = root;
		}
		PreOrderForm(root->lchild);

		if(root->tag)//��仰����Ҫ����Ϊ���������Ѿ���rchild��ɲ���nullptr�ˣ������Ū�ͻ���£��������ж�
			PreOrderForm(root->rchild);
	}



};


int main()
{
	BinaryClueTree tree;
	tree.PD();
	tree.PreOrderForm();
	
	tree.PreOrderVisit();
	system("pause");
}
/*
��������
a
b
c
e
#
#
#
d
#
#
f
g
h
#
#
i
#
#
#

*/