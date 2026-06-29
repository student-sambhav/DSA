class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=n-1;
        int h=n/2,k=0;
        while(l<n/2 && h<=r){
            if(nums[l]<nums[h]){
                k++;
                l++;
                h++;
            }
            else if(nums[l]>=nums[h]){
                h++;
            }
        }
        return n-2*k;
    }
};