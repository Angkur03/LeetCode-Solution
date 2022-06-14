class Solution {
public:
    int dp[505][505];
    int minDistance(string word1, string word2) {
        reset();
        int match = getMaxMatch(word1, word2, 0, 0);
        int ans = word1.size() - match + word2.size() - match;
        return ans;
    }
    
    void reset() {
        for(int i=0; i<=500; i++) {
            for(int j=0; j<=500; j++) {
                dp[i][j] = -1;
            }
        }
    }
    
    int getMaxMatch(string &word1, string &word2, int pos1, int pos2) {
        if(pos1 >= word1.size() || pos2 >= word2.size()) {
            return 0;
        }
        if(dp[pos1][pos2] != -1) {
            return dp[pos1][pos2];
        }
        
        int ret1 = 0;
        int ret2 = 0;
        int ret3 = 0;
        if(word1[pos1] == word2[pos2]) {
            ret1 = 1 + getMaxMatch(word1, word2, pos1+1, pos2+1);
        }
        ret2 = getMaxMatch(word1, word2, pos1+1, pos2);
        ret3 = getMaxMatch(word1, word2, pos1, pos2+1);
        
        return dp[pos1][pos2] = max(max(ret2,ret3),ret1);
    }
};