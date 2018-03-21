
#include<iostream>
#include<math.h>

#include <vector>
#include <string>
#include <deque>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

#include <algorithm>
#include <functional>
#include <numeric> //accmulate

using namespace std;

// Definition for singly - linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//#define test01
//#define test02
#define test03

#ifdef test01

int getMaxLengthSub(string s1, string s2)
{
	int ret = 0;
	vector<vector<int> > vecs(s1.size() + 1, vector<int>(s2.size() + 1, 0));

	for (int i = 1; i <= s1.size(); i++)
	{
		for (int j = 1; j <= s2.size(); j++)
		{
			if (s1[i - 1] == s2[j - 1]) //下标
			{
				vecs[i][j] = vecs[i - 1][j - 1] + 1;
			}
			else
			{
				vecs[i][j] = max(vecs[i - 1][j], vecs[i][j - 1]);
			}
		}
	}
	ret = vecs[s1.size()][s2.size()];
	return ret;
}

int main()
{
	//设有二维数组f[i, j] 表示 X 的 i 位和 Y 的 j 位之前的最长公共子序列的长度

	string input;
	while (cin >> input)
	{
		string temp(input); //拷贝一份
		reverse(input.begin(), input.end());

		int max_com = getMaxLengthSub(input, temp);

		cout << (input.size() - max_com) << endl; //<<endl少了换行测试通不过！！！
	}

	return 0;
}

#endif // test01

#ifdef test02

void char_shift(string &src)
{
	string str;


	int end = src.size() - 1;
	for (int i = 0; i <= end;)
	{
		if (src[i] >= 'A'&&src[i] <= 'Z')
		{
			char temp = src[i];
			for (int j = i + 1; j < src.size(); j++)
			{
				src[j - 1] = src[j];
			}
			src[src.size()-1] = temp;
			end--;
		}
		else
		{
			i++; //没有大写字符的时候才++
		}
	}


	return;
}

int main()
{
	string input;

	while (cin>>input)
	{
		char_shift(input);
		cout << input<<endl;
	}
	return 0;
}

#endif

#ifdef test03

void getMinMaxPair(vector<int> vec,int &min_pair,int &max_pair)
{

}

int main()
{
	int N;
	while (cin>>N)
	{
		vector<int> vec;
		int temp;
		for (int i = 0; i < N;i++)
		{
			cin >> temp;
			vec.push_back(temp);
		}

		int max_pair = 0, min_pair = 0;

		getMinMaxPair(vec,min_pair,max_pair);

		cout << min_pair << " " << max_pair << endl;
	}
	return 0;
}


//链接：https://www.nowcoder.com/questionTerminal/af709ab9ca57430886632022e543d4c6
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int num, i, j;
	while (cin >> num)//读入元素的总个数
	{
		if (num < 2)
		{
			cout << 0 << " " << 0 << endl;
			continue;
		}
		vector<int> arr;//arr不要声明为全局变量,不然全部测试数据都被存入了arr
		int length = num;
		int temp;
		while (num--)//不能写成while(cin>>temp)，不然，全部测试数据都被一次性存入了arr
		{
			cin >> temp;
			arr.push_back(temp);
		}
		sort(arr.begin(), arr.end());//C++排序函数：对[begin,end)内所有元素排序

		//求最小值minVal
		int minVal = arr[1] - arr[0];
		for (i = 1; i < length - 1; ++i)
		{
			int cur = arr[i + 1] - arr[i];
			if (cur < minVal)
				minVal = cur;
		}
		//求最小值的个数minCount
		int minCount = 0;
		if (minVal == 0)//arr中有相等元素时
		{
			for (i = 0; i < length - 1; ++i)
			{
				for (j = i + 1; j < length; ++j)
				{
					if (arr[i] == arr[j])
						++minCount;
				}
			}
		}
		else//arr中无元素相等时
		{
			for (i = 0; i < length - 1; ++i)
			{
				int cur = arr[i + 1] - arr[i];
				if (cur == minVal)
				{
					++minCount;
				}
			}
		}

		//求最大值maxVal
		int maxVal = arr[length - 1] - arr[0];
		//求最大值的个数maxCount
		int maxCount = 0;
		if (maxVal == 0)//全部元素都相等,利用组合原理
		{
			maxCount = length*(length - 1) / 2;
		}
		else//有不同的元素,最大值的个数=最小的个数*最大的个数
		{
			int smallCount = 0, bigCount = 0;
			for (i = 0; i < length; ++i)
			{
				if (arr[i] == arr[0])
					++smallCount;
				else if (arr[i] == arr[length - 1])
					++bigCount;
			}
			maxCount = smallCount*bigCount;
		}
		cout << minCount << " " << maxCount << endl;
	}
	return 0;
}
#endif