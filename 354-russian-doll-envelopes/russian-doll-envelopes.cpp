class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
       sort(envelopes.begin(), envelopes.end(),
[](vector<int>& a, vector<int>& b){

    if(a[0] == b[0])
        return a[1] > b[1];

    return a[0] < b[0];
});
vector<int> tails;
        int n=envelopes.size();
        for(auto e:envelopes){
            int h=e[1];
            auto it=lower_bound(tails.begin(),tails.end(),h);
            if(it==tails.end()){
                tails.push_back(h);
            }
            else{
                *it=h;
            }

        }
        return tails.size();
    }
        
};