class Solution {
public:
int n;
int dp[2001][4001];
int solve(vector<int>& rewardValues,int i,int sum){
    if(i>=n) return 0;
    if(dp[i][sum]!=-1) return dp[i][sum];
    int skip=solve(rewardValues,i+1,sum);
    int take=0;
    if(sum<rewardValues[i]){
        take=rewardValues[i]+solve(rewardValues,i+1,sum+rewardValues[i]);
    }
    return dp[i][sum]=max(take,skip);
}
    int maxTotalReward(vector<int>& rewardValues) {
        n=rewardValues.size();
        sort(rewardValues.begin(),rewardValues.end());
        memset(dp,-1,sizeof(dp));
        return solve(rewardValues,0,0);
    }
};