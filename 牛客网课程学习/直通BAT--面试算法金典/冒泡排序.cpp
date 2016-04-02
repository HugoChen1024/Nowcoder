// 对于一个int数组，请编写一个冒泡排序算法，对数组元素排序。

// 给定一个int数组A及数组的大小n，请返回排序后的数组。 

// 测试样例：
// [1,2,3,5,2,3],6
// [1,2,2,3,3,5]


class BubbleSort {
public:
    int* bubbleSort(int* A, int n) {
        // write code here
        for(int i=0;i<n;i++)
            {
            for(int j=0;j<n-i-1;j++)
                {
                if(A[j]>A[j+1])
                    {
                    int temp=A[j];
                    A[j]=A[j+1];
                    A[j+1]=temp;
                }
            }
        }
        return A;
    }
};