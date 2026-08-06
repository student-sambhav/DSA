class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int V, int src) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto it:times){
            int u=it[0];
            int v=it[1];
            int r=it[2];
            adj[u].push_back({v,r});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(V+1,INT_MAX);
        pq.push({0,src});
        dist[src]=0;
        while(!pq.empty()){
            int node=pq.top().second;
            int d=pq.top().first;
            pq.pop();
            for(auto it:adj[node]){
                int adjnode=it.first;
                int adjd=it.second;

                if(d+adjd<dist[adjnode]){
                    dist[adjnode]=d+adjd;
                    pq.push({dist[adjnode],adjnode});
                }
            }
        }
        int ans=INT_MIN;
        for(int i=1;i<=V;i++){
            ans=max(ans,dist[i]);
        }
        return ans==INT_MAX?-1:ans;
    }
};