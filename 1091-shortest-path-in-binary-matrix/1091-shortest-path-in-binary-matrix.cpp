class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<vector<int>> directions = {{1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1,-1},{1,-1},{-1,1}};
        queue<pair<int,int> >qq;
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;
        
        qq.push(make_pair(0,0));
        
        grid[0][0] = 1;
        
        while(!qq.empty()) {
            int cX = qq.front().first;
            int cY = qq.front().second;
            qq.pop();
            for(auto direction : directions) {
                int nX = cX + direction[0];
                int nY = cY + direction[1];

                if(nX >= 0 && nX < n && nY >= 0 && nY < m && grid[nX][nY] == 0) {
                    qq.push({nX, nY});
                    grid[nX][nY] = grid[cX][cY] + 1;
                }
            }
        }
        return grid[n-1][m-1] == 0 ? -1 : grid[n-1][m-1];
    }
};