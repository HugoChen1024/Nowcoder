/*****************************************************
* \file TreeLevel.cpp
* \date 2016/05/31 17:05

* \问题描述：
对于一棵二叉树，请设计一个算法，创建含有某一深度上所有结点的链表。
给定二叉树的根结点指针TreeNode* root，以及链表上结点的深度，请返回一个链表ListNode，代表该深度上所有结点的值，请按树上从左往右的顺序链接，
保证深度不超过树的高度，树上结点的值为非负整数且不超过100000。


* \问题分析：
<方法1>：层次遍历
这个题目的意思就是输出二叉树的某一层的所有元素，这个首先想到的是层次遍历，层次遍历最简单的方法就是用队列实现，我们传统的层次遍历方法是可以输出所有元素，那么如何区分相邻两层之间的元素呢？
其实我们可以用两个整数变量line1，line2来记录相邻两层的元素个数，其中line1代表出栈那一层留下的元素个数，line2代表下一层进栈元素的个数，
每当line1为0的时候，说明上一层已经全部出栈，下一层已经全部入栈，那么层次遍历层数就加一，这个时候将line2的值复制给line1，line2=0，
当遍历到第dep层的时候，便把那一层的所有元素输出，停止遍历。

//还有就是用两个队列实现，一个存放当前层的结点，一个存下一层的结点；或者一个队列一个vector存放当前行的所有节点，每一层更新vector
*****************************************************/

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr){}
};
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(nullptr){}
}; 

using namespace std;
#include <queue>
class TreeLevel{
public:
	ListNode* getTreeLevel(TreeNode* root,int dep){
	if (root==nullptr||dep<=0)
	{
		return nullptr;
	}
	ListNode* pHead = new ListNode(-1);
	ListNode* pNode = pHead;
	queue<TreeNode*> qu;
	qu.push(root);
	int lineCur = 1, lineNext = 0, num = 1;
	while (!qu.empty())
	{
		if (num==dep)
		{
			for (int i = 0; i < lineCur;i++)
			{
				TreeNode* node = qu.front();
				pNode->next = new ListNode(node->val);
				pNode = pNode->next;
				qu.pop();
			}
			return pHead->next;
		}
		TreeNode* node = qu.front();
		if (node->left)
		{
			qu.push(node->left);
			lineNext++;
		}
		if (node->right)
		{
			qu.push(node->right);
			lineNext++;
		}
		qu.pop();
		if (--lineCur==0)
		{
			lineCur = lineNext;
			lineNext = 0;
			num++;
		}
	}
	return pHead->next;
	}
};