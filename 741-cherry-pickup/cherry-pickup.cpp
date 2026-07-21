class Solution {
public:
    int n;
    vector<vector<int>> grid;
    vector<vector<vector<int>>> dp;

    int solve(int r1, int c1, int r2) {

        // Calculate c2 using the fact that
        // r1 + c1 = r2 + c2
        int c2 = r1 + c1 - r2;

        // Out of bounds
        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n)
            return -1e9;

        // Thorn cell
        if (grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return -1e9;

        // Destination reached
        if (r1 == n - 1 && c1 == n - 1)
            return grid[n - 1][n - 1];

        // Memoization
        if (dp[r1][c1][r2] != -1)
            return dp[r1][c1][r2];

        int cherries = 0;

        // Same cell -> count once
        if (r1 == r2 && c1 == c2)
            cherries = grid[r1][c1];
        else
            cherries = grid[r1][c1] + grid[r2][c2];

        // Four possible move combinations
        int ans = max({
            solve(r1 + 1, c1, r2 + 1), // Down Down
            solve(r1 + 1, c1, r2),     // Down Right
            solve(r1, c1 + 1, r2 + 1), // Right Down
            solve(r1, c1 + 1, r2)      // Right Right
        });

        cherries += ans;

        return dp[r1][c1][r2] = cherries;
    }

    int cherryPickup(vector<vector<int>>& g) {

        grid = g;
        n = grid.size();

        dp.assign(
            n,
            vector<vector<int>>(n,
                vector<int>(n, -1))
        );

        return max(0, solve(0, 0, 0));
    }
};