class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        for(auto it:nums){
            mpp[it]++;
        }
        int ans=0;
        for(auto it:mpp){
            if(it.second==1) return -1;
            ans+=(it.second+2)/3;
        }
        return ans;
    }
};