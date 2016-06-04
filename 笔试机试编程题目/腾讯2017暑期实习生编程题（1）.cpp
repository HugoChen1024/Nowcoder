//给定一个字符串s，你可以从中删除一些字符，使得剩下的串是一个回文串。如何删除才能使得回文串最长呢？
//输出需要删除的字符个数。
//
//输入描述 :
//
//输入数据有多组，每组包含一个字符串s，且保证 : 1 <= s.length <= 1000.
//
//
//
//输出描述 :
//
//	 对于每组数据，输出一个整数，代表最少需要删除的字符个数。
//
// 输入例子 :
//						 abcda
//						 google
//
//						 输出例子 :
//						 2
//						 2


#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
#include <memory.h>
const int MAX_NUM = 1010;
int dp[MAX_NUM][MAX_NUM];

//先求s的反串reverse，然后求他们的最长的公共子序列，要删除的字符个数就能知道
//时间复杂度O(N^2)
int getRemoveNumber(string &str)
{
	string s(str);
	reverse(s.begin(), s.end());
	memset(dp, 0, sizeof(dp));
	int val = str.length();
	int val1 = str.size();
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = 0; j < s.size(); j++)
		{
			if (str[i] == s[j])
			{
				dp[i + 1][j + 1] = dp[i][j] + 1;
			}
			else
				dp[i + 1][j + 1] = max(dp[i][j+1],dp[i+1][j]);
		}
	}
	return s.size() - dp[s.size()][s.size()]-1;  //size()和length的区别
}

int main()
{
	string str;
	while (getline(cin,str))
	{
		cout << getRemoveNumber(str) << endl;
	}
	return 0;
}



#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

//更简洁的方法实现
int main() {
	string s;
	while (cin >> s) {
		int m = s.size();
		vector<vector<int>> dp(m, vector<int>(m, 0));
		for (int len = 1; len < m; ++len)
		for (int i = 0, j = 0; i + len < m; ++i) {
			j = i + len;
			if (s[i] == s[j])
				dp[i][j] = dp[i + 1][j - 1];
			else
				dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
		}
		cout << dp[0][m - 1] << endl;
	}
}

//题目描述
//
//给定一个字符串，问是否能通过添加一个字母将其变为回文串。
//
//输入描述 :
//一行一个由小写字母构成的字符串，字符串长度小于等于10。
//
//
//输出描述 :
//输出答案(YES\NO).
//
//输入例子 :
//	 coco
//
// 输出例子 :
//YES

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool isPalindrome(string str)
{
	string temp = str;
	reverse(str.begin(), str.end());
	return str == temp;
}

int main()
{
	string str;
	while (cin >> str)
	{
		if (str.size() <= 0 || str.size() == 1)
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



////LCS实现

#include <stdio.h>
#include <string.h>
#define MAXLEN 100

void LCSLength(char *x, char *y, int m, int n, int c[][MAXLEN], int b[][MAXLEN])
{
	int i, j;
	for (i = 0; i <= m; i++)
		c[i][0] = 0;
	for (j = 1; j <= n; j++)
		c[0][j] = 0;
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (x[i - 1] == y[j - 1])
			{
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 0;
			}
			else if (c[i - 1][j] >= c[i][j - 1])
			{
				c[i][j] = c[i - 1][j];
				b[i][j] = 1;
			}
			else
			{
				c[i][j] = c[i][j - 1];
				b[i][j] = -1;
			}
		}
	}
}

void PrintLCS(int b[][MAXLEN], char *x, int i, int j)
{
	if (i == 0 || j == 0)
		return;
	if (b[i][j] == 0)
	{
		PrintLCS(b, x, i - 1, j - 1);
		printf("%c ", x[i - 1]);
	}
	else if (b[i][j] == 1)
		PrintLCS(b, x, i - 1, j);
	else
		PrintLCS(b, x, i, j - 1);
}

int main(int argc, char **argv)
{
	char x[MAXLEN] = { "ABCBDAB" };
	char y[MAXLEN] = { "BDCABA" };
	int b[MAXLEN][MAXLEN];
	int c[MAXLEN][MAXLEN];
	int m, n;

	m = strlen(x);
	n = strlen(y);

	LCSLength(x, y, m, n, c, b);
	PrintLCS(b, x, m, n);

	return 0;
}

