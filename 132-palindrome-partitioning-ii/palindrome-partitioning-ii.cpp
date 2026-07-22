class Solution {
public:
vector<vector<bool>>ispal;
vector<int>dp;
int solve(string &s,int start){
    if(s.size()==start){
        return 0;
    }
    int ans=INT_MAX;
    if(dp[start]!=-1) return dp[start];
    for(int i=start;i<s.size();i++){
        if(ispal[start][i]){
            ans=min(ans,1+solve(s,i+1));
        }
    }
    return dp[start]=ans;
}
    int minCut(string s) {
        int n=s.size();
        ispal.assign(n,vector<bool>(n,false));
        for(int gap=0;gap<n;gap++){
            for(int l=0;l+gap<n;l++){
                int r=l+gap;
                if(s[l]==s[r]){
                    if(r-l<=2){
                        ispal[l][r]=true;
                    }
                    else{
                        ispal[l][r]=ispal[l+1][r-1];
                    }
                }
            }
        }
        dp.assign(n,-1);
        return solve(s,0)-1;
    }
};