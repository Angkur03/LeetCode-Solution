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
    vector<int>vec;
    TreeNode* increasingBST(TreeNode* root) {
        traverse(root);
        TreeNode *newRoot = new TreeNode(vec[0]);
        TreeNode *temp = newRoot;
        for(int i=1; i<vec.size(); i++) {
           TreeNode *rightNode = new TreeNode(vec[i]);
            newRoot->right = rightNode;
            newRoot->left = NULL;
            newRoot = newRoot->right;
        }
        return temp;
    }
    
    void traverse(TreeNode* root) {
        if(root == NULL) {
            return;
        }
        traverse(root->left);
        vec.push_back(root->val);
        traverse(root->right);
    }
};