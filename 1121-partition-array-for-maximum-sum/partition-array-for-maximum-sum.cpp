class Solution {
public:
int dp[501];
int n;
int solve(vector<int>& arr,int i, int k){
    if(i>=n) return 0;
    int maxi=-1;
    int sum=0;
    if(dp[i]!=-1) return dp[i];
    for(int j=i;j<n && j-i+1<=k;j++){
        maxi=max(maxi,arr[j]);
        sum=max(sum,(j-i+1)*maxi+solve(arr,j+1,k));
    }
    return dp[i]=sum;

}
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n=arr.size();
        memset(dp,-1,sizeof(dp));
        return solve(arr,0,k);
    }
};