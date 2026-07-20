class Solution {
public:
int n;
int cost(vector<int>& houses,int i,int j){
    int mid=(i+j)/2;
    int res=0;
    for(int k=i;k<=j;k++){
        res+=abs(houses[k]-houses[mid]);
    }
    return res;
}
int dp[101][10001];
int solve(vector<int>& houses, int k,int i){
    if(i==n ) return 0;
    if(i!=n && k==0) return 1e9+7;
    int ans=1e9+7;
    if(dp[k][i]!=-1) return dp[k][i];
    for(int j=i;j<n;j++){
        ans=min(ans,cost(houses,i,j)+solve(houses,k-1,j+1));
    }
    return dp[k][i]=ans;
}
    int minDistance(vector<int>& houses, int k) {
        n=houses.size();
        sort(houses.begin(),houses.end());
        memset(dp,-1,sizeof(dp));
        int ca= solve(houses,k,0);
        return ca==1e9+7?-1:ca;
    }
};