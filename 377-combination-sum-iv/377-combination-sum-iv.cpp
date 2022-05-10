class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int dp[target+5];
        for(int i=0; i<=target; i++) {
            dp[i] = -1;
        }
        return getCount(nums, target, dp) ;
    }
    
    int getCount(vector<int>& nums, int target, int dp[]) {
        if(target == 0) {
            return 1;
        }
        
        if(target < 0) {
            return 0;
        }
        
        if(dp[target] != -1) {
            return dp[target];
        }
        
        int res = 0;
        for(int i=0; i<nums.size(); i++) {
            res += getCount(nums,target - nums[i],dp);
        }
        
        return dp[target] = res;
    }
};