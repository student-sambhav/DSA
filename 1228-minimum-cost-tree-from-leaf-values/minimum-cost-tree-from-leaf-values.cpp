class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>>maxval(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            maxval[i][i]=arr[i];
            for(int j=i+1;j<n;j++){
                maxval[i][j]=max(maxval[i][j-1],arr[j]);
            }
        }
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int len=1;len<n;len++){
            for(int i=0;i+len<n;i++){
                int j=i+len;
                dp[i][j]=INT_MAX;
                for(int k=i;k<j;k++){
                    dp[i][j]=min(dp[i][j],maxval[i][k]*maxval[k+1][j]+dp[i][k]+dp[k+1][j]);
                }
            }
        }
        return dp[0][n-1];
    }
};