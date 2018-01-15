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
		bool ltag;
	};
	//false 表示装的不是孩子，而是后继

	Node * root;
	Node * pre;
public:
	BinaryClueTree():root(nullptr),pre(nullptr)
	{
		PreOrderFormTree(root, 1);
	}

	void PreOrderFormTree(Node*& root,int index) //先序构建二叉树
	{
		char ch = '#';
		cin >> ch;
		if (ch == '#')
		{
			root = nullptr;
			return;
		}
		root = new Node;
		if (root == nullptr)
		{
			cerr << "ERROR:内存不足" << endl;
			return;
		}
		root->data = ch;
		if (pre != nullptr && !pre->tag)
		{
			pre->rchild = root;
			pre = nullptr;
		}
		cout << "构造左子树" << index<<endl;
		PreOrderFormTree(root->lchild,index+1);
		if (root->lchild == nullptr)
		{
			root->ltag = false;
		}
		cout << "构造右子树" <<index<< endl;
		PreOrderFormTree(root->rchild,index+1);
		if (root->rchild == nullptr)
		{
			root->tag = false;
			if (root->ltag)//如果有左孩子的话，那后继好像也不应该是左孩子哦，
				root->rchild = root->lchild;
			else
				pre = root;
		}		
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
		cout << root->data<<' ';
		PreOrder(root->lchild);
		if(root->tag)
			PreOrder(root->rchild);
	}



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

};


int main()
{
	BinaryClueTree tree;
	tree.PD();
	tree.PreOrderVisit();
	system("pause");
}
/*
测试数据
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