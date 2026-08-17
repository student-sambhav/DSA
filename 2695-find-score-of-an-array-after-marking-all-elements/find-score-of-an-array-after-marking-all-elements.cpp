class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n=nums.size();
        vector<int>vis(n,0);
        vector<pair<int,int>>ans;
        for(int i=0;i<n;i++){
            ans.push_back({nums[i],i});
        }
        sort(ans.begin(),ans.end());
        long long score=0;
        for(auto it:ans){
            int nums=it.first;
            int i=it.second;
            if(vis[i]) continue;
            score+=nums;
            vis[i]=1;
            if(i>0){
                vis[i-1]=1;
            }
            if(i<n-1){
                vis[i+1]=1;
            }
        }
        
        return score;
    }
};