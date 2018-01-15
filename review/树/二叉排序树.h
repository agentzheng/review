#include<iostream>

template<class Type>
class BinarySortTree
{
	struct Node
	{
		Type data;
		Node * lchild;
		Node * rchild;
		Node * pre;
	};

	Node * root;

	void DeleteTree(Node* head)//递归地删除二叉树
	{
		if (head == nullptr)
			return;
		DeleteTree(head->lchild);
		DeleteTree(head->rchild);
		delete head;
	}
	
	Node*  get_prev(Node * index)//获得index的中序前驱指针
	{
		Node *prev = index->lchild;
		if (prev==nullptr)
			return prev;
		Node *temp = prev;
		while (temp->lchild != nullptr)
		{
			prev = temp;
			temp = temp->rchild;
		}
		return prev;
	}


	bool remove(Node * index)
	{
		if (index == nullptr)
		{
			std::cout << "移除失败，本来就没有你移个啥" << std::endl;
			return false;
		}

		if (index==root)//如果要删除的是根结点
		{
			Node * q = get_prev(index);
			if (q==nullptr)
			{
				q=root;
				root = root->rchild;
				delete q;//这里的q只是我用来存储临时而已
				if (root != nullptr)
					root->pre = nullptr;
				return true;
			}
			index->data = q->data;
			remove(q);
			return true;
		}

		//这个是引用（*index->pre）的指向index的那个指针,这个东西可不能随便改
		Node*& ptr_to_index = (index == index->pre->rchild) ? index->pre->rchild : index->pre->lchild;

		//接下来分三种情况
		if (index->lchild == nullptr&&index->rchild == nullptr)//1.index为叶子节点
			ptr_to_index = nullptr;
		else if (index->rchild != nullptr)//右子树不为空
		{
			ptr_to_index = index->rchild;
			index->rchild->pre = index->pre;
		}
		else if (index->lchild != nullptr)//左子树不为空
		{
			ptr_to_index = index->lchild;
			index->lchild->pre = index->pre;
		}
		else//两棵子树都不为空,取出index的直接前驱，然后直接替换index的data就行了
		{
			Node * prev = get_prev(index);
			index->data = prev->data;
			index = nullptr;
			remove(prev);
		}
		delete index;
		return true;
	}

	


	Node* search(Node * head,Type data)
	{
		if (head == nullptr)
			return nullptr;
		if (head->data == data)
			return head;
		Node * index = nullptr;
		if(data<head->data)//data应该在左子树当中
			index=search(head->lchild,data);
		else
			index = search(head->rchild,data);//data如果有的话应该在右子树当中
		return index;
	}

	//这是一个递归的中序遍历
	void print(Node * head)
	{
		if (head == nullptr)
			return;
		print(head->lchild);
		std::cout << head->data << ' ';
		print(head->rchild);
		if (head == root)
			std::cout << endl;
	}
	
	Node * insert(Node * head, Type data)
	{
		if (head == nullptr)
		{
			head = new Node;
			head->lchild = nullptr;
			head->rchild = nullptr;
			head->pre = NULL;
			head->data = data;
			return head;
		}

		int cmp = data-head->data;
		if (cmp != 0)
		{
			Node*& child = cmp > 0 ? head->rchild : head->lchild;
			child = insert(child, data);
			child->pre = head;
		}
		else
			cout << "已经在树里面了" << endl;
		return head;
	}



public:
	BinarySortTree():root(nullptr)
	{
		//当root==nullptr时树为空；
	}

	~BinarySortTree()
	{
		DeleteTree(root);
	}


	

	bool insert(Type data)
	{
		root = insert(root,data);
		return true;
	}
	

	/*
	bool insert(Type data)
	{
		//返回出来的index是有4种可能,如果空，那么整棵树为空，可能正好和data一样，也有可能是要插入在子树当中的
		Node * index = where_to_insert(root,data);
		Node * index_bak = index;
		if (index == nullptr)//这说明整棵树都是空的
		{
			root = new Node;
			index = root;
		}
		else if (index->data == data)//相等
		{
			std::cout << "已在树中" << std::endl;
			return true;
		}
		else if (data > index->data)//应该放在右孩子
		{
			index->rchild = new Node;
			index = index->rchild;
		}
		else //放在左孩子
		{
			index->lchild = new Node;
			index = index->lchild;
		}
		if (index == nullptr)//如果申请空间失败
			return false;
		index->pre = index_bak;
		index->data = data;
		index->rchild = nullptr;
		index->lchild = nullptr;
		return true;
	}
	/*
	Node* where_to_insert(Node * head,Type data)
	{
		if (head == nullptr)
			return nullptr;
		if (head->data == data)
			return head;
		//要么在左子树查找要么在右子树查找
		Node * index = (data>head->data)? where_to_insert(head->rchild,data):where_to_insert(head->lchild,data);

		if (index == nullptr)//如果上面找不到，说明就应该放在head下面了
			return head;
		return index;
	}
	*/

	Node* search(Type data)
	{
		return search(root, data);
	}

	bool remove(Type data)//向外暴露的接口
	{
		Node* index = search(data);
		int cmp = data - head->data;
		if (cmp != 0)
		{
			Node*& child = cmp > 0 ? head->rchild : head->lchild;
			child = remove(child, data);
			child->pre = head;
		}
		else//那么就要删掉head了。
		{

		}
		return remove(index);
	}

	void print()
	{
		print(root);
	}

	

};


