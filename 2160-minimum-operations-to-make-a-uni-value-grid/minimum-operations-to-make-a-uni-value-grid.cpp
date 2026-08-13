class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans.push_back(grid[i][j]);
            }
        }
        sort(ans.begin(),ans.end());
        int l=ans.size();
        int div=ans[0]%x;
        for(int i=1;i<l;i++){
            if(ans[i]%x!=div){
                return -1;
            }
        }
        int cnt=0;
        int mid=l/2;
        for(int i=0;i<l;i++){
            cnt+=(abs(ans[i]-ans[mid])/x);
        }
        return cnt;
    }
};