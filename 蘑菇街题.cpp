//现在有一张半径为r的圆桌，其中心位于(x, y)，现在他想把圆桌的中心移到(x1, y1)。每次移动一步，都必须在圆桌边缘固定一个点然后将圆桌绕这个点旋转。问最少需要移动几步。
//
//输入描述 :
//一行五个整数r, x, y, x1, y1(1≤r≤100000, -100000≤x, y, x1, y1≤100000)
//
//
//输出描述 :
//	 输出一个整数，表示答案

/**************************************************

#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
long long r, x, y, x1, y1;  //数据类型
while (cin >> r >> x >> y >> x1 >> y1)  //多次测试
{
long d = sqrt((x - x1)*(x - x1) + (y - y1)*(y - y1));
long result = (d % (2 * r) == 0) ? (d / (2 * r)) : (d / (2 * r) + 1);
cout << result << endl;
}

return 0;
}

**************************************************/


//给定一个递增序列，a1 <a2 <...<an 。定义这个序列的最大间隔为d = max{ ai + 1 - ai }(1≤i<n), 现在要从a2, a3 ..an - 1 中删除一个元素。
//问剩余序列的最大间隔最小是多少？
//
//输入描述 :
//第一行，一个正整数n(1 <= n <= 100), 序列长度; 接下来n个小于1000的正整数，表示一个递增序列。
//
//
//输出描述 :
//输出答案。
/*

*/

#include<iostream>
using namespace std;
#include<vector>

int getMaxInterval(vector<int> ans)
{
	int result = 0;
	for (int i = 0; i < ans.size()-1; i++)
	{
		if (ans[i+1]-ans[i]>result)
		{
			result = ans[i + 1] - ans[i];
		}
	}
	return result;
}

int main()
{
	int n;
	vector<int> input,mid;
	while (cin>>n)
	{
		int reuslt=0;
		for (int i = 0; i < n; i++)
		{
			int temp=0;
			cin >> temp;
			input.push_back(temp);
		}
		mid = input;
		for (auto it = input.begin()+1; it != input.end()-1; it++)
		{
			input.erase(it);				
			if (reuslt>getMaxInterval(input))
			{
				reuslt = getMaxInterval(input);
			}
			else
			reuslt = (getMaxInterval(input));
			input = mid;
		}
	}
	return 0;
}