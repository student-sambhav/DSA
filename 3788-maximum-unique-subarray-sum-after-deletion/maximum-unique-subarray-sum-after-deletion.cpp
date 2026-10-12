class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int sum=0;
        bool haspos=false;
        int maxi=INT_MIN;
        for(auto it:st){
            maxi=max(maxi,it);
            if(it>0){
                sum+=it;
                haspos=true;
            }
        }
        if(nums.size()==1){
            return nums[0];
        }
        return haspos?sum:maxi;
    }
};