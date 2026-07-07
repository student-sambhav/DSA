class Solution {
public:
int dp[1001];
int solve(vector<int>nums,int ind,int n){
    if(ind>n) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int take=nums[ind]+solve(nums,ind+2,n);
    int nt=solve(nums,ind+1,n);
    return dp[ind]=max(take,nt);
}
    int rob(vector<int>& nums) {  
        int n=nums.size();
        if(n == 1)
            return nums[0];

        memset(dp, -1, sizeof(dp));
        int case1 = solve(nums, 0, n - 2);

        memset(dp, -1, sizeof(dp));
        int case2 = solve(nums, 1, n - 1);

        return max(case1, case2);
    }
};