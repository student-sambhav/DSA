class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<int,char>mpp;
        int key=2;
        int cnt=0;
        for(char ch:word){
            if(key>9){
                key=2;
            }
            mpp[key]++;
            cnt+=mpp[key];
            key++;
        }
        return cnt;
    }
};