class Solution {
public:
vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n=maze.size();
        int m=maze[0].size();
        queue<pair<int,int>>q;
        q.push({entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]]='+';
        int steps=0;
        while(!q.empty()){
            int s=q.size();
            while(s--){
                auto curr=q.front();
                q.pop();
                int x=curr.first;
                int y=curr.second;

                if((x==0 || x==n-1 || y==0 || y==m-1) && !(x==entrance[0] && y==entrance[1]) ) return steps;

                for(auto it:dir){
                    int nx=it[0]+x;
                    int ny=it[1]+y;

                    if(nx>=0 && nx<n && ny>=0 && ny<m && maze[nx][ny]!='+'){
                        q.push({nx,ny});
                        maze[nx][ny]='+';
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};