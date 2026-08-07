class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
       int n=time.size();
       unordered_map<int,int>mpp;
       int cnt=0;
       for(auto it:time){
        int rem=it%60;
        int need=(60-rem)%60;
        cnt+=mpp[need];
        mpp[rem]++;
       }
       return cnt;
    }
};