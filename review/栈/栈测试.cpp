#include"链栈.hpp"
#include<vld.h>

using namespace std;

int main()
{
	int n = 0;
	cout << "请输入你要进行的操作的次数" << endl;
	cin >> n;
	LinkedStock<int> stack;
	for (int i = 0; i < n; i++)
	{
		cout << "请输入你要做的操作，自底向上遍历栈请选b，pop请选p，push请选i，获取栈顶元素请选g，清空c，获取元素个数 n"<<endl;
		char ch;
		int t = 0;
		cin >> ch;
		switch (ch)
		{
			case 'b':
				stack.print();
				break;
			case 'i':
				cout << "请输入要进栈的值" << endl;
				cin >> t;
				stack.push(t);
				stack.print();
				break;
			case 'p':
				if (stack.pop(t))
					cout << t << endl;
				else
					cout << "出栈失败" << endl;
				stack.print();
				break;
			case 'g':
				if (stack.get_top(t))
					cout << t << endl;
				else
					cout << "获取栈顶元素失败" << endl;
				break;
			case 'c':
				stack.clear();
				break;
			case 'n':
				cout <<"栈的高度为"<< stack.get_height() << endl;
				break;
		}
	}

	
	system("pause");
	return 0;
}




