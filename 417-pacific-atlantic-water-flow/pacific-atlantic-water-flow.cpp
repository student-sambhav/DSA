class Solution {
public:
int n,m;
void bfs(int i,int j,vector<vector<int>>& heights,vector<vector<int>>&vis){
    if(vis[i][j]) return;
    vis[i][j]=1;
    queue<pair<int,int>>q;
    q.push({i,j});
    while(!q.empty()){
        int row=q.front().first;
        int col=q.front().second;
        q.pop();
        for(auto it:dir){
            int nrow=row+it[0];
            int ncol=col+it[1];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
              !vis[nrow][ncol] && heights[nrow][ncol]>=heights[row][col]){
                vis[nrow][ncol]=1;
                q.push({nrow,ncol});
              }
        }
    }
}
vector<vector<int>>dir={{0,-1},{0,1},{-1,0},{1,0}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n=heights.size();
        m=heights[0].size();
        vector<vector<int>>pacific(n,vector<int>(m,0));
        vector<vector<int>>atlantic(n,vector<int>(m,0));

        for(int j=0;j<m;j++){
            bfs(0,j,heights,pacific);
        }
        
        for(int j=0;j<m;j++){
            bfs(n-1,j,heights,atlantic);
        }
        
        for(int i=0;i<n;i++){
            bfs(i,0,heights,pacific);
        }
        
        for(int i=0;i<n;i++){
            bfs(i,m-1,heights,atlantic);
        }
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};