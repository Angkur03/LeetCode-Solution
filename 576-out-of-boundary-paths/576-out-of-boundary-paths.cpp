class Solution {
public:
    int dp[55][55][55];
    int mod = pow(10,9) + 7;
    
    void reset() {
        memset(dp, -1, sizeof(dp));
    }
    
    int dfs(int m, int n, int maxMoves, int x, int y) {
        if(x < 0 || y < 0 || x >= m || y >= n){
            return 1;
        }
        
        if(maxMoves == 0){
            return 0;
        }
        
        if(dp[maxMoves][x][y] != -1){
            return dp[maxMoves][x][y] % mod;
        }
        
        int res = 0;
        res = (res + dfs(m, n, maxMoves - 1, x, y - 1)) % mod;
        res = (res + dfs(m, n, maxMoves - 1, x - 1, y)) % mod;
        res = (res + dfs(m, n, maxMoves - 1, x + 1, y)) % mod;
        res = (res + dfs(m, n, maxMoves - 1, x, y + 1)) % mod;
        
        dp[maxMoves][x][y] = res;
        return dp[maxMoves][x][y] % mod;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        reset();
        return dfs(m, n, maxMove, startRow, startColumn);
    }
};