class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
       vector<pair<int,int>>res;
       int n=ages.size();
       for(int i=0;i<n;i++){
        res.push_back({ages[i],scores[i]});
       }
       int ans=0;
       vector<int>dp(n,0);
       sort(res.begin(),res.end());
       for(int i=0;i<n;i++){
        dp[i]=res[i].second;
        for(int j=0;j<i;j++){
            if(res[i].second>=res[j].second)
            dp[i]=max(dp[i],res[i].second+dp[j]);
        }
        ans=max(ans,dp[i]);
       }
       return ans;
    }
};