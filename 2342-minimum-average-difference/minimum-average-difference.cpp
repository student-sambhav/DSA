class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size();
        vector<long long>prefix(n);
        prefix[0]=nums[0];
        long long total=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
            total+=nums[i];
        }
        long long ans=0;
        long long mindiff=INT_MAX;
        for(int i=0;i<n;i++){
            long long suffix=total-prefix[i];
            long long a=prefix[i]/(i+1);
            long long b;
            if(i==n-1){
                b=0;
            }
            else b=suffix/(n-1-i);
            if(mindiff>abs(a-b)){
                mindiff=abs(a-b);
                ans=i;
            }
        }
        return ans;
    }
};