#include<iostream>
using namespace std;
#include<queue>
#include<algorithm>
#include<vector>


template<class Type>
class Undirect_Graph
{
	class Edge
	{
public:
		int src;
		int dest;
		double weight;

		bool operator<(Edge& e1 )
		{
			return weight < e1.weight;
		}

	};
	
	struct Node
	{
		Edge * edge;
		Node * next;
	};

	struct Vertex
	{
		Type data;
		Node * head;
	};

	Edge * E;
	Vertex * G;
	int n;//顶点数
	int m;//边数
	int * marked;


public:
	Undirect_Graph(int _n, int _m) :m(_m), n(_n), marked(new int[_n])
	{
		fill(marked, marked + n * sizeof(int),-1);
		G = new Vertex[n];
		cout << "初始化顶点参数" << endl;
		for (int i = 0; i < n; i++)
		{
			cout << "请输入第" << i << "个顶点的值" << endl;
			cin >> G[i].data;
			G[i].head = nullptr;
		}
		E = new Edge[m];
		cout << "初始化边参数" << endl;
		for (int i = 0; i < m; i++)
		{
			cout << "请输入第" << i << "条边的起点,终点，权值并用空格隔开,请注意第一个顶点是0" << endl;
			cin >> E[i].src >> E[i].dest>>E[i].weight;
			Append(G[E[i].src].head, &E[i]);
			Append(G[E[i].dest].head, &E[i]);
		}
	}

	~Undirect_Graph()
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
		delete[] E;
		delete[] marked;
	}

	void Append(Node *&ptr,Edge* edge)
	{
		if (ptr == nullptr)
		{
			ptr = new Node;
			ptr->edge = edge;
			ptr->next = nullptr;
		}
		else
			Append(ptr->next, edge);
	}
	



	void Prim()
	{
		queue<Edge> mst;
		priority_queue<Edge> pq;
		marked[0] = true;
		enqueue(0, pq);
		while (pq.size()!=0)
		{
			Edge crossing = pq.top();
			int newone = marked[crossing.src] ? crossing.dest : crossing.src;
			mst.push(crossing);
			marked[newone] = true;
			enqueue(newone,pq);
			dequeue(pq);
		}
		while (mst.size()!=0)
		{
			cout << mst.front().src << "," << mst.front().dest << endl;
			mst.pop();
		}
	}

	void enqueue(int k,priority_queue<Edge>& pq)
	{
		Node* ptr = G[k].head;
		while (ptr != nullptr)
		{
			pq.push(*(ptr->edge));
			ptr = ptr->next;
		}
	}


	void dequeue(priority_queue<Edge>& pq)
	{
		for (int i = 0; i < n; i++)
			cout << marked[i];
		queue<Edge> q;
		cout << endl;
		
		while (pq.size()!=0)
		{
			Edge temp = pq.top();
			pq.pop();
			if (!marked[temp.src]||!marked[temp.dest])
				q.push(temp);
		}
		while (q.size()!=0)
		{
			pq.push(q.front());
			q.pop();
		}
	}



	void kruskal()
	{
		vector<Edge> edges;
		vector<Edge> mst;
		for (int i = 0; i < m; i++)
			edges.push_back(E[i]);
		sort(edges.begin(),edges.end());
		for (vector<Edge>::iterator it = edges.begin(); it != edges.end(); it++)
		{
			if (marked[it->src] != -1 && marked[it->dest] != -1)
				continue;
			if (marked[it->src]==-1)
				marked[it->src] = it->dest;
			if (marked[it->dest]==-1)
				marked[it->dest] = it->src;
			mst.push_back(*it);
		}

		for (vector<Edge>::iterator it = mst.begin(); it != mst.end(); it++)
		{
			cout << it->src << "," << it->dest << endl;
		}
		for (int i = 0; i < n; i++)
		{
			cout << marked[i] << endl;
		}
		
	}


};
