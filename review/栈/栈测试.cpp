#include"��ջ.hpp"
#include<vld.h>

using namespace std;

int main()
{
	int n = 0;
	cout << "��������Ҫ���еĲ����Ĵ���" << endl;
	cin >> n;
	LinkedStock<int> stack;
	for (int i = 0; i < n; i++)
	{
		cout << "��������Ҫ���Ĳ������Ե����ϱ���ջ��ѡb��pop��ѡp��push��ѡi����ȡջ��Ԫ����ѡg�����c����ȡԪ�ظ��� n"<<endl;
		char ch;
		int t = 0;
		cin >> ch;
		switch (ch)
		{
			case 'b':
				stack.print();
				break;
			case 'i':
				cout << "������Ҫ��ջ��ֵ" << endl;
				cin >> t;
				stack.push(t);
				stack.print();
				break;
			case 'p':
				if (stack.pop(t))
					cout << t << endl;
				else
					cout << "��ջʧ��" << endl;
				stack.print();
				break;
			case 'g':
				if (stack.get_top(t))
					cout << t << endl;
				else
					cout << "��ȡջ��Ԫ��ʧ��" << endl;
				break;
			case 'c':
				stack.clear();
				break;
			case 'n':
				cout <<"ջ�ĸ߶�Ϊ"<< stack.get_height() << endl;
				break;
		}
	}

	
	system("pause");
	return 0;
}




