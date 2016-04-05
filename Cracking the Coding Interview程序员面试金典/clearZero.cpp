
//题目描述
//
//请编写一个算法，若MxN矩阵中某个元素为0，则将其所在的行与列清零。
//给定一个MxN的int[][]矩阵(C++中为vector>)mat和矩阵的阶数n，请返回完成操作后的int[][]矩阵(C++中为vector>)，保证n小于等于300，矩阵中的元素为int范围内。
//测试样例：
//[[1, 2, 3], [0, 1, 2], [0, 0, 1]]
//返回：[[0, 0, 3], [0, 0, 0], [0, 0, 0]]

#include<iostream>
using namespace std;
#include<vector>

//题目分析：
//（1）题目陷阱：
//一看到这个题目可能会想到遍历整个矩阵，只要发现值为0，就将其所在行和与列全部清零。这个是个错误的思想，当清零的时候，0元素覆盖了还没有遍历到的元素，所以只有数组有一个零，最后就导致整个数组全为0。
//（2）思路一：
//可以新建有一个同样大小矩阵标记零元素出现的位置，然后在第二次遍历矩阵时将0元素所在行与列清零，这样做的空间复杂度为0(MN)。
//（3）思路二：
//其实如果一行或者一列中不管是有一个零元素还是多个，这行都是要被删除的，所以我们定义两个数组分别表示行、列是否有零元素，在第一次遍历的时候，确定这两个数组，第二次遍历的时候，根据这两个数组的内容，将对应位置元素清零。所以这样所需要的存储空间是O(M + N)。

class Clearer {
public:
	vector<vector<int> > clearZero(vector<vector<int> > mat, int n) {
		// write code here
		
		//bool *sign1 = new bool[len1]();
		//bool *sign2 = new bool[len2]();
		int col = mat.size();
		int row = mat[0].size();
		vector<bool> x(col,false), y(row,false);  //初始化
		for (size_t i = 0; i < col; i++)
		{
			for (size_t j = 0; j < row; j++)
			{
				if (mat[i][j]==0)
				{
					x[i] = true;
					y[j] = true;
				}
			}
		}

		for (size_t i = 0; i < col; i++)
		{
			for (size_t j = 0; j < row; j++)
			{
				if (x[i]||y[j])
				{
					mat[i][j] = 0;
				}
			}
		}
		return mat;
	}
};