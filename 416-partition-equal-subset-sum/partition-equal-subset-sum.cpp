class Solution {
public:
int n;
int dp[201][10001];
bool solve(vector<int>&nums,int i ,int sum){
    if(sum==0) return true;
    if(i==n) return false;
    if(dp[i][sum]!=-1) return dp[i][sum];
    bool skip=solve(nums,i+1,sum);
    bool take=false;
    if(nums[i]<=sum){
        take=solve(nums,i+1,sum-nums[i]);
    }
    return dp[i][sum]=take||skip;
}
    bool canPartition(vector<int>& nums) {
      n=nums.size();
      int sum=0;
      memset(dp,-1,sizeof(dp));
      for(int i=0;i<n;i++){
        sum+=nums[i];
      }
      if(sum%2!=0){
        return false;
      }
      return solve(nums,0,sum/2);
    }
};