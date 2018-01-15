#include<iostream>
#include<stack>
#include<vld.h>

using namespace std;

bool is_valid(char * str)
{
	stack<char> temp;
	int i = 0;
	while (str[i] != '\0')
	{
		char ch = str[i];
		if (ch=='[' || ch == '(')
			temp.push(str[i]);
		else if (ch == ']')
		{
			ch=temp.top();
			temp.pop();
			if (ch != '[')
				return false;
		}
		else if (ch==')')
		{
			ch=temp.top();
			temp.pop();
			if (ch != '(')
				return false;
		}
		i++;
	}
	if(temp.empty())
		return true;
	return false;
}

int main()
{
	char str[300];
	while (cin >> str)
	{
		cout << is_valid(str);
	}
	system("pause");
	return 0;
}