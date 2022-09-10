class Solution {
public:
    int dp[2][105][1005];
    
    void reset() {
        memset(dp,-1,sizeof(dp));
    }
    
    int getMax(int buy,int k,int idx,vector<int>& prices) {
        if(k == 0 || idx >= prices.size()) {
            return 0;
        }
        
        if(dp[buy][k][idx] != -1) return dp[buy][k][idx];
        
        int profit = 0;
        if(buy == 1) {
            int ifBuy = -prices[idx] + getMax(0, k, idx+1, prices);
            int ifNotBuy = getMax(1, k, idx+1, prices);
            profit = max(ifBuy, ifNotBuy);
        } else {
            int sell = prices[idx] + getMax(1, k-1, idx+1, prices);
            int ifNotSell = getMax(0, k, idx+1, prices);
            profit = max(sell, ifNotSell);
        }
        
        return dp[buy][k][idx] = profit;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        reset();
        return getMax(1, k, 0, prices);
    }
};