class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int l=0,r=0;
        int maxf=0,maxlen=0;
        unordered_map<char,int>mpp;
        while(r<n){
            mpp[s[r]-'A']++;
            maxf=max(maxf,mpp[s[r]-'A']);
            if(r-l+1-maxf>k){
                mpp[s[l]-'A']--;
                l++;
            }
            maxlen=max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};