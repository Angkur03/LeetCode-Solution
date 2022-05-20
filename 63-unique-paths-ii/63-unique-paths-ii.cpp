class Solution {
public:
    int dp[105][105];
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n,m;
        n = obstacleGrid.size();
        m = obstacleGrid[0].size();
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                dp[i][j] = -1;
            }
        }
        
        if(obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1) {
            return 0;
        }
        
        return getNumberOfPaths(obstacleGrid, n, m, 0, 0);
    }
    
    int getNumberOfPaths(vector<vector<int>>& obstacleGrid,int n,int m, int x,int y) {
        //cout<<x<<" "<<y<<" "<<n<<" "<<m<<end;
        if(dp[x][y] != -1) {
            return dp[x][y];
        }
        if(x == n-1 && y == m-1) {
            return 1;
        }
        
        int xx = x + 1;
        int yy = y;
        int ret1 = 0;
        int ret2 = 0;
        if(xx >= 0 && xx < n && yy >= 0 && yy < m) {
            if(obstacleGrid[xx][yy] == 0) {
               ret1 = getNumberOfPaths(obstacleGrid, n, m, xx, yy);
            }
        }
        
         xx = x;
         yy = y + 1;
        if(xx >= 0 && xx < n && yy >= 0 && yy < m) {
            if(obstacleGrid[xx][yy] == 0) {
               ret2 = getNumberOfPaths(obstacleGrid, n, m, xx, yy);
            }
        }
        
        return dp[x][y] = ret1 + ret2;
    }
};