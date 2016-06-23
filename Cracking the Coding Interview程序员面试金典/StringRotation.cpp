/*****************************************************
* \file StringRotation.cpp
* \date 2016/06/23 17:11

* \问题描述：

对于一个字符串，和字符串中的某一位置，请设计一个算法，将包括i位置在内的左侧部分移动到右边，将右侧部分移动到左边。
给定字符串A和它的长度n以及特定位置p，请返回旋转后的结果。
测试样例：
"ABCDEFGH",8,4
返回："FGHABCDE"

* \问题分析：



*****************************************************/

#include<iostream>
using namespace std;
#include<string>
class StringRotation {
public:
	string rotateString(string A, int n, int p) {
		// write code here
		string B;
		B.assign(A.begin()+p+1, A.begin() + n);  
		for (int i = 0; i <= p;i++)
		{
			B.push_back(A[i]);
		}
		return B;
	}
};

//return A.substr(p+1) + A.substr(0, p+1);

// string b=A+A;
// string a = b.substr(p + 1, n);
// return a;

int main()
{
	string A = "ABCDEFGHJK";
	StringRotation s;
	string B=s.rotateString(A, 10, 7);
	cout << B << endl;
}