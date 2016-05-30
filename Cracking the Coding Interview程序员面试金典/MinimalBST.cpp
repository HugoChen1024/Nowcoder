/*****************************************************
* \file MinimalBST.cpp
* \date 2016/05/30 16:00

* \问题描述：
对于一个元素各不相同且按升序排列的有序序列，请编写一个算法，创建一棵高度最小的二叉查找树。
给定一个有序序列int[] vals,请返回创建的二叉查找树的高度。

* \问题分析：
由于没有让给出树的构造过程，所以可以直接通过归纳的方式计算得出结果。但是在这里我们仍旧使用递归的方式模拟树的构建，并最终得到二叉搜索树。
题目中要求树的高度最小实际上是让构造一个平衡二叉树，或者说为了让左右两个子树的节点数量越接近越好。

///虽然可以直接公式算高度，不过也写了个建树顺便算高度的
*****************************************************/
#include <iostream>
using namespace std;
#include <vector>

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr){}
};
class MinimalBST {
public:
	TreeNode* buildBST(vector<int> _vals,int _left,int _right)
	{
		if (_left>_right)
		{
			return nullptr;
		}
		int mid = _left + (_right - _left) / 2;
		TreeNode* root = new TreeNode(_vals[mid]);
		root->left = buildBST(_vals, _left, mid - 1);
		root->right = buildBST(_vals, mid + 1, _right);
		return root;
    }
	int highBST(TreeNode* _root)
	{
		if (_root==nullptr)
		{
			return 0;
		}
		int left = highBST(_root->left);
		int right = highBST(_root->right);
		return left > right ? (left + 1) : (right + 1);
	}
	int buildMinimalBST(vector<int> vals) {
		// write code here
		if (vals.size()<=0)
		{
			return 0;
		}
		TreeNode* root = buildBST(vals,0,vals.size()-1);
		return highBST(root);
	}
};