class Solution {
public:
    long long coinChange(vector<int>& coins, int amount) {
        long long dp[10005];    
         
        for(long long i=0; i<amount+1; i++) {
            dp[i] = INT_MAX;
        }
        
        dp[0] = 0;
        
        for(long long i=0; i<=amount; i++){
            if(dp[i] == INT_MAX) {
                continue;
            }
            for(long long j=0; j<coins.size(); j++) {
                long long val = i + coins[j];
                if(val<=amount) {
                    dp[val] = min(dp[i] + 1, dp[val]);
                }
            }
        }
        
        if(dp[amount] == INT_MAX) {
            return -1;
        }
        
        return dp[amount];
    }
    
};