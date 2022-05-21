class Solution {
public:
    int dp[15][10005];
    int coinChange(vector<int>& coins, int amount) {
        for(int i=0; i<15; i++) {
            for(int j=0; j<10001; j++) {
                dp[i][j] = -1;
            }
        }
        long ans = getMinCoin(coins, amount, 0);
        if(ans >= INT_MAX) {
            return -1;
        }
        return int(ans);
    }
    
    long getMinCoin(vector<int>& coins, int amount,int pos) {
        if(pos >= coins.size() || amount < 0) {
            return INT_MAX;
        }
        //cout<<amount<<" "<<pos<<endl;
        if(amount == 0) {
            //cout<<"found"<<endl;
            return 0;
        }
        if(dp[pos][amount] != -1) {
            return dp[pos][amount];
        }
        long  ret1 = 0;
        long ret2 = 0;
        long ret3 = 0;
        
        ret1 = getMinCoin(coins, amount - coins[pos], pos + 1) + 1;
        ret2 = getMinCoin(coins, amount - coins[pos], pos) + 1;
        ret3 = getMinCoin(coins, amount, pos + 1) ;
        //cout<<ret1<<" "<<ret2<<endl;
        return dp[pos][amount] = min(min(ret1,ret2),ret3);
    }
};