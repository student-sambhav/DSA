class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        int n=transactions.size();
        long long sum=0;
        int maxi=0;
        for(auto it:transactions){
            if(it[0]>it[1]){
                sum+=it[0]-it[1];
                maxi=max(maxi,it[1]);
            }
            else{
                maxi=max(maxi,it[0]);
            }
        }
        return sum+maxi;
    }
};