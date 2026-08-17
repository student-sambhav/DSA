class Solution {
public:
int n;
long long ans=INT_MIN;
void solve(vector<int>&nums,int i,long long pro,int size){
    if(i==n){
        if(size!=0) ans=max(ans,pro);
        return ;
    }
    solve(nums,i+1,pro*nums[i],size+1);
    solve(nums,i+1,pro,size);

}
    long long maxStrength(vector<int>& nums) {
        n=nums.size();
        solve(nums,0,1,0);
        return ans;
    }
};