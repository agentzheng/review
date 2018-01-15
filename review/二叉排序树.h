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

	void DeleteTree(Node* head)//�ݹ��ɾ��������
	{
		if (head == nullptr)
			return;
		DeleteTree(head->lchild);
		DeleteTree(head->rchild);
		delete head;
	}
	
	Node*  get_prev(Node * index)//���index������ǰ��ָ��
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
			std::cout << "�Ƴ�ʧ�ܣ�������û�����Ƹ�ɶ" << std::endl;
			return false;
		}

		if (index==root)//���Ҫɾ�����Ǹ����
		{
			Node * q = get_prev(index);
			if (q==nullptr)
			{
				q=root;
				root = root->rchild;
				delete q;//�����qֻ���������洢��ʱ����
				if (root != nullptr)
					root->pre = nullptr;
				return true;
			}
			index->data = q->data;
			remove(q);
			return true;
		}

		//��������ã�*index->pre����ָ��index���Ǹ�ָ��,��������ɲ�������
		Node*& ptr_to_index = (index == index->pre->rchild) ? index->pre->rchild : index->pre->lchild;

		//���������������
		if (index->lchild == nullptr&&index->rchild == nullptr)//1.indexΪҶ�ӽڵ�
			ptr_to_index = nullptr;
		else if (index->rchild != nullptr)//��������Ϊ��
		{
			ptr_to_index = index->rchild;
			index->rchild->pre = index->pre;
		}
		else if (index->lchild != nullptr)//��������Ϊ��
		{
			ptr_to_index = index->lchild;
			index->lchild->pre = index->pre;
		}
		else//������������Ϊ��,ȡ��index��ֱ��ǰ����Ȼ��ֱ���滻index��data������
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
		if(data<head->data)//dataӦ��������������
			index=search(head->lchild,data);
		else
			index = search(head->rchild,data);//data����еĻ�Ӧ��������������
		return index;
	}

	//����һ���ݹ���������
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
			cout << "�Ѿ�����������" << endl;
		return head;
	}



public:
	BinarySortTree():root(nullptr)
	{
		//��root==nullptrʱ��Ϊ�գ�
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
		//���س�����index����4�ֿ���,����գ���ô������Ϊ�գ��������ú�dataһ����Ҳ�п�����Ҫ�������������е�
		Node * index = where_to_insert(root,data);
		Node * index_bak = index;
		if (index == nullptr)//��˵�����������ǿյ�
		{
			root = new Node;
			index = root;
		}
		else if (index->data == data)//���
		{
			std::cout << "��������" << std::endl;
			return true;
		}
		else if (data > index->data)//Ӧ�÷����Һ���
		{
			index->rchild = new Node;
			index = index->rchild;
		}
		else //��������
		{
			index->lchild = new Node;
			index = index->lchild;
		}
		if (index == nullptr)//�������ռ�ʧ��
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
		//Ҫô������������Ҫô������������
		Node * index = (data>head->data)? where_to_insert(head->rchild,data):where_to_insert(head->lchild,data);

		if (index == nullptr)//��������Ҳ�����˵����Ӧ�÷���head������
			return head;
		return index;
	}
	*/

	Node* search(Type data)
	{
		return search(root, data);
	}

	bool remove(Type data)//���Ⱪ¶�Ľӿ�
	{
		Node* index = search(data);
		int cmp = data - head->data;
		if (cmp != 0)
		{
			Node*& child = cmp > 0 ? head->rchild : head->lchild;
			child = remove(child, data);
			child->pre = head;
		}
		else//��ô��Ҫɾ��head�ˡ�
		{

		}
		return remove(index);
	}

	void print()
	{
		print(root);
	}

	

};


