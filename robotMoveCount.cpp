
#include<memory.h>


//题目描述
//
//地上有一个m行和n列的方格。一个机器人从坐标0, 0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，
//但是不能进入行坐标和列坐标的数位之和大于k的格子。 例如，当k为18时，机器人能够进入方格（35, 37），因为3 + 5 + 3 + 7 = 18。
//但是，它不能进入方格（35, 38），因为3 + 5 + 3 + 8 = 19。请问该机器人能够达到多少个格子？

//思路
//深搜基础题，从0开始按照四个方向递归求解即可
class Solution {
public:
	int movingCount(int threshold, int rows, int cols)
	{
		bool *vis = new bool[rows*cols];
		memset(vis,false,rows*cols);
		int result = movingCountCore(threshold,rows,cols,0,0,vis);
		delete[]vis;
		return result;
	}
	int movingCountCore(int threshold,int rows,int cols,int x,int y,bool *vis)
	{
		int count = 0;
		if (x >= 0 && x<rows && y >= 0 && y<cols && getSum(x) + getSum(y) <= threshold && !vis[x*cols + y])
		{
			vis[x*cols + y] = true;
			count = 1 + movingCountCore(threshold, rows, cols, x - 1, y, vis)
				+ movingCountCore(threshold, rows, cols, x + 1, y, vis)
				+ movingCountCore(threshold, rows, cols, x, y - 1, vis)
				+ movingCountCore(threshold, rows, cols, x, y + 1, vis);
		}
		return count;
	}
	int getSum(int num)
	{
		int sum = 0;
		while (num)
		{
			sum += num % 10;//先取各位
			num /= 10;//从低到高位
		}
		return sum;
	}
};

