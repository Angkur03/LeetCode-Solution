class Solution {
public:
    int dp[1001][1001];
    
    void reset() {
        int val = INT_MIN;
        for(int i=0; i<=1000; i++) {
            for(int j=0; j<=1000; j++) {
                dp[i][j] = val;
            }
        }
        //memset(dp,-1000,sizeof(dp));
    }
    
    int getMaxSum(vector<int>& nums, vector<int>& multipliers, int start, int end, int pos, int n) {
        if(pos >= n) {
            return 0;
        }
        
        if(dp[pos][start] != INT_MIN) return dp[pos][start];
        
        int left = getMaxSum(nums, multipliers, start+1, end, pos+1, n) + nums[start] * multipliers[pos];
        
        int right = getMaxSum(nums, multipliers, start, end-1, pos+1, n) + nums[end] * multipliers[pos];
        //cout<<left<<" -- "<<right<<endl;
        return dp[pos][start] = max(left, right);
        
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        reset();
        return getMaxSum(nums, multipliers, 0, nums.size()-1, 0, multipliers.size());
    }
};