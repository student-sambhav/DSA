class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n=costs.size();
        int maxi=*max_element(costs.begin(),costs.end());
        vector<int>cnt(maxi+1,0);
        for(int it:costs){
            cnt[it]++;
        }
        int j=0;
        int res=0;
        for(long long i=1;i<=maxi;i++){
            if(cnt[i]){
             if(coins-cnt[i]*i>=0){
                coins-=cnt[i]*i;
                res+=cnt[i];
             }
             else{
                res+=coins/i;
                break;
             }
            }
        }
        return res;

    }
};