//题目描述
//
//实现一个函数，检查二叉树是否平衡，平衡的定义如下，对于树中的任意一个结点，其两颗子树的高度差不超过1。
//给定指向树根结点的指针TreeNode* root，请返回一个bool，代表这棵树是否平衡。

//题目分析：
//<方法1>：
//平衡二叉树是通过左右子树的高度来判断是否为平衡二叉树的，所以我们首先想到的是如何求一个树的高度，求一个树的高度很简单，递归求解，每次求出左右子树的最大高度再加1便是父节点的高度，这样递归下去，便可以求出任何一颗树的高度。
//既然可以求出任何一个节点的高度，那么通过再次遍历二叉树，判断任何一个节点的左右子树高度相差是否满足平衡二叉树便可实现平衡二叉树的判断。
//求一颗平衡树高度的时间复杂度为O(logN)，那么在第二次遍历的时候需要求每个节点的高度时间复杂度为O(NlogN)。其实这个过程大部分都是重复判断的，下面的方法是该方法的浓缩。
//<方法2>：
//在一次遍历的过程中，既求一个节点的高度，同时该节点是否满足平衡条件，递归函数中一个引用参数返回子节点的高度，然后父节点的高度便可以通过两个子节点的高度求出来，首先判断两个子节点的高度是否满足平衡二叉树，不满足直接返回，满足的情况下，求出当前节点的高度，继续向上递归。
//该方法的时间复杂度只有O(logN)

struct TreeNode
{
	int val;
	struct TreeNode *right;
	struct TreeNode *left;
    TreeNode(int x):val(x), right(nullptr), left(nullptr){}

};

//方法一：
class Balance
{
public:
	int treeDeep(TreeNode *root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		//int deep = 0;
		int left = treeDeep(root->left);
		int right = treeDeep(root->right);
		return left > right ? (left + 1) : (right + 1);
	}
	bool isBalance(TreeNode *root)
	{
		if (root==nullptr)
		{
			return true;
		}
	/*	if (root->left!=nullptr)
		{

		}*/
		int left = treeDeep(root->left);
		int right = treeDeep(root->right);
		if (left-right>1||left-right<-1)
		{
			return false;
		}
		return isBalance(root->left) && isBalance(root->right);
	}

};

//方法二
class Balance {
public:
	bool isBalance(TreeNode* root) {
		// write code here
		int high = 0;
		return isBalance1(root, high);
	}
	bool isBalance1(TreeNode* root, int &high)
	{
		if (root == nullptr)
		{
			high = 0;
			return true;
		}
		int lhigh, rhigh;
		if (!isBalance1(root->left, lhigh) || !isBalance1(root->right, rhigh))
			return false;
		if (lhigh - rhigh>1 || lhigh - rhigh<-1)
			return false;
		high = (lhigh >= rhigh ? lhigh : rhigh) + 1;
		return true;
	}
};