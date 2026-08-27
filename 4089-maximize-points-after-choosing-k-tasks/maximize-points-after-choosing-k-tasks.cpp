class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        int n=technique1.size();
        vector<int>ans;
        long long sum=accumulate(technique1.begin(),technique1.end(),0LL);
        for(int i=0;i<n;i++){
            ans.push_back(technique2[i]-technique1[i]);
        }
        sort(ans.begin(),ans.end(),greater<int>());
        int j=0;
        int a=n-k;
        while(a>0 && j<ans.size()){
            if(ans[j]>0){
                sum+=ans[j];
                a--;
            }
            j++;
        }
        return sum;
    }
};