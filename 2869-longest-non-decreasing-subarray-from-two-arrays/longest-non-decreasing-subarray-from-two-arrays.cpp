class Solution {
public:
int n;
int dp[100001][2];
int solve(vector<int>&nums1,vector<int>&nums2){
    n=nums1.size();
    dp[0][0]=1;
    dp[0][1]=1;
    int ans=1;
    for(int i=1;i<n;i++){
        dp[i][0]=1;
        dp[i][1]=1;
    if(nums1[i]>=nums1[i-1]){
        dp[i][0]=max(dp[i][0],dp[i-1][0]+1);
    }
    if(nums1[i]>=nums2[i-1]){
        dp[i][0]=max(dp[i][0],dp[i-1][1]+1);
    }
    if(nums2[i]>=nums1[i-1]){
        dp[i][1]=max(dp[i][1],dp[i-1][0]+1);
    }
    if(nums2[i]>=nums2[i-1]){
        dp[i][1]=max(dp[i][1],dp[i-1][1]+1);
    }
    ans=max(ans,max(dp[i][0],dp[i][1]));
    }
    return ans;
}
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        return solve(nums1,nums2);
    }
};