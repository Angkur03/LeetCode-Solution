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
    map<int,int>mp;
    set<int>st;
    
    int findSecondMinimumValue(TreeNode* root) {
        if(root == NULL) {
            return -1;
        }
        traverse(root);
        int ans = -1;
        int cnt = 0;
        set<int>::iterator itr;
        for (itr = st.begin(); itr != st.end(); itr++) {
            cnt++;
            if(cnt == 2) {
                ans = *itr;
                break;
            }
        }
        return ans;
    }
    
    void traverse(TreeNode* root) {
        if(root == NULL) {
            return ;
        }
        st.insert(root->val);
        traverse(root->left);
        traverse(root->right);
    }
    
    
};