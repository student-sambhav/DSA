class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        if(n==0) return 0;
        int start=0;
        int maxlen=1;
        vector<vector<int>>dp(n,vector<int>(n,false));
        for(int gap=0;gap<n;gap++){
            for(int l=0;l+gap<n;l++){
                int r=l+gap;
                if(s[l]==s[r]){
                    if(r-l+1<=2){
                        dp[l][r]=true;
                    }
                    else{
                        dp[l][r]=dp[l+1][r-1];
                    }
                    
                }
                if(dp[l][r] && r-l+1>maxlen){
                    start=l;
                    maxlen=r-l+1;
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j]==true){
                    cnt++;
                }
            }
        }
            return cnt;
    }
};