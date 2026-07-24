/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
void dfs(unordered_map<int,Employee*>&mpp,int id,int &sum){
    sum+=mpp[id]->importance;
    for(auto it:mpp[id]->subordinates){
        dfs(mpp,it,sum);
    }
}
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,Employee*>mpp;
        for(auto it:employees){
            mpp[it->id]=it;
        }
        int sum=0;
        dfs(mpp,id,sum);
        return sum;
    }
};