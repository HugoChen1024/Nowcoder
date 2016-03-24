//题目描述
//
//将一个英文语句以单词为单位逆序排放。例如“I am a boy”，逆序排放后为“boy a am I”
//所有单词之间用一个空格隔开，语句中除了英文字母外，不再包含其他字符
//
//接口说明
///**
//* 反转句子
//*
//* @param sentence 原句子
//* @return 反转后的句子
//*/
//public String reverse(String sentence);
//输入描述:
//将一个英文语句以单词为单位逆序排放。
//
//
//输出描述 :
//得到逆序的句子

#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

//void reverse(string sentence)
//{
//	if (sentence.empty())
//	{
//		return;
//	}
//	vector<string> result;
//	string  temp;  //不要定义为vector<char>
//	for (size_t i = 0; i < sentence.size(); i++)
//	{
//	//	if (sentence[i]!=' ')
//		{
//			temp.push_back(sentence[i]);
//		}
//		if (sentence[i] == ' '||i==sentence.size()-1)//
//		{
//			result.push_back(temp);
//			temp.clear();
//		}
//	//	result.push_back(temp);
//	}
//	for (int i = result.size(); i >0; i--)
//	{
//		cout << result[i-1];
//	}
//}

void reverse(string sentence)
{
	istringstream ss(sentence);  //包含头文件
	string temp,result="";
	while (ss>>temp)//可以给vector<string>
	{
		if (result=="")  //第一个
		{
			result = temp;
		}
		else
		    result = temp + ' ' + result;
	}
	cout << result<<endl;
}
int main()
{
	string str;
	while (getline(cin,str))
	{
  		reverse(str);
//		cout << endl;
	}
//	cout << endl;
	return 0;
}