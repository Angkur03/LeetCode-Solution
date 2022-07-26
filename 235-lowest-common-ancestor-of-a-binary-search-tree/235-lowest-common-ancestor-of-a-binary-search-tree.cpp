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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root, p, q);
    }
    
    TreeNode * dfs(TreeNode * root, TreeNode * p , TreeNode * q) {
        if( root == p || root == q || root == NULL)
            return root;
        TreeNode * par1 = dfs(root->left, p, q);
        TreeNode * par2 = dfs(root->right, p, q);
        if( par1 && par2)
            return root;
        else
            return par1 ? par1:par2;
    }  
};