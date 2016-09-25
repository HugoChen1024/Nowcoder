
//对于一个int数组，请编写一个选择冒泡算法，对数组元素排序。
//给定一个int数组A及数组的大小n，请返回排序后的数组。
//测试样例：
//[1, 2, 3, 5, 2, 3], 6
//[1, 2, 2, 3, 3, 5]


#include <iostream> 
using namespace std;
#include<string>



void printResult(string str,int* A,int n)
{
	cout << str << "的结果:\n";
	for (int i = 0; i < n; i++)
	{
		cout << A[i] <<" ";
	}
	cout << endl;
}

void swap(int a, int b)
{
	int temp=a;
	a = b;
	b = a;
}

class BubbleSort {
public:
	int* bubbleSort(int* A, int n) {
		// write code here
		for (int i = 0; i<n; i++)
		{
			for (int j = 0; j<n - i - 1; j++)
			{
				if (A[j]>A[j + 1])
				{
					int temp = A[j];
					A[j] = A[j + 1];
					A[j + 1] = temp;
				}
			}
		}
		return A;
	}
};


//请编写一个选择排序算法
class SelectionSort {
public:
	int* selectionSort(int* A, int n) {
		// write code here
		int k = 0;
		for (int i = 0; i < n-1; i++)
		{
			k = i;
			for (int j = i; j < n; j++)
			{
				if (A[k]>A[j])
				{
					k = j;
				}
			}
			if (k!=i)
			{
				int temp = A[i];
				A[i] = A[k];
				A[k] = temp;
			}
		}
		return A;
	}
};

//请编写一个选择插入算法

class InsertionSort
{
public:
	int* insertionSort(int* A, int n)
	{
		for (int i = 1; i < n; i++)
		{
			int temp = A[i];
			int j = i - 1;
			for (; j >= 0;j--)   //j前面的已经排好序，从后面往前比较，当没有比当前值大的时候bereak;
			{
				if (A[j]>temp)
				{
					A[j + 1] = A[j];
				}
				else
				{
					break;
				}
			}
			A[j + 1] = temp;
		}
		return A;
	}
};


int main()
{

	int N = 0;
	cout << "排序数据个数：\n";
	cin >> N;
	int* A = new int[N];
	cout << "请输入待排序的数据：\n";
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	BubbleSort bubble;
	bubble.bubbleSort(A,N);
	printResult("bubbleSort", A, N);

	SelectionSort select;
	select.selectionSort(A, N);
	printResult("selectSort", A, N);

	InsertionSort insert;
	insert.insertionSort(A, N);
	printResult("InsetSort", A, N);


	return 0;
}