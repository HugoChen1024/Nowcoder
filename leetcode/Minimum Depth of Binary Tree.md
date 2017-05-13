- 平时练习一下leetcode

- 先根据牛课网上题练习，同步[leetcode官网](https://leetcode.com/)

## 题目

- Given a binary tree, find its minimum depth.The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

## 思路

- 本题要注意最小深度与最大深度的区别:对于最大深度,不需要考虑当前子树是否为单子树（即一侧树深度为0）的情况，即最大深度一直等于左右子树的最大值；对于最小深度，需要考虑当前子树是否为单子树的情况，对于双子树，其最小深度为左右子树的最小值，对于单子树，其最小深度为左右深度的最大值（因为一侧的子树为0）.

## Nowcoder 

```C++
class Solution {
public:
    int run(TreeNode *root) {  //叶子结点才记录深度，然后不断更新
        if(root==nullptr)
            return 0;
        int l_depth=0,r_depth=0;
       
        l_depth=run(root->left);
        r_depth=run(root->right);
        
        if(l_depth==0)
            return r_depth+1;
        if(r_depth==0)
            return l_depth+1;
        if(l_depth<r_depth)
            return l_depth+1;
        else 
            return r_depth+1;
    }
};
```
## leetcode

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
    int minDepth(TreeNode *root) {
        if(!root) return 0;
        if(!root->left) return 1 + minDepth(root->right);
        if(!root->right) return 1 + minDepth(root->left);
        return 1+min(minDepth(root->left),minDepth(root->right));
    }
};

```