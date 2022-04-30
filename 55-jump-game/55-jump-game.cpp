class Solution {
public:
    int dp[10005] = {-1};
    vector<int>input;
    bool canJump(vector<int>& nums) {
        input = nums;
        for(int i=0; i<nums.size(); i++) {
            dp[i] = -1;
        }
        jumpGame(0);
        int lastIndex = nums.size() - 1;
        if(dp[lastIndex] == 1) {
            return true;
        } 
        return false;
    }
    
    void jumpGame(int pos) {
        if (input.size() == pos) {
            return;
        }
        
        if(dp[pos] != -1) {
            return;
        }
        dp[pos] = 1;
        int val = input[pos];
        int sz = input.size();
        int range = pos + val;
        
        for(int j = pos+1; j<sz && j<=range; j++) {
            if(dp[j] == -1) {
                jumpGame(j);
                }
            }
        }
        
};