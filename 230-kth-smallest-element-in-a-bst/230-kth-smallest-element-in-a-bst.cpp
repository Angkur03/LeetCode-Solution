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
    set<int>st;
    set<int>::iterator it;
    
    int kthSmallest(TreeNode* root, int k) {
        traverse(root);
        int cnt = 0;
        int ans = 0;
        it = st.begin();
        while(it != st.end()) {
            cnt++;
            if(cnt == k) {
                ans = *it;
                break;
            }
            it++;
        }
        return ans;
    }
    
    void traverse(TreeNode* root) {
        if(root == NULL) {
            return;
        }
        st.insert(root->val);
        traverse(root->left);
        traverse(root->right);
    }
};