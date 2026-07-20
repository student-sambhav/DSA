class Solution {
public:
int n;
int dp[1001];
int solve(vector<vector<int>>& books, int shelfWidth,int i){
    if(i==n) return 0;
    int width=0;
    int height=0;
    int ans=1e9+7;
    if(dp[i]!=-1) return dp[i];
    for(int j=i;j<n;j++){
        width+=books[j][0];
        if(width>shelfWidth){
            break;
        }
        height=max(height,books[j][1]);
        ans=min(ans,height+solve(books,shelfWidth,j+1));
    }
    return dp[i]=ans;


}
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        n=books.size();
        memset(dp,-1,sizeof(dp));
        return solve(books,shelfWidth,0);
    }
};