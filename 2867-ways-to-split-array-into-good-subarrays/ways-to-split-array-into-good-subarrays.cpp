class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int n=nums.size();
        int mod=1e9+7;
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                ans.push_back(i);
            }
        }
        if (ans.empty()) return 0;
        long long res=1;
        for(int i=1;i<ans.size();i++){
            res = (1LL * res * (ans[i] - ans[i-1])) % mod;
        }
        return res;
    }
};