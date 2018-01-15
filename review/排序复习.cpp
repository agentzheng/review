#include<iostream>
#include<vld.h>
#include"DoubleArr.h"
using namespace std;

//希尔插入排序的一般形式,当factcor为1时为直接插入排序
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

//直接插入排序
void InsertSort(int * arr,int n)
{
	HillInsertSort(arr, n, 1);
}


//希尔排序
void HillSort(int *arr, int n)
{
	int inc_factor = n / 2;//初始化增量因子
	HillInsertSort(arr, n, inc_factor);
}

//冒泡排序
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

//简单选择排序
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
		arr[i] = small;//将最小的值变成无序序列的第一个
	}
}

//调整堆，这里做的事情实际上只是把当前索引为parent的节点向下调整，放到它应该在的地方
void HeapAdjust(int* arr, int  parent, int length)//默写出来还行你好啊
{
	int temp = arr[parent];//暂存parent节点的值，省的一直交换
	while (parent * 2+1 < length)
	{
		int j = parent * 2+1;
		if (j + 1 < length&&arr[j + 1] > arr[j])//如果右孩子存在，而且还比左孩子大,那么就把j++
			j++;
		//上面这步之后，arr[j]代表的是parent的两个孩子中最大的那个
		if (arr[j] > temp)
		{
			arr[parent] = arr[j];
			parent = j;
		}
		else //这个else的意思就是如果两个孩子最大的都没有它自己大，那就没什么必要换了，这就是他的位置
			break;
	}
	arr[parent] = temp;
}

void HeapSort(int * arr, int length)//堆排序
{
	//初始化大顶堆，才能从小到大
	for (int i = length / 2; i >= 0; i--)
	{
		HeapAdjust(arr, i, length);
	}

	//取出堆顶元素，放到堆长度后面一格，然后将所谓的i--，这里i指的是堆的大小
	for (int i = length - 1; i > 0; i--)
	{
		int temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;
		HeapAdjust(arr, 0, i);

	}
}


//归并排序 hello world 
void merge_sort(int* arr, int * help, int front, int rear)//这两个要实心的吗，都是实心的，就是front和rear都是装着东西的,辅助数组很蛋疼
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

//最简单版的计数排序,数组元素的取值范围为0-k
void CountSort(int* arr,int n,int k)
{
	const int length = k + 1;
	int* count = new int[length];
	int *help = new int[n];
	memset(count, 0, sizeof(int)*(length));//初始化数组为0
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


//快速排序，front和rear这两个都是实心的
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

//基数排序 lenth为最多位数
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
	cout << "请输入总元素个数" << endl;
	int n = 0;
	cin >> n;
	int * arr = new int[n];
	cout << "请输入如" << n << "个元素，并用空白字符隔开" << endl;
	for (int i = 0; i < n; i++)
	{
		int tmp = 0;
		cin >> tmp;
		arr[i] = tmp;
	}
	cout << "开始排序" << endl;
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
