class Solution {
public:
int n, m;
vector<vector<vector<int>>> dp;

int solve(vector<vector<int>>& grid, int k, int i, int j) {

    if(i < 0 || j < 0 || k < 0)
        return -1e9;

    if(i == 0 && j == 0)
        return 0;

    if(dp[i][j][k] != -1)
        return dp[i][j][k];

    int nk = k;

    if(grid[i][j] != 0)
        nk--;

    if(nk < 0)
        return dp[i][j][k] = -1e9;

    int up = solve(grid, nk, i-1, j);
    int left = solve(grid, nk, i, j-1);

    return dp[i][j][k] =
        grid[i][j] + max(up, left);
}

int maxPathScore(vector<vector<int>>& grid, int k) {

    m = grid.size();
    n = grid[0].size();

    k = min(k, m + n - 2);

    dp.assign(m,
        vector<vector<int>>(n,
            vector<int>(k + 1, -1)));

    int ans = solve(grid, k, m-1, n-1);

    return ans < 0 ? -1 : ans;
}
};