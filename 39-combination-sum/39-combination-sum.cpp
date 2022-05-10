class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>pattern;
        getCombination(ans,candidates,target,0,pattern);
        return ans;
    }
    
    void getCombination(vector<vector<int>> &ans, vector<int> candidates, int target,int pos,vector<int>pattern){
        if(target == 0) {
            ans.push_back(pattern);
            // for(int i=0; i<pattern.size(); i++) {
            //     cout<<i<<" -- "<<pattern[i]<<endl;
            // }
            return;
        }
        if(target < 0) {
            return;
        }
        
        for(int i=pos; i<candidates.size(); i++) {
            int val = candidates[i];
            pattern.push_back(val);
            getCombination(ans,candidates,target-val,i,pattern);
            pattern.pop_back();
        }
    }    
};