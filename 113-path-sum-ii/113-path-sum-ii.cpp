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
    vector<int>path;
    vector<vector<int>>ans;
    
    void preparePathSum(TreeNode* root, int targetSum, int sum) {
        if(root == NULL ) {
            return;
        }
        sum += root->val;
        path.push_back(root->val);
        if(sum == targetSum && !root->left && !root->right) {
            //cout<<" found "<<path.size()<<endl;
            ans.push_back(path);
        }

        preparePathSum(root->left, targetSum, sum);
        preparePathSum(root->right, targetSum, sum);
        
        path.pop_back();
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        preparePathSum(root, targetSum, 0);
        return ans;
    }
};