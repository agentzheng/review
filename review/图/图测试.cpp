#include"图_邻接矩阵.h"
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

/*测试数据
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