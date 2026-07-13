class Solution {
public:
int n;
int t[1001];
int tar;
int solve(vector<int>& nums,int target){
    if(target==0){
        return 1;
    }
    if(t[target]!=-1) return t[target];
    int ans=0;
    for(int x:nums){
        if(x<=target){
            ans+=solve(nums,target-x);
        }
    }
    return t[target]=ans;
}
    int combinationSum4(vector<int>& nums, int target) {
       n=nums.size();
       tar=target;
       memset(t,-1,sizeof(t));
       return solve(nums,target);
    }
};