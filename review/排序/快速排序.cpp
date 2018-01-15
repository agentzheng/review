#include<iostream>
#include<vld.h>
#include"DoubleArr.h"
using namespace std;

//ϣ�����������һ����ʽ,��factcorΪ1ʱΪֱ�Ӳ�������
void HillInsertSort(int * arr, int n, int factor)
{
	if (factor < 1)
		return;
	for (int i = 0; i < factor; i++)
	{
		int sorted = i;
		for (sorted = i; sorted < n - factor; sorted += factor)
		{
			int j = sorted + factor;
			int sentinel = arr[j];
			while (sentinel < arr[j - factor] && j >= factor)
			{
				arr[j] = arr[j - factor];
				j -= factor;
			}
			arr[j] = sentinel;
		}
	}
	HillInsertSort(arr, n, factor - 1);
}

//ֱ�Ӳ�������
void InsertSort(int * arr,int n)
{
	HillInsertSort(arr, n, 1);
}


//ϣ������
void HillSort(int *arr, int n)
{
	int inc_factor = n / 2;//��ʼ����������
	HillInsertSort(arr, n, inc_factor);
}

//ð������
void BubbleSort(int * arr, int n)
{
	for (int i=n-1;i>0;i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

//��ѡ������
void SimpleSelectSort(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		int small = arr[i];
		int small_index = i;
		for (int j = i+1; j < n; j++)
		{
			if (arr[j] < small)
			{
				small = arr[j];
				small_index = j;
			}
		}
		arr[small_index] = arr[i];//
		arr[i] = small;//����С��ֵ����������еĵ�һ��
	}
}

//�����ѣ�������������ʵ����ֻ�ǰѵ�ǰ����Ϊparent�Ľڵ����µ������ŵ���Ӧ���ڵĵط�
void HeapAdjust(int* arr, int  parent, int length)//Ĭд����������ð�
{
	int temp = arr[parent];//�ݴ�parent�ڵ��ֵ��ʡ��һֱ����
	while (parent * 2+1 < length)
	{
		int j = parent * 2+1;
		if (j + 1 < length&&arr[j + 1] > arr[j])//����Һ��Ӵ��ڣ����һ������Ӵ�,��ô�Ͱ�j++
			j++;
		//�����ⲽ֮��arr[j]�������parent�����������������Ǹ�
		if (arr[j] > temp)
		{
			arr[parent] = arr[j];
			parent = j;
		}
		else //���else����˼������������������Ķ�û�����Լ����Ǿ�ûʲô��Ҫ���ˣ����������λ��
			break;
	}
	arr[parent] = temp;
}

void HeapSort(int * arr, int length)//������
{
	//��ʼ���󶥶ѣ����ܴ�С����
	for (int i = length / 2; i >= 0; i--)
	{
		HeapAdjust(arr, i, length);
	}

	//ȡ���Ѷ�Ԫ�أ��ŵ��ѳ��Ⱥ���һ��Ȼ����ν��i--������iָ���ǶѵĴ�С
	for (int i = length - 1; i > 0; i--)
	{
		int temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;
		HeapAdjust(arr, 0, i);

	}
}


//�鲢���� hello world 
void merge_sort(int* arr, int * help, int front, int rear)//������Ҫʵ�ĵ��𣬶���ʵ�ĵģ�����front��rear����װ�Ŷ�����,��������ܵ���
{
	if (front == rear)
		return;
	if ((front + 1 == rear) && arr[rear] < arr[front])
	{
		int temp = arr[front];
		arr[front] = arr[rear];
		arr[rear] = temp;
		return;
	}
	merge_sort(arr, help, front, (front + rear) / 2);
	merge_sort(arr, help, (front + rear) / 2 + 1, rear);
	
	int n = rear - front + 1;
	int first_ptr = front;
	int sec_ptr = (front + rear) / 2 + 1;

	for (int i = 0; i < n; i++)
	{
		if (first_ptr <= (front + rear) / 2 && (arr[first_ptr] < arr[sec_ptr] || sec_ptr>rear))
		{
			help[i] = arr[first_ptr];
			first_ptr++;
		}
		else
		{
			help[i] = arr[sec_ptr];
			sec_ptr++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		arr[i + front] = help[i];
	}

}

void merge_sort_util(int *arr, int n)
{
	int * help = new int[n];
	merge_sort(arr, help, 0, n - 1);
	delete[] help;
}

//��򵥰�ļ�������,����Ԫ�ص�ȡֵ��ΧΪ0-k
void CountSort(int* arr,int n,int k)
{
	const int length = k + 1;
	int* count = new int[length];
	int *help = new int[n];
	memset(count, 0, sizeof(int)*(length));//��ʼ������Ϊ0
	int i = 0;
	for (; i < n; i++)
		count[arr[i]]++;
	for (i=1; i < length; i++)
		count[i] += count[i - 1];
	for (i = n-1; i >=0; i--)
	{
		help[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	}
	for (i = 0; i < n; i++)
		arr[i] = help[i];
	delete[] help;
	delete[] count;
}


//��������front��rear����������ʵ�ĵ�
void QuickSort(int *arr, int front, int rear,int level=0)
{
	cout << "level="<<level << endl;
	int standerd = arr[front];
	int i = front;
	int j = rear;
	while (true)
	{
		while (arr[j] >=standerd&&i!=j)
			j--;
		while (arr[i] <= standerd&&i!=j)
			i++;
		if (i == j)
			break;
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	arr[front] = arr[i];
	arr[i] = standerd;
	for (int index = front; index <=rear; index++)
	{
		cout << arr[index] <<' ';
	}
	cout << endl;
	if(i-1>front)
		QuickSort(arr, front, i - 1,level+1);
	if(i+1<rear)
		QuickSort(arr, i+1,rear,level+1);
}

//�������� lenthΪ���λ��
void BaseSort(int * arr, int n,int length)
{
	for (int i = 0; i < length; i++)
	{
		DoubleArr<int> help(10, n, INT_MAX);
		DoubleArr<int> count(1, 10, 0);
		int div = pow(10, i);
		for (int j = 0; j < n; j++)
		{
			int temp = (arr[j] / div) % 10;
			help[temp][count[0][temp]] = arr[j];
			count[0][temp]++;
		}
		int index = 0;
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < count[0][j]; k++)
			{
				arr[index] = help[j][k];
				index++;
			}
		}
	}
}




int main()
{
	cout << "��������Ԫ�ظ���" << endl;
	int n = 0;
	cin >> n;
	int * arr = new int[n];
	cout << "��������" << n << "��Ԫ�أ����ÿհ��ַ�����" << endl;
	for (int i = 0; i < n; i++)
	{
		int tmp = 0;
		cin >> tmp;
		arr[i] = tmp;
	}
	cout << "��ʼ����" << endl;
	QuickSort(arr, 0,n-1);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
	delete[] arr;
	system("pause");
	return 0;
}
