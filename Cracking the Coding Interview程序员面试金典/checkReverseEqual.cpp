
/*****************************************************
* \file checkReverseEqual.cpp
* \date 2016/04/06 17:59
*问题描述：

假定我们都知道非常高效的算法来检查一个单词是否为其他字符串的子串。请将这个算法编写成一个函数，给定两个字符串s1和s2，请编写代码检查s2是否为s1旋转而成，要求只能调用一次检查子串的函数。
给定两个字符串s1, s2, 请返回bool值代表s2是否由s1旋转而成。字符串中字符为英文字母和空格，区分大小写，字符串长度小于等于1000。
测试样例：
"Hello world", "worldhello "
返回：false
"waterbottle", "erbottlewat"
返回：true


*问题分析：

以s1=ABCD为例，我们先分析s1进行循环移位之后的结果：
ABCD->BCDA->CDAB->DABC->ABCD  .......
假设我们把前面移走的数据进行保留：
ABCD->ABCDA->ABCDAB->ABCDABC->ABCDABCD.....
因此看出，对s1做循环移位，所得字符串都将是字符串s1s1的子字符串。如果s2可以由s1循环移位得到，则一定可以在s1s1上。
将两个s1连接起来,判断s2是否为s1的子串,利用string的find来实现
s1拼接自己一次当作s3，s2如果是s1旋转来的就必定是s3的子串

****************************************************/


#include<iostream>
#include<string>
using namespace std;


class ReverseEqual {
public:	
	
	bool checkReverseEqual(string s1, string s2) {
		// write code 
		if (s1.size()==0||s2.size()==0)
		{
			return false;
		}
		string s = s2 + s2;
		if (s.find(s1)==-1)//if (str.contains(s1))  //int find(char c, int pos = 0) const;//从pos开始查找字符c在当前字符串的位置
		{
			return false;
		}
		return true;
	}
	
};