class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        vector<long long>prefix(n);
        prefix[0]=nums[0];
        long long total=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
            total+=nums[i];
        }
        long long cnt=0;
        for(int i=0;i<n-1;i++){
            long long suffix=total-prefix[i];
            if(prefix[i]>=suffix){
                cnt++;
            }
        }
        return cnt;
    }
};