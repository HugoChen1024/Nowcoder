//题目描述
//
//请编写一个方法，将字符串中的空格全部替换为“ % 20”。假定该字符串有足够的空间存放新增的字符，
//并且知道字符串的真实长度(小于等于1000)，同时保证字符串由大小写的英文字母组成。
//给定一个string iniString 为原始的串，以及串的长度 int len, 返回替换后的string。
//测试样例：
//"Mr John Smith”,13
//返回："Mr%20John%20Smith"
//”Hello  World”, 12
//返回：”Hello % 20 % 20World”

#include<iostream>
#include<string>
#include<sstream>
using namespace std;

class Replacement {
public:
	string replaceSpace(string iniString, int length) {
		// write code here
		string result="";
		for (size_t i = 0; i < length; i++)
		{
			if (iniString[i] == ' ')
			{
				result += "%20";
			}
			else
				result += iniString[i];
		}

		//int i;
		//while (iniString[i]!='\0')    //运行超时
		//{
		//	if (iniString[i]==' ')
		//	{
		//		iniString.insert(i,"%20");
		//		i += 2;
		//	}
		//}


		//istringstream ss(iniString);
		//string temp,result="";
		//while (ss>>temp)
		//{
		//	result += temp + "%20";  //去掉最后几个  //连续两个空格不能通过。
		//}
		//result.erase(result.end()-4,result.end()-1);

		return result;
	}
};