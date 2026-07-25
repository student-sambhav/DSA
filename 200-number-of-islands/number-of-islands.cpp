class Solution {
public:
int n,m;
vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
void bfs(int i,int j,vector<vector<int>>&vis,vector<vector<char>>& grid){
    vis[i][j]=1;
    queue<pair<int,int>>q;
    q.push({i,j});
    while(!q.empty()){
        int row=q.front().first;
        int col=q.front().second;
        q.pop();
        for(auto it:dir){
            int nrow=it[0]+row;
            int ncol=it[1]+col;
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol] &&
            grid[nrow][ncol]=='1'){
                vis[nrow][ncol]=1;
                q.push({nrow,ncol});
            }
        }
    }
}
    int numIslands(vector<vector<char>>& grid) {
      n=grid.size();
      m=grid[0].size();
      vector<vector<int>>vis(n,vector<int>(m,0));
      int cnt=0;
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && grid[i][j]=='1'){
                cnt++;
                bfs(i,j,vis,grid);
            }
        }
      }
      return cnt;
    }
};