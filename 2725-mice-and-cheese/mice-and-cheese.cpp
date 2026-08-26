class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n=reward1.size();
        vector<int>ans;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=reward2[i];
            ans.push_back(reward1[i]-reward2[i]);
        }
        sort(ans.begin(),ans.end(),greater<int>());
        for(int i=0;i<k;i++){
            sum+=ans[i];
        }
        return sum;
    }
};