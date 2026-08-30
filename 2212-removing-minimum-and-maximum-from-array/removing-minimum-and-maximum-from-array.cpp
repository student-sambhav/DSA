class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN,l=0;
        int mini=INT_MAX,r=0;
        for(int i=0;i<n;i++){
            if(nums[i]>maxi){
                maxi=nums[i];
                l=i;
            }
            if(nums[i]<mini){
                mini=nums[i];
                r=i;
            }
        }
         int cnt = INT_MAX;

    // Both from left
    cnt = min(cnt, max(l, r) + 1);

    // Both from right
    cnt = min(cnt, n - min(l, r));

    // max from left, min from right
    cnt = min(cnt, l + 1 + n - r);

    // min from left, max from right
    cnt = min(cnt, r + 1 + n - l);

    return cnt;

    }
};