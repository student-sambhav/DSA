class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
     int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        for(int i=n-1;i>=0;i--){
            for(int cap=1;cap<=k;cap++){
            dp[i][1][cap]=max(-prices[i]+dp[i+1][0][cap],
            dp[i+1][1][cap]);

            dp[i][0][cap]=max(prices[i]+dp[i+1][1][cap-1],
            dp[i+1][0][cap]);
            }

        }
        return dp[0][1][k];
    }
};