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
class BSTIterator {
public:
    vector<int>vec;
    stack<int>st;
    BSTIterator(TreeNode* root) {
        traverse(root);
        for(int i=vec.size()-1; i>=0; i--) {
            st.push(vec[i]);
        }
    }
    
    int next() {
        int val = st.top();
        st.pop();
        return val;
    }
    
    bool hasNext() {
        return !st.empty();
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

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */