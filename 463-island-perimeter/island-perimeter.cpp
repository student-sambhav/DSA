class Solution {
public:
int n,m;
vector<vector<int>>dir{{-1,0},{1,0},{0,-1},{0,1}};
int bfs(int row,int col,vector<vector<int>>&vis,vector<vector<int>>& grid){
    vis[row][col]=1;
    queue<pair<int,int>>q;
    q.push({row,col});
    int perimeter=0;
    while(!q.empty()){
        int r=q.front().first;
        int c=q.front().second;
        q.pop();
        for(auto it:dir){
          int nrow=r+it[0];
          int ncol=c+it[1];

          if(nrow<0 || ncol<0 || nrow>=n || ncol>=m || grid[nrow][ncol]==0){
            perimeter++;
          }
           else if(grid[nrow][ncol]==1 && !vis[nrow][ncol]){
    vis[nrow][ncol] = 1;
    q.push({nrow,ncol});
}
          }
        }
        
    return perimeter;  
} 
    int islandPerimeter(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int ans=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    ans=bfs(i,j,vis,grid);
                }
            }
        }
        return ans;
    }
};