class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int n = nums.size();

        int sum = 0;
        for(int x : nums)
            sum += x;

        if(sum % 2)
            return false;

        sum /= 2;

        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

        // Base case
        for(int i = 0; i <= n; i++)
            dp[i][0] = true;

        // Fill table
        for(int i = n - 1; i >= 0; i--) {

            for(int s = 1; s <= sum; s++) {

                bool skip = dp[i + 1][s];

                bool take = false;

                if(nums[i] <= s)
                    take = dp[i + 1][s - nums[i]];

                dp[i][s] = take || skip;
            }
        }

        return dp[0][sum];
    }
};