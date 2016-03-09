//题目描述
//
//写出一个程序，接受一个有字母和数字以及空格组成的字符串，和一个字符，然后输出输入字符串中含有该字符的个数。不区分大小写。
//
//输入描述 :
//输入一个有字母和数字以及空格组成的字符串，和一个字符。
//
//
//输出描述 :
//输出输入字符串中含有该字符的个数。
//
//输入例子 :
//ABCDEF
//A
//
//输出例子 :
//1
#include<iostream>
using namespace std;
#include<string>
void main()
{
	string str;
	char temp;
	cin >> str;  //	getline(cin,str);
	cin >> temp;
	int result=0;  //result=getNumber(str,temp);写成函数的形式，在函数内将大小写转换，然后判断
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i]==temp)
		{
			result++;
		}
	}
	cout << result<<endl;
};