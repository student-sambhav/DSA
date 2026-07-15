class Solution {
public:
vector<vector<int>>dp;
int solve(int i,int j,vector<int>& cuts){
    if(j-i<=1) return 0;
    int ans=INT_MAX;
    if(dp[i][j]!=-1) return dp[i][j];
    for(int k=i+1;k<j;k++){
        ans=min(ans,solve(i,k,cuts)+solve(k,j,cuts)+cuts[j]-cuts[i]);
    }
    return dp[i][j]=ans;
}
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int m=cuts.size();
        dp.assign(m+1,vector<int>(m+1,-1));
        return solve(0,m-1,cuts);
    }
};