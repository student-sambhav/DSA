class Solution {
public:
int n,m;
vector<vector<int>>dir{{-1,0},{1,0},{0,1},{0,-1}};
void bfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        queue<pair<int,int>> q;
        vis[row][col] = 1;
        q.push({row,col});
        while(!q.empty()) {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            
            for(auto &d : dir) {
                int nx = r + d[0];
                int ny = c + d[1];
                
                if(nx>= 0 && nx<n && ny>=0 && ny<m &&
                   !vis[nx][ny] && grid[nx][ny] == 0) {
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(grid[i][0]==0 && !vis[i][0]) bfs(i,0,grid,vis);
            if(grid[i][m-1]==0 && !vis[i][m-1]) bfs(i,m-1,grid,vis);
        }
        for(int j=0;j<n;j++){
            if(grid[0][j]==0 && !vis[0][j]) bfs(0,j,grid,vis);
            if(grid[n-1][j]==0 && !vis[n-1][j]) bfs(n-1,j,grid,vis);
        }
        int cnt=0;
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(!vis[i][j] && grid[i][j]==0){
                    bfs(i,j,vis,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};