class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        for(auto it:nums){
            mpp[it]++;
        }
        if(k==1){
            int ans=-1;
            for(auto x:nums){
                if(mpp[x]==1){
                    ans=max(ans,x);
                }
            }
            return ans;
        }
        if(k==n){
            return *max_element(nums.begin(),nums.end());
        }
        int ans=-1;
        if(mpp[nums[0]]==1){
            ans=max(ans,nums[0]);
        }
        if(mpp[nums[n-1]]==1){
            ans=max(ans,nums[n-1]);
        }
        return ans;
    }
};