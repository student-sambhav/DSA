class Solution {
public:
int n,m;
vector<vector<int>>dir{{1,0},{-1,0},{0,-1},{0,1}};
 bool bfs(int row,int col,vector<vector<int>>&vis,vector<vector<int>>& grid1, vector<vector<int>>& grid2){
    vis[row][col]=1;
    queue<pair<int,int>>q;
    q.push({row,col});
    bool issub=true;
    while(!q.empty()){
        int r=q.front().first;
        int c=q.front().second;
        q.pop();
        if(grid1[r][c]==0) issub=false;
        for(auto it:dir){
            int nrow=r+it[0];
            int ncol=c+it[1];
            if(nrow>=0 && ncol>=0 && ncol<m && nrow<n && !vis[nrow][ncol]
             && grid2[nrow][ncol]==1){
                vis[nrow][ncol]=1;
                q.push({nrow,ncol});
            }
        }
       
    }
     return issub;
}
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n=grid1.size();
        m=grid1[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid2[i][j]==1){
                    if(bfs(i,j,vis,grid1,grid2)){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};