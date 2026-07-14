class Solution {
public:
int n;
int dp[1001][1001];
int solve(vector<vector<int>>& pairs,int i,int prev){
    if(i==n) return 0;
    if(dp[i][prev+1]!=-1) return dp[i][prev+1];
    int skip=solve(pairs,i+1,prev);
    int take=0;
    if(prev==-1 || pairs[i][0]>pairs[prev][1]){
        take=1+solve(pairs,i+1,i);
    }
    return dp[i][prev+1]= max(take,skip);
}
    int findLongestChain(vector<vector<int>>& pairs) {
       n=pairs.size();
       memset(dp,-1,sizeof(dp));
       sort(pairs.begin(),pairs.end());
       return solve(pairs,0,-1);
    }
};