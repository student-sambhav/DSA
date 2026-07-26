class Solution {
public:
int n,m;
unordered_map<int,int>area;
vector<vector<int>>dir={{-1,0},{1,0},{0,-1},{0,1}};
int bfs(int i,int j,int id,vector<vector<int>>&vis,vector<vector<int>>& grid){
    vis[i][j]=1;
    queue<pair<int,int>>q;
    q.push({i,j});
    int cnt=1;
    grid[i][j]=id;
    while(!q.empty()){
        int row=q.front().first;
        int col=q.front().second;
        q.pop();
        for(auto it:dir){
            int nrow=row+it[0];
            int ncol=col+it[1];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] &&
            grid[nrow][ncol]==1){
                cnt++;
                vis[nrow][ncol]=1;
                q.push({nrow,ncol});
                grid[nrow][ncol]=id;
            }
        }
    }
    return cnt;
}
    int largestIsland(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    cnt++;
                }
            }
        }
        int id=2;
        if(cnt==0) return m*n;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    int landarea=bfs(i,j,id,vis,grid);
                    area[id]=landarea;
                    id++;
                }
            }
        }

        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                   unordered_set<int>st;
                   for(auto it:dir){
                    int nrow=i+it[0];
                    int ncol=j+it[1];

                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
                    grid[nrow][ncol]>1){
                        st.insert(grid[nrow][ncol]);
                    }

                   }
                   int total=1;
                   for(int id:st){
                    total+=area[id];
                   }
                   ans=max(ans,total);
                }
            }
        }
        return ans;
    }
};