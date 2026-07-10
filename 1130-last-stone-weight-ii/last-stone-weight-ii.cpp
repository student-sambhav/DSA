class Solution {
public:
int dp[101][3001];
int n;
int solve(vector<int>& stones,int i,int cursum){
    if(i==n){
        return 0;
    }
    if(dp[i][cursum]!=-1) return dp[i][cursum];
    int skip=solve(stones,i+1,cursum);
    int take=0;
    if(stones[i]<=cursum){
        take=stones[i]+solve(stones,i+1,cursum-stones[i]);
    }
    return dp[i][cursum]=max(take,skip);
    

}
    int lastStoneWeightII(vector<int>& stones) {
        n=stones.size();
        int total=0;
        for(int x:stones){
            total+=x;
        }
        memset(dp,-1,sizeof(dp));
        int cap=total/2;
        int best=solve(stones,0,cap);
        return total-2*best;
    }
};