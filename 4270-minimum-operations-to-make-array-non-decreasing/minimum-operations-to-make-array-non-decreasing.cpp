class Solution {
public:
    long long minOperations(vector<int>& nums) {
        int n=nums.size();
        long long cnt=0;
        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i]){
                cnt+=nums[i-1]-nums[i];
            }
        }
        return cnt;
    }
};