class Solution {
public:
    int dp[1005];
    int combinationSum4(vector<int>& nums, int target) {
        for(int i=0; i<=target; i++) {
            dp[i] = -1;
        }
        return getCount(nums, target) ;
    }
    
    int getCount(vector<int>& nums, int target) {
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
            res += getCount(nums,target - nums[i]);
        }
        
        return dp[target] = res;
    }
};