class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        vector<int>ans(arr.begin(),arr.end());
        sort(ans.begin(),ans.end());
        unordered_map<int,int>mpp;
        int rank=1;
        for(int i=0;i<n;i++){
            if(i>0 && ans[i-1]!=ans[i]){
                rank++;
            }
            mpp[ans[i]]=rank;
        }
        vector<int>res;
        for(auto x:arr){
            res.push_back(mpp[x]);
        }
        return res;

    }
};