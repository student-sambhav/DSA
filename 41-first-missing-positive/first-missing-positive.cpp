class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int n=nums.size();
        for(int i=0;i<n;i++){
               if(nums[i]>0){
                mpp[nums[i]]++;
               }
            
        }
        for(int i=1;i<=n+1;i++){
            if(mpp.find(i)==mpp.end()){
                return i;
                
            }
        }
        return -1;
    }
};