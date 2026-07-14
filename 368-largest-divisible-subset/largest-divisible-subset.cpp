class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        vector<int>t(n,1);
        vector<int>prev(n,-1);
        int lastindex=0;
        int maxi=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                if(t[i]<t[j]+1){
                    t[i]=t[j]+1;
                    prev[i]=j;
                }
                if(t[i]>maxi){
                    maxi=t[i];
                    lastindex=i;
                }
                }
            }
        }
        vector<int>res;
        while(lastindex!=-1){
            res.push_back(nums[lastindex]);
            lastindex=prev[lastindex];
        }
        return res;
    }
};