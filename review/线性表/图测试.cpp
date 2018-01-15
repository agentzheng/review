#include"图_邻接表.h"
#include<iostream>
#include<vld.h>
using namespace std;

int main()
{
	int m = 0, n = 0;
	cout << "请输入顶点数和边数，用空格隔开" << endl;
	cin >> n >> m;
	Graph<int> graph(n,m);
	graph.BFS();
	system("pause");
	return 0;
}