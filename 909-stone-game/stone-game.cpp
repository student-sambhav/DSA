class Solution {
public:
int dp[501][501];
int solve(vector<int>&piles,int i,int j){
    if(i>=j) return -1;
    if(dp[i][j]!=-1) return dp[i][j];
    int a=piles[i]+solve(piles,i+1,j);
    int b=piles[j]+solve(piles,i,j-1);
    return dp[i][j]=max(a,b);
}
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        memset(dp,-1,sizeof(dp));
        int ans=solve(piles,0,n-1);
        int sum=accumulate(piles.begin(),piles.end(),0);
        if(ans>sum/2) return true;
        return false;
    }
};