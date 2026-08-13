class Solution {
public:
int n,m;
int dp[1001][1001][3];
int solve(vector<vector<int>>& coins,int i,int j,int k){
    if(i>=n || j>=m) return -1e9;
    if(i == n-1 && j == m-1) {
        if(coins[i][j] < 0 && k > 0)
            return 0;
        return coins[i][j];
    }
    int r=0,d=0;
    if(dp[i][j][k]!=-1e9) return dp[i][j][k];
    if(coins[i][j]<0 && k>0){
     int take = coins[i][j] +
               max(solve(coins,i+1,j,k),
                   solve(coins,i,j+1,k));
    int skip = max(solve(coins,i+1,j,k-1),
                   solve(coins,i,j+1,k-1));

    return dp[i][j][k] = max(take, skip);
    }
    else{
    r=coins[i][j]+solve(coins,i+1,j,k);
    d=coins[i][j]+solve(coins,i,j+1,k);
    }
    return dp[i][j][k]=max(r,d); 
}
    int maximumAmount(vector<vector<int>>& coins) {
        n=coins.size();
        m=coins[0].size();
        fill(&dp[0][0][0], &dp[0][0][0] + 1001 * 1001 * 3, -1e9);
        return solve(coins,0,0,2);
    }
};