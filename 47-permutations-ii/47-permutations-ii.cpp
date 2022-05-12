class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>pattern,mp(nums.size(), 0);
        set<vector<int>> patSet;
        
        getPermutation(nums,pattern,mp,patSet);
        for(auto st: patSet) {
            ans.push_back(st);
        }
        return ans;
    }
    
    void getPermutation(vector<int>& nums, vector<int>pattern,vector<int>mp, set<vector<int>> &patSet) {
        if(pattern.size() == nums.size()) {
            patSet.insert(pattern);
            return;
        }
        
        for(int i=0; i<nums.size(); i++) {
            int val = nums[i];
            if(mp[i] == 0) {
                pattern.push_back(val);
                mp[i] = 1;
                getPermutation(nums,pattern,mp,patSet);
                pattern.pop_back();
                mp[i] = 0;
            }
        }
    }
};