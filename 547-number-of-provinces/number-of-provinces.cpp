class Solution {
public:
void dfs(int node,vector<int>adjlist[],vector<int>&vis){
    vis[node]=1;
    for(auto it:adjlist[node]){
        if(!vis[it]){
            dfs(it,adjlist,vis);
        }
    }
}
    int findCircleNum(vector<vector<int>>& adj) {
       int n=adj.size();
       vector<int>adjlist[n];
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(adj[i][j]==1 && i!=j){
                adjlist[i].push_back(j);
            }
        }
       }
       vector<int>vis(n,0);
       int cnt=0;
       for(int i=0;i<n;i++){
        if(!vis[i]){
            cnt++;
            dfs(i,adjlist,vis);
        }
       }
       return cnt;
    }
};