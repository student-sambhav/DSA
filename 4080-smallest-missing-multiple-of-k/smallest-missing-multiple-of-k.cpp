class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=0;
        int mini=INT_MIN;
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            mini=min(mini,nums[i]);
            mpp[nums[i]]++;
        }
        int ans=0;
        for(int i=1;i<=maxi+k;i++){
            if(i%k==0 && mpp.find(i)==mpp.end()){
                ans=i;
                break;
            }
        }
        return ans;

    }
};