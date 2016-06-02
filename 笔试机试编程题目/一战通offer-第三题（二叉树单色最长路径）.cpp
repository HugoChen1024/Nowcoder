
//对于一棵由黑白点组成的二叉树，我们需要找到其中最长的单色简单路径，其中简单路径的定义是从树上的某点开始沿树边走不重复的点到树上的
//另一点结束而形成的路径，而路径的长度就是经过的点的数量(包括起点和终点)。而这里我们所说的单色路径自然就是只经过一种颜色的点的路径。
//你需要找到这棵树上最长的单色路径。
//给定一棵二叉树的根节点(树的点数小于等于300，请做到O(n)的复杂度)，请返回最长单色路径的长度。
//这里的节点颜色由点上的权值表示，权值为1的是黑点，为0的是白点。


//这题用动态规划来求解。需要用到一对引用传值(white和black)来记录每个节点的左右孩子节点的黑白路径长度值传递上来。
//如：lhswhite ，lhsblack ，rhswhite，rhsblack分别表示两个孩子节点的黑白最长路径长度
//分两类情况：
//（1）当父节点为黑时：其white = 0，black = max(lhsblack + 1, rhsblack + 1)，它的最长单色路径长度为lhsblack + rhsblack + 1；
//（2）当父节点为白时：其black = 0，white = max(lhswhite + 1, rhswhite + 1)，它的最长单色路径长度为lhswhite + rhswhite + 1；

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(nullptr), right(nullptr) {
	}
};
//也不知道为什么就是不AC,和下面的有区别吗？？？？
class LongestPath {
public:
	int result = 0;
	
	int findPath(TreeNode* root) {
		// write code here
		if (root==nullptr)
		{
			return 0;
		}
		int white = 0, black = 0;
		path(root,white,black);
		return result;
	}
	void path(TreeNode* root, int &white, int &balck)
	{
		if (root->right == nullptr&&root->right == nullptr)
		{
			if (root->val == 1)
			{
				balck = 1; white = 0;
			}
			else
			{
				balck = 0; white = 1;
			}
		}
		else
		{
			int lblack = 0, lwhite = 0;
			int rblack = 0, rwhite = 0;
			if (root->right != nullptr)
			{
				path(root->right, rwhite, rblack);
			}
			if (root->left != nullptr)
			{
				path(root->left, lwhite, lblack);
			}
			if (root->val == 1)
			{
				if (lblack + rblack + 1 > result)
					result = lblack + rblack + 1;
				white = 0;
				balck = (lblack + 1) > (rblack + 1) ? (lblack + 1) : (rblack + 1);
			}
			else
			{
				if (rwhite + lwhite + 1 > result)
					result = rwhite + lwhite + 1;
				balck = 0;
				white = (lwhite + 1) > (rwhite + 1) ? (lwhite + 1) : (rwhite + 1);
			}
		}
	}
};

class LongestPath {
public:
	int ret = 0;
	int findPath(TreeNode* root) {
		// write code here
		int white = 0, black = 0;
		dfsPath(root, white, black);
		return ret;
	}
	void dfsPath(TreeNode* root, int &white, int &black){
		if (root->left == nullptr && root->right == nullptr){
			if (root->val == 1){
				white = 0; black = 1;
			}
			else{
				white = 1; black = 0;
			}
		}
		else{
			int lhswhite = 0, lhsblack = 0;
			int rhswhite = 0, rhsblack = 0;
			if (root->left != nullptr) dfsPath(root->left, lhswhite, lhsblack);
			if (root->right != nullptr) dfsPath(root->right, rhswhite, rhsblack);
			if (root->val == 1){
				if (lhsblack + rhsblack + 1 > ret) ret = lhsblack + rhsblack + 1;
				white = 0;
				black = lhsblack + 1 > rhsblack + 1 ? lhsblack + 1 : rhsblack + 1;
			}
			else{
				if (lhswhite + rhswhite + 1 > ret) ret = lhswhite + rhswhite + 1;
				black = 0;
				white = lhswhite + 1 > rhswhite + 1 ? lhswhite + 1 : rhswhite + 1;
			}
		}
	}
};