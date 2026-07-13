class Solution {
public:
int n;
int dp[2501][2501];
int solve(vector<int>& nums, int prev, int i) {

    if (i == n)
        return 0;

    if (dp[prev + 1][i] != -1)
        return dp[prev + 1][i];

    int skip = solve(nums, prev, i + 1);

    int take = 0;

    if (prev == -1 || nums[i] > nums[prev]) {
        take = 1 + solve(nums, i, i + 1);
    }

    return dp[prev + 1][i] = max(skip, take);
}
    int lengthOfLIS(vector<int>& nums) {
      n=nums.size();
      memset(dp,-1,sizeof(dp));
      return solve(nums,-1,0);
    }
};