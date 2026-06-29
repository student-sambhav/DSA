class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
     unordered_map<int ,int>mpp;
     int n=hours.size();
     long long ans=0;
     for(int i=0;i<n;i++){
        int rem=hours[i]%24;
        int need=(24-rem)%24;
        ans+=mpp[need];
        mpp[rem]++;
     }
     return ans;

    }
};