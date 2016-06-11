//题目描述
//
//请实现一个函数，检查一棵二叉树是否为二叉查找树。
//给定树的根结点指针TreeNode* root，请返回一个bool，代表该树是否为二叉查找树。


#include<iostream>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};


class Checker {
public:
	//先想到的是返回true的情况， //改为return true有错误。
	bool checkBST(TreeNode* root) {  
		// write code here
		if (root == NULL) return true;
		if (root->left && root->left->val > root->val)
			return false;
		if (root->left && root->left->right && root->left->right->val>root->val)
			return false;
		if (root->right && root->right->val < root->val)
			return false;
		if (root->right&&root->right->left&&root->right->left->val < root->val)
			return false;

		return checkBST(root->left) && checkBST(root->right);
	}
};

//
//《程序员面试金典》 代码详解：http ://blog.csdn.net/zdplife/article/category/5799903
//题目分析：
//<方法1>
//首先我们想到的是二叉树中序遍历后的结果是有序的，根据这个结果，我们可以中序遍历二叉树，并把遍历结果存放在一个数组里面，然后判断这个数组大小是否是有序数组，如果是有序数组，则是二叉查找树，否则就不是。
//这个方法的时间复杂度是O(N)，但是空间复杂度比较高，需要浪费O（N）的存储空间。
//<方法2>
//其实在<方法1>的基础上，我们可以在中序遍历的同时，比较大小，每次记录下上次遍历过的元素的值，如果当前元素的值大于上次遍历元素的值，则接着遍历，否则返回false，因为这个记录是一个址传递，所以需要用到引用形参进行传递。
//这个方法的时间复杂度与<方法1>的时间复杂度相同，只是空间复杂度只需要一个元素O(1)。
class Checker {
public:
	bool checkBST(TreeNode* root) {
		// write code here
		int min = INT_MIN;
		return inOrderCompare(root, min);
	}
	bool inOrderCompare(TreeNode* root, int &last)
	{
		if (root == NULL)
			return true;
		if (!inOrderCompare(root->left, last))
			return false;
		if (root->val < last)
			return false;
		last = root->val;
		if (!inOrderCompare(root->right, last))
			return false;
		return true;
	}
};
//<方法3>
//可以根据二叉查找树的定义来判断，二叉树的定义，所有左子树的节点小于根节点，所有右子树的节点大于根节点，并且左右子树也是二叉查找树。所以在递归的过程中，我们只需要传递两个参数（当前根节点对应的二叉树的所有节点的最大值和最小值），
//同时不断的更新这两个参数，如果当前节点的值不在这两个数范围中，则直接返回false，否则接着递归便可。




//非递归遍历二叉树，然后判断结果是否递增
#include <stack>
#include <vector>
class Checker {
public:
	bool checkBST(TreeNode* root) {
		// write code here
		stack<TreeNode*> s;
		TreeNode *pNode = root;
		vector<int> data;
		while (pNode != NULL || !s.empty())
		{
			while (pNode != NULL)
			{
				s.push(pNode);
				pNode = pNode->left;
			}
			if (!s.empty())
			{
				pNode = s.top();
				data.push_back(pNode->val);
				s.pop();
				pNode = pNode->right;
			}
		}
		for (size_t i = 0; i < data.size() - 1; i++)
		{
			if (data[i] > data[i + 1])
				return false;
		}
		return true;
	}
};

//首先利用中序遍历排序，其次遍历检查排序序列是否递增，最后输出结果！
class Checker {
public:
	vector<int> res;
	bool checkBST(TreeNode* root) {
		// write code here
		if (root == NULL) return true;
		bool flag = false;
		inorder(root);
		for (int i = 0; i<res.size() - 1; i++)
		{
			if (res[i]>res[i + 1])
			{
				flag = true;
				break;
			}
		}
		if (flag)
			return false;
		else
			return true;
	}
	void inorder(TreeNode* root){
		if (root == NULL) return;
		inorder(root->left);
		res.push_back(root->val);
		inorder(root->right);
	}
};