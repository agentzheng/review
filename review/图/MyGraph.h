#pragma once
#include<iostream>
#include<set>
#include<vector>
#include <algorithm>  
#include<vld.h>//��������ڴ�й¶��
using namespace std;

template<class T>
class Graph
{
	int n;	//������
	T * vertex; //��������
	int**  Amatrix;//�ڽӾ���
	int** dis;
	int** path;
	bool direction;//�Ƿ�Ϊ����ͼ
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
		Amatrix = dis = path =NULL;// ��ʼ����Щָ��
		vertex = new T[n];
		for (int i = 0; i < n; i++)
		{
			cout << "�������" << i << "���ڵ��ֵ" << endl;
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
		} //��ʼ��
		int i = -1, j = -1, w = INT_MAX;
		while (true)
		{
			cout << "������ÿһ���ߵĲ��� ������ �յ���� Ȩֵ������ͼÿ����ֻ������һ�Σ����������뽫�����յ���Ϊ����" << endl;
			cin >> i >> j >> w;
			if (i<0 || j<0 || w<0)
				break;
			else
			{
				Amatrix[i][j] = w;
				if (!direction)//���������ͼ�Ǿ��ǶԳƵ�
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

	void MST_Prim()//��ʼ�Ľڵ�
	{
		if (direction)
		{
			cout << "�����ˣ���������,����������ͼ������ת�����㷨" << endl;
			return;
		}
		struct Cost
		{
			int Vi;
			int lowcost;
		};

		int init_index = 0;
		set<int> U; //����U
		set<int> ExpU;//����V-U
		vector<Cost> help;
		U.insert(init_index);
		for (int i = 0; i < n; i++)
		{
			if (i != init_index)
				ExpU.insert(i);
			help.push_back({ init_index,Amatrix[init_index][i] });
		}
		int now_index = init_index;
		//��ʼ���㷨
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

		vector<node> U; //����U
		set<node> ExpU;//����V-U

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
	
		cout << vertex[index1] << "��" << vertex[index2] << "����̾���Ϊ" << dis[index1][index2] << endl;
		int temp = 0;
		cout << " path: " << vertex[index1];
		temp = path[index1][index2];
		//ѭ�����;����ÿ��·����
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

		//��ʼ��
		for (int row = 0; row <n; row++) 
		{
			for (int col = 0; col <n; col++) 
			{
				//�Ѿ���D��ʼ��Ϊ�ڽӾ����ֵ
				dis[row][col] = Amatrix[row][col];
				//����P�ĳ�ֵ��Ϊ�����ߵ��յ㶥����±�
				path[row][col] = col;
			}
		}

		//����ѭ�������ڼ���ÿ����Ե����·��
		for (int k = 0; k <n; k++) 
		{
			for (int row = 0; row <n; row++) 
			{
				for (int col = 0; col <n; col++) 
				{
					//Ϊ�˷�ֹ�����������Ҫ����һ��selectֵ
					int select = (dis[row][k] == INT_MAX || dis[k][col] == INT_MAX) ? INT_MAX : (dis[row][k] + dis[k][col]);
					if (dis[row][col] > select) {
						//�������ǵ�D����
						dis[row][col] = select;
						//�������ǵ�P����
						path[row][col] = path[row][k];
					}
				}
			}

		}
		//�㶨��
		searched = true;
	}
	
	
};
