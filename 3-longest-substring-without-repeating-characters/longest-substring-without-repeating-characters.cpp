class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      unordered_map<int,int>mpp;
      int l=0,r=0;
      int maxi=0;
      while(r<s.size()){
        mpp[s[r]]++;
        while(mpp.size()<r-l+1){
            mpp[s[l]]--;
            if(mpp[s[l]]==0) mpp.erase(s[l]);
            l++;
        }
        if(mpp.size()==r-l+1){
            maxi=max(maxi,r-l+1);
        }
        r++;
      }
      return maxi;
    }
};