//小Q最近遇到了一个难题：把一个字符串的大写字母放到字符串的后面，各个字符的相对位置不变，且不能申请额外的空间。
//你能帮帮小Q吗？
//
//输入描述 :
//
//输入数据有多组，每组包含一个字符串s，且保证 : 1 <= s.length <= 1000.
//
//
//
//输出描述 :
//
//	 对于每组数据，输出移位后的字符串。
//
// 输入例子 :
//						 AkleBiCeilD
//
//						 输出例子 :
//						 kleieilABCD


#include<iostream>
using namespace  std;
#include <string>


//应该从头往后遍历，把连续的大写字母找到，遇到小写字母，交换。
//如果先找到大写字母，马上找连续的小写字母，那遇到连续的大写字母该怎么办呢？
//或者从尾向头遍历，方法类似。
string changeSequenceStr(string &str)
{
	int size = str.size();
	/*for (int i = 0; i < size;i++)
	{
	if (isupper(str[i]))
	{
	int j = i+1;
	while (islower(str[j])&&j<size)
	{
	j++;
	}
	if (isupper(str[j])&&j<size)
	{
	char temp = str[i];
	for (int k = i; k < j; k++)
	{
	str[k] = str[k + 1];
	}
	str[j - 1] = temp;
	}
	}
	}*/

	for (int i = 0; i < size;i++)
	{
		if (isupper(str[i]))
		{
			int j = i;
			while (isupper(str[j])&&j<size)
			{
				j++;
			}
			if (j==(size-1)&&isupper(str[j]))
			{
				break;
			}
			if (islower(str[j])&&j<size)
			{
				char temp = str[j];
				for (int k = j; k > i;k--)
				{
					str[k] = str[k - 1];
				}
				str[i] = temp;
			}
		}
	}
	return str;
}

int main()
{
	string str;
	while (getline(cin,str))
	{
		cout << changeSequenceStr(str)<<endl;
	}
	return 0;
}