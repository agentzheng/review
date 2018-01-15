#pragma once
#include<iostream>
#include<set>
#include<vector>
#include <algorithm>  
#include<vld.h>//用来检测内存泄露的
using namespace std;

template<class T>
class Graph
{
	int n;	//顶点数
	T * vertex; //顶点内容
	int**  Amatrix;//邻接矩阵
	int** dis;
	int** path;
	bool direction;//是否为有向图
	bool searched;
	Graph();

	void get2d(int**& pointer,int layer)
	{
		pointer = new   int*[layer];
		for (int i = 0; i<layer; i++)
			pointer[i] = new   int[layer];
	}

	void free2d(int**& pointer,int layer)
	{
		if (!pointer)
			return;
		for (int i = 0; i < layer; i++)
			delete[] pointer[i];
		delete[] pointer;
	}
	
public:
	Graph(int N, bool dir) :n(N), direction(dir),searched(false)
	{
		Amatrix = dis = path =NULL;// 初始化这些指针
		vertex = new T[n];
		for (int i = 0; i < n; i++)
		{
			cout << "请输入第" << i << "个节点的值" << endl;
			cin >> vertex[i];
		}
		init_amatrix();
	}

	void init_amatrix()
	{
		get2d(Amatrix, n);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == j)
					Amatrix[i][j] = 0;
				else
					Amatrix[i][j] = INT_MAX;
			}
		} //初始化
		int i = -1, j = -1, w = INT_MAX;
		while (true)
		{
			cout << "请输入每一条边的参数 起点序号 终点序号 权值，无向图每条边只需输入一次，结束输入请将起点或终点置为负数" << endl;
			cin >> i >> j >> w;
			if (i<0 || j<0 || w<0)
				break;
			else
			{
				Amatrix[i][j] = w;
				if (!direction)//如果是无向图那就是对称的
					Amatrix[j][i] = w;
			}
		}

	}

	~Graph()
	{
		free2d(Amatrix,n);
		free2d(path, n);
		free2d(dis, n);
		delete[] vertex;
	}

	void MST_Prim()//初始的节点
	{
		if (direction)
		{
			cout << "做不了，溜了溜了,你这是有向图，请左转朱刘算法" << endl;
			return;
		}
		struct Cost
		{
			int Vi;
			int lowcost;
		};

		int init_index = 0;
		set<int> U; //集合U
		set<int> ExpU;//集合V-U
		vector<Cost> help;
		U.insert(init_index);
		for (int i = 0; i < n; i++)
		{
			if (i != init_index)
				ExpU.insert(i);
			help.push_back({ init_index,Amatrix[init_index][i] });
		}
		int now_index = init_index;
		//初始化算法
		while (!ExpU.empty())
		{
			int min_index = -1;
			int min_cost = INT_MAX;
			for (int i = 0; i < n; i++)
			{
				if (help[i].lowcost > 0 && help[i].lowcost < min_cost&&ExpU.find(i) != ExpU.end() && U.find(help[i].Vi) != U.end())
				{
					min_index = i;
					min_cost = help[i].lowcost;
				}
			}
			ExpU.erase(ExpU.find(min_index));
			U.insert(min_index);
			for (int i = 0; i < n; i++)
			{
				if (Amatrix[min_index][i] < help[i].lowcost&&Amatrix[min_index]>0 && ExpU.find(i) != ExpU.end())
				{
					help[i].Vi = min_index;
					help[i].lowcost = Amatrix[min_index][i];
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			cout << i << " ";
		}
		cout << endl;
		for (int i = 0; i < n; i++)
		{
			cout << help[i].Vi << " ";
		}
		cout << endl;
		for (int i = 0; i < n; i++)
		{
			cout << help[i].lowcost << " ";
		}
		cout << endl;

	}
	
	void toposort()
	{
		struct node
		{
			int index;
			int indegree;
		};

		bool idez(node v)
		{
			if (v.indegree == 0)
				return true;
			else
				return false;
		}

		set<node>::iterator find_index(set<node>& ExpU,int index)
		{
			set<node>::iterator it = ExpU.begin();
			for (; it != ExpU.end(); it++)
			{
				if (index == it->index)
					break;
			}
			return it;
		}

		vector<node> U; //集合U
		set<node> ExpU;//集合V-U

		int ** linkable = new int*[n];
		for (int i = 0; i < n; i++)
			linkable[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			int ID = 0;
			for (int i = 0; i < n; i++)
			{
				if (Amatrix[i][j] > 0 && Amatrix[i][j] < MAX)
				{
					ID++;
					linkable[i][j] = 1;
				}
			}
			ExpU.insert({ j,ID });
		}
		set<node>::iterator it = find_if(ExpU.begin(), ExpU.end(), idez) != ExpU.end();
		while (!ExpU.empty() && it!=ExpU.end())
		{
			
			for (int j = 0; j < n; j++)
			{
				if (linkable[it->index][j])
				{
					f
				}
			}

			U.push_back(*it);
			ExpU.erase(it);

			it = find_if(ExpU.begin(), ExpU.end(), idez) != ExpU.end();
		}
	}


	void search(int index1, int index2)
	{
		if (!searched)
			Floyd();
	
		cout << vertex[index1] << "到" << vertex[index2] << "的最短距离为" << dis[index1][index2] << endl;
		int temp = 0;
		cout << " path: " << vertex[index1];
		temp = path[index1][index2];
		//循环输出途径的每条路径。
		while (temp != index2)
		{
			cout << "-->"  << vertex[temp];
			temp = path[temp][index2];
		}
		cout << "-->"  << vertex[index2] << endl;
	}
	
	void Floyd() 
	{
		get2d(dis, n);
		get2d(path, n);

		//初始化
		for (int row = 0; row <n; row++) 
		{
			for (int col = 0; col <n; col++) 
			{
				//把矩阵D初始化为邻接矩阵的值
				dis[row][col] = Amatrix[row][col];
				//矩阵P的初值则为各个边的终点顶点的下标
				path[row][col] = col;
			}
		}

		//三重循环，用于计算每个点对的最短路径
		for (int k = 0; k <n; k++) 
		{
			for (int row = 0; row <n; row++) 
			{
				for (int col = 0; col <n; col++) 
				{
					//为了防止溢出，所以需要引入一个select值
					int select = (dis[row][k] == INT_MAX || dis[k][col] == INT_MAX) ? INT_MAX : (dis[row][k] + dis[k][col]);
					if (dis[row][col] > select) {
						//更新我们的D矩阵
						dis[row][col] = select;
						//更新我们的P矩阵
						path[row][col] = path[row][k];
					}
				}
			}

		}
		//搞定了
		searched = true;
	}
	
	
};
