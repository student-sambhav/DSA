class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        for(auto it:nums){
            mpp[it]++;
        }
        int ans=-1;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                if(mpp[nums[i]]==1){
                    ans=nums[i];
                    break;
                }
            }
        }
        return ans;
    }
};