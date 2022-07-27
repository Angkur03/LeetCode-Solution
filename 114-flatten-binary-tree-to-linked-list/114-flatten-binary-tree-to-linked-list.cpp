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
    vector<TreeNode*> vec;
    void getPreOrder(TreeNode* root) {
        if(root == NULL) {
            return;
        }
        vec.push_back(root);
        getPreOrder(root->left);
        getPreOrder(root->right);
    }
    
    void flatten(TreeNode* root) {
        if(root == NULL) {
            return;
        }
        getPreOrder(root);
        root->left = NULL;
        for(int i=1; i<vec.size(); i++) {
            root->right = vec[i];
            vec[i]->left = NULL;
            root = root->right;
        }
    }
    
};