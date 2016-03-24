//题目描述
//
//请实现一个算法，在不使用额外数据结构和储存空间的情况下，翻转一个给定的字符串(可以使用单个过程变量)。
//给定一个string iniString，请返回一个string，为翻转后的字符串。保证字符串的长度小于等于5000。
//测试样例：
//"This is nowcoder"
//返回："redocwon si sihT"

#include<iostream>
#include<string>
using namespace std;
class Reverse {
public:
	string reverseString(string iniString) {
		// write code here
		//string result;
		if(iniString.empty())
		{
			return  iniString;
		}
		//for (int i = iniString.size(); i >0; i--)  //error: control reaches end of non-void function [-Werror,-Wreturn-type]  //没有返回值啊
		//{
		//	cout << iniString[i - 1];
		//}
		//两个数字交换，可以借助第三变量，也可以不借助第三变量；有三种方法，自行总结
		//iniString[i] ^= iniString[j] ^= iniString[i] ^= iniString[j];//交换  
		for (int i = 0; i < iniString.size()/2; i++)
		{
			char temp = iniString[i];
			iniString[i] = iniString[iniString.size() - 1 - i];
			iniString[iniString.size() - 1 - i] = temp;
		}

		return iniString;
	}
};

//题目描述
//
//给定两个字符串，请编写程序，确定其中一个字符串的字符重新排列后，能否变成另一个字符串。这里规定大小写为不同字符，且考虑字符串重点空格。
//给定一个string stringA和一个string stringB，请返回一个bool，代表两串是否重新排列后可相同。保证两串的长度都小于等于5000。
//测试样例：
//"This is nowcoder", "is This nowcoder"
//返回：true
//"Here you are", "Are you here"
//返回：false

#include<iostream>
using namespace std;
#include<string>
#include<map>
//直接用的sort函数,虽然简洁，复杂度却是O(nlogn);
//正规的做法，应该是hash，用256的元素记录每个字符出现的次数
//再进行比较，扫描一遍，比较一遍，复杂度只要O(n).
class Same {
public:
	bool checkSam(string stringA, string stringB) {
		// write code here
		map<char,int> maps;
		if (stringA.size()!=stringB.size())
		{
			return false;
		}
		for (size_t i = 0; i < stringA.size(); i++)
		{
			maps[stringA[i]]++;
		}
		for (size_t i = 0; i < stringB.size(); i++)
		{
			maps[stringB[i]]--;
		}
		//if (maps.empty())   //为什么没有通过呢？？？
		//{
		//	return true;
		//}
		//else
		//{
		//	return false;
		//}
		for (size_t i = 0; i < maps.size(); i++) //通过测试
		{
			if (maps[i]!=0)
			{
				return false;
			}
		}
		return true;
	}
};


////想法不错，但是若是AA，BB此题也可通过
//bool checkSam(string stringA, string stringB) {
//	// write code here
//	int lenA = stringA.length();
//	int lenB = stringB.length();
//	if (lenA == lenB){
//		int t = 0;
//		for (int i = 0; i<lenA; i++){
//			t ^= stringA[i];
//			t ^= stringB[i];
//		}
//		if (t == 0){
//			return true;
//		}
//	}
//	return false;
//}