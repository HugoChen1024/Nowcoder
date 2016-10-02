/*****************************************************
* \file findMissing.cpp
* \date 2016/10/02 11:29
* \author ranjiewen
* \contact: ranjiewen@outlook.com 
* \问题描述：

数组A包含了0到n的所有整数，但其中缺失了一个。对于这个问题，我们设定限制，使得一次操作无法取得数组number里某个整数的完整内容。唯一的可用操作是询问数组中第i个元素的二进制的第j位(最低位为第0位)，该操作的时间复杂度为常数，请设计算法，在O(n)的时间内找到这个数。
给定一个数组number，即所有剩下的数按从小到大排列的二进制各位的值，如A[0][1]表示剩下的第二个数二进制从低到高的第二位。同时给定一个int n，意义如题。请返回缺失的数。
测试样例：
[[0],[0,1]]
返回：1


* \问题分析：
思路：整数值x的二进制表示最低位为1的时候，x为奇数；最低位为0时，x为偶数。
由于数组中的数是0~n剩余数按照从小到大进行排列的，因此在缺失数之前，数组行标与数是相等的，即行标i = x，此时行标i % 2的值与数组中numbers[i][0]是相等的，即i为奇数，numbers[i][0]为1；为偶数时，numbers[i][0]为0.
第一个 i % 2与numbers[i][0]不相等处即为缺失数。
要注意缺失数为n即最大值的情况。要单独return n；


*****************************************************/

//理解题目：


#include <iostream>
using namespace std;
#include <vector>
class Finder {
public:
	//O(N)
	int findMissing(vector<vector<int> > numbers, int n) {
		// write code here
		for (int i = 0; i < n;i++)
		{
			if (numbers[i][0]!=i%2)
			{
				return i;
			}
		}
		return n;
	}

	// O(logN)
	int method2(vector<vector<int> > numbers, int n) {
		int low = 0, high = numbers.size() - 1;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (numbers[mid][0] == (mid & 1))
				low = mid + 1;
			else
				high = mid - 1;
		}
		if (low == numbers.size()) 
			return n;
		else 
			return low;
	}
};