class Solution {
public:
int dp[10001];
int solve(vector<int>&points,int i){
  if(i>=points.size()) return 0;
  if(dp[i]!=-1) return dp[i];
  int take=points[i]+solve(points,i+2);
  int nt=solve(points,i+1);
  return dp[i]= max(take,nt);
}
    int deleteAndEarn(vector<int>& nums) {
        int mx=*max_element(nums.begin(),nums.end());
        vector<int>points(mx+1,0);
        for(int num:nums){
            points[num]+=num;
        }
        memset(dp,-1,sizeof(dp));
        return solve(points,0);
    }
};