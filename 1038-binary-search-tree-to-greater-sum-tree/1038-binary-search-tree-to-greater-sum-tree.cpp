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
    TreeNode* bstToGst(TreeNode* root) {
        traverse(root);
        sort(vec.begin(), vec.end());
        // for(int i=0; i<vec.size(); i++) {
        //     cout<<i<<" "<<vec[i]<<endl;
        // }
        newTree(root);
        return root;
    }
    
    void traverse(TreeNode* root) {
        if(root == NULL) {
            return;
        }
        
        vec.push_back(root->val);
        traverse(root->left);
        traverse(root->right);
    }
    
    void newTree(TreeNode* root) {
        if(root == NULL) {
            return;
        }
        int currentVal = root->val;
        //cout<<"cVal "<<currentVal<<endl;
        int sum = 0;
        for(int i=0; i<vec.size(); i++) {
            if(vec[i] >= currentVal) {
                sum+=vec[i];
            }
        }
        root->val = sum;
        newTree(root->left);
        newTree(root->right);
    }
};