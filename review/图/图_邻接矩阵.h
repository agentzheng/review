#include<iostream>
#include"../Matrix.h"
using namespace std;
#include<queue>
template<class Type>
class Graph
{
	Matrix<int> linkmat;
	Type * G;
	int n;//顶点数
	int m;//边数
	bool * marked;
	queue<int> q;

public:
	Graph(int _n, int _m) :m(_m), n(_n), marked(new bool[_n] {0}),linkmat(_n,_n,0)
	{
		G = new Type[n];
		cout << "初始化顶点参数" << endl;
		for (int i = 0; i < n; i++)
		{
			cout << "请输入第" << i << "个顶点的值" << endl;
			cin >> G[i];
		}
		cout << "初始化边参数" << endl;
		for (int i = 0; i < m; i++)
		{
			cout << "请输入第" << i << "条边的起点,终点，并用空格隔开,请注意第一个顶点是0" << endl;
			int src = -1, dest = -1;
			cin >> src >> dest;
			linkmat(src,dest) = 1;
		}
	}
	~Graph()
	{
		delete[] G;
		delete[] marked;
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
		cout << G[k] << endl;
		marked[k] = true;
		for (int i = 0; i < n; i++)
		{
			if (linkmat[k][i] != 0)
				DFS(i);
		}
	}

	void BFS()
	{
		for (int i = 0; i < n; i++)
			BFS(i);
	}

	void BFS(int k)
	{
		if (marked[k])
			return;
		cout << G[k] << endl;
		marked[k] = true;
		q.push(k);
		while (!q.empty())
		{
			int index = q.front();
			q.pop();
			for (int i = 0; i < n; i++)
			{
				if (linkmat(index,i) != 0)
				{
					if (marked[i])
						continue;
					cout << G[i] << endl;
					marked[i] = true;
					q.push(i);
				}
			}
		}
	}




};
