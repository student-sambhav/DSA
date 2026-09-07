class Solution {
public:
    int partitionString(string s) {
        int n=s.size();
        int cnt=1;
        unordered_map<int,int>mpp;
        for(char c:s){
            mpp[c]++;
            if(mpp[c]>1){
                cnt++;
                mpp.clear();
                mpp[c]++;
            }
        }
        return cnt;
    }
};