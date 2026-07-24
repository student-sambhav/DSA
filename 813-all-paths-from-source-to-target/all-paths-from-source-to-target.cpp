class Solution {
public:
void dfs(vector<vector<int>>& graph,vector<vector<int>>&res,vector<int>temp,int source,int target){
    temp.push_back(source);
    if(source==target){
        res.push_back(temp);
    }
    for(auto it:graph[source]){
        dfs(graph,res,temp,it,target);
    }
}
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        int source=0;
        int target=n-1;
        vector<vector<int>>result;
        vector<int>temp;
        dfs(graph,result,temp,source,target);
        return result;
    }
};