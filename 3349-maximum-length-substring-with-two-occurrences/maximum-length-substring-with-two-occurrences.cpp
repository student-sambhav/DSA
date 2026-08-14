class Solution {
public:
    int maximumLengthSubstring(string s) {
     int l=0,maxlen=0;
     unordered_map<char,int>mpp;
     for(int i=0;i<s.size();i++){
        mpp[s[i]]++;
        while(mpp[s[i]]>2){
            mpp[s[l]]--;
            if(mpp[s[l]]==0) mpp.erase(s[l]);
            l++;
        }
        maxlen=max(maxlen,i-l+1);
     }
     return maxlen;   
    }
};