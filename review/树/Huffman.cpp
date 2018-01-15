#include<iostream>
#include<vld.h>
using namespace std;
#define MAXVALUE  10000

struct HNode
{
	int weight;
	int parent;
	int lchild;
	int rchild;
	char value;
} ;        /* 结点结构体 */

HNode * Create(int n)//一棵有n个叶子节点的赫夫曼树有2*n-1个节点
{
	int length = 2 * n - 1;
	HNode* tree = new HNode[length];
	for (int i = 0; i < n; i++)
	{
		tree[i].parent = -1;
		tree[i].lchild = -1;
		tree[i].rchild = -1;
		cout << "请输入第" << i << "个元素的权值和值,输入元素顺序无影响" << endl;
		cin >> tree[i].weight >> tree[i].value;
	}
	for (int i = n; i < length; i++)
	{
		tree[i].parent = -1;
		tree[i].lchild = -1;
		tree[i].rchild = -1;
		tree[i].weight = MAXVALUE;
		tree[i].value = '\0';
	}

	return tree;
}



 bool MergeTwoSmall(HNode * tree,int n)
{
	 int minweight = MAXVALUE;
	 int minid = -1;
	 int subminweight = MAXVALUE;
	 int subminid = -1;
	 
	 //通过一次遍历挑出(parent为-1)中最小的两个
	 for (int i = 0; i < n; i++)
	 {
		if (tree[i].parent != -1)//parent为-1意思就是他现在是这个集合的
			 continue;
		 
		if (tree[i].weight < minweight)
		{
			minweight = tree[i].weight;
			minid = i;
		}
		if(minweight<=tree[i].weight&&tree[i].weight<subminweight&&i!=minid)
		{
			subminweight = tree[i].weight;
			subminid = i;
		}
	 }
	
	 if (subminid == -1)//这个意思就是已经只剩下一棵树了，这个时候我想minid应该不是为-1,但是subminid却是-1
		 return true;
	 tree[minid].parent = tree[subminid].parent = n;
	 tree[n].weight = subminweight + minweight;
	 tree[n].lchild = minid;
	 tree[n].rchild = subminid;

	 return false ;
}

void HuffmanTree(HNode * tree,int n)
{	
	
	int t = n;
	while (!MergeTwoSmall(tree, t))
	{
		t++;
	}

	for (int i = 0; i < 2 * n - 1; i++)
	{
		cout << i << '\t' << tree[i].parent <<"\t"<< tree[i].weight <<"\t"<< tree[i].value << endl;
	}

}



int main()
{
	int n = 4;
	HNode* tree = Create(n);
	HuffmanTree(tree, n);
	delete [] tree;
	system("pause");
}
