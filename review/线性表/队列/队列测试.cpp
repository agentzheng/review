#include"循环队列.hpp"
#include<vld.h>

using namespace std;

int main()
{
	int n = 0;
	cout << "请输入你要进行的操作的次数" << endl;
	cin >> n;
	CycleQueue<int> queue(3);
	for (int i = 0; i < n; i++)
	{
		cout << "请输入你要做的操作，自头向尾遍历队列请选b，出队列请选p，获取队列头部元素请按g，进队列请选i，清空c，获取元素个数 n"<<endl;
		char ch;
		int t = 0;
		cin >> ch;
		switch (ch)
		{
			case 'b':
				queue.print();
				break;
			case 'i':
				cout << "请输入要进栈的值" << endl;
				cin >> t;
				queue.enQueue(t);
				queue.print();
				break;
			case 'p':
				if (queue.deQueue(t))
					cout << t << endl;
				else
					cout << "出栈失败" << endl;
				queue.print();
				break;
			case 'g':
				if (queue.get_front(t))
					cout << t << endl;
				else
					cout << "获取栈顶元素失败" << endl;
				break;
			case 'c':
				queue.clear();
				break;
			case 'n':
				cout <<"栈的高度为"<< queue.get_height() << endl;
				break;
		}
	}
	system("pause");
	return 0;
}




