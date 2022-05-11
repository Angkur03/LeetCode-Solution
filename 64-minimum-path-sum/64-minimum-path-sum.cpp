class Solution {
public:
    int dp[205][205];
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size() - 1;
        int m = grid[0].size() - 1;
        for(int i=0; i<=n; i++) {
            for(int j=0; j<=m; j++) {
                dp[i][j] = -1;
            }
        }
        int res =  minSum(grid,0,0);
        // cout<<"res --"<<endl;
        // for(int i=0; i<=n; i++) {
        //     for(int j=0; j<=m; j++) {
        //         cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
        //     }
        // }
        return res;
    }
    
    int minSum(vector<vector<int>>&grid, int row, int col) {
        int n = grid.size();
        int m = grid[0].size();
        //cout<<row<<" "<<col<<endl;
        //cout<<row<<" "<<col<<" "<<dp[row][col]<<endl;
        if(dp[row][col] != -1) {
            return dp[row][col];
        }
        if(row == n-1 && col == m-1) {
            //cout<<"found"<<endl;
            return grid[row][col];
        }
        
        int ret1 = INT_MAX;
        int ret2 = INT_MAX;
        if(row + 1 < n) {
            ret1 = minSum(grid, row+1,col) + grid[row][col];
        } 
        if(col + 1 < m) {
            ret2 = minSum(grid, row,col+1) + grid[row][col];  
        }
        
        return dp[row][col] = min(ret1, ret2);
    }
};