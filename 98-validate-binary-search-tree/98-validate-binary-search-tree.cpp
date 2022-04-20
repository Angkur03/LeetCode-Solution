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
    vector<int>nodes;
    bool isValidBST(TreeNode* root) {
        isOk(root);
        if(nodes.size() == 0 || nodes.size() == 1) {
            return true;
        }
        
        for(int i=1; i<nodes.size(); i++) {
            if(nodes[i] <= nodes[i-1]) {
                return false;
            }
        }
        return true;
    }
    
    void isOk(TreeNode* root) {
        if(root == NULL) {
            return;
        }
        isOk(root->left);
        nodes.push_back(root->val);
        isOk(root->right);
    }
};