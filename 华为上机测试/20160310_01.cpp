//题目描述
//
//•连续输入字符串，请按长度为8拆分每个字符串后输出到新的字符串数组；
//•长度不是8整数倍的字符串请在后面补数字0，空字符串不处理。
//
//输入描述 :
//连续输入字符串(输入2次, 每个字符串长度小于100)
//
//
//输出描述 :
//	 输出到长度为8的新字符串数组

#include<iostream>
#include<string>
using namespace std;
void fun(string str,int len)
{
	int m = len % 8;//余数
	int n = len / 8;//整数；
	int i = 0;
	while (i<n)
	{
		for (size_t k = 0; k < 8; k++)
		{
			cout << str[i * 8 + k];
		}
		i++;
		cout << endl;
	}
	if (m!=0)
	{
		for (size_t k = 0; k < m; k++)
		{
			cout << str[n * 8 + k];
		}
		for (size_t k = m; k < 8; k++)
		{
			cout << 0;
		}
		cout << endl;
	}
}
int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	int len1 = str1.length();
	int len2 = str2.size();
	fun(str1,len1);
	fun(str2, len2);
	return 0;

	/*string str,str1;
	cin >> str;
	str1 = str;
	int len = str.size();
	int n = 2;
	while (n)
	{	
		if (len%8!=0)
		{
			for (size_t i = len; i < 8*(len/8+1); i++)
			{
				str1.push_back(0);
			}
		}
		for (size_t i = 1; i <= str1.size(); i++)
		{
			cout << str1[i-1];
			if (i%8==0)
			{
				cout << endl;
			}
		}
		n--;
	}*/


	//string str;
	//int n = 10;
	//while (n)
	//{
	//	str.push_back(0);  //根本就不会输出
	//	n--;
	//}
	//cout << str<<0<<0<<"0"<<endl;
}