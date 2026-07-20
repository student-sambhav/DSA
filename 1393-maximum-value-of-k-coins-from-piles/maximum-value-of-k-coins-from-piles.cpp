class Solution {
public:
int n;
int dp[2001][2001];
int solve(vector<vector<int>>& piles,int i, int k){
    if(i==n || k==0) return 0;
    if(dp[i][k]!=-1) return dp[i][k]; 
    int ans=solve(piles,i+1,k);
    int sum=0;
    int m=piles[i].size();
    for(int t=0;t<min(m,k);t++){
       sum+=piles[i][t];
       ans=max(ans,sum+solve(piles,i+1,k-t-1));
    }
    return dp[i][k]=ans;
}
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        n=piles.size();
        memset(dp,-1,sizeof(dp));
        return solve(piles,0,k);
    }
};