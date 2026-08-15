class Solution {
public:
    int maxRepOpt1(string text) {
        int n=text.size();
        unordered_map<char,int> total;
    for(char c : text)
        total[c]++;
        unordered_map<char,int>mpp;
        int maxi=0,maxlen=0;
        int l=0,r=0;
        while(r<n){
        mpp[text[r]]++;
        maxi=max(maxi,mpp[text[r]]);
        while(r-l+1-maxi>1){
            mpp[text[l]]--;
            l++;
        }
        for(auto it : mpp) {
            if(it.second == maxi) {
                maxlen = max(maxlen,
                             min(r-l+1, total[it.first]));
                break;
            }
        }

            r++;
        }
        return maxlen;
    }

};