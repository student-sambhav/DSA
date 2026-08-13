class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long>prefix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        vector<long long> minPrefix(k, LLONG_MAX);

    long long ans = LLONG_MIN;
    minPrefix[0] = 0;
    for(int i = 0; i < n; i++) {
        int rem = (i + 1) % k;
        if(minPrefix[rem] != LLONG_MAX) {
            ans = max(ans, prefix[i] - minPrefix[rem]);
        }
        minPrefix[rem] = min(minPrefix[rem], prefix[i]);
    }
    return ans;

    }
};