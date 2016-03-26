//题目描述
//
//有一副由NxN矩阵表示的图像，这里每个像素用一个int表示，请编写一个算法，在不占用额外内存空间的情况下(即不使用缓存矩阵)，
//将图像顺时针旋转90度。
//给定一个NxN的矩阵，和矩阵的阶数N, 请返回旋转后的NxN矩阵, 保证N小于等于500，图像元素小于等于256。
//测试样例：
//[[1, 2, 3], [4, 5, 6], [7, 8, 9]], 3
//返回：[[7, 4, 1], [8, 5, 2], [9, 6, 3]]

#include<iostream>
using namespace std;
#include<vector>
class Transform {
public:
	vector<vector<int> > transformImage(vector<vector<int> > mat, int n) {
		// write code here
		//转置的实现
		/*for (size_t i = 0; i < mat.size(); i++)
		{
			for (size_t j = 0; j < n; j++)
			{
				int temp = mat[i][j];
				mat[i][j] = mat[j][i];
				mat[j][i] = temp;
			}
		}*/


		/* 思路：逐层旋转，最外层向内，其中layer表示当前所处理的层，每次都是n*n矩阵中可以形成方阵中的四个数进行旋转，
		         左->上，下->左，右->下，上->右的顺序，在第一步之前先存储“上”中的值*/
		//for (int layer = 0; layer < n / 2; layer++){   
		//	int first = layer;
		//	int last = n - 1 - layer;
		//	for (int i = first; i < last; i++){    //每层内部的数据变换方法
		//		int offset = i - first;
		//		int top = mat[first][i];
		//		//left -> top
		//		mat[first][i] = mat[last - offset][first];
		//		//bottom -> left
		//		mat[last - offset][first] = mat[last][last - offset];
		//		//right -> bottom
		//		mat[last][last - offset] = mat[i][last];
		//		//top -> right
		//		mat[i][last] = top;
		//	}
		//}

		
		/*思路：和上面一样
			把矩阵想成一个洋葱，一圈包着一圈，外一圈每一条边比里一圈每一条边长度多2，每一条边只有边长度 - 1个元素需要覆盖另一条边的对应元素，
			因为每一条边与相邻两条边相交，一条边第一个元素旋转90度其实覆盖的是这一条边的最后一个元素，也是相邻边的第一个元素。*/
		/*int temp;
		for (int i = 0; i<n / 2; i++){   //分层
			for (int j = i; j<n - 1 - i; j++){
				temp = mat[i][j];
				mat[i][j] = mat[n - j - 1][i];
				mat[n - j - 1][i] = mat[n - i - 1][n - j - 1];
				mat[n - i - 1][n - j - 1] = mat[j][n - i - 1];
				mat[j][n - i - 1] = temp;
			}
		}*/
		
		//先列变换，在次对角线对称交换   或者 先次对角线交换，在行变换
		int i, j, temp = 0;
		//左右列交换
		for (i = 0; i<n; i++)
		{
			for (j = 0; j<n / 2; j++) 
			{
				temp = mat[i][j];
				mat[i][j] = mat[i][n - 1 - j];
				mat[i][n - 1 - j] = temp;
			}
		}
		//每条对角线对称交互
		for (i = 0; i<n; i++)
		{
			for (j = 0; j<n - i; j++)
			{
				temp = mat[i][j];
				mat[i][j] = mat[n - 1 - j][n - 1 - i];
				mat[n - 1 - j][n - 1 - i] = temp;
			}
		}
		return mat;
	}
};