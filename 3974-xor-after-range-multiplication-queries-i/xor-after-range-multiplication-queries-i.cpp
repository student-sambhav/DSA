class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        long long mod=1e9+7;
        for(auto querie:queries){
        int l1=querie[0];
        int r1=querie[1];
        int k1=querie[2];
        int v1=querie[3];

        while(l1<=r1){
            nums[l1] = ((long long)nums[l1] * v1) % mod;
            l1+=k1;
        }
        }
        long long ans = 0;

        for(long long x : nums) {
          ans ^= x;
        } 
        return ans;

    }
};