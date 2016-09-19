
//如果对于一个字符串A，将A的前面任意一部分挪到后边去形成的字符串称为A的旋转词。比如A = "12345", A的旋转词有"12345", "23451", "34512", "45123"和"51234"。对于两个字符串A和B，请判断A和B是否互为旋转词。
//给定两个字符串A和B及他们的长度lena，lenb，请返回一个bool值，代表他们是否互为旋转词。
//测试样例：
//"cdab", 4, "abcd", 4
//返回：true

#include <iostream>
using namespace std;
#include <string>

class Rotation {
public:
	bool chkRotation(string A, int lena, string B, int lenb) {
		// write code here
		if (A.size()!=B.size())
		{
			return false;
		}
		A = A + A;
		int index = A.find(B); //经典的用KMP算法
		if (index!=-1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};


// KMP Algorithm
public int getIndexOf(String s, String m) {
	if (s.length() < m.length()) {
		return -1;
	}
	char[] ss = s.toCharArray();
	char[] ms = m.toCharArray();
	int si = 0;
	int mi = 0;
	int[] next = getNextArray(ms);
	while (si < ss.length && mi < ms.length) {
		if (ss[si] == ms[mi]) {
			si++;
			mi++;
		}
		else if (next[mi] == -1) {
			si++;
		}
		else {
			mi = next[mi];
		}
	}
	return mi == ms.length ? si - mi : -1;
}

public int[] getNextArray(char[] ms) {
	if (ms.length == 1) {
		return new int[] { -1 };
	}
	int[] next = new int[ms.length];
	next[0] = -1;
	next[1] = 0;
	int pos = 2;
	int cn = 0;
	while (pos < next.length) {
		if (ms[pos - 1] == ms[cn]) {
			next[pos++] = ++cn;
		}
		else if (cn > 0) {
			cn = next[cn];
		}
		else {
			next[pos++] = 0;
		}
	}
	return next;
}
