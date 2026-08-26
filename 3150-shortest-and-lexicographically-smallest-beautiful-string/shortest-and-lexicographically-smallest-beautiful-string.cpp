class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size();
        int mini=INT_MAX;
        int l=0,r=0,m=0,a=0;
        int cntone=0;
        while(r<n){
            if(s[r]=='1'){
                cntone++;
            }
            while(cntone==k){
                if(mini>r-l+1){
                mini=min(mini,r-l+1);
                a=r;
                m=l;
            }
            else if(mini==r-l+1){
             string curr=s.substr(l,r-l+1);
             string best=s.substr(m,mini);
             if(curr<best){
                a=r;
                m=l;
             }
             }
             if(s[l]=='1'){
                    cntone--;
                }
                l++;
            }
            r++;
        }
        if(mini==INT_MAX){
            return "";
        }
        return s.substr(m,mini);
    }
};