class Solution {
public:
int n,t;
int dp[1001][1001];
int solve(vector<int>& nums,int i,int cursum){
    if(cursum==t) return 0;
    if(i==n) return -1000000;
    if(dp[i][cursum]!=-1) return dp[i][cursum];
    int skip=solve(nums,i+1,cursum);
    int take=-1000000;
    if(nums[i]<=t-cursum){
      take=1+solve(nums,i+1,cursum+nums[i]);
    }
    return dp[i][cursum]=max(take,skip);
}
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        n=nums.size();
        t=target;
        memset(dp,-1,sizeof(dp));
        int ans=solve(nums,0,0);
        return ans<=0?-1:ans;
    }
};