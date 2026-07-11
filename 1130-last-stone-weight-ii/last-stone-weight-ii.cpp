class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
        int total=0;
        for(int x:stones){
            total+=x;
        }
        int cap=total/2;
        vector<vector<int>>dp(n+1,vector<int>(cap+1,0));
        for(int i = 0; i <= n; i++)
            dp[i][0] = 0;

        for(int i=n-1;i>=0;i--){
            for(int s=1;s<=cap;s++){
                int skip=dp[i+1][s];
                int take=0;
                if(stones[i]<=s){
                    take=stones[i]+dp[i+1][s-stones[i]];
                }
                dp[i][s]=max(take,skip);
            }
        }
        int best=dp[0][cap];
        return total - 2 * best;
    }
};