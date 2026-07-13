class Solution {
public:
    int n;
int t[301][5001];
int solve(int i,int amount, vector<int>& coins){
    if(amount==0) return 1;
    if(i==n) return 0;
    if(coins[i]>amount){
        return solve(i+1,amount,coins);
    }
    if(t[i][amount]!=-1) return t[i][amount];
    int take=solve(i,amount-coins[i],coins);
    int nt=solve(i+1,amount,coins);
    return t[i][amount]=take+nt;
}
    int change(int amount, vector<int>& coins) {
        n=coins.size();
        memset(t,-1,sizeof(t));
        return solve(0,amount,coins);
    }
};