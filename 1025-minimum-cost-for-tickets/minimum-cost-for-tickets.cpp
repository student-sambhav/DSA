class Solution {
public:
int n;
int dp[366];
int solve(vector<int>& days, vector<int>& costs,int i){
    if(i>=n) return 0;
    if(dp[i]!=-1) return dp[i];
    int cost1=costs[0]+solve(days,costs,i+1);
    int j=i;
    while(j<n && days[i]+7>days[j]){
        j++;
    }
    int cost7=costs[1]+solve(days,costs,j);
    int k=i;
    while(k<n && days[i]+30>days[k]){
        k++;
    }
    int cost30=costs[2]+solve(days,costs,k);
    return dp[i]=min(cost1,min(cost7,cost30));

}
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        n=days.size();
        memset(dp,-1,sizeof(dp));
        return solve(days,costs,0);
    }
};