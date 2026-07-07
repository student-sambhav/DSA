class Solution {
public:
int dp[501];
int solve(vector<int>& nums,int ind){
    if(ind>=nums.size()) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int take=nums[ind]+solve(nums,ind+2);
    int nt=solve(nums,ind+1);
    return dp[ind]=max(take,nt);
}
    int rob(vector<int>& nums) {
    int ind=0; 
    memset(dp,-1,sizeof(dp));
    return solve(nums,ind);

    }
};