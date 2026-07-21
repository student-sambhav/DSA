class Solution {
public:
int n,m;
int dp[71][71][71];
int solve(vector<vector<int>>& grid,int currow,int cola,int colb){
    if(cola < 0 || cola >= m || colb < 0 || colb>= m) return -1e9+7;
    if(currow==n) return 0;
    int ans=0;
    if(dp[currow][cola][colb]!=-1) return dp[currow][cola][colb];
    if(cola==colb){
        ans+=grid[currow][cola];
    }
    else{
        ans+=grid[currow][cola];
        ans+=grid[currow][colb];
    }
    int maxi=-1e9;
    for(int i=cola-1;i<=cola+1;i++){
        for(int j=colb-1;j<=colb+1;j++){
            maxi=max(maxi,solve(grid,currow+1,i,j));
        }
    }
    ans+=maxi;
    return dp[currow][cola][colb]= ans;

}
    int cherryPickup(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(grid,0,0,m-1);
    }
};