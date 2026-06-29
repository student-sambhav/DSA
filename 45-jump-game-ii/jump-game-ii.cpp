class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps=0,r=0,l=0;
        int n=nums.size();
        if(n==1) return 0;
        while(r<n-1){
            int far=0;
            for(int i=l;i<=r;i++){
                far=max(far,nums[i]+i);
            }
            l=r+1;
            r=far;
            jumps=jumps+1;
            if(r>n) break; 
        }
        return jumps;
    }
};