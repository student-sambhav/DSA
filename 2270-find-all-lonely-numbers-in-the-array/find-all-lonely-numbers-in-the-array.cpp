class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(auto it:nums){
            mpp[it]++;
        }
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(mpp[nums[i]]==1){
                if(mpp[nums[i]+1]==0 && mpp[nums[i]-1]==0){
                    ans.push_back(nums[i]);
                }
            }
        }
        return ans;
    }
};