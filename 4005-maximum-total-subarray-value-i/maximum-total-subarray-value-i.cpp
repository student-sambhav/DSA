class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n=nums.size();
        long long maxi=nums[0],mini=nums[0];
        for(int i=0;i<n;i++){
            maxi=max(maxi,(long long)nums[i]);
            mini=min(mini,(long long)nums[i]);
        }
        return (maxi-mini)*k;
    }
};