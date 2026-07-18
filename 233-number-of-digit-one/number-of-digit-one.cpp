class Solution {
public:
string num;
long long dp[20][2][20];
long long solve(int i,int tight,int cntone){
    if(i==num.size()){
        return cntone;
    }
    if(dp[i][tight][cntone]!=-1) return dp[i][tight][cntone];
    int limit=tight?num[i]-'0':9;
    long long ans=0;
    for(int digit=0;digit<=limit;digit++){
        ans+=solve(i+1,tight && (limit==digit),cntone+(digit==1));
    }
    return dp[i][tight][cntone]=ans;
}
    int countDigitOne(int n) {
        num=to_string(n);
        memset(dp,-1,sizeof(dp));
        return solve(0,1,0);
    }
};