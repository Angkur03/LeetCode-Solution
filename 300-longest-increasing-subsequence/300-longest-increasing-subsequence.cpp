class Solution {
public:
    vector<vector<int>> dp;
    
    int lengthOfLIS(vector<int>& nums) {
        dp.resize(size(nums), vector<int>(1+size(nums), -1));   
        return solve(nums, 0, -1);
    }
    
    int solve(vector<int>& nums, int i, int prevVal) {
        if(i >= nums.size()) return 0;
        if(dp[i][prevVal+1] != -1) return dp[i][prevVal+1];
        int take = 0, dontTake = solve(nums, i + 1, prevVal);
        if(prevVal == -1 || nums[i] > nums[prevVal]) take = 1 + solve(nums, i + 1, i); 
        
        return dp[i][prevVal+1] = max(take, dontTake);
    }
};
/*
[10,9,2,5,3,7,101,18]
[0,1,0,3,2,3]
[7,7,7,7,7,7,7]
[1,24,2,53,0,1,2,3,4,5,8,7,6,7,8,9,10]
}
*/