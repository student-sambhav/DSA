class Solution {
public:
    void nextPermutation(vector<int>& nums) {
       int n=nums.size();
       int pivot=-1;
       for(int i=n-2;i>=0;i--){
        if(nums[i]<nums[i+1]){
            pivot=i;
            break;
        }
       }
       if(pivot == -1){
        reverse(nums.begin(), nums.end());
        return;
    }
       int mini=INT_MAX;
       int ind=0;
       for(int i=pivot;i<n;i++){
        if(nums[i]>nums[pivot]){
            mini=min(mini,nums[i]);
            ind=i;
        }
       }
       swap(nums[pivot],nums[ind]);
       reverse(nums.begin()+pivot+1,nums.end());
    }
};