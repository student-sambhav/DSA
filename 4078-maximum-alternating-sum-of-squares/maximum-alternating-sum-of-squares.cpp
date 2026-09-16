class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                nums[i]=-nums[i];
            }
        }
        sort(nums.begin(),nums.end(),greater<int>());
        long long sum=0;
        for(int i=0;i<=n/2;i++){
            if(n%2==0){
                if(i==n/2) continue;
            }
            sum=sum+nums[i]*nums[i];
        }
        for(int i=n/2;i<n;i++){
            if(n%2!=0){
                if(i==n/2) continue;
            }
            sum=sum-nums[i]*nums[i];
        }
        return sum;
    }
};