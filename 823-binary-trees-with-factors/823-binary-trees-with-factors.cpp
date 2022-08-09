class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        map<int,int>dp;
        long res = 0, mod = pow(10, 9) + 7;
       
        sort(arr.begin(), arr.end());
            
        for(int i=0; i<arr.size(); i++) {
            int val = arr[i];
            dp[val] = 1;
            for(int j=0; j<i; j++) {
                int tmp = arr[j];
                if (val % tmp == 0) {
                    int div = val/tmp;
                    dp[val] += ((dp[tmp]%mod) * (dp[div]%mod)) % mod;
                    dp[val]%=mod;
                }
            }
            res+=dp[val];
            res%=mod;
        }
        
        return res;
    }
};