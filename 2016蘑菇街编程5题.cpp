
//现在有一张半径为r的圆桌，其中心位于(x, y)，现在他想把圆桌的中心移到(x1, y1)。每次移动一步，都必须在圆桌边缘固定一个点然后将圆桌绕这个点旋转。问最少需要移动几步。
//
//输入描述 :
//一行五个整数r, x, y, x1, y1(1≤r≤100000, -100000≤x, y, x1, y1≤100000)
//
//
//输出描述 :
//	 输出一个整数，表示答案


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



//给定一个递增序列，a1 <a2 <...<an 。定义这个序列的最大间隔为d = max{ ai + 1 - ai }(1≤i<n), 现在要从a2, a3 ..an - 1 中删除一个元素。
//问剩余序列的最大间隔最小是多少？
//
//输入描述 :
//第一行，一个正整数n(1 <= n <= 100), 序列长度; 接下来n个小于1000的正整数，表示一个递增序列。
//
//
//输出描述 :
//输出答案。

/*************************操碎了心啊******************************/
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

int getMaxInterval(vector<int> ans)
{
	int result = 0;
	for (int i = 0; i < ans.size() - 1; i++)
	{
		if (ans[i + 1] - ans[i]>result)
		{
			result = ans[i + 1] - ans[i];
		}
	}
	return result;
}

int main()
{
	int n;
	vector<int> input, mid;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
		{
			int temp = 0;
			cin >> temp;
			input.push_back(temp);
		}
		/*mid = input;       //自己写的有错
		for (auto it = input.begin() + 1; it != input.end() - 1; it++)
		{
		input.erase(it);
		if (reuslt>getMaxInterval(input))
		{
		reuslt = getMaxInterval(input);
		}
		else
		reuslt = (getMaxInterval(input));
		input = mid;
		}*/
		/*	int min = INT_MAX;    //参考别人的
		for (int i = 1; i < input.size() - 1; ++i)
		{
		vector<int> tmp = input;//借助的临时变量
		tmp.erase(tmp.begin() + i);
		if (getMaxInterval(tmp) < min)
		min = getMaxInterval(tmp);
		}
		*/

		//记录相邻元素的间隔值，间隔值得最大值
		vector<int> temp;
		int maxd = 0;
		for (int i = 1; i <= input.size() - 1; i++)
		{
			temp.push_back(input[i] - input[i - 1]);
			maxd = (input[i] - input[i - 1])>maxd ? (input[i] - input[i - 1]) : maxd;
		}
		//相邻间隔值合并，找出最小的最大间隔
		//当删除元素在原数组的最大间隔的两个元素时候最大间隔增大，当在其他位置时候，
		//这个最大间隔不变，其他位置的间隔增加
		int result = 10000;
		for (int i = 1; i <= temp.size() - 1; i++)
		{
			int d = temp[i] + temp[i - 1];
			if (d > maxd)
			{
				//大于最大间隔里面求最小的；只有当删除每个元素对应的间隔都大于maxd，最大间隔的最小值才有意义
				if (d<result)   //vs下怎么这句话不执行啊？？？
				{
					result = d;
				}
				//   result = min(d,result);  //或者这样求最小值
			}
			else     //若其中一个间隔比maxd小，那这是的最大间隔还是maxd;当所有间隔值比maxd小时，最大间隔的最小值就是maxd
			{
				result = maxd;
			}
		}
		cout << result << endl;
	}
	return 0;
}

/*********************************************************/


//A和B是好友，他们经常在空闲时间聊天，A的空闲时间为[a1, b1], [a2, b2]..[ap, bp]。
//B的空闲时间是[c1 + t, d1 + t]..[cq + t, dq + t], 这里t为B的起床时间。这些时间包括了边界点。B的起床时间为[l, r]的一个时刻。
//若一个起床时间能使两人在任意时刻聊天，那么这个时间就是合适的，问有多少个合适的起床时间？
//
//输入描述 :
//第一行数据四个整数：p,q,l,r（1≤p,q≤50,0≤l≤r≤1000)。接下来p行数据每一行有一对整数ai，bi(0≤ai<bi≤1000)表示a的时间表，
//接下来p行每行一对整数ci，di(0≤ci,di≤1000)表示b的时间表。保证ai+1>bi,ci+1>di
//
//输出描述 :
//输出答案个数

//解题思路：
//
//小蘑的时间假设为[a，b]，小菇的时间假设是[c + t，d + t]，小菇起床的时间是t∈[l，r]
//那么当"a < b < (c+t) < (d+t)"或者"(c+t) < (d+t) < a < b"的情况时，小蘑和小菇无法聊天，由题目条件已知"a < b"和"c < d"，那么推出"(c+t) < (d+t)"
//所以仅仅当"b < (c+t)"或者"(d+t) < a"时无法聊天，其余情况都是可以聊天的
/**********************************************************************/
#include<iostream>
using namespace std;
#include<vector>
int p, q, l, r;
bool isAdapter(int t,vector<vector<int>> m,vector<vector<int> > n)
{
	int count = 0;
	for (int i = 0; i < p; i++)
	{
		for (int j = 0; j < q; j++)
		{
			if (!(m[i][1] + t)<n[j][0] || !(n[j][2] + t)<m[i][0])
			{
				return true;
			}
		}
	}
	return false;
}
int main()
{
	while (cin>>p>>q>>l>>r)
	{	
		int temp=0;
		vector<vector<int>> m(p,vector<int>(2)), n(q,vector<int>(2));
		for (int i = 0; i < p; i++)  //输入有效性
		{
			for (int j = 0; j < 2; j++)
			{
				cin >> temp;
				m[i][j] = temp;
			}
		}
		for (int i = 0; i < q; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				cin >> temp;
				n[i][j] = temp;
			}
		}
		int count = 0;
		for (int t = l; t <= r; t++)
		{
			if (isAdapter(t, m, n))
				count++;
		}
		cout << count << endl;
	}
	return 0;
}

/************************************************************************************/

//有一个投篮游戏。球场有p个篮筐，    编号为0，1...，p - 1   。每个篮筐下有个袋子，每个袋子最多装一个篮球。
//有n个篮球，每个球编号xi 。规则是将数字为xi 的篮球投到xi 除p的余数为编号的袋里。若袋里已有篮球则球弹出游戏结束  输出i  ，否则重复至所有球都投完。
//输出 - 1。问游戏最终的输出是什么？
//输入描述:
//第一行两个整数p, n（2≤p, n≤300)。p为篮筐数，n为篮球数。接着n行为篮球上的数字xi(0≤xi≤1e9)
//输出描述:
//输出游戏的结果
//输入例子 :
//10 5
//0
//21
//53
//41
//53
//输出例子:
//4
/*********************************************************/
#include<iostream>
using namespace std;
#include<vector>
int main()
{
	int p, n;
	while (cin>>p>>n)
	{
		vector<long long> bNumber(n,0);  //bNumber(n,0) 这样push_back()会从第五个开始累加，前面5个为0，然后再push数据
		vector<bool> pNumber(p, false);
		long long temp = 0;
		for (int i = 0; i < n; i++)
		{
			//cin >> temp;
			//bNumber.push_back(temp);
			cin >> bNumber[i];   //这样可以避免从第五个累加，确定了下标
		}
		bool complete = true;
		for (size_t i = 0; i < bNumber.size(); i++)
		{
			if (pNumber[bNumber[i] % p] == false)
			{
				pNumber[bNumber[i] % p] =true;
				//continue;
			}
			else if (pNumber[bNumber[i] % p] == true)
			{
				complete = false;
				cout<< i+1<<endl;
				break;
			}
		}
		if (complete)  //处理方法
		{
			cout << -1 << endl;
		}
	}
	return 0;
}

/*********************************************************/


//给定一个字符串，问是否能通过添加一个字母将其变为回文串。
//输入描述:
//
//一行一个由小写字母构成的字符串，字符串长度小于等于10。
//输出描述 :
//
//输出答案(YES\NO).

//1.既然能通过增加一个字符变成回文串，那一定也可以通过删除一个字符变成回文串。用一个循环，每次循环依次删掉一个字符，然后检查新串是否是回文串，看起来简单方便许多。
//2.暴力，在所有位置添加a-z,依次判断是否满足回文串
//3.设置两个指针，一个从头向后，一个从尾向前，如果一样就继续，如果不一样就尝试跳过一个，如果一样就继续，直到指针相遇
//4.转化成这个思想不错：判断原字符串和翻转字符串的最长公共子序列长度是否比原字符串长度小1或相等
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool isPalindrome(string str)
{
	string temp = str;
	reverse(str.begin(),str.end());
	return str == temp;
}

int main()
{
	string str;
	while (cin>>str)
	{
		if (str.size()<=0||str.size()==1)
		{
			cout << "YES" << endl;
		}
		else
		{
			bool temp = true;
			for (size_t i = 0; i < str.size(); i++)
			{
				string strTemp = str;
				strTemp.erase(strTemp.begin() + i);   //  tmp = str.substr(0, i) + str.substr(i + 1);  
				if (isPalindrome(strTemp))
				{
					cout << "YES" << endl;
					temp = false;
					break;
				}
			}
			if (temp)
			{
				cout << "NO" << endl;
			}
		}
	}
	return 0;
}