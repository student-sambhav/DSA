class Solution {
public:
int n;
int dp[1001];
int solve(vector<int>& nums,int i, int target){
    if(i==n-1){
    return 0; 
    }   
    if(dp[i]!=-1) return dp[i];
int take=-1000000000;
    for(int j=i+1;j<n;j++){
        if(abs(nums[j]-nums[i])<=target){
            take=max(take,1+solve(nums,j,target));
        }
        
    }
    return dp[i]=take;
 
}
    int maximumJumps(vector<int>& nums, int target) {
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        int ans=solve(nums,0,target);
        return ans < 0 ? -1 : ans;
    }
};