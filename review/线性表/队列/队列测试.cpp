#include"ѭ������.hpp"
#include<vld.h>

using namespace std;

int main()
{
	int n = 0;
	cout << "��������Ҫ���еĲ����Ĵ���" << endl;
	cin >> n;
	CycleQueue<int> queue(3);
	for (int i = 0; i < n; i++)
	{
		cout << "��������Ҫ���Ĳ�������ͷ��β����������ѡb����������ѡp����ȡ����ͷ��Ԫ���밴g����������ѡi�����c����ȡԪ�ظ��� n"<<endl;
		char ch;
		int t = 0;
		cin >> ch;
		switch (ch)
		{
			case 'b':
				queue.print();
				break;
			case 'i':
				cout << "������Ҫ��ջ��ֵ" << endl;
				cin >> t;
				queue.enQueue(t);
				queue.print();
				break;
			case 'p':
				if (queue.deQueue(t))
					cout << t << endl;
				else
					cout << "��ջʧ��" << endl;
				queue.print();
				break;
			case 'g':
				if (queue.get_front(t))
					cout << t << endl;
				else
					cout << "��ȡջ��Ԫ��ʧ��" << endl;
				break;
			case 'c':
				queue.clear();
				break;
			case 'n':
				cout <<"ջ�ĸ߶�Ϊ"<< queue.get_height() << endl;
				break;
		}
	}
	system("pause");
	return 0;
}




