class Solution {
public:
int n, m;
vector<vector<int>> dir = {
    {-1,0},
    {1,0},
    {0,-1},
    {0,1}
};
queue<pair<int,int>> q;
void dfs(vector<vector<int>>& grid,
         vector<vector<int>>& vis,
         int i, int j) {
    vis[i][j] = 1;
    q.push({i,j});
    for(auto it : dir) {
        int ni = i + it[0];
        int nj = j + it[1];
        if(ni < 0 || ni >= n ||
           nj < 0 || nj >= m)
            continue;
        if(grid[ni][nj] == 1 &&
           !vis[ni][nj]) {
        dfs(grid, vis, ni, nj);
        }
    }
}
int bfs(vector<vector<int>>& grid,
        vector<vector<int>>& vis) {

    int dist = 0;

    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            auto [i,j] = q.front();
            q.pop();
            for(auto it : dir) {
                int ni = i + it[0];
                int nj = j + it[1];
                if(ni < 0 || ni >= n ||
                   nj < 0 || nj >= m)
                    continue;
                if(grid[ni][nj] == 1 &&
                   !vis[ni][nj]) {

                    return dist;
                }

                if(grid[ni][nj] == 0 &&
                   !vis[ni][nj]) {

                    vis[ni][nj] = 1;
                    q.push({ni,nj});
                }
            }
        }

        dist++;
    }

    return -1;
}
    int shortestBridge(vector<vector<int>>& grid) {
       n = grid.size();
    m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    bool found = false;

    for(int i = 0; i < n && !found; i++) {
        for(int j = 0; j < m; j++) {

            if(grid[i][j] == 1) {
                dfs(grid, vis, i, j);
                found = true;
                break;
            }
        }
    }
    return bfs(grid, vis);
    }
};