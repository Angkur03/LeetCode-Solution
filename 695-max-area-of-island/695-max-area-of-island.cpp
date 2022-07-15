class Solution {
public:
    int m,n;
    int visited[50][50];
    int dr[4] = {1,-1,0,0};
    int dc[4] = {0,0,-1,1};
    vector<vector<int>> input;
    map<int,int>mp;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        input = grid;
        m = grid.size();
        n = grid[0].size();
        reset();
        int color = 1;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[i].size(); j++) {
                if(grid[i][j] == 1 && visited[i][j] == 0) {
                    //cout<<i<<" "<<j<<" "<<color<<endl;
                    dfs(i,j,color++);
                }
            }
        }
        
        int mx = 0;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(visited[i][j] != 0) {
                    //cout<<visited[i][j]<<endl;
                    mp[visited[i][j]]++;
                    mx = max(mx, mp[visited[i][j]]);
                }
            }
        }
        
        return mx;
    }
    
    void reset() {
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                visited[i][j] = 0;
            }
        }
    }
    
    void dfs(int x, int y,int color) {
        visited[x][y] = color;
        for(int i=0; i<4; i++) {
            int xx = x + dr[i];
            int yy = y + dc[i];
            if(xx>=0 && xx<m && yy>=0 && yy<n && input[xx][yy] == 1 && visited[xx][yy] == 0) {
                dfs(xx,yy,color);
            }
        }
    }
    
};