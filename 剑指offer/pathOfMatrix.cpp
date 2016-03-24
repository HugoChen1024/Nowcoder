
#include<memory.h>

//题目描述
//
//请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
//路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
//如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。 
//例如 a b c e s f c s a d e e 矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，
//因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。

//思路
//深搜的基本题型，分别以每个格子为起点，往四个方向去遍历，直到找到符合题意的字符串即可
class Solution {
public:
	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
		if (matrix==nullptr||str==nullptr||rows<1||cols<1)
		{
			return false;
		}
		//建立一个标记数组，走过的位置为true，没走过的为false
		bool *vis = new bool[rows*cols];
		memset(vis,false,rows*cols);
		int pathLength = 0;
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < cols; j++)
			{
				if (hasPathCore(matrix,rows,cols,i,j,str,pathLength,vis))
				{
					return true;
				}
			}
		}
		delete[]vis;
		return false;
	}
	//判断从一个元素出发是否能找到一条路径
	bool hasPathCore(char *matrix,int rows,int cols,int x,int y,char *str,int pathLength,bool *vis)
	{
		if (str[pathLength]=='\0')//嵌套调用出口
		{
			return true;
		}
		bool hasPath = false;//函数返回值
		if (x>=0&&x<=rows&&y>=0&&y<=cols&&matrix[x*cols+y]==str[pathLength]&&!vis[x*cols+y])//坐标范围判断，x=0开始，所以x*cols+y索引正确
		{
			++pathLength;
			vis[x*cols + y] = true;
			hasPath = hasPathCore(matrix, rows, cols, x - 1, y, str, pathLength, vis)
				|| hasPathCore(matrix, rows, cols, x + 1, y, str, pathLength, vis)
				|| hasPathCore(matrix, rows, cols, x, y - 1, str, pathLength, vis)
				|| hasPathCore(matrix, rows, cols, x, y + 1, str, pathLength, vis);
			if (!hasPath) //没有路径时，返回到原来位置
			{
				--pathLength;
				vis[x*cols + y] = false;
			}		
		}
		return hasPath;
	}
	


};