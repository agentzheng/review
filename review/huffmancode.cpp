//�Գ���Ƶ����ΪȨֵӦ����û������ģ�����������������ô׷�ݻص�ԭ��������·
//�����⣬��ΪʲôҪ׷�ݻ�ȥ������Դ��ϵ���ѽ�����������㲻����lchild��rchild�𡣡����������Ծ����ͷŶ����
//�о������е�����
#include<iostream>
#include<vld.h>
#include<string>
using namespace std;
#define MAXVALUE  10000

struct HNode
{
	int weight;
	int parent;
	int lchild;
	int rchild;
	char value;
};        /* ���ṹ�� */

HNode * Create(int n)//һ����n��Ҷ�ӽڵ�ĺշ�������2*n-1���ڵ�
{
	int length = 2 * n - 1;
	HNode* tree = new HNode[length];
	for (int i = 0; i < n; i++)
	{
		tree[i].parent = -1;
		tree[i].lchild = -1;
		tree[i].rchild = -1;
		cout << "�������" << i << "��Ԫ�ص�Ȩֵ��ֵ,����Ԫ��˳����Ӱ��" << endl;
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
bool MergeTwoSmall(HNode * tree, int n)
{
	int minweight = MAXVALUE;
	int minid = -1;
	int subminweight = MAXVALUE;
	int subminid = -1;

	//ͨ��һ�α�������(parentΪ-1)����С������
	for (int i = 0; i < n; i++)
	{
		if (tree[i].parent != -1)//parentΪ-1��˼������������������ϵ�
			continue;

		if (tree[i].weight < minweight)
		{
			minweight = tree[i].weight;
			minid = i;
		}
		if (minweight <= tree[i].weight&&tree[i].weight<subminweight&&i != minid)
		{
			subminweight = tree[i].weight;
			subminid = i;
		}
	}

	if (subminid == -1)//�����˼�����Ѿ�ֻʣ��һ�����ˣ����ʱ������minidӦ�ò���Ϊ-1,����subminidȴ��-1
		return true;
	tree[minid].parent = tree[subminid].parent = n;
	tree[n].weight = subminweight + minweight;
	tree[n].lchild = minid;
	tree[n].rchild = subminid;

	return false;
}

void HuffmanTree(HNode * tree, int n)
{

	int t = n;
	while (!MergeTwoSmall(tree, t))
	{
		t++;
	}

	for (int i = 0; i < 2 * n - 1; i++)
	{
		cout << i << '\t' << tree[i].parent << "\t" << tree[i].weight << "\t" << tree[i].value << endl;
	}

}



void print(HNode* tree,int index,string str)
{
	if (tree[index].lchild == -1 && tree[index].rchild == -1)
	{
		cout << tree[index].value<<"="<<str << endl;
		return;
	}
	if (tree[index].lchild != -1)
		print(tree, tree[index].lchild, str + "0");
	if (tree[index].rchild != -1)
		print(tree, tree[index].rchild, str + '1');
}


void print(HNode * tree, int n)
{
	print(tree, 2 * n - 2, "");
}
int main()
{
	int n = 4;
	HNode* tree = Create(n);
	HuffmanTree(tree, n);
	print(tree, n);
	delete[] tree;
	system("pause");
}
