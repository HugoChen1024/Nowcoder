
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
void swap(int *a, int *b)
{
	int temp=*a;
	*a = *b;
	*b = temp;
}

//冒泡排序 O(n^2) 
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

//请编写一个选择排序算法 O(n^2) 
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

//请编写一个插入算法 O(n^2) 
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

//归并排序 O(N*log(N))
class MergeSort {
public:
	int* mergeSort(int* A, int n) {
		// write code here
		mergeSort(A, 0, n - 1);
		return A;
	}
	void mergeSort(int* A, int beg, int end)
	{
		if (beg < end)
		{
			int mid = beg + (end - beg) / 2;
			mergeSort(A, beg, mid);
			mergeSort(A, mid + 1, end);
			merge(A,beg,mid,end);
		}
		return;
	}
	void merge(int* A, int beg_, int mid_, int end_)
	{
		int *B = new int[end_ - beg_ + 1];
		int index1 = beg_;
		int index2 = mid_ + 1;
		int i = 0;
		while (index1<=mid_&&index2<=end_)
		{
			if (A[index1]<=A[index2])
			{
				B[i++] = A[index1++];
			}
			else
			{
				B[i++] = A[index2++];
			}
		}
		while (index1 <= mid_)
		{
			B[i++] = A[index1++];
		}
		while (index2<=end_)
		{
			B[i++] = A[index2++];
		}
		//memcpy(A,B,end_-beg_+1);
		for (int i = 0; i < end_ - beg_ + 1;i++)
		{
			A[beg_+i] = B[i];   //A[beg_++] 不能写，改变了输入参数
		}
		delete[] B;
	}
};

//快速排序 O(N*log(N))
#include <math.h>
class QuickSort {
public:
	int* quickSort(int* A, int n) {
		// write code here
		quickSort(A, 0, n - 1);
		return A;
	}
	void quickSort(int* A, int low, int high)
	{
		if (low <= high)
		{
			int part = partition(A, low, high);
			quickSort(A, low, part - 1);
			quickSort(A, part + 1, high);
		}
		return;
	}

	int partition(int* A, int low, int high)
	{
		int privotKey = A[low];	//基准元素
		while (low < high)
		{	    //从表的两端交替地向中间扫描
			while (low < high  && A[high] >= privotKey) 
				--high;  //从high 所指位置向前搜索，至多到low+1 位置。将比基准元素小的交换到低端
			swap(&A[low], &A[high]);
			while (low < high  && A[low] <= privotKey) 
				++low;
			swap(&A[low], &A[high]);
		}
		return low;
	}
};
class QuickSort2 {
public:
	int* quickSort(int* A, int n) {
		// write code here
		quickSort(A, 0, n - 1);
		return A;
	}
	void quickSort(int* A, int low, int high)
	{
		if (low <= high)
		{
			int randn = low + rand() % (high - low + 1);  //随机选择关键字的下标
			swap(&A[randn], &A[high]);                      //void swap(int* A,int index1,int index2) //最好都操作下标

			int part = partition(A, low, high);
			quickSort(A, low, part - 1);
			quickSort(A, part + 1, high);
		}
		return;
	}

	int partition(int* A, int low, int high) //O(N)
	{
		//int pivot = A[low];//很多随机选择放在这里面，而且是以值的形式确定，而非下标标记为关键字
		
		int pivot = low-1; //关键字的位置
		for (int i = low ; i <= high; i++)
		{
			if (A[i] <= A[high])
			{
				swap(&A[i], &A[++pivot]);  //感觉这样会把A数组前面的值覆盖？-->其实没有交换的效果就是把前面的交换到后面
			}
		}
		return pivot;
	}
};

//推排序  O(N*log(N))
class HeapSort {
public:
	int* heapSort(int* A, int n) {
		// write code here
		buildHeap(A, n); //初始时构建堆
		//从最后一个元素开始对序列进行调整
		for (int i = n - 1; i >= 0;i--)
		{
			swap(&A[0], &A[i]);
			heapAdjust(A,0,i);
		}
		return A;
	}

	void buildHeap(int* A, int size_A)
	{
		for (int i = (size_A)/ 2-1; i >= 0; i--)
		{
			heapAdjust(A,i,size_A);
		}
	}

	void heapAdjust(int* A, int root, int size_A) //大顶堆
	{
		int leftchild = 2 * root + 1;
		if (leftchild<size_A) //递归形式
		{
			int rightchild = leftchild + 1;
			if (rightchild<size_A)
			{
				if (A[leftchild]<A[rightchild])
				{
					leftchild = rightchild;
				}
			}
			//leftchild为左右子节点中较大的结点
			if (A[root]<A[leftchild])
			{
				int temp = A[root];
				A[root] = A[leftchild];   //将较大结点值上移到根节点
				A[leftchild] = temp; //完成交换，子节点变为以前的根节点
				heapAdjust(A, leftchild, size_A);
			}
		}
		return;
	}
};
class HeapSort2 {
public:
	int* heapSort(int* A, int n) {
		// write code here
		buildHeap(A, n); //初始时构建堆
		//从最后一个元素开始对序列进行调整
		for (int i = n - 1; i >= 0; i--)
		{
			swap(&A[0], &A[i]);
			heapAdjust(A, 0, i);
		}
		return A;
	}

	void buildHeap(int* A, int size_A)
	{
		for (int i = (size_A - 1) / 2; i >= 0; i--)
		{
			heapAdjust(A, i, size_A);
		}
	}

	void heapAdjust(int* A, int root, int size_A)  //调整为大顶堆
	{
		int temp = A[root];
		int leftchild = 2 * root + 1;
		while (leftchild < size_A) //非递归形式
		{
			int rightchild = leftchild + 1;
			if (rightchild < size_A)
			{
				if (A[leftchild] < A[rightchild])
				{
					leftchild = rightchild;
				}
			}
			//leftchild为左右子节点中较大的结点
			if (A[root] < A[leftchild])
			{
				A[root] = A[leftchild];   //将较大结点值上移到根节点
				root = leftchild;         //更新新的根节点
				leftchild = 2 * root + 1;		
			}
			else  //当前结点大于左右子节点则不需要调整
			{
				break;
			}		
			A[root] = temp; //完成交换，子节点变为以前的根节点
		}
		return;
	}
};

//希尔排序  O(N*log(N)) ---不稳定
class ShellSort {
public:
	int* shellSort(int* A, int n) {
		// write code here
		int dk = n / 2;
		while (dk>=1)
		{
			shellSort2(A,n,dk);
			dk /= 2;
		}
		return A;
	}
	void shellSort(int* A, int n, int dk)
	{
		for (int i = dk; i < n;i++)
		{
			int index = i; //当前访问的位置
			while (index>=dk)
			{
				if (A[index-dk]>A[index])
				{
					swap(&A[index-dk],&A[index]); //交换不算最优，找到插入位置才交换
					index -= dk;
				}
				else
				{
					break;
				}
			}
		}
	}
	void shellSort2(int* A,int n,int dk)
	{
		for (int i = dk; i < n;i++)
		{
			if (A[i]<A[i-dk]) //找到插入位置
			{
				int x = A[i];//复制哨兵
				A[i] = A[i - dk];
				int j = i - dk; //从该位置向前查找
				while (x<A[j]&&j>=0) //防止j越界
				{
					A[j] = A[j - dk];
					j -= dk; //向前移动
				}
				A[j + dk] = x;// 插入到正确位置
			}
		}
	}

};


#define N 13
int main()
{
	//待排数据输入方式：
		/*int N = 0;
		cout << "排序数据个数：\n";
		cin >> N;
		int* A = new int[N];
		cout << "请输入待排序的数据：\n";
		for (int i = 0; i < N; i++)
		{
		cin >> A[i];
		}*/
	//数据直接给定	
		int B[N] = { 1, 6, 3, 5, 2, 4 };
		int C[13] = { 54, 35, 48, 36, 27, 12, 44, 44, 8, 14, 26, 17, 2 };
		int* A = C;

	//从文件中读取，大量数据，计算时间复杂度
		
	printResult("待排原始数据：", C, N);

	BubbleSort bubble;
	bubble.bubbleSort(A,N);
	printResult("bubbleSort", A, N);

	SelectionSort select;
	select.selectionSort(A, N);
	printResult("selectSort", A, N);

	InsertionSort insert;
	insert.insertionSort(A, N);
	printResult("InsetSort", A, N);

	MergeSort merge;
	merge.mergeSort(A, N);
	printResult("MergeSort", A, N);

	QuickSort qucik;
	qucik.quickSort(A, N);
	printResult("QucikSort",A,N);

	QuickSort2 qucik2;
	qucik2.quickSort(A, N);
	printResult("QucikSort2", A, N);

	HeapSort heap;
	heap.heapSort(A, N);
	printResult("heapSort", A, N);

	HeapSort2 heap2;
	heap2.heapSort(A, N);
	printResult("heapSort2", A, N);


	ShellSort shell;
	shell.shellSort(A,N);
	printResult("shellSort", A, N);

	return 0;
}