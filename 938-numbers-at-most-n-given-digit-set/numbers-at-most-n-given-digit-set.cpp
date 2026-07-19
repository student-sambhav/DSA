class Solution {
public:
vector<string> dig;
string num;
int dp[12][2][2];
int solve(int i,int tight,int leadingzero){
    if(i==num.size()){
        return leadingzero?0:1;
    }
    if(dp[i][tight][leadingzero]!=-1) return dp[i][tight][leadingzero];
    int limit=tight?num[i]-'0':9;
    int ans=0;
    if(leadingzero){
        ans+=solve(i+1,0,1);
    }
    for(auto &x:dig){
        int d=x[0]-'0';
        if(d>limit) continue;
        ans+=solve(i+1,tight && (limit==d),0);
    }
    return dp[i][tight][leadingzero]=ans;
}
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        dig=digits;
        num=to_string(n);
        memset(dp,-1,sizeof(dp));
        return solve(0,1,1);
    }
};