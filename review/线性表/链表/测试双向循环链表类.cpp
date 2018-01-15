#include"dualcyclelinklist.hpp"
#include <vld.h>

int main()
{
	DualCycleLinkList<int> lists;
	int n = 0;
	cout << "请输入要放入表中的元素" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp = 0;
		cin >> temp;
		lists.push_back(temp);
	}
	lists.prints();


	cout << "遍插茱萸少一人" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << lists[i] << " ";
	}
	cout << endl;

	system("pause");
}