class Solution {
public:
int reverseof(int b){
    int res=0;
    while(b){
        int rem=b%10;
        res=res*10+rem;
        b/=10;
    }
    return res;
}
    int minMirrorPairDistance(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            int a=reverseof(nums[i]);
            if(mpp.find(nums[i])!=mpp.end()){
                ans=min(ans,i-mpp[nums[i]]);
            }
            mpp[a]=i;
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};