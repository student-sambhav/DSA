class Solution {
public:
vector<vector<int>>dir={{1,1},{0,1},{1,0},{-1,0},{0,-1},{-1,-1},{1,-1},{-1,1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(n==0 || grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        queue<pair<int,int>>q;
        q.push({0,0});
        grid[0][0]=1;
        int level=0;
        while(!q.empty()){
            int s=q.size();
            while(s--){
                auto curr=q.front();
                q.pop();
                int x=curr.first;
                int y=curr.second;
                
                if(x==n-1 && y==n-1) return level+1;

                for(auto it:dir){
                    int nx=x+it[0];
                    int ny=y+it[1];

                    if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]==0){
                        q.push({nx,ny});
                        grid[nx][ny]=1;
                    }
                }
            }
            level++;
        }
        return -1;
    }
};