#include"ͼ_�ڽӱ�.h"
#include<iostream>
#include<vld.h>
using namespace std;

int main()
{
	int m = 0, n = 0;
	cout << "�����붥�����ͱ������ÿո����" << endl;
	cin >> n >> m;
	Graph<int> graph(n,m);
	graph.BFS();
	system("pause");
	return 0;
}