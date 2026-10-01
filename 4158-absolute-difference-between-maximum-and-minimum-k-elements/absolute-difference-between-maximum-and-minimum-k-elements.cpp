class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=1;
        int j=0;
        int sum=0;
        int l=k;
        while(l){
            sum+=nums[n-i];
            i++;
            l--;
        }
        while(k){
            sum-=nums[j];
            j++;
            k--;
        }
        return sum;
    }
};