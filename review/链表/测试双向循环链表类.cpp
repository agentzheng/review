#include"dualcyclelinklist.hpp"
#include <vld.h>

int main()
{
	DualCycleLinkList<int> lists;
	int n = 0;
	cout << "������Ҫ������е�Ԫ��" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp = 0;
		cin >> temp;
		lists.push_back(temp);
	}
	lists.prints();


	cout << "���������һ��" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << lists[i] << " ";
	}
	cout << endl;

	system("pause");
}