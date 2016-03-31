//题目描述
//
//密码要求 :
//
//1.长度超过8位
//
//2.包括大小写字母.数字.其它符号, 以上四种至少三种
//
//3.不能有相同长度超2的子串重复
//
//说明:长度超过2的子串
//
//输入描述 :
//一组或多组长度超过2的子符串。每组占一行
//
//输出描述 :
//如果符合要求输出：OK，否则输出NG


//第三个条件呢，其实是要找一串字符串中，重复的字串长度，如果大于2就不符合。例如ABCX1&ABC, 中ABC重复了，由于长度超过2，所以不符合。这道题呢021Abc9Abc1
//
//0	2	1	A	b	c	9	A	b	c	1
//1	0	0	0	0	0	0	0	0	0	0
//0	2	0	0	0	0	0	0	0	0	0
//0	0	3	0	0	0	0	0	0	0	0
//0	0	0	4	0	0	0	1	0	0	0
//0	0	0	0	5	0	0	0	2	0	0
//0	0	0	0	0	6	0	0	0	3	0
//0	0	0	0	0	0	7	0	0	0	0
//0	0	0	0	1	0	0	8	0	0	0
//0	0	0	0	0	2	0	0	9	0	0
//0	0	0	0	0	0	3	0	0	10	0
//0	0	0	0	0	0	0	0	0	0	11

//
//看上图，这个图是按这个规则画的，如果字符串相等，dp[i][j] = dp[i - 1][j - 1] + 1, 否则为0，那么我们发现除了对角线部分的数字以外，其余部分的数字中，1, 2, 3出现了两次，如图红色字体，那么我们就可以得到长度为3的字串重复出现了两次，这样这个问题就基本解决。
//
//下来我们只需要遍历这个二维矩阵，不过得加个条件，对角线上的数字不做统计，只需要判断大于二，相同的数字出现的次数，如果次数大于2则不否合要求。用一个一维数组统计出对角线以外的数字出现的个数，然后从3开始遍历，如果存在a[i]>1，说明长度大于2且出现了至少两次，直接输出不合格。
//public static boolean Ischongfu(String str){
//	int[][] dp = new int[str.length() + 1][str.length() + 1];
//	for (int i = 0; i<str.length(); i++){
//		for (int j = 0; j<str.length(); j++) {
//			if (str.charAt(i) == str.charAt(j)){
//				dp[i + 1][j + 1] = dp[i][j] + 1;
//			}
//		}
//	}
//	int[] a = new int[str.length()];
//	for (int i = 0; i <= str.length(); i++){
//		for (int j = 0; j <= str.length(); j++) {
//			if (str.charAt(i) != str.charAt(j)) {
//				a[dp[i][j]]++;
//			}
//		}
//	}
//	for (int i = 3; i<a.length; i++){
//		if (a[i]>1){
//			return false;
//		}
//	}
//	return true;

#include<iostream>
using namespace std;
#include<string>
bool judgeCode(string str)
{
	int isNumber = 0;
	int isBigChar = 0;
	int isLittleChar = 0;
	int isOthers = 0;

	if (str.size()>=8)   //条件一
	{
		return false;
	}
	for (size_t i = 0; i < str.size(); i++)  
	{
		if (str[i]>'0'&&str[i]<'9')
		{
			isNumber = 1;
		}else if (str[i]>'a'&&str[i]<'z')
		{
			isLittleChar = 1;
		}
		else if (str[i]>'A'&&str[i]<'Z')
		{
			isBigChar = 1;
		}
		else
		{
			isOthers = 1;
		}
	}
	int number = isNumber + isLittleChar + isBigChar + isOthers;
	if (number<3)  //条件二
		return false;

	for (int i = 0; i<str.size(); i++)  
	{
		int LenOfChild = 1;
		for (int j = i + 1; j<str.size(); j++)
		{
			int m = i;
			int n = j;
			while (m<str.size() && n<str.size() && str[m] == str[n])  //连续子串
			{
				m++;
				n++;
				LenOfChild++;
			}
			if (LenOfChild>3)  //条件三
				return false;
			else
				LenOfChild = 1;
		}
	}

	return true;
}
int main()
{
	string str;
	while (getline(cin,str))
	{
		bool result=judgeCode(str);
		if (result)
		{
			cout << "OK" << endl;
		}
		else
		{
			cout << "NG" << endl;
		}
	}
	return 0;
}