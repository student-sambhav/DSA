class Solution {
public:
vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        if(n==1 && m==1) return 0;
        vector<vector<vector<bool>>>vis(n,vector<vector<bool>>(m,vector<bool>(k+1,false)));
        queue<tuple<int,int,int>>q;
        q.push({0,0,k});
        vis[0][0][k]=true;
        int steps=0;
        while(!q.empty()){
            int s=q.size();
            while(s--){
                auto [x,y,rem]=q.front();
                q.pop();
                if(x==n-1 && y==m-1) return steps;
                for(auto it:dir){
                    int nx=it.first+x;
                    int ny=it.second+y;
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                    int nr=rem-grid[nx][ny];

                    if(nr<0) continue;

                    if(nx>=0 && ny>=0 && nx<n && ny<m && !vis[nx][ny][nr]){
                        vis[nx][ny][nr]=true;
                        q.push({nx,ny,nr});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};