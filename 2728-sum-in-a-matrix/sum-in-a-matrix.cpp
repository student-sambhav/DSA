class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int n=nums.size();
        int m=nums[0].size();
        int j=0;
        int score=0;
        for(int i = 0; i < n; i++) {
        sort(nums[i].begin(), nums[i].end(), greater<int>());
    }
        vector<int>ans;
        while(j<m){
        for(int i=0;i<n;i++){
            ans.push_back(nums[i][j]);
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,ans[i]);
        }
        score+=maxi;
        ans.clear();
        j++;
        }
        return score;
    }
};