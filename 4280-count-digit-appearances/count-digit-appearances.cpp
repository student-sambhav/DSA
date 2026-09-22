class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int n=nums.size();
        int cnt=0;
        for(auto it:nums){
            while(it){
                int rem=it%10;
                if(rem==digit){
                    cnt++;
                }
                it=it/10;
            }
        }
        return cnt;
    }
};