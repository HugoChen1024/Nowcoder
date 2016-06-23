/*****************************************************
* \file Successor.cpp
* \date 2016/06/23 15:34

* \问题描述：
题目描述

请设计一个算法，寻找二叉树中指定结点的下一个结点（即中序遍历的后继）。
给定树的根结点指针TreeNode* root和结点的值int p，请返回值为p的结点的后继结点的值。
保证结点的值大于等于零小于等于100000且没有重复值，若不存在后继返回-1。

* \问题分析：



*****************************************************/

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(nullptr), right(nullptr) {
	}
};

#include <iostream>
using namespace std;
#include <vector>
class Successor {
private:
	vector<int> vc;
public:
	void inOrder(TreeNode* root)
	{
		if (root != nullptr)
		{
			{
				inOrder(root->left);
				vc.push_back(root->val);
				inOrder(root->right);
			}
		}
	}
	int findSucc(TreeNode* root, int p) {
		// write code here
		inOrder(root);
		int val=-1;
		//这样不通过AC??
		/*for (auto it = vc.begin(); it != vc.end();it++)
		{
			if (*it==p)
			{
				val= *(it++);
				break;
			}  
		}*/
		for (int i = 0; i < vc.size();i++)
		{
			if (vc[i]==p&&i<vc.size()-1)
			{
				return vc[i + 1];
			}
		}
		return val;
	}	
};