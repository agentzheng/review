#include "����������.h"
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
			cout << "��������Ҫ�����Ԫ��" << endl;
			cin >> i;
			if (cin.fail())
			{
				cin.clear();
				while (cin.get() != '\n');
				cout << "�벻Ҫ��Ƥ����������" << endl;
				break;
			}
			tree.insert(i);
			break;
		case 'p':
			tree.print();
			break;
		case 'd' :
			cout << "��������Ҫɾ����Ԫ��" << endl;
			cin >> i;
			if (cin.fail())
			{
				cin.clear();
				while (cin.get() != '\n');
				cout << "�벻Ҫ��Ƥ����������" << endl;
				break;
			}
			tree.remove(i);
			break;
		}
		tree.print();
		cout << "��������Ҫִ�еĲ���,i��ʾ���룬d��ʾɾ��,p��ʾ���,����#�˳�" << endl;
		cin >> ch;
	}
	system("pause");
	return 0;
}