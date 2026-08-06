class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
     unordered_map<int,vector<pair<int,double>>>adj;
     for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        double p=succProb[i];
        adj[u].push_back({v,p});
        adj[v].push_back({u,p});
     }
     vector<double>res(n,0.0);
     priority_queue<pair<double,int>>pq;
     pq.push({1,start});
     res[start]=1;
     while(!pq.empty()){
        int node=pq.top().second;
        double d=pq.top().first;
        pq.pop();
        for(auto it:adj[node]){
            int adjnode=it.first;
            double prob=it.second;
            if(res[adjnode]<prob*d){
                res[adjnode]=prob*d;
                pq.push({res[adjnode],adjnode});
            }
        }
     }
     return res[end];
    }
};