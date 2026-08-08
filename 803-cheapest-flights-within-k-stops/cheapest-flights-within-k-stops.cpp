class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>>q;
        vector<int>dist(n,INT_MAX);
        q.push({0,{src,0}});
        dist[src]=0;
        while(!q.empty()){
            int stops=q.front().first;
            int u=q.front().second.first;
            int cost=q.front().second.second;
            q.pop();
            if(stops>k) continue;

            for(auto it:adj[u]){
                int v=it.first;
                int dcost=it.second;

                if(dcost+cost<dist[v] && stops<=k){
                    dist[v]=dcost+cost;
                    q.push({stops+1,{v,dist[v]}});
                }
            }
        }
        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];
    }
};