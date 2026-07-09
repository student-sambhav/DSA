class Solution {
public:
int solve(vector<int>nums,int ind,int n){
   vector<int>dp(n+3,0);
   for(int i=n;i>=ind;i--){
    int take=nums[i]+dp[i+2];
    int nt=dp[i+1];
    dp[i]=max(take,nt);
   }
   return dp[ind];
}
    int rob(vector<int>& nums) {  
        int n=nums.size();
        if(n == 1)
            return nums[0];

        
        int case1 = solve(nums, 0, n - 2);

       
        int case2 = solve(nums, 1, n - 1);

        return max(case1, case2);
    }
};