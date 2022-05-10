class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int>ans;
        getCombination(res,ans,k,n,0);
        return res;
    }
    
    void getCombination(vector<vector<int>> &res, vector<int>ans, int k, int n,int pos) {
        if(ans.size() == k && n == 0) {
            res.push_back(ans);
            return;
        }
        
        for(int i = pos+1; i<10; i++) {
            ans.push_back(i);
            getCombination(res,ans,k,n-i,i);
            ans.pop_back();
        }
    }
};