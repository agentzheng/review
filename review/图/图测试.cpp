#include"ͼ_�ڽӾ���.h"
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

/*��������
8 7

0

1

2

3

4

5

6

7


0 1

1 2

2 4

1 3

7 6

3 5

0 7

*/