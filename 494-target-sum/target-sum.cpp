class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int totalsum=0;
        for(int x:nums){
            totalsum+=x;
        }
        if(abs(target) > totalsum)
            return 0;

        if((totalsum + target) % 2 != 0)
            return 0;

        int req = (totalsum + target) / 2;
        vector<vector<int>>dp(n+1,vector<int>(req+1));
        dp[n][0]=1;
        for(int i=n-1;i>=0;i--){
            for(int s=0;s<=req;s++){
                int skip=dp[i+1][s];
                int take=0;
                if(nums[i]<=s){
                    take=dp[i+1][s-nums[i]];
                }
                dp[i][s]=take+skip;
            }
        }
        return dp[0][req];
    }
};