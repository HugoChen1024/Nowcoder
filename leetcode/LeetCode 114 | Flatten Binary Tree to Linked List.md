
## 题目

```
给定一个二叉树，原地将它展开为链表。

例如，给定二叉树

    1
   / \
  2   5
 / \   \
3   4   6

将其展开为：

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6

```

## 解析

- 通过递归实现；可以用先序遍历，然后串成链表
- 主要思想就是：先递归对右子树进行链表化并记录，然后将root->right指向 左子树进行链表化后的头结点，然后一直向右遍历子树，连接上之前的右子树

```C++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* treetolist(TreeNode* root)
	{
        if(!root)
            return NULL;
		TreeNode* right=treetolist(root->right); //记录右子树
		root->right=treetolist(root->left);
		root->left=NULL;
		
		TreeNode* cur=root;
		while(cur->right)
		{
			cur=cur->right;
		}
		cur->right=right;
		return root;
	}
    void flatten(TreeNode* root) {
        
		treetolist(root);
    }
};

```

- 理解上面代码过后就容易理解：[LeetCode | Flatten Binary Tree to Linked List（二叉树转化成链表）](https://blog.csdn.net/a45872055555/article/details/38563269)
