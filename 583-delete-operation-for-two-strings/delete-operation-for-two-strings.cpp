class Solution {
public:
int lcs(string &word1, string &word2,int n,int m){
    if(n==0 || m==0) return 0;
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(word1[i-1]==word2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}
    
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        //return (n-lcs(word1,word2,n,m)+m-lcs(word1,word2,n,m));
        return n+m-2*lcs(word1,word2,n,m);
    }
};