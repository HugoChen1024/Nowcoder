//题目描述
//
//描述：
//输入一个整数，将这个整数以字符串的形式逆序输出
//程序不考虑负数的情况，若数字含有0，则逆序形式也含有0，如输入为100，则输出为001
//
//
//输入描述 :
//输入一个int整数
//
//
//输出描述 :
//将这个整数以字符串的形式逆序输出

//
////先居然想到了用栈，因为像数制转换一样，要逆序输出，结果直接从后面取每一位输出即可。
#include<iostream>
using namespace std;
int main()
{
	int input;
	while (cin>>input)
	{
		int bit;
		while (input)
		{
			bit = input % 10;
			cout << bit;
			input /= 10;
		}
		cout << endl;
	}
	return 0;
}


//题目描述
//
//写出一个程序，接受一个字符串，然后输出该字符串反转后的字符串。例如：
//
//输入描述 :
//输入N个字符
//
//
//输出描述 :
//输出该字符串反转后的字符串

#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str="";
	while (getline(cin,str))
	{
		////string subscript out of range
		////1.有说没有初始化的，2有说cin >> n; 后面加一句cin.ignore(); 过滤掉上一句cin中的回车 ；但是没有找到答案
		//for (size_t i = str.size()-1; i >=0; i--) 
		//{
		//	cout << str[i];  //为什么这样做就会数组大小溢出
		//}
		for (size_t i = str.size(); i >0; i--)  //正确
		{
			cout << str[i-1];
		}
		cout << endl;
	}
	return 0;
}