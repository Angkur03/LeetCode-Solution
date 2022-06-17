/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int count = 0;
    int dfs(TreeNode* root){
        if(root==NULL)return 1;
        if(root->left == NULL && root->right == NULL)return 0;
        int stateLeft = dfs(root->left);
        int stateRight = dfs(root->right);
        if(stateLeft == 0 || stateRight == 0){
            count++;
            return 2;
        }
        else if(stateLeft == 2 || stateRight == 2)return 1;
        return 0;
    }
    
    int minCameraCover(TreeNode* root) {
        if(dfs(root)==0)count++;
        return count;
    }
};