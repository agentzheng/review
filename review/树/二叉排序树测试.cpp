#include "二叉排序树.h"
#include<iostream>
#include<vld.h>
using namespace std;

int main()
{	
	char ch = '\0';
	BinarySortTree<int> tree;
	while (ch != '#')
	{
		int i = 0;
		switch (ch)
		{
		case 'i':
			cout << "请输入你要插入的元素" << endl;
			cin >> i;
			if (cin.fail())
			{
				cin.clear();
				while (cin.get() != '\n');
				cout << "请不要调皮，输入数字" << endl;
				break;
			}
			tree.insert(i);
			break;
		case 'p':
			tree.print();
			break;
		case 'd' :
			cout << "请输入你要删除的元素" << endl;
			cin >> i;
			if (cin.fail())
			{
				cin.clear();
				while (cin.get() != '\n');
				cout << "请不要调皮，输入数字" << endl;
				break;
			}
			tree.remove(i);
			break;
		}
		tree.print();
		cout << "请输入你要执行的操作,i表示插入，d表示删除,p表示输出,输入#退出" << endl;
		cin >> ch;
	}
	system("pause");
	return 0;
}