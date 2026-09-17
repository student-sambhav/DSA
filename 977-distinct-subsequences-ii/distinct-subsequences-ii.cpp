class Solution {
public:
    int distinctSubseqII(string s) {
        int mod=1e9+7;
        vector<long long>last(26,0);
        long long dp=1;
        for(char ch:s){
            int c=ch-'a';
            long long newdp=(2*dp%mod-last[c]+mod)%mod;
            last[c]=dp;
            dp=newdp;
        }
        return (int)(dp-1+mod)%mod;
    }
};