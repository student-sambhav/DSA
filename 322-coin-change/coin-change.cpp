class Solution {
public:
int n,t;
int dp[13][10001];
int solve(vector<int>& coins,int i,int sum){
    if(sum==t){
        return 0;
    }
    if(i==n)
        return 100000;
        if(dp[i][sum]!=-1) return dp[i][sum];
    int skip=solve(coins,i+1,sum);
    int take=100000;
    if(coins[i]<=t-sum){
        take=1+solve(coins,i,sum+coins[i]);
    }
    return dp[i][sum]=min(take,skip);
}
    int coinChange(vector<int>& coins, int amount) {
    n=coins.size();
    t=amount;
    memset(dp,-1,sizeof(dp));
    int ans= solve(coins,0,0);
    return ans>=100000?-1:ans;
    }
};