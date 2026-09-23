class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
      int n=nums.size();
      int total=accumulate(nums.begin(),nums.end(),0);
      int rem=total-x;
      if(rem==0) return nums.size();
      int len=maxlen(rem,nums);
      if(len==0) return -1;
      return n-len;

    }
    int maxlen(int rem,vector<int>& nums){
        unordered_map<int,int>mpp;
        mpp[0]=-1;
        int sum=0;
        int res=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(mpp.count(sum-rem)){
                res=max(res,i-mpp[sum-rem]);
            }
            if(!mpp.count(sum)){
                mpp[sum]=i;
            }
        }
        return res;
    }
};