class Solution {
public:
int solve(int i,int buy,int cap,vector<int>&prices,int n,
vector<vector<vector<int>>> &dp){
   if(i==n || cap==0) return 0;
   int profit=0;
   if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];
   if(buy){
    profit=max(-prices[i]+solve(i+1,0,cap,prices,n,dp), // buy
    solve(i+1,1,cap,prices,n,dp)); //skip
   }
   else{
    profit=max(prices[i]+solve(i+1,1,cap-1,prices,n,dp),//sell
    solve(i+1,0,cap,prices,n,dp));//skip
   }
   return dp[i][buy][cap]=profit;
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(0,1,2,prices,n,dp);
    }
};