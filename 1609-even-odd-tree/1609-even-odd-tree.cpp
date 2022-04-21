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
    vector<vector<int> > vec;
    bool isEvenOddTree(TreeNode* root) {
        traverse(root,0);
        int flag = 0;
        for(int i=0; i<vec.size(); i++) {
            int prev = -1;
            //cout<<"i "<<vec[i].size()<<endl;
            for(int j = 0; j<vec[i].size(); j++) {
                int val = vec[i][j];
                //cout<<i<<" val "<<val<<endl;
                if(i%2 == 0) {
                    if(prev == -1 && val%2 == 1) {
                        prev = val;
                    } else if(val > prev && val%2 == 1) {
                        prev = val;
                    } else {
                        flag = 1;
                        break;
                    }
                } else {
                    if(prev == -1 && val%2 == 0) {
                        prev = val;
                    } else if(val < prev && val%2 == 0) {
                        prev = val;
                    } else {
                        flag = 1;
                        break;
                    }
                }
            }
        }
        return flag == 0;
    }
    
    void traverse(TreeNode* root, int lev) {
        if(root == NULL) {
            return;
        }
        if(vec.size() <= lev) {
            vec.push_back({});
        }
        vec[lev].push_back(root->val);
        traverse(root->left, lev+1);
        traverse(root->right, lev+1);
    }
};

/*
[5,9,1,3,5,7]
[1,10,4,3,null,7,9,12,8,6,null,null,2]
[5,4,2,3,3,7]
[1]
*/