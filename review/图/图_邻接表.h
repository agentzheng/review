#include<iostream>
using namespace std;
#include<queue>
template<class Type>
class Graph
{
	struct Node
	{
		int Vi;
		Node * next;
	};

	struct Vertex 
	{
		Type data;
		Node * head;
	};

	Vertex * G;
	int n;//顶点数
	int m;//边数
	bool * marked;
	queue<Node*> q;



public:
	Graph(int _n, int _m) :m(_m), n(_n), marked(new bool[_n] {0})
	{
		G = new Vertex[n];
		cout << "初始化顶点参数" << endl;
		for (int i = 0; i < n; i++)
		{
			cout << "请输入第" << i << "个顶点的值" << endl;
			cin >> G[i].data;
			G[i].head = nullptr;
		}
		cout << "初始化边参数" << endl;
		for (int i = 0; i < m; i++)
		{
			cout << "请输入第" << i << "条边的起点,终点，并用空格隔开,请注意第一个顶点是0" << endl;
			int index = -1,dest=-1;
			cin >>index>>dest;
			Append(G[index].head, dest);
		}
	}

	~Graph()
	{
		for (int i = 0; i < n; i++)
		{
			Node * ptr = G[i].head;
			while (ptr != nullptr)
			{
				Node * ptr2 = ptr;
				ptr = ptr->next;
				delete ptr2;
			}
		}
		delete[] G;
		delete[] marked;
	}


	

	void BFS(int k)
	{
		if (marked[k])
			return;
		cout << G[k].data << endl;
		marked[k] = true;
		q.push(G[k].head);
		while (!q.empty())
		{
			Node * ptr = q.front();
			q.pop();
			while (ptr != nullptr)
			{
				if (marked[ptr->Vi])
				{
					ptr = ptr->next;
					continue;
				}
				q.push(G[ptr->Vi].head);
				cout << G[ptr->Vi].data<<endl;
				marked[ptr->Vi] = true;
				ptr = ptr->next;
			}
		}
	}


	void BFS()
	{
		for (int i = 0; i < n; i++)
			BFS(i);
	}


	void Append(Node *&ptr,int dest)
	{
		if (ptr == nullptr)
		{
			ptr = new Node;
			ptr->Vi = dest;
			ptr->next = nullptr;
		}
		else
			Append(ptr->next, dest);
	}

	void DFS()
	{
		for (int i = 0; i < n; i++)
			DFS(i);
	}

	void DFS(int k)
	{
		if (marked[k])
			return;
		cout << G[k].data << endl;
		marked[k] = true;
		Node * ptr = G[k].head;
		while (ptr != nullptr)
		{
			DFS(ptr->Vi);
			ptr = ptr->next;
		}
	}


	


};
