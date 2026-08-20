class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        int n=nums.size();
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        long long req=abs(goal-sum);
        if(req%limit==0){
            return req/limit;
        }
        return req/limit + 1;
    }
};