class Solution {
public:
int n,t,totalsum;
int dp[1001][20001];
int solve(vector<int>&nums,int i,int currsum){
    if(i==n){
        return currsum==t;
    }
    if(dp[i][currsum+totalsum]!=-1) return dp[i][currsum+totalsum];
    int plus=solve(nums,i+1,currsum+nums[i]);
    int minus=solve(nums,i+1,currsum-nums[i]);
    return dp[i][currsum+totalsum]= plus+minus;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        n=nums.size();
        t=target;
        totalsum=0;
        memset(dp,-1,sizeof(dp));
        for(int x:nums){
            totalsum+=x;
        }
        return solve(nums,0,0);
    }
};