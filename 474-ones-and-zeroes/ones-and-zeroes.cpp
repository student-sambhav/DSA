class Solution {
public:
int N;
int dp[601][101][101];
int solve(vector<string>& strs,int i ,int m, int n){
    if(i==N) return 0;
    int zeros=0,ones=0;
    if(dp[i][m][n]!=-1) return dp[i][m][n];
    for(char ch:strs[i]){
        if(ch=='0'){
            zeros++;
        }
        else{
            ones++;
        }
    }
        int skip=solve(strs,i+1,m,n);
        int take=0;
        if(zeros<=m && ones<=n){
            take=1+solve(strs,i+1,m-zeros,n-ones);
        }
    
    return dp[i][m][n]=max(take,skip);
}
    int findMaxForm(vector<string>& strs, int m, int n) {
        N=strs.size();
        memset(dp,-1,sizeof(dp));
        return solve(strs,0,m,n);
    }
};