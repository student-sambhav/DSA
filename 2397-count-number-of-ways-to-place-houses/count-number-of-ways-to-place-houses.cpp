class Solution {
public:
long long dp[10001];
int mod=1e9+7;
long long solve(int i,int n){
    if(i>=n) return 1;
    if(dp[i]!=-1) return dp[i];
    long long empty=solve(i+1,n);
    long long house=solve(i+2,n);
    return dp[i]=(empty+house)%mod;
}
    int countHousePlacements(int n) {
        memset(dp,-1,sizeof(dp));
        long long oneside= solve(0,n);
        return (oneside*oneside)%mod;
    }
};