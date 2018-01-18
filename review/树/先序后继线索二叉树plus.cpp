#include<iostream>
#include<stack>
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
	//false 表示装的不是孩子，而是后继

	Node * root;
	Node * pre;
public:
	BinaryClueTree() :root(nullptr), pre(nullptr)
	{
		PreOrderFormTree(root, 1);
	}


	//最简单的先序构造二叉树
	void PreOrderFormTree(Node*& root, int index) //先序构建二叉树
	{
		char ch = '#';
		cin >> ch;
		if (ch == '#')
		{
			root = nullptr;
			return;
		}

		//这是一个新节点
		root = new Node;
		if (root == nullptr)
		{
			cerr << "ERROR:内存不足" << endl;
			return;
		}
		root->tag = true;
		root->data = ch;
		//节点本身构造完毕
		cout << "构造左子树" << index << endl;
		PreOrderFormTree(root->lchild, index + 1);

		cout << "构造右子树" << index << endl;
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
		if(root->tag)//我知道了，这个东西是限制一下，因为在现在这种情况下，root没有右孩子，但是它的rchild并不为空，所以不能作为主要依据，应该以root->tag作为主要依据
			PreOrder(root->rchild);
	}


	//其实是这样的，如果他有左孩子，那么后继就是左孩子，如果他没有左孩子，那么这个时候我们存在右孩子的后继就派上用场了
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

		if(root->tag)//这句话很重要，因为你在上面已经把rchild变成不是nullptr了，如果再弄就会出事，必须先判断
			PreOrderForm(root->rchild);
	}

	void UnRecursivePreOrder()
	{
		Node * pointer = root;
		stack<Node*> S;
		while (!S.empty()||pointer)
		{
			while (pointer != nullptr)
			{
				cout << pointer->data << " ";
				S.push(pointer);
				pointer = pointer->lchild;
			}
			if (!S.empty())//pointer变右孩子的时候，我们顺便把它的双亲弹出来了，其实栈顶已经不是这个右孩子的双亲了，而是孩子的爷爷。。。
			{
				pointer = S.top();
				S.pop();
				pointer = pointer->rchild;
			}
		}
	}

};


int main()
{
	BinaryClueTree tree;
	//tree.PD();
	//tree.PreOrderForm();
	
	tree.UnRecursivePreOrder();
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